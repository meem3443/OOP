#include <iostream>

int findMax(int refArray[5])
{
  int temp = refArray[0];

  for (int i = 1; i < 5; i++)
  {
    if (temp < refArray[i])
    {
      temp = refArray[i];
    }
  }

  return temp;
}

int main()
{
  int array[5] = {1, 3, 5, 7, 9};
  int(&refArray)[5] = array;
  std::cout << "The maximum value is: " << findMax(refArray) << std::endl;
  return 0;
}