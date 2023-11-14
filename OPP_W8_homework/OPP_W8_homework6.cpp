#include <iostream>

class Parent {
 char *p;
public:
  Parent() {
   p = new char[10];
   std::cout << "Parent Constructor invocation" << std::endl;
   }
  virtual ~Parent() {
   delete [] p;
   std::cout << "Parent Destructor invocation" << std::endl;
   }
};
class Child : public Parent {
 char *c;
public:
  Child() : Parent() {
   c = new char[10];
   std::cout << "Child Constructor invocation" << std::endl;
   }
  virtual ~Child() {
   delete [] c;
   std::cout << "Child Destructor invocation" << std::endl;
   }
};
int main() {
  std::cout << "--- Case1: Normal Child instantiation ---" << std::endl;
   Child *c = new Child();
  delete c;

  std::cout << "--- Case2: Parent pointer to Child ---" << std::endl;
    Parent *p = new Child();
    
    delete p;
    //p가 할당해제 되나 Child는 할당해제 되지 않는다. 그리하여 메모리 누수 발생.
  
}
