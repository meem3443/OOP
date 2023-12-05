#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Rect {
    int w, h;

public:
    Rect() : w(0), h(0) {}
    Rect(int w, int h) : w(w), h(h) {}
    int area() const { return w * h; }
    void print() const {
        cout << "(" << w << "," << h << "," << area() << ")" << endl;
    }

    bool operator<(const Rect& other) const {
        return area() < other.area();
    }
};

int main() {
    int numRectangles;
    cout << "사각형의 개수: ";
    cin >> numRectangles;

    vector<Rect> rectangles;

    for (int i = 0; i < numRectangles; ++i) {
        int width, height;
        cout << "사각형의 폭: ";
        cin >> width;
        cout << "사각형의 높이: ";
        cin >> height;

        rectangles.emplace_back(width, height);
    }

    sort(rectangles.begin(), rectangles.end());

    for (const Rect& rect : rectangles) {
        rect.print();
    }

    return 0;
}