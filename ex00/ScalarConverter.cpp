#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other){
	*this = other;
};
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &){
	return *this;
};
ScalarConverter::~ScalarConverter(){};

static bool isCharLiteral(const std::string &s) {
  return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isIntLiteral(const std::string &s) {
  char *end = NULL;
  errno = 0;
  std::strtol(s.c_str(), &end, 10);
  return (errno == 0 && *end == '\0');
}

static bool isFloatLiteral(const std::string &s) {
  if (s == "nanf" || s == "+inff" || s == "-inff")
    return true;
  if (s.length() == 0 || s[s.length() - 1] != 'f')
    return false;

  char *end = NULL;
  errno = 0;
  std::strtof(s.c_str(), &end);

  return (errno == 0 && end != NULL && *end == 'f' && *(end + 1) == '\0');
}

static bool isDoubleLiteral(const std::string &s) {
  if (s == "nan" || s == "+inf" || s == "-inf")
    return true;

  char *end = NULL;
  errno = 0;
  std::strtod(s.c_str(), &end);

  return (errno == 0 && *end == '\0');
}

void ScalarConverter::convert(std::string const &literal) {
  if (isCharLiteral(literal)) {
    char c = literal[1];
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
    return;
  }

  double value = 0;
  if (isIntLiteral(literal)) {
    value = std::strtol(literal.c_str(), NULL, 10);
  } else if (isFloatLiteral(literal)) {
    if (literal == "nanf")
      value = std::numeric_limits<float>::quiet_NaN();
    else if (literal == "+inff")
      value = std::numeric_limits<float>::infinity();
    else if (literal == "-inff")
      value = -std::numeric_limits<float>::infinity();
    else
      value = std::strtof(literal.c_str(), NULL);
  } else if (isDoubleLiteral(literal)) {
    if (literal == "nan")
      value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf")
      value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf")
      value = -std::numeric_limits<double>::infinity();
    else
      value = std::strtod(literal.c_str(), NULL);
  } else {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
    return;
  }

  // CHAR output
  if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
    std::cout << "char: impossible\n";
  } else if (!std::isprint(static_cast<int>(value))) {
    std::cout << "char: Non displayable\n";
  } else {
    std::cout << "char: '" << static_cast<char>(value) << "'\n";
  }

  // INT output
  if (std::isnan(value) || std::isinf(value) ||
      value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min()) {
    std::cout << "int: impossible\n";
  } else {
    std::cout << "int: " << static_cast<int>(value) << "\n";
  }

  double frac;
  double intpart;
  // FLOAT output
  float f = static_cast<float>(value);
  if (std::isnan(f)) {
    std::cout << "float: nanf\n";
  } else if (std::isinf(f)) {
    if (f > 0)
      std::cout << "float: +inff\n";
    else
      std::cout << "float: -inff\n";
  } else {
    frac = std::modf(value, &intpart);
    if (frac == 0.0) {
      std::cout << "float: " << std::fixed << std::setprecision(1) << value
                << "f\n";
    } else {
      std::cout << "float: " << std::fixed << value << "f\n";
    }
  }

  // DOUBLE output
  if (std::isnan(value)) {
    std::cout << "double: nan\n";
  } else if (std::isinf(value)) {
    if (value > 0)
      std::cout << "double: +inf\n";
    else
      std::cout << "double: -inf\n";
  } else {
    frac = std::modf(value, &intpart);
    if (frac == 0.0) {
      std::cout << "double: " << std::fixed << std::setprecision(1) << value
                << std::endl;
    } else {
      std::cout << "double: " << std::fixed << value << std::endl;
    }
  }
}
