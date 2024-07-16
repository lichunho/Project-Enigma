#ifndef plugboardOperations_H
#define plugboardOperations_H

#include "plugboardClass.h"
#include <iostream>
#include <vector>

using namespace std;

char plugboardOperations(	vector<plugboard> &pair, 
												 	char input, 
												 	bool debug = false) {

	for(int i = 0; i < pair.size(); i++)
	{
			input = pair.at(i).swapChar(input);
	}
	
return input;
}

#endif
