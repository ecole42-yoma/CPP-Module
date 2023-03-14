#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: ./RPN \"expression...\"" << std::endl;
  } else {
    RPN rpn(argv[1]);
  }
}
