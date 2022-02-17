#include <iostream>
#include <fstream>

int main() {
    std::ifstream original_file("../original.txt");
    std::ofstream copy_file("./copied.txt");

    if (!original_file.is_open() || !copy_file.is_open())
        return EXIT_FAILURE;

    std::string str;
    while (std::getline(original_file, str)) {
        copy_file << str << std::endl;
    }

    copy_file.close();
    original_file.close();

    return 0;
}