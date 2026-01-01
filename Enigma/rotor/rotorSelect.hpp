#ifndef ROTORSELECT_HPP
#define ROTORSELECT_HPP
#include <iostream>

using namespace std;

/**************************************************************************
getRotorInput
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
void getRotorInput(string selection[], char setting[], char position[]);

void getValidReflector(bool needGuide,string selection[]);

void getValidRotor(bool needGuide,string selection[]);

void getValidSetting(bool needGuide, char setting[]);

void getValidPosition(bool needGuide, char position[]);

#endif