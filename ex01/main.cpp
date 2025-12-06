// #include <cstdint>
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>
#include <string>

int main(void) {
  Data data;
  uintptr_t raw;
  data.str = "this is data.str";
  data.num = 10;
  std::cout << "===== before serialize =====" << std::endl;
  std::cout << data.str << std::endl;
  std::cout << data.num << std::endl;
  std::cout << &(data) << std::endl;
  std::cout << &(data.str) << std::endl;
  std::cout << &(data.num) << std::endl;

  std::cout << "\n===== after serialize and deserialize =====" << std::endl;
  raw = Serializer::serialize(&data);
  Data *data_ptr = Serializer::deserialize(raw);
  std::cout << data_ptr->str << std::endl;
  std::cout << data_ptr->num << std::endl;
  std::cout << data_ptr << std::endl;
  std::cout << &(data_ptr->str) << std::endl;
  std::cout << &(data_ptr->num) << std::endl;
}
