#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <random>

std::vector<int> loto(int range_loto, int num_randoms) {
    std::vector<int> v(range_loto);
    std::iota(v.begin(), v.end(), 1);

    auto rd = std::random_device {}();
    auto rng = std::default_random_engine { rd };
    std::shuffle(v.begin(), v.end(), std::default_random_engine{std::random_device{}()});
    v.resize(num_randoms);
    return v;
}

int main() {
    auto v = loto(51, 6);
    for(auto n: v) std::cout << n << ' ';
}
