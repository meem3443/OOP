#include <iostream>
#include <algorithm> // max_element, min_element을 사용하기 위한 헤더파일
#include <vector>    // 벡터를 사용하기 위한 헤더파일

int main() {
    const int size = 10;
    std::vector<int> numbers(size);

    // 10개의 정수 입력 받기
    std::cout << "10개의 정수를 입력하세요:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "정수 " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    // 최소값과 최대값 찾기
    auto min_it = std::min_element(numbers.begin(), numbers.end());
    auto max_it = std::max_element(numbers.begin(), numbers.end());

    // 최소값과 최대값 출력
    std::cout << "최소값: " << *min_it << "\n";
    std::cout << "최대값: " << *max_it << "\n";

    return 0;
}
