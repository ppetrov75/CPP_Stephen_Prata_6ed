#include <iostream>
#include <algorithm>
#include <cctype>

namespace {

    bool my_isalphanum(char ch) {
        return std::isalnum(static_cast<unsigned char>(ch));
    }

    bool check_palindrom(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        std::string tmp;
        std::copy_if(str.begin(), str.end(), std::back_inserter(tmp),
                     //my_isalphanum);
                     [](unsigned char c) { return static_cast<bool>(std::isalnum(c)); });

        return (tmp == std::string(tmp.rbegin(), tmp.rend()));
    }
}

int main() {
    std::string str;
    std::cout << "Enter string: ";
//    std::cin >> str;

    if (!check_palindrom("Madam, I’m Adam."))
        std::cout << "not ";
    std::cout << "palindrom\n";
}