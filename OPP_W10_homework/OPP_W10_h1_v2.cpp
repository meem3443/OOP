#include <iostream>
#include <string>

class AbstractFactoryPattern {
public:
    // 도형을 나타내는 추상 클래스
    class Shape {
    public:
        virtual void draw() = 0;
        virtual ~Shape(){}
    };

    // RoundedRectangle 클래스가 Shape를 상속하고 구현
    class RoundedRectangle : public Shape {
    public:
        void draw() override {
            std::cout << "RoundedRectangle::draw() 메서드 내부." << std::endl;
        }
        virtual ~RoundedRectangle(){};
    };

    // RoundedSquare 클래스가 Shape를 상속하고 구현
    class RoundedSquare : public Shape {
    public:
        void draw() override {
            std::cout << "RoundedSquare::draw() 메서드 내부." << std::endl;
        }
        virtual ~RoundedSquare(){}
    };

    // Rectangle 클래스가 Shape를 상속하고 구현
    class Rectangle : public Shape {
    public:
        void draw() override {
            std::cout << "Rectangle::draw() 메서드 내부." << std::endl;
        }
        virtual ~Rectangle(){}
    };

    // Square 클래스가 Shape를 상속하고 구현
    class Square : public Shape {
    public:
        void draw() override {
            std::cout << "Square::draw() 메서드 내부." << std::endl;
        }
        virtual ~Square(){}
    };

    // 추상 팩토리를 나타내는 AbstractFactory 클래스
    class AbstractFactory {
    public:
        virtual Shape* getShape(const std::string& shapeType) = 0;
        virtual ~AbstractFactory(){}
    };

    // ShapeFactory 클래스가 AbstractFactory를 상속하고 구현
    class ShapeFactory : public AbstractFactory {
    public:
        Shape* getShape(const std::string& shapeType) override {
            if (shapeType == "RECTANGLE") {
                return new Rectangle();
            }
            else if (shapeType == "SQUARE") {
                return new Square();
            }
            return nullptr;
        }
        virtual ~ShapeFactory(){}
    };

    // RoundedShapeFactory 클래스가 AbstractFactory를 상속하고 구현
    class RoundedShapeFactory : public AbstractFactory {
    public:
        Shape* getShape(const std::string& shapeType) override {
            if (shapeType == "RECTANGLE") {
                return new RoundedRectangle();
            }
            else if (shapeType == "SQUARE") {
                return new RoundedSquare();
            }
            return nullptr;
        }
        virtual ~RoundedShapeFactory(){}
    };

    // FactoryProducer 클래스가 AbstractFactory를 생성
    class FactoryProducer {
    public:
        AbstractFactory* getFactory(bool rounded) {
            if (rounded) {
                return new RoundedShapeFactory();
            }
            else {
                return new ShapeFactory();
            }
        }
        virtual ~FactoryProducer(){}
    };
};

int main() {
    // 도형 팩토리 얻기
    AbstractFactoryPattern::FactoryProducer factoryProducer;
    AbstractFactoryPattern::AbstractFactory* shapeFactory = factoryProducer.getFactory(false);
    // Shape Rectangle 객체 얻기
    AbstractFactoryPattern::Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    // Shape Rectangle의 draw 메서드 호출
    shape1->draw();

    // Shape Square 객체 얻기
    AbstractFactoryPattern::Shape* shape2 = shapeFactory->getShape("SQUARE");
    // Shape Square의 draw 메서드 호출
    shape2->draw();

    // 도형 팩토리 얻기
    AbstractFactoryPattern::AbstractFactory* shapeFactory1 = factoryProducer.getFactory(true);

    // Shape Rectangle 객체 얻기
    AbstractFactoryPattern::Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
    // Shape Rectangle의 draw 메서드 호출
    shape3->draw();\

    // Shape Square 객체 얻기
    AbstractFactoryPattern::Shape* shape4 = shapeFactory1->getShape("SQUARE");
    // Shape Square의 draw 메서드 호출
    shape4->draw();

    // 메모리 정리
    delete shape1;
    delete shape2;
    delete shape3;
    delete shape4;
    delete shapeFactory;
    delete shapeFactory1;

  
    return 0;
}
