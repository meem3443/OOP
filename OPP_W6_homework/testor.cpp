#include<iostream>
using namespace std;


class mother{
  int num;

  public:
  mother(){
    num = 10;
    cout<<"mother constructer"<<endl;
  }
};

class son :  mother{
  public:
  son(){
    cout<<"son constructer"<<endl;
  }
};


int main(){
  
  son();


  return 0;
};

