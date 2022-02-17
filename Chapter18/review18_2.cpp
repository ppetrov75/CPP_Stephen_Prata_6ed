#include <iostream>

using std::cout;
using std::endl;

double up(double x) { return 2.0 * x; }
void r1(const double &rx) { cout << rx << endl; }
void r2(double &rx) { cout << rx << endl; }
void r3(double &&rx) { cout << rx << endl; }

int main() {
    double w = 10.0;
    r1(w);
    r1(w + 1);
    r1(up(w));

    r2(w);
    r2(w+1);    // error: cannot bind non-const lvalue reference of type ‘double&’ to an rvalue of type ‘double’
    r2(up(w));  // error: cannot bind non-const lvalue reference of type ‘double&’ to an rvalue of type ‘double’

    r3(w);      // error: cannot bind rvalue reference of type ‘double&&’ to lvalue of type ‘double’
    r3(w+1);
    r3(up(w));
}