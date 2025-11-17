#pragma once
#include <iostream>
#include <string>
class Converter {
private:


public:
  Converter(std::string input);
  ~Converter();
  Converter &operator=(const Converter &other);
  Converter(const Converter &other);
};

std::ostream &operator<<(std::ostream &out, const Converter &c);
