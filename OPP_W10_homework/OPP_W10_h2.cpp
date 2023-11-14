#include <iostream>

// Implementor Interface (색상을 정의하는 구현자)
class Color {
public:
    virtual void applyColor() = 0;
    virtual ~Color() = default;
};

// Concrete Implementor (구체적인 색상 구현)
class RedColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying Red Color" << std::endl;
    }
};

class BlueColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying Blue Color" << std::endl;
    }
};

// Abstraction (도형을 정의하는 추상화)
class Shape {
protected:
    Color* color; // 색상을 가리키는 포인터
public:
    Shape(Color* color) : color(color) {}

    virtual void applyColor() = 0;
    virtual ~Shape() = default;
};

// Refined Abstraction (정제된 도형)
class Circle : public Shape {
public:
    Circle(Color* color) : Shape(color) {}

    void applyColor() override {
        std::cout << "Drawing Circle ";
        color->applyColor(); // 색상 적용
    }
};

class Square : public Shape {
public:
    Square(Color* color) : Shape(color) {}

    void applyColor() override {
        std::cout << "Drawing Square ";
        color->applyColor(); // 색상 적용
    }
};

int main() {
    Color* red = new RedColor();
    Color* blue = new BlueColor();

    Shape* redCircle = new Circle(red);
    Shape* blueSquare = new Square(blue);

    redCircle->applyColor(); // 원을 빨간색으로 그리기
    blueSquare->applyColor(); // 사각형을 파란색으로 그리기

    delete red;
    delete blue;
    delete redCircle;
    delete blueSquare;

    return 0;
}
