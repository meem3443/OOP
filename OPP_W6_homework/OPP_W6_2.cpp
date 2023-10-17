#include <iostream>
#include <exception>

class MyException : public std::exception {
public:
    MyException(const char* message) : message(message) {}

    // 오버라이딩된 what() 메서드
    const char* what() const noexcept override {
        return message;
    }

private:
    const char* message;
};

int main() {
    try {
        throw MyException("너무 잘생겨서 예외가 발생했습니다!");
    } catch (const std::exception& e) {
        std::cout << "예외가 발생했습니다: " << e.what() << std::endl;
    }

    return 0;
}
