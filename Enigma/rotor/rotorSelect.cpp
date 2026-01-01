#include "rotorSelect.hpp"

/**************************************************************************
getRotorInput
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
void getRotorInput(string selection[], char setting[], char position[])
{
    bool needGuide = false;

    // INPUT
    cout << "Do you require a step-by-step guide? " << endl;
    cout << "'Y' for yes, 'D' for default, ";
    cout << "input settings directly if no" << endl;
    cout << "-> ";
    cin >> selection[0];

    if (selection[0] == "Y" || selection[0] == "y") {
        needGuide = true;
    }

    if (selection[0] == "D" || selection[0] == "d") {
        selection[0] = "B";
        selection[1] = "I";
        selection[2] = "II";
        selection[3] = "III";
        setting[1] = 'A';
        setting[2] = 'A';
        setting[3] = 'A';
        position[1] = 'A';
        position[2] = 'A';
        position[3] = 'A';
        return;
    }

    getValidReflector(needGuide, selection);
    getValidRotor(needGuide, selection);
    getValidSetting(needGuide, setting);
    getValidPosition(needGuide, position);
}

void getValidReflector(bool needGuide, string selection[])
{
    bool validInput = false;

    while (!validInput) {
        if (needGuide) {
            cout << "Please select the reflector: " << endl;
            cout << "Options: B, C (Choose 1)" << endl;
            cout << "-> ";
            cin >> selection[0];
        }
        if (selection[0] == "B" || selection[0] == "C") {
            validInput = true;
        } else {
            cout << "Invalid input, please try again." << endl;
            needGuide = true;
        }
    }
}

bool isValidRotor(string rotor)
{
    string rotorOptions[8] = {
        "I", "II", "III", "IV", "V", "VI", "VII", "VIII"
    };

    for (int i = 0; i < 8; i++) {
        if (rotor == rotorOptions[i]) {
            return true;
        }
    }
    return false;
}

void getValidRotor(bool needGuide, string selection[])
{
    bool validInput = false;

    while (!validInput) {
        if (needGuide) {
            cout << "Please input the rotor selection: " << endl;
            cout << "Options: I, II, III, IV, V, VI, VII, VIII (Choose 3)"
                 << endl;
            cout << "(e.g.: I II III)" << endl;
            cout << "-> ";
        }

        cin >> selection[1] >> selection[2] >> selection[3];

        if (isValidRotor(selection[1]) == false ||
            isValidRotor(selection[2]) == false ||
            isValidRotor(selection[3]) == false) {
            validInput = false;
            needGuide = true;
            continue;
        }

        if (selection[1] == selection[2] || selection[1] == selection[3] ||
            selection[2] == selection[3]) {
            validInput = false;
            needGuide = true;
            continue;
        }

        validInput = true;
    }
}

void getValidPosition(bool needGuide, char position[])
{
    bool validInput = false;

    while (!validInput) {
        if (needGuide) {
            cout << "Please input the rotor position: " << endl;
            cout << "(e.g.: A A A)" << endl;
            cout << "-> ";
        }

        cin >> position[1] >> position[2] >> position[3];

        if ((position[1] < 'A' || position[1] > 'Z') ||
            (position[2] < 'A' || position[2] > 'Z') ||
            (position[3] < 'A' || position[3] > 'Z')) {
            validInput = false;
            needGuide = true;
            continue;
        }

        validInput = true;
    }
}

void getValidSetting(bool needGuide, char setting[])
{
    bool validInput = false;

    while (!validInput) {
        if (needGuide) {
            cout << "Please input the rotor settings: " << endl;
            cout << "(e.g.: A A A)" << endl;
            cout << "-> ";
        }

        cin >> setting[1] >> setting[2] >> setting[3];

        if ((setting[1] < 'A' || setting[1] > 'Z') ||
            (setting[2] < 'A' || setting[2] > 'Z') ||
            (setting[3] < 'A' || setting[3] > 'Z')) {
            validInput = false;
            needGuide = true;
            continue;
        }

        validInput = true;
    }
}
