#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "plugboard/plugboard.hpp"
#include "rotor/rotorOperations.hpp"

#include <string>

class EnigmaMachine {
private:
  rotor rotors[4];
  Plugboard plugboard;
  bool debug;

public:
  EnigmaMachine();

  void setDebug(bool debug);
  void setPlugboard(const Plugboard &plugboard);
  void clearPlugboard();
  bool addPlugPair(char letterA, char letterB);

  void configure(const std::string &reflector,
                 const std::string &leftRotor,
                 const std::string &middleRotor,
                 const std::string &rightRotor,
                 char ringLeft,
                 char ringMiddle,
                 char ringRight,
                 char posLeft,
                 char posMiddle,
                 char posRight);

  void configure(const std::string (&selection)[4],
                 const char (&setting)[4],
                 const char (&position)[4]);

  void setPositions(char posLeft, char posMiddle, char posRight);
  std::string encrypt(const std::string &message,
                      bool groupFive = true,
                      bool preserveNonAlpha = false);
  char encryptChar(char c, bool preserveNonAlpha = false);

  void printRotors();
};

#endif

