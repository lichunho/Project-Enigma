#include "rotorOperations.h"
#include "plugboardOperations.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<plugboard> pair;
  pair.push_back({'A','B'});
  pair.push_back({'C','D'});
  
  rotor rotor[4];
  rotor[0] = {"YRUHQSLDPXNGOKMIEBFZCWVJAT", ' ', 'A', 'A'};
  rotor[1] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A', 'A'};
  rotor[2] = {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A', 'A'};
  rotor[3] = {"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A', 'A'};

  char input = ' ';
  //char output = ' ';

  
  for (int i = 0; i < 10; i++) {

    input = 'A';

    input = plugboardOperations(pair, input);
    input = rotorOperations(rotor, input);
    input = plugboardOperations(pair, input);
    cout << input;

    if (!((i + 1) % 5))
      cout << " ";
    if (!((i + 1) % 40))
      cout << endl;

  }

  

  return 0;
}
