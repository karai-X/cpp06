#include "Converter.hpp"

Converter::Converter(std::string input) {}

Converter::~Converter() {}

Converter &Converter::operator=(const Converter &other) {
  (void)other;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Converter &b) {
  //   out << b.getName() << ", Converter grade " << b.getGrade() << ".";
  return out;
}

Converter::Converter(const Converter &other) { *this = other; }
