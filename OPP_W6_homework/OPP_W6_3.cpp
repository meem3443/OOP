#include<iostream>
using namespace std;

class A : public exception{
  private: 
  const char* messages;
  

  public:
  int value;
  A() : messages("default Error"),value(8){
    cout<<"Constructor( )\nDestructor( )"<<endl;
  }

  A(const char * messages) : messages(messages){}

  ~A(){
  }
  
  const void ExceptionMessage() const {
  }
  
  void showMeTheE(){
  messages = "Custom Error";
  throw A(messages);
  }

};

int main(){
  try
  {
    A A;
    throw A.value;

  }
  catch(int e)
  {
   cout<<"Catch: "<<e<<endl;
  }
  
  return 0;
}
