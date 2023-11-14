#include <iostream> 

void increment(int* x) 
{ 
  int *ptr = x;
  ++*(ptr);
}

int main() 
{ 
  int x=55; 
  std::cout<<" Before increment: "<<x<< std::endl;
  increment( &x ); 
  std::cout << " After increment: " << x << std::endl;

  system("pause");
  return 0;
}
