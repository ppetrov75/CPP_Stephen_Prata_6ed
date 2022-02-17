#include <fstream>

int main() {
    std::ifstream file1("../file1.txt");
    std::ifstream file2("../file2.txt");
    std::ofstream file_merge("./file_merge.txt");

    if (!file1.is_open() || !file2.is_open() || !file_merge.is_open())
        return EXIT_FAILURE;

    while (true) {
        std::string str1;
        std::string str2;

        std::getline(file1, str1);
        std::getline(file2, str2);
        file_merge << str1 + " " + str2 << std::endl;

        if (file1.eof() && file2.eof())
            break;
    }

    file1.close();
    file2.close();
    file_merge.close();
}