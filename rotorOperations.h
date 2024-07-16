#ifndef rotorOperations_H
#define rotorOperations_H

#include "rotorClass.h"
#include <iostream>

using namespace std;

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
