#include <iostream>
#include <cstring>

int main() {

    static const auto len_max = 255;
    char str[len_max];

    std::cin.get(str, len_max, '$');
    std::cout << "input: '" << str << "'" << " len: " << strlen(str) << std::endl;

    char ch = std::cin.get();
    std::cout << "next char: " << ch;

    return 0;
}