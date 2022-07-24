#include <iostream>
#include <fstream>

// 1. Введение в файловые потоки
// 2. Область видимости объектов inFile/outFile
int factorial(int n)
{
  int result{ 1 };
  while(n > 1)
  {
    result *= n--;
  }

  return result;
}

int main()
{
  std::ifstream inFile("input.txt");
  if(!inFile.is_open()){
    // Check where the executable file is located
    std::cerr << "input.txt file wasn't found" << std::endl;
    return 1;
  }

  std::ofstream outFile("output.txt");
  if(!outFile.is_open()){
    std::cerr << "output.txt file wasn't found" << std::endl;
    return 1;
  }

  // file

  int arg;
  //std::cin >> arg;
  inFile >> arg;
  inFile.close();

  int result = factorial(arg);
  //std::cout << arg << "! = " << result << std::endl;
  outFile   << arg << "! = " << result << std::endl;
  outFile.close();

  return 0;

}