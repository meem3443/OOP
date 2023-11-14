#include <iostream>


class BaseClass {
public:
    virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass {
public:
    void derivedMethod() {}
};

int main() {
    BaseClass* base = new DerivedClass(); // DerivedClass 객체를 BaseClass 포인터에 할당

    DerivedClass* derived = dynamic_cast<DerivedClass*>(base); // 다운캐스팅 시도

    if (derived != nullptr) {
        // derived가 유효한 DerivedClass 객체를 가리키는지 확인
        std::cout << "Everything is OKAY" << std::endl;
    } else {
        std::cout << "Something went wrong" << std::endl;
    }

    delete base; // 할당된 메모리 해제

    return 0;
}
