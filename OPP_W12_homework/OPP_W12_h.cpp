#include<iostream>
using namespace std;

template <typename T>
T swap(T* i1, T* i2){
  T temp = *i1;
  *i1 = *i2;
  *i2 = temp;
  return 0;
}

int main(){

  int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;

  swap(&a, &b);
  swap(&c, &d);

  cout<<"a :"<<a<<endl;
  cout<<"b :"<<b<<endl;
  cout<<"c :"<<c<<endl;
  cout<<"d :"<<d<<endl;

  
  return 0;
}
