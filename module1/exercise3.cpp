#include <iostream>

template <int N>
struct IsSmallPrime : std::false_type {
};

template <>
struct IsSmallPrime<2> : std::true_type {
};

template <>
struct IsSmallPrime<3> : std::true_type {
};

template <>
struct IsSmallPrime<5> : std::true_type {
};

template <>
struct IsSmallPrime<7> : std::true_type {
};

int main() {
    std::cout << std::boolalpha << IsSmallPrime<1>::value << std::endl;  // prints 0 (false)
    std::cout << std::boolalpha << IsSmallPrime<2>::value << std::endl;  // prints 1 (true)
    return 0;
}
