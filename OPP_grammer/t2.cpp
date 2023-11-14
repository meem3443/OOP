#include <iostream>
#include <cstring> // <string.h> 대신 <cstring>를 포함

class MyString {
private:
    char* data;

public:
    MyString(const char* input) {
        data = new char[strlen(input) + 1];
        strcpy(data, input);
    }

    // 이동 생성자 정의
    MyString(MyString&& other) {
        data = other.data;     // 데이터 이동
        other.data = nullptr;  // 원래 객체의 데이터를 nullptr로 설정
    }

    // 소멸자 정의
    ~MyString() {
        delete[] data;
    }

    char* getData() {
        return data;
    }

    void printAddress() {
        std::cout << "Object Address: " << this << std::endl;
        std::cout << "Data Address: " << static_cast<void*>(data) << std::endl;
    }

    
};

int main() {
    MyString str1("Hello, World!");  // 문자열 생성
    str1.printAddress();
    std::cout<<std::endl;
    MyString str2 = std::move(str1); // 이동 생성자 호출
    str1.printAddress();
    str2.printAddress();

    // 이제 str1은 더 이상 유효한 데이터를 가지고 있지 않음

  
    

    return 0;
}
