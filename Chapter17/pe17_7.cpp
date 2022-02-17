#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void ShowStr(const std::string &s) {
    std::cout << s << std::endl;
}

void GetStrs(std::ifstream &f, std::vector<std::string> &v) {

    while (f && !f.eof()) {
        size_t len;
        std::string s;
        f.read((char *) &len, sizeof(size_t));
        s.resize(len);
        f.read(const_cast<char *>(s.data()), len);
        v.push_back(s);
    }

}

class Store {
    std::ofstream &f_;
public:
    explicit Store(std::ofstream &f) : f_(f) {}

    Store & operator()(const std::string &s) {
        if (f_.is_open()) {
            auto len = s.length();
            f_.write((char *) &len, sizeof(size_t));
            f_.write(s.data(), len);
        }
        return *this;
    }
};

int main() {
    using std::string;
    using std::vector;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::ofstream;
    using std::ifstream;
    using std::ios_base;

    vector<string> vostr;
    string temp;

    // acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}