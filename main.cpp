#include "plugboardOperations.h"
#include "rotorOperations.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**************************************************************************
getRotorInput
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
void getRotorInput(string selection[], char setting[], char position[]) {
  bool needGuide = false;

  //INPUT 
  cout << "Do you require a step-by-step guide? " << endl;
  cout << "'Y' for yes, input settings directly if no" << endl;
  cout << "-> ";
  cin >> selection[0];

 if (selection[0] == "Y" || selection[0] == "y") {
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

  bool debug = false;
  
  rotor rotor[4];
  string selection[4] = {"B", "I", "II", "III"};
  char setting[4] = {' ', 'A', 'A', 'A'};
  char position[4] = {' ', 'A', 'A', 'A'};

  getRotorInput(selection, setting, position);
  initializeRotors(rotor, selection, setting, position);

  if(debug){
    for (int i = 0; i < 4; i++) {
       rotor[i].printRotor();
    }
  }

  //INPUT - Get plugboard input from user
  vector<plugboard> plugboardPairs;
  //createPair(plugboardPairs, 'U', 'Z');


  string userInput;
  cout << "Please input the message to be encrypted" << endl;
  cout << "-> ";
  cin >> userInput;

  //PROCESSING - Perform the encryption process
  char input = ' ';
  string output = "";
  for (int i = 0; i < userInput.size(); i++) {
    input = toupper(userInput[i]);
    input = plugboardOperations(plugboardPairs, input);
    input = rotorOperations(rotor, input);
    input = plugboardOperations(plugboardPairs, input);
    output.push_back(input);
    
    //Print a space every 5 character to increase readability
    if (!((i + 1) % 5))
      output.push_back(' ');
  }

  //OUTPUT - Print the encrypted message
  cout << "The encrypted message will be" << endl;
  cout << "-> " << output;

  return 0;
}
