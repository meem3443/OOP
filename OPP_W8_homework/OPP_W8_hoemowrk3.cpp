#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Base1 {
public:
  Base1(int n) : vector_(n , 3) {cout<<"Base 1 Constructor"<<endl;}

  

private:
  std::vector<char> vector_;
};

class Base2 {
public:
  Base2(int n) : vector_(n , 3) {cout<<"Base 2 Constructor"<<endl;}
  //.....
private:
  std::vector<char> vector_;
};

class Derived : public Base1, Base2 {
public:
  Derived (const std::string& str) : Base2(1024), Base1(512)
  { i = 0;
    cout<<"Derived 1 Constructor"<<endl;
  }
  // ...
private:
  std:: string str_;
  int i = 0;
};
int main() {
  Derived drv("1");
 return 0;
}
//순서 바꿔도 상관없음 Base2 -> Base1 -> Derived