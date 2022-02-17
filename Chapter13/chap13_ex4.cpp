#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::ostream;

class Port {
private:
    char *m_brand = nullptr;
    enum {
        ST_LEN = 20
    };
    char m_style[ST_LEN]{}; // i.e., tawny, ruby, vintage
    int m_bottles = 0;
public:
    explicit Port(const char *br = "none", const char *st = "none", int b = 0) : m_bottles(b) {
        m_brand = new char[std::strlen(br) + 1];
        std::strcpy(m_brand, br);
        std::strncpy(m_style, st, ST_LEN - 1);
        m_style[ST_LEN - 1] = 0;
    }

    Port(const Port &p) {
        m_brand = new char[std::strlen(p.m_brand) + 1];
        std::strcpy(m_brand, p.m_brand);
        std::strncpy(m_style, p.m_style, ST_LEN - 1);
        m_style[ST_LEN - 1] = 0;
        m_bottles = p.m_bottles;
    }

    virtual ~Port() { delete[] m_brand; }

    Port &operator=(const Port &p) {
        if (this == &p)
            return *this;
        delete[] m_brand;
        m_brand = new char[std::strlen(p.m_brand) + 1];
        std::strcpy(m_brand, p.m_brand);
        std::strncpy(m_style, p.m_style, ST_LEN - 1);
        m_style[ST_LEN - 1] = 0;
        m_bottles = p.m_bottles;

        return *this;
    }

    Port &operator+=(int b) {
        m_bottles += b;
        return *this;
    }

    // subtracts b from m_bottles, if available
    Port &operator-=(int b) {
        m_bottles -= b;
        if (m_bottles < 0)
            m_bottles = 0;

        return *this;
    }

    int BottleCount() const {
        return m_bottles;
    }

    virtual void Show() const {
        cout << "Brand: " << m_brand << endl;
        cout << "Kind: " << m_style << endl;
        cout << "Bottles: " << m_bottles << endl;
    }

    friend ostream &operator<<(ostream &os, const Port &p) {
        os << p.m_brand << ", " << p.m_style << ", " << p.m_bottles << " ";
        return os;
    }
};


class VintagePort : public Port // m_style necessarily = "vintage"
{
private:
    char *m_nickname = nullptr; // i.e., "The Noble" or "Old Velvet", etc.
    int m_year = 0; // vintage m_year
public:
    VintagePort() = default;

    VintagePort(const char *brand, int bottles, const char *nn, int year) : Port(brand, "vintage", bottles),
                                                                            m_year(year) {
        m_nickname = new char[std::strlen(nn) + 1];
        std::strcpy(m_nickname, nn);
    }

    VintagePort(const VintagePort &vp) : Port(vp), m_year(vp.m_year) {
        m_nickname = new char[std::strlen(vp.m_nickname) + 1];
        std::strcpy(m_nickname, vp.m_nickname);
    }

    ~VintagePort() override { delete[] m_nickname; }

    VintagePort &operator=(const VintagePort &vp) {
        if (this == &vp) {
            return *this;
        }
        Port::operator=(vp);
        delete[] m_nickname;
        m_nickname = new char[std::strlen(vp.m_nickname) + 1];
        std::strcpy(m_nickname, vp.m_nickname);
        m_year = vp.m_year;
        return *this;

    }

    void Show() const override {
        Port::Show();
        cout << "NickName: " << ((m_nickname == nullptr ) ? "none" : m_nickname) << endl;
        cout << "Year: " << m_year << endl;
    }

    friend ostream &operator<<(ostream &os, const VintagePort &vp) {
        os << static_cast<const Port &>(vp);
        os << ", " << vp.m_nickname ;
        os << ", " << vp.m_year << " ";
        return os;
    }
};


int main() {

    Port p0;
    Port p1("Gallo", "tawny", 20);
    Port p2 = p1;
    p1 += 10;
    p2 -= 5;

    p0.Show();
    p1.Show();
    p2.Show();

    cout << p1 << p2 << endl;

    cout << "*****\n";
    VintagePort vp;

    VintagePort vp1("Brand", 100, "Old Velvet", 2015);
    vp1.Show();

    vp = vp1;
    vp -= 50;
    vp.Show();
    VintagePort vp2 = vp;
    cout << vp;

}