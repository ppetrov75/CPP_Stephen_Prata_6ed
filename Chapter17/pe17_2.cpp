#include <iostream>
#include <fstream>

int main() {
    std::string file_name;
    std::cout << "file name: ";
    std::cin >> file_name;

    std::ofstream file(file_name);
    std::string str;
    std::cout << "enter contents of file: '";
    while (true) {
        std::cin >> str;
        if (std::cin.eof())
            break;
        file << str << std::endl;
    }
    std::cout << "'\n";
    file.flush();
    file.close();

    std::cout << "file contents: '";
    std::ifstream file1(file_name);
    while(std::getline(file1, str)) {
        std::cout << str << std::endl;
    }
    std::cout << "'";
    file1.close();
}