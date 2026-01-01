#ifndef rotorOperations_H
#define rotorOperations_H

#include "rotorClass.hpp"
#include <fstream>
#include <iostream>

using namespace std;

/**************************************************************************
importRotorDetails
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
rotor importRotorDetails(string rotorSelection);

/**************************************************************************
initializeRotors
- Update the ringSettings on rotors based on userInput
**************************************************************************/
void initializeRotors(rotor rotor[], string selection[], char setting[],
                      char position[]);

/**************************************************************************
rotorOperations
- Perform the rotor operations
- Rotor 1 to 3 -> reflector -> rotor 3 -> 1
- Incredment the rotors after each operation
**************************************************************************/
char rotorOperations(rotor rotor[], char input, bool debug = false);

#endif
