// functor.cpp -- using a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

/*
template<class T>  // functor class defines operator()()
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void outint(int n) {std::cout << n << " ";}
*/

int main()
{
//    using std::list;
//    using std::cout;
//    using std::endl;
//    using std::for_each;
//    using std::remove_if;

//    TooBig<int> f100(100); // limit = 100
//    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
//    std::list<int> yadayada(vals, vals + 10); // range constructor
//    std::list<int> etcetera(vals, vals + 10);

    // C++0x can use the following instead
    std::list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    std::list<int> etcetera(yadayada);//{50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    auto outint = [](int n){std::cout << n << " "; };

    std::cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    std::cout << std::endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    std::cout << std::endl;
    yadayada.remove_if([](int x){return (x > 100);});               // use a named function object
    etcetera.remove_if([](int x){return (x > 200);});   // construct a function object
    std::cout <<"Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    std::cout << std::endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    std::cout << std::endl;
    // std::cin.get();
    return 0;
}
