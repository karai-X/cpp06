#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  srand(time(NULL));
  int r = rand() % 3;
  switch (r) {
  case 0:
    return new A();
  case 1:
    return new B();
  default:
    return new C();
  }
}

// Identify using pointer
void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (...) {
  }
  std::cout << "Unknown type" << std::endl;
}

int main(void) {
  Base *a = new A;
  Base *b = new B;
  Base *c = new C;
  std::cout << "===== Test identify(Base *p) =====" << std::endl;
  identify(a);
  identify(b);
  identify(c);
  std::cout << "===== Test identify(Base &p) =====" << std::endl;
  identify(*a);
  identify(*b);
  identify(*c);
  std::cout << "===== Test generate =====" << std::endl;
  Base *unknown = generate();
  identify(unknown);
  identify(*unknown);
}
