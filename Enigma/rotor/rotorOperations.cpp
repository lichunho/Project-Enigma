#include "rotorOperations.hpp"
#include "rotorData.hpp"

/**************************************************************************
importRotorDetails
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
rotor importRotorDetails(string rotorSelection) {
  rotor designatedRotor;

  const rotor_data::RotorSpec *spec = rotor_data::find(rotorSelection);
  if (spec != nullptr) {
    designatedRotor.setWiring(string(spec->wiring));
    designatedRotor.setNotch(string(spec->notch));
  } else {
    cout << "ERROR - Invalid rotor selection: " << rotorSelection << endl;
  }

  return designatedRotor;
}

/**************************************************************************
initializeRotors
- Update the ringSettings on rotors based on userInput
**************************************************************************/
void initializeRotors(rotor rotor[], string selection[], char setting[],
                      char position[]) {

  rotor[0] = importRotorDetails(selection[0]);
  for (int i = 1; i <= 3; i++) {
    rotor[i] = importRotorDetails(selection[i]);
    rotor[i].setRing(setting[i]);
    rotor[i].setPosition(position[i]);
  }
  
}

/**************************************************************************
rotorOperations
- Perform the rotor operations
- Rotor 1 to 3 -> reflector -> rotor 3 -> 1
- Incredment the rotors after each operation
**************************************************************************/
char rotorOperations(rotor rotor[], char input, bool debug) {
  bool middleAtNotch = rotor[2].advanceNext();
  bool rightAtNotch = rotor[3].advanceNext();

  if (middleAtNotch) {
    rotor[1].shift();
  }

  if (middleAtNotch || rightAtNotch) {
    rotor[2].shift();
  }

  rotor[3].shift();

  if(debug)
  {
    cout << "Rotor config: ";
    for(int i = 1; i <= 3; i++)
      {
        cout << rotor[i].getPosistion();
      }
    cout << endl;
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
