#include "rotorData.hpp"

namespace rotor_data {

static const RotorSpec kSpecs[] = {
    { "I", "EKMFLGDQVZNTOWYHXUSPAIBRCJ", "Q", false },
    { "II", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "E", false },
    { "III", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "V", false },
    { "IV", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "J", false },
    { "V", "VZBRGITYUPSDNHLXAWMJQOFECK", "Z", false },
    { "VI", "JPGVOUMFYQBENHZRDKASXLICTW", "ZM", false },
    { "VII", "NZJHGRCXMYSWBOUFAIVLPEKQDT", "ZM", false },
    { "VIII", "FKQHTLXOCBJSPDZRAMEWNIUYGV", "ZM", false },
    { "B", "YRUHQSLDPXNGOKMIEBFZCWVJAT", "", true },
    { "C", "FVPJIAOYEDRZXWGCTKUQSBNMHL", "", true },
};

const RotorSpec *find(const std::string &selection) {
  for (const auto &spec : kSpecs) {
    if (selection == spec.name) {
      return &spec;
    }
  }
  return nullptr;
}

} // namespace rotor_data

