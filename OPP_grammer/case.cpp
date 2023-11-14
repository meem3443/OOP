#include<iostream>
using namespace std;

int num = 10; // 글로벌 변수로 프로그램이 끝날때까지 남아있는다.

/**
 * 이부분은 글로벌 영역./
 * ::을 앞에 붙이는것으로 변수에 접근 가능하다.
 * 
 * 
 * 
*/

/*
int& reference; / 래퍼런스 형 변수. 새로운 변수의 이름이다. 두가지 특징을 가진다.
  1. 기존에 있는 변수를 통해서 초기화를 하기 때문에, 비어있게 저장못함 즉 "초기화" 필수다.
  2. 참조시 주소값을 통해서 역참조하는것과 같다. 즉 포인터를 통해 주소에 접근하는것과 같음.

  ex)
  int secondnum = 10; 
  int& firstnum = secondnum;
  int* pointer = &secondnum;

  firstnum++; == 10+1 == 11
  pointer++ == 에러;
  *pointer++
*/
class A{
  private:
  int x;
  int y;

  protected:
  int z;

  public:
  A(int c): x(c){}

  int& return_ref_x() {return x;}
  int return_x() {return x;}
  void status_x(){cout<<x<<endl;}
  int get()const{return x;}


};

class B : A{


  void printParent(){cout<<z<<endl;}

  
};



void increment(int x){
  ++x; //call by value. 입력된 매개변수의 값을 "복사"하여 전달한다.
}

void increment(int *x){
  ++*x; //call by pointer. 입력된 매개변수의 "주소"를 "복사"하여 전달한다.
}


int main(){
  int num = 100;
  
  cout<<num<<endl;
  cout<<::num<<endl;

  increment(num);
  cout<<num<<endl;

  increment(&num);
  cout<<num<<endl;
  A a(10);
  a.status_x();

 
  const int& err = a.return_x();

  return 0;
}

