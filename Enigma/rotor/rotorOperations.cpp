#include "rotorOperations.hpp"

/**************************************************************************
importRotorDetails
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
rotor importRotorDetails(string rotorSelection) {
  ifstream rotorDetails;
  rotorDetails.open("rotor/rotorDetails.txt");

  rotor designatedRotor;
  string rotorIndex;
  string rotorWiring;
  string rotorNotchPosition;
  string disregardLine;

  while (!rotorDetails.eof()) {
    rotorDetails >> rotorIndex;
    if (rotorIndex == rotorSelection) {
      rotorDetails >> rotorWiring >> rotorNotchPosition;
      designatedRotor.setWiring(rotorWiring);
      designatedRotor.setNotch(rotorNotchPosition);
    } else {
      getline(rotorDetails, disregardLine);
    }
  }

  rotorDetails.close();

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
