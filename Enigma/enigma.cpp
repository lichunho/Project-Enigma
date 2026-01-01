#include "enigma.hpp"

#include <cctype>
#include <iostream>

EnigmaMachine::EnigmaMachine() {
  debug = false;
}

void EnigmaMachine::setDebug(bool debug) {
  this->debug = debug;
}

void EnigmaMachine::setPlugboard(const Plugboard &plugboard) {
  this->plugboard = plugboard;
}

void EnigmaMachine::clearPlugboard() {
  Plugboard empty;
  plugboard = empty;
}

bool EnigmaMachine::addPlugPair(char letterA, char letterB) {
  if (letterA < 'A' || letterA > 'Z' || letterB < 'A' || letterB > 'Z') {
    return false;
  }
  if (letterA == letterB) {
    return false;
  }
  if (plugboard.occupiedLetter(letterA) || plugboard.occupiedLetter(letterB)) {
    return false;
  }

  plugboard.createPair(letterA, letterB);
  return true;
}

void EnigmaMachine::configure(const std::string &reflector,
                             const std::string &leftRotor,
                             const std::string &middleRotor,
                             const std::string &rightRotor,
                             char ringLeft,
                             char ringMiddle,
                             char ringRight,
                             char posLeft,
                             char posMiddle,
                             char posRight) {
  std::string selection[4] = { reflector, leftRotor, middleRotor, rightRotor };
  char setting[4] = { ' ', ringLeft, ringMiddle, ringRight };
  char position[4] = { ' ', posLeft, posMiddle, posRight };
  initializeRotors(rotors, selection, setting, position);
}

void EnigmaMachine::configure(const std::string (&selection)[4],
                             const char (&setting)[4],
                             const char (&position)[4]) {
  std::string selectionCopy[4] = { selection[0], selection[1], selection[2],
                                   selection[3] };
  char settingCopy[4] = { setting[0], setting[1], setting[2], setting[3] };
  char positionCopy[4] = { position[0], position[1], position[2],
                           position[3] };
  initializeRotors(rotors, selectionCopy, settingCopy, positionCopy);
}

void EnigmaMachine::setPositions(char posLeft, char posMiddle, char posRight) {
  rotors[1].setPosition(posLeft);
  rotors[2].setPosition(posMiddle);
  rotors[3].setPosition(posRight);
}

char EnigmaMachine::encryptChar(char c, bool preserveNonAlpha) {
  unsigned char ch = static_cast<unsigned char>(c);
  if (!isalpha(ch)) {
    if (preserveNonAlpha) {
      return c;
    }
    return '\0';
  }

  char input = static_cast<char>(toupper(ch));
  input = plugboard.operations(input);
  input = rotorOperations(rotors, input, debug);
  input = plugboard.operations(input);
  return input;
}

std::string EnigmaMachine::encrypt(const std::string &message,
                                  bool groupFive,
                                  bool preserveNonAlpha) {
  std::string output;
  int lettersProcessed = 0;

  for (size_t i = 0; i < message.size(); i++) {
    char encrypted = encryptChar(message[i], preserveNonAlpha);

    if (encrypted == '\0') {
      continue;
    }

    output.push_back(encrypted);

    unsigned char original = static_cast<unsigned char>(message[i]);
    if (isalpha(original)) {
      lettersProcessed++;
      if (groupFive && !(lettersProcessed % 5)) {
        output.push_back(' ');
      }
    }
  }

  return output;
}

void EnigmaMachine::printRotors() {
  for (int i = 0; i < 4; i++) {
    rotors[i].printRotor();
  }
}
