#include <iostream>
#include <deque>

int main() {
    std::deque<int> d {
        1, 9, 7, 3,
        2, 1, 2, 9
    };

    for (const auto& elem : d) {
        std::cout << elem << std::endl;
    }

    return 0;
}