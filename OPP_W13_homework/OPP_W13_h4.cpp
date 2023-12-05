#include <iostream>

// Component Interface
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// Concrete Component - 원(Circle)
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Shape : Circle" << std::endl;
    }
};

// Concrete Component - 직사각형(Rectangle)
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Shape : Reactangle" << std::endl;
    }
};

// Decorator - Shape을 확장하는 데코레이터
class ShapeDecorator : public Shape {
protected:
    Shape* decoratedShape;

public:
    ShapeDecorator(Shape* shape) : decoratedShape(shape) {}

    void draw() const override {
        if (decoratedShape)
            decoratedShape->draw();
    }

    virtual ~ShapeDecorator() {
        delete decoratedShape;
    }
};

// Concrete Decorator - 색상을 추가하는 데코레이터
class ColorDecorator : public ShapeDecorator {
private:
    std::string color;

public:
    ColorDecorator(Shape* shape, const std::string& col) : ShapeDecorator(shape), color(col) {}

    void draw() const override {
        if (decoratedShape) {
            decoratedShape->draw();
            std::cout << "Border Color: " << color << std::endl;
        }
    }
};

int main() {
    // 기본 도형
    Shape* circle = new Circle();
    Shape* rectangle = new Rectangle();

    // 도형에 색상 추가
    Shape* coloredCircle = new ColorDecorator(new Circle(), "Red");
    Shape* coloredRectangle = new ColorDecorator(new Rectangle(), "Red");

    // 기본 도형 그리기
    std::cout << "Circle with normal border:" << std::endl;
    circle->draw();

    // 색상이 추가된 도형 그리기
    std::cout << "\nCircle with red border:" << std::endl;
    coloredCircle->draw();

    std::cout << "\nDrawing Colored Rectangle:" << std::endl;
    coloredRectangle->draw();

    // 메모리 해제
    delete circle;
    delete rectangle;
    delete coloredCircle;
    delete coloredRectangle;

    return 0;
}
