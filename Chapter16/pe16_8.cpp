#include <iostream>
#include <set>
#include <algorithm>

int main() {

    std::set<std::string> mat_friends;
    std::set<std::string> pat_friends;

    std::cout << "Mat friends(entre q to quit):\n";
    std::string name;
    while(std::cin >> name && name != "q") {
        mat_friends.insert(name);
    }

    std::cout << "Pat friends(entre q to quit):\n";
    while(std::cin >> name && name != "q") {
        pat_friends.insert(name);
    }

    std::set<std::string> all_friends;
    std::merge(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(),
               std::inserter(all_friends, all_friends.begin()));

    std::cout << "Mat friends: ";
    for(auto &f : mat_friends)
        std::cout << f << " ";
    std::cout << std::endl;

    std::cout << "Pat friends: ";
    for(auto &f : pat_friends)
        std::cout << f << " ";
    std::cout << std::endl;

    std::cout << "Friends: ";
    for(auto &f : all_friends)
        std::cout << f << " ";
    std::cout << std::endl;
}