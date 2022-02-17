#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

template<class T>
int reduce(T ar[], int n) {
    auto p = std::unique(ar, ar + n);
    return p - ar;
}

int main() {
    std::ostream_iterator<long, char> long_out(std::cout, " ");
    std::ostream_iterator<std::string , char> str_out(std::cout, " ");

    long ar[]{1, 1, 2, 2, 3, 4, 5};
    std::string strings[]{"aaa", "aaa", "bbbb", "bbbb", "c", "cccccccccccccccccccccccccccccccc"};

    auto len = sizeof(ar) / sizeof(ar[0]);
    std::copy(ar, ar + len, long_out);

    auto new_len = reduce<long>(ar, len);
    std::cout << "\nlength: " << len;

    std::cout << "\nAfter reduce:\n";
    std::copy(ar, ar + new_len, long_out);
    std::cout << "\nnew length: " << new_len << std::endl;

    std::cout << "\nStrings array:\n";
    auto strs_len = sizeof(strings) / sizeof(strings[0]);
    std::copy(strings, strings + strs_len, str_out);
    std::cout << "\nlength: " << strs_len;
    auto new_strs_len = reduce<std::string>(strings, strs_len);
    std::cout << "\nAfter reduce:\n";
    std::copy(strings, strings + new_strs_len, str_out);
    std::cout << "\nnew length: " << new_strs_len << std::endl;
}