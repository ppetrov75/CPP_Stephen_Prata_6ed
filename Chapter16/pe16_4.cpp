#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

int reduce(long ar[], int n) {
    auto p = std::unique(ar, ar + n);
    return p - ar;
}

int main() {
    std::ostream_iterator<long, char> out(std::cout, " ");
    long ar[]{1, 1, 2, 2, 3, 4, 5};

    auto len = sizeof(ar) / sizeof(ar[0]);
    std::copy(ar, ar + len, out);

    auto new_len = reduce(ar, len);
    std::cout << "\nlength: " << len;

    std::cout << "\n\nAfter reduce:\n";
    std::copy(ar, ar + new_len, out);
    std::cout << "\nnew length: " << new_len << std::endl;
}