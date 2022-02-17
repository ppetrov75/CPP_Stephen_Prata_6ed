#include <string>
#include <memory>
#include <iostream>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;

        Info() = default;
        Info(std::string q, std::string z) : qcode(q), zcode(z) {}
    };

private:
    std::unique_ptr<Info> pi;
public:
    Cpmv() {
        std::cout << "Cpmv::Cpmv()\n";
        pi = std::make_unique<Info>();
    }

    Cpmv(std::string q, std::string z) {
        std::cout << "Cpmv::Cpmv(q, z)\n";
        pi = std::make_unique<Info>(q, z);
    }

    Cpmv(const Cpmv & cp) {
        std::cout << "Cpmv::Cpmv(&cp)\n";

        if(&cp == this)
            return;

        pi = std::make_unique<Info>();
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
    }

    Cpmv(Cpmv && mv) {
        std::cout << "Cpmv::Cpmv(&&mv)\n";

        if(&mv == this)
            return;

        std::swap(pi, mv.pi);
    }

    ~Cpmv() {
        std::cout << "Cpmv::~Cpmv()\n";
    }

    Cpmv & operator=(const Cpmv & cp) {
        std::cout << "Cpmv::operator=\n";

        if (&cp != this) {
            pi->qcode = cp.pi->qcode;
            pi->zcode = cp.pi->zcode;
        }

        return *this;
    }


    Cpmv & operator=(Cpmv && mv) {
        std::cout << "Cpmv::operator= move\n";

        if(&mv != this) {
            std::swap(pi, mv.pi);
        }

        return *this;
    }

    Cpmv operator+(const Cpmv & obj) const {
        std::cout << "Cpmv::operator+\n";
        Cpmv ret;
        ret.pi->qcode = pi->qcode + obj.pi->qcode;
        ret.pi->zcode = pi->zcode + obj.pi->zcode;

        return ret;
    }

    void display() const {
        std::cout << "q: " << pi->qcode << ", z: " << pi->zcode << "\n";
    }
};


int main() {
    Cpmv cp0;
    Cpmv cp1("qcode1", "zcode1");
    cp1.display();
    Cpmv cp2(Cpmv("qcode2", "zcode2"));
    cp2.display();

    Cpmv cp3(cp1);
    cp3.display();

    cp0 = cp1;
    cp0.display();

    std::cout<< "*** move ***\n";
    Cpmv cpmv1 = std::move(Cpmv("qmove", "zmove"));
    cpmv1.display();

    cpmv1 = std::move(cp1);
    cpmv1.display();

    cp0 = cp3 + cp2;
    cp0.display();

    /*
     Cpmv::Cpmv()
Cpmv::Cpmv(q, z)
q: qcode1, z: zcode1
Cpmv::Cpmv(q, z)
q: qcode2, z: zcode2
Cpmv::Cpmv(&cp)
q: qcode1, z: zcode1
Cpmv::operator=
q: qcode1, z: zcode1
*** move ***
Cpmv::Cpmv(q, z)
Cpmv::Cpmv(&&mv)
Cpmv::~Cpmv()
q: qmove, z: zmove
Cpmv::operator= move
q: qcode1, z: zcode1
Cpmv::operator+
Cpmv::Cpmv()
Cpmv::operator= move
Cpmv::~Cpmv()
q: qcode1qcode2, z: zcode1zcode2
Cpmv::~Cpmv()
Cpmv::~Cpmv()
Cpmv::~Cpmv()
Cpmv::~Cpmv()
Cpmv::~Cpmv()
     */
}