#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

struct Data {
  std::string str;
  int num;
};

class Serializer {
private:

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
