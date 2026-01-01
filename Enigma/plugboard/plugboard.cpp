#include "plugboard.hpp"

Plugboard::Plugboard() {}

Plugboard::Plugboard(vector<PlugPair> pairs) { this->pairs = pairs; }

bool Plugboard::occupiedLetter(char letter)
{
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs.at(i).contains(letter)) {
            return true;
        }
    }
    return false;
}

void Plugboard::createPair(char letterA, char letterB)
{

    bool letterAOccupied = false;
    bool letterBOccupied = false;
    // Check if letter is already used to create another pair

    for (int i = 0; i < pairs.size(); i++) {
        if (pairs.at(i).contains(letterA)) {
            letterAOccupied = true;
        }
        if (pairs.at(i).contains(letterB)) {
            letterBOccupied = true;
        }
    }

    if (letterAOccupied) {
        cout << "ERROR - " << letterA << " is already being used." << endl;
    } else if (letterBOccupied) {
        cout << "ERROR - " << letterB << " is already being used." << endl;
    } else {
        PlugPair currPair = PlugPair(letterA, letterB);
        pairs.push_back(currPair);
    }
}

char Plugboard::operations(char input)
{

    for (int i = 0; i < pairs.size(); i++) {
        input = pairs.at(i).swapChar(input);
    }

    return input;
}

int Plugboard::getNumPairs() { return pairs.size(); }

void Plugboard::printPlugboard()
{
    for (int i = 0; i < pairs.size(); i++) {
        pairs.at(i).printPlug();
    }
}
