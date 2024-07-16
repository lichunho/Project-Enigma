#ifndef rotorOperations_H
#define rotorOperations_H

#include "rotorClass.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rotorOperations(bool debug = false)
{
  rotor rotorOne("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A', 'A');
  rotor rotorTwo("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A', 'A');
  rotor rotorThree("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A', 'A');
  rotor reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT", ' ', 'A', 'A');
  char temp = ' ';

  bool rotateNext = false;

  for (int i = 0; i < 120; i++) {
    temp = 'A';

    if(rotorTwo.rotateNext()){
      rotorOne.shift();
      rotorTwo.shift();
      rotorThree.shift();
    }
    else if(rotorThree.rotateNext()){
      rotorTwo.shift();
      rotorThree.shift();
    }
    else{
      rotorThree.shift();
    }

    temp = rotorThree.encodeChar(temp);
    temp = rotorTwo.encodeChar(temp);
    temp = rotorOne.encodeChar(temp);
    temp = reflector.encodeChar(temp);
    temp = rotorOne.decodeChar(temp);
    temp = rotorTwo.decodeChar(temp);
    temp = rotorThree.decodeChar(temp);

    cout << temp;
    if((i+1)%5 == 0)  cout << " ";

  }

  temp = ' ';
  rotateNext = false;
}


#endif
