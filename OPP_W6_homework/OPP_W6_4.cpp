#include <iostream>
using namespace std;

class Person
{
protected:
  string name = "김진서";
  int age = 21;
  string address = "daejeon";
};

class Student : Person
{
public:
  string getName() { return name; }
  int getAge() { return age; }
  string getAddress() { return address; }
  string getStudentID() { return "202202575"; }
};

int main()
{
  Student st;
  std::cout << "Name: " << st.getName() << endl;
  std::cout << "Age: " << st.getAge() << endl;
  std::cout << "Address: " << st.getAddress() << endl;
  std::cout << "Student ID: " << st.getStudentID() << endl;

  return 0;
}

