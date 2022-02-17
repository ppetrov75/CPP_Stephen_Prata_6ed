#include <iostream>
#include <array>

const int Size = 5;

template<typename T>
void sum(std::array<double, Size> a, T fp) {
    for (auto pt = a.begin(); pt != a.end(); ++pt) {
        fp(*pt);
    }
}

int main() {
    double total = 0.0;
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    sum(temp_c, [&total](double w){total += w;});

    std::cout << "total: " << total << '\n';
    return 0;
}

