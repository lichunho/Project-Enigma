#ifndef plugboardOperations_H
#define plugboardOperations_H

#include "plugboardClass.h"
#include <iostream>
#include <vector>

using namespace std;

void createPair(vector <plugboard> &pair, char letterA, char letterB) {

	bool letterAOccupied = false;
	bool letterBOccupied = false;
	//Check if letter is already used to create another pair
	
	for (int i = 0; i < pair.size(); i++){
		if(pair.at(i).contains(letterA)){
			letterAOccupied = true;
		}
		if(pair.at(i).contains(letterB)){
			letterBOccupied = true;
		}
	}

	if(letterAOccupied){
		cout << "ERROR - " << letterA << " is already being used." << endl;
	}
	else if(letterBOccupied){
			cout << "ERROR - " << letterB << " is already being used." << endl;
	}
	else{
		pair.push_back({letterA, letterB});
	}

	
}

char plugboardOperations(vector<plugboard> &pair, char input) {

  for (int i = 0; i < pair.size(); i++) {
    input = pair.at(i).swapChar(input);
  }

  return input;
}

#endif
