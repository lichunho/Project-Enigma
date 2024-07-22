#include "plugboardOperations.h"
#include "rotorOperations.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<plugboard> plugboardPairs;
  createPair(plugboardPairs,'A','B');

  rotor rotor[4];
  rotor[0] = importRotorDetails("B");
  rotor[1] = importRotorDetails("I");
  rotor[2] = importRotorDetails("II");
  rotor[3] = importRotorDetails("III");
  
  string userInput;
  cout << "Please input the message to be encrypted" << endl;
  cout << "-> ";
  cin >> userInput;

  char input = ' ';
  cout << "The encrypted message will be" << endl;
  cout << "-> ";
  for (int i = 0; i < userInput.size(); i++) {
    input = userInput[i];
    input = plugboardOperations(plugboardPairs, input);
    input = rotorOperations(rotor, input);
    input = plugboardOperations(plugboardPairs, input);
    cout << input;
  }

  return 0;
}
