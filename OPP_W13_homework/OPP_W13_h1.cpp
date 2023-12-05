#include <iostream>

using namespace std;




template <typename T>
T sum(T value) { return value; } // template function

template <typename T, typename... Args>
T sum(T first, Args... rest)
{
  return first + sum(rest...);
}

template <typename T, typename... Args>
double average(T first, Args... rest)
{
  return static_cast<double>(sum(first, rest...)) / (sizeof...(rest) + 1);
}

int main()
{
  std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5

  return 0;
}
