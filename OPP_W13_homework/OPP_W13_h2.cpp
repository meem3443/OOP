#include <iostream>
#include <algorithm>

template<typename T>
T min_value(T x) {
    return x;
}

template<typename T, typename... Args>
T min_value(T x, Args... args) {
    T smaller = min_value(args...);
    return std::min(x, smaller);
}

int main() {
    auto x = min_value(42, 3.14, 11.1f, -2);
    std::cout << x;

    return 0;
}
