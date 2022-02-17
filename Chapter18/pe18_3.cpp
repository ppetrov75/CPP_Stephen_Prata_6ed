#include <iostream>
#include <iomanip>

long double sum_values() {
    return 0.0;
}
template <typename  T, typename... Args>
long double sum_values(T value, Args... args) {
    long double sum = 0;

    sum = value + sum_values(args...);

    return sum;
}

int main() {

    std::cout << sum_values(1.1, 2.2, 3.3, 4.4, 5.5) << "\n";
    std::cout << std::setprecision(12) << sum_values(1.1111115678, 2.222222345, 3.33333, 4.12344444, 5.54685555) << "\n";

}