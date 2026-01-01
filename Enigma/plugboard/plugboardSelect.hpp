#ifndef PLUGBOARDSELECT_HPP
#define PLUGBOARDSELECT_HPP
#include "plugboard.hpp"
#include <iostream>
#include <vector>

using namespace std;

/**************************************************************************
getPlugboardInput
- Receives user selection of the plugboard
- Opens txt file and import the corresponding plugboard detials
**************************************************************************/
void getPlugboardInput(Plugboard *plugboard);

bool getValidPair(bool needGuide, Plugboard plugboard, char selection[]);

#endif
