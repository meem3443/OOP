#include <iostream>
#include <forward_list>
using namespace std;

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (auto current = first, next = std::next(first); next != last; ++current, ++next) {
            if (comp(*next, *current)) {
                swap(*current, *next);
                swapped = true;
            }
        }
    }
}

class compGreater {
public:
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

class compLess {
public:
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

int main() {
    forward_list<int> values{7, 0, 6, 1, 5, 2, 4, 3};

    cout << "오름차순 정렬" << endl;
    
    bubble_sort(values.begin(), values.end(), compLess());
    for (const auto& value : values) {
        cout << value << " ";
    }
    cout << endl;

    cout << "내림차순 정렬" << endl;
    bubble_sort(values.begin(), values.end(), compGreater());
    for (const auto& value : values) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
