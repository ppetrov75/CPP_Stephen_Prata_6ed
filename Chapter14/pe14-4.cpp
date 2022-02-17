#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <memory>
#include "person.h"

using std::cin;
using std::cout;
using std::endl;
using std::strchr;


int main() {

    std::vector<Person *> persons;

    int ct;
    while(true)
    {
        char choice;
        cout << "Enter the Persons category:\n"
             << "p: poker  g: gungs  "
             << "b: baddude  q: quit\n";
        cin >> choice;
        while (strchr("pgbq", choice) == NULL)
        {
            cout << "Please enter a p, g, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'g':   persons.push_back(new Gunslinger()); break;
            case 'p':   persons.push_back(new PokerPlayer()); break;
            case 'b':   persons.push_back(new BadDude()); break;
        }
        cin.get();
    }

    for(auto &p : persons) {
        p->show();
        cout << "***" << endl;
    }

    std::for_each(persons.begin(), persons.end(), std::default_delete<Person>());

    return 0;
}