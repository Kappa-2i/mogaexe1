
#include "zlasdtest/test.hpp"
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  int choice = 1;
  std::cout << std::endl << "Choose a test: \n1-lasdtest \n2-mytest" << std::endl;
  std::cin >> choice;
  switch(choice){
    case 1:
      lasdtest();
      break;
    case 2:
      mytest();
      break;
    default:
      std::cout << "Invalid choice" << std::endl;
  }
  return 0;
}