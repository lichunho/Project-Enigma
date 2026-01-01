#ifndef ROTORDATA_HPP
#define ROTORDATA_HPP

#include <string>

namespace rotor_data {

struct RotorSpec {
  const char *name;
  const char *wiring;
  const char *notch;
  bool isReflector;
};

const RotorSpec *find(const std::string &selection);

} // namespace rotor_data

#endif
