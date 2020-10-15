#include <iostream>

template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << '\n';
}

template <typename... Numbers>
auto areEven(Numbers... nums) {
    print(nums...);
    return ((nums % 2 == 0) && ...);
}

int main() {
    print(5, 2, 1, 3);

    std::cout << std::boolalpha << areEven(2, 4, 6) << '\n';

    return 0;
}
