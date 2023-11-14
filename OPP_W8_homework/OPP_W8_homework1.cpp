#include <iostream>

class MyData{
 int number;
 std::string strNumber;
public:
 MyData(int data, std::string str): number(data), strNumber(str){}
//Operator conversion
 operator int(){return number;}
 operator std::string(){return strNumber;} 

//Unary operator
 int operator++(int){ //postfix operation (indicated by dummy 'int')
   int temp = number;
   number++;
   return temp;// 연산자 오버로딩 후위 연산자.
 }
 int operator++(){ //prefix operation
   return ++number;
 } // 연산자 오버로딩 전위 연산자.

 friend std::ostream& operator<<(std::ostream&, MyData &);
};

// non-member operator<< function
std::ostream& operator<<(std::ostream& os, MyData & md){
  return os << "This number is: " << md.strNumber << "\n";
} // 비 멤버 변수 오퍼레이텅 오버로딩

int main(){
 MyData mydata(1, "one");

 std::string strNum = mydata;
 int intNum = mydata;

 std::cout << strNum << std::endl; // one
 std::cout << intNum << std::endl; // 1
 std::cout << mydata++ << std::endl; // 1
 std::cout << ++mydata << std::endl; // 3
 std::cout << mydata;

}
