#include <iostream>
#include <algorithm>

namespace {
    bool check_palindrom(const std::string& str) {
        std::string tmp(str.rbegin(), str.rend());
        return (str == tmp);
    }
}

int main() {
    std::string str;
    std::cout << "Enter string: ";
    std::cin >> str;

//    if (!check_palindrom(str))
    if(str != std::string(str.rbegin(), str.rend()))
        std::cout << "not ";
    std::cout << "palindrom\n";
}