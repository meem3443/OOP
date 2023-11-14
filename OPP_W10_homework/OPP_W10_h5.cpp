#include <iostream>
#include <cassert>

class CEO
{
public:
  CEO() {}
  virtual ~CEO() {}
};

class CPO 
{
public:
  CPO() {}
  virtual ~CPO() {}
};

class Manager : public CEO, public CPO
{
public:
  Manager() {}
  virtual ~Manager() {}
};

class Staff : public Manager
{
public:
  Staff() {}
  virtual ~Staff() {}
};

int main()
{

  CPO *cpo = new Staff; // CPO는 rank 2이므로 Manger의 rank 3 보다 크다. 따라서 Upcasting.
  CEO *ceo = new Staff; // CEO의 rank 1이므로 Staff의 rank 4 보다 크다. 따라서 Upcasting.

  Staff *staff = dynamic_cast<Staff *>(cpo);       // CPO를 Staff로 다운캐스팅
  Staff *staff2 = dynamic_cast<Staff *>(ceo);      // CEO를 Staff로 다운캐스팅
  Manager *manager = dynamic_cast<Manager *>(ceo); // CEO를 Manager로 다운캐스팅

  assert(staff != nullptr);   // staff가 nullptr이 아닌지 확인
  assert(staff2 != nullptr);  // staff2가 nullptr이 아닌지 확인
  assert(manager != nullptr); // manager가 nullptr이 아닌지 확인

  delete cpo;
  delete ceo;

  return 0;
}

