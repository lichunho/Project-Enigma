#include "enigma.hpp"
#include "plugboard/plugboard.hpp"
#include "plugboard/plugboardSelect.hpp"
#include "rotor/rotorOperations.hpp"
#include "rotor/rotorSelect.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    bool debug = true;

    string selection[4] = { "B", "I", "II", "III" };
    char setting[4] = { ' ', 'A', 'A', 'A' };
    char position[4] = { ' ', 'A', 'A', 'A' };

    getRotorInput(selection, setting, position);
    EnigmaMachine enigma;
    enigma.configure(selection, setting, position);

    if (debug) {
        enigma.printRotors();
    }

    // INPUT - Get plugboard input from user
    Plugboard plugboard;
    getPlugboardInput(&plugboard);
    enigma.setPlugboard(plugboard);

    string userInput;
    cout << "Please input the message to be encrypted" << endl;
    cout << "-> ";
    getline(cin >> ws, userInput);

    string output = enigma.encrypt(userInput, true, false);

    // OUTPUT - Print the encrypted message
    cout << "The encrypted message will be" << endl;
    cout << "-> " << output << endl;

    return 0;
}
