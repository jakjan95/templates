#include <complex>
#include <iostream>

template <typename T1, typename T2>
auto makeComplex(T1 first, T2 second) {
    return std::complex<T1>(first, second);
}

int main() {
    std::complex<int> a = makeComplex(4, 5);         // both ints
    std::complex<double> b = makeComplex(3.0, 2.0);  // both doubles
    std::complex<int> c = makeComplex(1, 5.0);       // int, double -> takes int

    return 0;
}
