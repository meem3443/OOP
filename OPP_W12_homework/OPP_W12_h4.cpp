#include <iostream>

using namespace std;

template<typename T>
T gu(T x, T y) {
    return x < y ? x : y;
}

template<>
double gu<double>(double x, double y){
    return x < y ? x : y;
}

int main() {
    int x = 3;
    int y = 2;
    double d = 2.1;
    double e = 3.3;
    

    cout << "min(x,y): " << gu(x, y) << ", min(d,e): " << gu(d, e) << ", min(d, x): "<< gu<double>(d, x) <<endl;

    return 0;
}
