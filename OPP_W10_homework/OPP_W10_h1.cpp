#include <iostream>

// Abstract Product A
class AbstractProductA {
public:
    virtual void use() = 0;
    virtual ~AbstractProductA() = default;
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using Concrete Product A1" << std::endl;
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void use() override {
        std::cout << "Using Concrete Product A2" << std::endl;
    }
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void operate() = 0;
    virtual ~AbstractProductB() = default;
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operate() override {
        std::cout << "Operating Concrete Product B1" << std::endl;
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operate() override {
        std::cout << "Operating Concrete Product B2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
    virtual ~AbstractFactory() = default;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA = factory1->createProductA();
    AbstractProductB* productB = factory1->createProductB();

    productA->use();
    productB->operate();

    delete factory1;
    delete productA;
    delete productB;

    return 0;
}
