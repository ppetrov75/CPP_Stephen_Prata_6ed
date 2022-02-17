#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include <stdexcept>
#include <sstream>

class bad_hmean : public std::logic_error
{
private:
protected:
    double v1;
    double v2;
    mutable std::string m_msg;
public:
    explicit bad_hmean(double a = 0, double b = 0, const std::string& s = "") : std::logic_error(s), v1(a), v2(b) {}
    const char* what() const noexcept override;
};

const char* bad_hmean::what() const noexcept
{
    std::stringstream s;

    s << "\nlogic_error::what(): " << std::logic_error::what() << std::endl;
    s << "hmean(" << v1 << ", " << v2 <<"): "
              << "invalid arguments: a = -b\n";
    m_msg = std::move(s.str());

    return m_msg.c_str();
}

class bad_gmean : public bad_hmean //std::logic_error
{
public:
    explicit bad_gmean(double a = 0, double b = 0, const std::string& s = "") : bad_hmean(a, b, s) {}
    const char* what() const noexcept override;
};

const char*  bad_gmean::what() const noexcept
{
    std::stringstream s;
    s << "\nlogic_error::what(): " << std::logic_error::what() << std::endl;
    s << "gmean(" << v1 << ", " << v2 <<"): "
         << " arguments should be >= 0\n";
    m_msg = std::move(s.str());

    return m_msg.c_str();
}


// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (std::logic_error & e)
        {
            cout << e.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b,"hmean() ");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b, "gmean() ");
    return std::sqrt(a * b);
}
