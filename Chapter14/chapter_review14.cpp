#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Frabjous {
private:
    char fab[20]{};
public:
    Frabjous(const char *s = "C++")  {
        std::strncpy(fab, s, 19);
    }

    virtual void tell() { cout << fab; }
};

class Gloam : private Frabjous {
private:
    int glip;
//    Frabjous fb;
public:
    explicit Gloam(int g = 0, const char *s = "C++") : glip(g), Frabjous(s) {}

    Gloam(int g, const Frabjous &f) : glip(g), Frabjous(f) {}

    void tell() {
        cout << glip << endl;
        Frabjous::tell();
    }
};

int main() {

    Gloam g(5, "xyz");
    g.tell();


    return 0;
}