#include "plugboardSelect.hpp"

#include <cctype>

void getPlugboardInput(Plugboard *plugboard)
{
    bool needGuide = false;
    string choice;
    char selection[2];

    // INPUT
    cout << "Do you require a step-by-step guide? " << endl;
    cout << "'Y' for yes, 'N' for no, 'S' for skip" << endl;
    cout << "-> ";
    cin >> choice;

    needGuide = choice == "Y" || choice == "y";

    if (choice == "S" || choice == "s") {
        return;
    }

    while (getValidPair(needGuide, *plugboard, selection)) {
        plugboard->createPair(selection[0], selection[1]);
        cout << "Created pair: " << selection[0] << " <-> " << selection[1]
             << endl;
    }
}

bool validPair(Plugboard plugboard, char inputOne, char inputTwo)
{

    if (inputOne < 'A' || inputOne > 'Z') {
        return false;
    }
    if (inputTwo < 'A' || inputTwo > 'Z') {
        return false;
    }
    if (inputOne == inputTwo) {
        return false;
    }
    if (plugboard.occupiedLetter(inputOne) ||
        plugboard.occupiedLetter(inputTwo)) {
        return false;
    }

    return true;
}

bool getValidPair(bool needGuide, Plugboard plugboard, char selection[])
{
    bool validInput = false;
    string input;

    while (!validInput) {
        if (needGuide) {
            cout << "Please select a plugboard pair: " << endl;
            cout << "Options: A-Z (type 'end' to finish)" << endl;
            cout << "-> ";
        }

        cin >> input;

        if (input == "end" || input == "END") {
            return false;
        }

        if (input.size() != 2) {
            validInput = false;
            cout << "Invalid input, please try again." << endl;
            needGuide = true;
            continue;
        }

        selection[0] = static_cast<char>(toupper(static_cast<unsigned char>(input[0])));
        selection[1] = static_cast<char>(toupper(static_cast<unsigned char>(input[1])));

        if (!validPair(plugboard, selection[0], selection[1])) {
            validInput = false;
            cout << "Invalid input, please try again." << endl;
            needGuide = true;
        } else {
            validInput = true;
        }
    }
    return true;
}
