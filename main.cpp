#include "plugboardOperations.h"
#include "rotorOperations.h"
#include <iostream>
#include <vector>

using namespace std;

void getUserInput(rotor rotor[], string selection[], char setting[],
                  char position[]) {
  bool needGuide = false;

  cout << "Do you require a step-by-step guide? " << endl;
  cout << "'Y' for yes, input settings directly if no" << endl;
  cout << "-> ";
  cin >> selection[0];

  if (selection[0] == "Y") {
    needGuide = true;
  }

  if (needGuide) {
    cout << "Please select the reflector: " << endl;
    cout << "Options: B, C (Choose 1)" << endl;
    cout << "-> ";
    cin >> selection[0];
  }

  if (needGuide) {
    cout << "Please input the rotor selection: " << endl;
    cout << "Options: I, II, III, IV, V, VI, VII, VIII (Choose 3)" << endl;
    cout << "(e.g.: I II III)" << endl;
    cout << "-> ";
  }
  cin >> selection[1] >> selection[2] >> selection[3];

  if (needGuide) {
    cout << "Please input the rotor settings: " << endl;
    cout << "(e.g.: A A A)" << endl;
    cout << "-> ";
  }
  cin >> setting[1] >> setting[2] >> setting[3];

  if (needGuide) {
    cout << "Please input the rotor position: " << endl;
    cout << "(e.g.: A A A)" << endl;
    cout << "-> ";
  }
  cin >> position[1] >> position[2] >> position[3];
}

int main() {

  vector<plugboard> plugboardPairs;
  createPair(plugboardPairs, 'U', 'Z');
  createPair(plugboardPairs, 'M', 'B');
  createPair(plugboardPairs, 'Y', 'T');
  createPair(plugboardPairs, 'P', 'C');
  createPair(plugboardPairs, 'N', 'H');

  rotor rotor[4];

  string selection[4] = {"B", "VI", "VII", "VIII"};
  char setting[4] = {' ', 'I', 'H', 'F'};
  char position[4] = {' ', 'N', 'I', 'I'};

  //getUserInput(rotor, selection, setting, position);
  initializeRotors(rotor, selection, setting, position);

  for (int i = 0; i < 4; i++) {
    // rotor[i].printRotor();
  }

  string userInput;
  // cout << "Please input the message to be encrypted" << endl;
  // cout << "-> ";
   cin >> userInput;

  for (int i = 0; i < 100; i++) {
    //userInput.push_back('A');
  }

  char input = ' ';
  string output = "";
  for (int i = 0; i < userInput.size(); i++) {
    input = userInput[i];
    input = plugboardOperations(plugboardPairs, input);
    input = rotorOperations(rotor, input);
    input = plugboardOperations(plugboardPairs, input);
    output.push_back(input);
    if (!((i + 1) % 5))
      output.push_back(' ');
  }
  cout << "The encrypted message will be" << endl;
  cout << "-> " << output;

  return 0;
}
