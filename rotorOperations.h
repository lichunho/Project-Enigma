#ifndef rotorOperations_H
#define rotorOperations_H

#include "rotorClass.h"
#include <fstream>
#include <iostream>

using namespace std;

/**************************************************************************
importRotorDetails
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
rotor importRotorDetails(string rotorSelection) {
  ifstream rotorDetails;
  rotorDetails.open("rotorDetails.txt");

  rotor designatedRotor;
  string rotorIndex;
  string rotorWiring;
  char rotorNotchChar;
  string disregardLine;

  while (!rotorDetails.eof()) {
    rotorDetails >> rotorIndex;
    if (rotorIndex == rotorSelection) {
      rotorDetails >> rotorWiring >> rotorNotchChar;
      designatedRotor.setWiring(rotorWiring);
      designatedRotor.setNotch(rotorNotchChar);
    } else {
      getline(rotorDetails, disregardLine);
    }
  }

  rotorDetails.close();

  return designatedRotor;
}

/**************************************************************************
initializeRotors
- 
**************************************************************************/
void initializeRotors(rotor rotor[4], string selection[]){
  
}

/**************************************************************************
rotorOperations
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
char rotorOperations(rotor rotor[], char input, bool debug = false) {
  if (rotor[2].advanceNext()) {
    rotor[1].shift();
    rotor[2].shift();
    rotor[3].shift();
  } else if (rotor[3].advanceNext()) {
    rotor[2].shift();
    rotor[3].shift();
  } else {
    rotor[3].shift();
  }

  input = rotor[3].encodeChar(input);
  input = rotor[2].encodeChar(input);
  input = rotor[1].encodeChar(input);
  input = rotor[0].encodeChar(input);
  input = rotor[1].decodeChar(input);
  input = rotor[2].decodeChar(input);
  input = rotor[3].decodeChar(input);

  return input;
}

#endif
