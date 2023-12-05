#include <iostream>
using namespace std;

template <typename T>
void swap(T* i1, T* i2) {
    T temp = *i1;
    *i1 = *i2;
    *i2 = temp;
    return 0;
}


template <>
void swap<string>(string* i1, string* i2) {
    string temp = *i1;
    *i1 = *i2;
    *i2 = temp;

    
}

int main() {
    int a = 1;
    int b = 2;
    float c = 3.3;
    float d = 4.4;
    string e = "world";
    string f = "hello";

    swap(&a, &b);
    swap(&c, &d);
    swap(&e, &f); 

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;

    return 0;
}
