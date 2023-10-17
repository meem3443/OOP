#include <iostream>
using namespace std;

class alpha {
private:
    int result;

public:
    alpha() : result(0) {}

    alpha operator++() {
        result++;
        return *this;
    }

    alpha operator++(int) {
        alpha temp = *this;
        result++;
        return temp;
    }

    void showResult(){
      std::cout<<result<<endl;
    }

};

int main() {
    alpha a;
    a.showResult();
    ++a; 
    a.showResult();
    a++;
    a.showResult();

    

    return 0;
}
