#include "plugboard/plugboard.hpp"
#include "plugboard/plugboardSelect.hpp"
#include "rotor/rotorOperations.hpp"
#include "rotor/rotorSelect.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    bool debug = true;

    rotor rotor[4];
    string selection[4] = { "B", "I", "II", "III" };
    char setting[4] = { ' ', 'A', 'A', 'A' };
    char position[4] = { ' ', 'A', 'A', 'A' };

    getRotorInput(selection, setting, position);
    initializeRotors(rotor, selection, setting, position);

    if (debug) {
        for (int i = 0; i < 4; i++) {
            rotor[i].printRotor();
        }
    }

    // INPUT - Get plugboard input from user
    Plugboard plugboard;
    getPlugboardInput(plugboard);

    string userInput;
    cout << "Please input the message to be encrypted" << endl;
    cout << "-> ";
    cin >> userInput;

    // PROCESSING - Perform the encryption process
    char input = ' ';
    string output = "";
    for (int i = 0; i < userInput.size(); i++) {
        input = toupper(userInput[i]);
        input = plugboard.operations(input);
        input = rotorOperations(rotor, input);
        input = plugboard.operations(input);
        output.push_back(input);

        // Print a space every 5 character to increase readability
        if (!((i + 1) % 5))
            output.push_back(' ');
    }

    // OUTPUT - Print the encrypted message
    cout << "The encrypted message will be" << endl;
    cout << "-> " << output << endl;

    return 0;
}
