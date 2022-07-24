#include <stdlib.h>
#include <math.h>
#include <iostream>

const double PI = 3.1415926535;

int main ()
{
  char buffer[256];
  std::cout << "Enter degrees: ";
  std::cin >> buffer;

  double angle = atof(buffer);
  double result = sin(angle * PI / 180);
  std::cout <<"The sin of " << angle << " degrees is " << result << "\n";
}