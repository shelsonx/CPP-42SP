#include "Array.hpp"
#include <iomanip>

#define SIZE 4

int main(void) {
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  std::cout << "Ints: " << std::endl;
  {
    Array<int> arr(SIZE);

    try {
      arr[0] = 1;
      arr[1] = 3;
      arr[2] = 5;
      arr[3] = 7;
      for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << std::endl;
      }
      std::cout << "array.size()= " << arr.size() << std::endl;
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  std::cout << "Floats: " << std::endl;
  {
    Array<float> arr(SIZE);
    
    try {
      arr[0] = 1.5;
      arr[1] = 3.2;
      arr[2] = 5.3;
      arr[3] = 7.0;
      for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << std::endl;
      }
      std::cout << "array.size()= " << arr.size() << std::endl;
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  std::cout << "Strings: " << std::endl;
  {
    Array<std::string> arr(SIZE);
    
    try {
      arr[0] = "Deus";
      arr[1] = "Davi";
      arr[2] = "Doriane";
      arr[3] = "Shell";
      for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << std::endl;
      }
      std::cout << "array.size()= " << arr.size() << std::endl;
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  std::cout << "Exception: " << std::endl;
  {
    Array<std::string> arr(SIZE);
    
    try {
      arr[0] = "Deus";
      arr[1] = "Davi";
      arr[2] = "Doriane";
      arr[SIZE] = "Shell";
      for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << std::endl;
      }
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  std::cout << "Copy assignment constructor test: " << std::endl;
  {
    
    try {
      Array<std::string> arr1(1);
      arr1[0] = "Deus";
      Array<std::string> arr2 = arr1;
      arr1[0] = "Jesus";
      std::cout << "arr2: " << arr2[0] << std::endl;
      std::cout << "arr1: " << arr1[0] << std::endl;
      std::cout << "array.size()= " << arr1.size() << std::endl;
  
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  std::cout << "Copy constructor test: " << std::endl;
  {
    
    try {
      Array<std::string> arr1(1);
      arr1[0] = "Davi";
      Array<std::string> arr2(arr1);
      arr1[0] = "Lucca";
      std::cout << "arr2: " << arr2[0] << std::endl;
      std::cout << "arr1: " << arr1[0] << std::endl;
      std::cout << "array.size()= " << arr2.size() << std::endl;
  
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
  return 0;
}
