#include <iostream>
#include <fstream>
#include <set>

int main() {
    std::ifstream mat_file("../mat.txt");
    std::ifstream pat_file("../pat.txt");
    std::ofstream matnpat_file("./matnpat.txt");

    if (!mat_file.is_open() || !pat_file.is_open() || !matnpat_file.is_open()) {
        return EXIT_FAILURE;
    }

    std::string str;
    std::set<std::string> friends;
    while (std::getline(mat_file, str)) {
        friends.insert(str);
    }

    while (std::getline(pat_file, str)) {
        friends.insert(str);
    }

    for (auto &s: friends) {
        matnpat_file << s << std::endl;
    }

    mat_file.close();
    pat_file.close();
    matnpat_file.close();

    return 0;
}