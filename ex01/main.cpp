// #include <cstdint>
#include <iostream>
#include <stdint.h>
#include <string>

struct Data {
  std::string str;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

int main(void) {
  Data data;
  uintptr_t raw;
  data.str = "this is data.str";
  std::cout << "===== before serialize =====" << std::endl;
  std::cout << data.str << std::endl;
  std::cout << &(data) << std::endl;

  std::cout << "\n===== after serialize and deserialize =====" << std::endl;
  raw = serialize(&data);
  Data *data_ptr = deserialize(raw);
  std::cout << data_ptr->str << std::endl;
  std::cout << data_ptr << std::endl;
}

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }
