#ifndef rotorOperations_H
#define rotorOperations_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

void rotorShift(string &map, bool debug);
void activateRotor(string rotor[], bool debug);
char encryptChar(char input, string map, bool debug);
char decryptChar(char input, string map, bool debug);
void rotorOperations(vector <char> &message, bool debug);

/*******************************************************************************
rotorShift
- Perform a shift on the rotor
*******************************************************************************/
void rotorShift(string &map, bool debug = false)
{

  if (debug) cout << endl << "Map before change: " << map << endl;

  char temp = map.at(0);

  for (int i = 0; i < map.size() - 1; i++)
  {
      map.at(i) = map.at(i + 1);
  }

  map.at(map.size() - 1) = temp;

  if (debug) cout << "Map after change:  " << map << endl << endl;

}

/*******************************************************************************
activateRotor
- Decide which rotor to rotate and call rotorShift
*******************************************************************************/
void activateRotor(string rotor[], bool debug = false)
{
  if(rotor[1].at(0) == 'A')
  {
    if(rotor[2].at(0) == 'A')
    {
      if (debug) cout << "Rotating 3rd rotor" << endl;
      rotorShift(rotor[3]);
    }
    if (debug) cout << "Rotating 2nd rotor" << endl;
    rotorShift(rotor[2]);
  }
  if (debug) cout << "Rotating 1st rotor" << endl;
  rotorShift(rotor[1]);
}


/*******************************************************************************
encryptChar
- 
*******************************************************************************/
char encryptChar(char input, string map, bool debug = false)
{
  int position = 0;
  char output = ' ';

  position = input - 'A';
  output = map.at(position);

  if(debug)
  {
    cout << endl;
    cout << "Character before encryption: " << input << endl;
    cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    cout << map << endl;
    cout << "Character after encryption: " << output << endl;
    cout << endl;
  }

  return output;
}

/*******************************************************************************
defineMap
- Generate a 

*******************************************************************************/
char decryptChar(char input, string map, bool debug = false)
{
  int position = 0;
  char output = ' ';

  position = map.find(input);
  output = position + 'A';

  if(debug)
  {
    cout << endl;
    cout << "Character before decryption: " << input << endl;
    cout << map << endl;
    cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    cout << "Character after encryption: " << output << endl;
    cout << endl;
  }

  return output;
}

/*******************************************************************************
defineMap
- Generate a 

*******************************************************************************/
void rotorOperations(vector <char> &message, bool debug = false)
{
  string rotor[] = {"EJMZALYXVBWFCRQUONTSPIKHGD", 
                    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
                    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
                    "BDFHJLCPRTXVZNYEIWGAKMUSQO"};

  for (int i = 0; i < message.size(); i++)
  {
    message.at(i) = encryptChar(message.at(i), rotor[1]);
    message.at(i) = encryptChar(message.at(i), rotor[2]);
    message.at(i) = encryptChar(message.at(i), rotor[3]);
    message.at(i) = encryptChar(message.at(i), rotor[0]);
    message.at(i) = decryptChar(message.at(i), rotor[3]);
    message.at(i) = decryptChar(message.at(i), rotor[2]);
    message.at(i) = decryptChar(message.at(i), rotor[1]);

    activateRotor(rotor);
  }
}

#endif
