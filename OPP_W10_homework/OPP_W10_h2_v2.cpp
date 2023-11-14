#include <iostream>
using namespace std;

// 구현 인터페이스 (DrawAPI)
class DrawAPI
{
public:
  virtual void drawCircle(int radius, int x, int y) = 0;
  virtual ~DrawAPI(){};
};

// 구현 클래스 (RedCircle)
class RedCircle : public DrawAPI
{
public:
  void drawCircle(int radius, int x, int y) override
  {
    cout << "Drawing Circle [color: red, radius: " << radius << ", x: " << x << ", y: " << y << "]" << endl;
  }
  virtual ~RedCircle(){};
};

// 구현 클래스 (GreenCircle)
class GreenCircle : public DrawAPI
{
public:
  void drawCircle(int radius, int x, int y) override
  {
    cout << "Drawing Circle [color: green, radius: " << radius << ", x: " << x << ", y: " << y << "]" << endl;
  }
  virtual ~GreenCircle(){};
};

// 추상 클래스 (Shape)
class Shape
{
protected:
  DrawAPI *drawAPI;

public:
  Shape(DrawAPI *api) : drawAPI(api) {}
  virtual void draw() = 0;
  virtual ~Shape(){};
};

// 구체 클래스 (Circle)
class Circle : public Shape
{
private:
  int x, y, radius;

public:
  Circle(int x, int y, int radius, DrawAPI *api) : Shape(api), x(x), y(y), radius(radius) {}

  void draw() override
  {
    drawAPI->drawCircle(radius, x, y);
  }
  virtual ~Circle(){};
};

int main()
{
  DrawAPI *redAPI = new RedCircle();
  DrawAPI *greenAPI = new GreenCircle();

  Shape *redCircle = new Circle(100, 100, 10, redAPI);
  Shape *greenCircle = new Circle(100, 100, 10, greenAPI);

  redCircle->draw();
  greenCircle->draw();

  delete redAPI;
  delete greenAPI;
  delete redCircle;
  delete greenCircle;

  return 0;
}
