#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

class ScalarConverter {
public:
  static void convert(std::string const &literal);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(ScalarConverter const &);
  ~ScalarConverter();
};

#endif
