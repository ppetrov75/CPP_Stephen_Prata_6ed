#include <utility>
#include <string>
#include <iostream>

class A
{
public:
    int m_i{5};
    std::string m_s{"empty"};

    A() = default;
    A(std::string s_, int i_ = 55555) : m_s(s_), m_i(i_) {}

    A& operator=(A a) {
        using namespace std;
        swap(*this, a);
        return *this;
    }

    friend
    void swap(A& a, A& other) {
        using std::swap;
        swap(a.m_i, other.m_i);
        swap(a.m_s, other.m_s);
    }
};


int main() {
    A a;
    A tmp;

    tmp = a;
    //a = tmp;

    std::cout << std::endl;
    endl(std::cout);

}
