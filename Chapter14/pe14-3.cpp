#include <iostream>
#include <cstring>
#include "queuetp.h"
#include "workermi.h"

using std::cin;
using std::cout;
using std::endl;
using std::strchr;

int main() {

    QueueTp<Worker *> que;

    int ct;
    for (ct = 0; ct < que.get_size(); ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter  s: singer  "
             << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'w':   que.enqueue(new Waiter("Waiter", 123));
                break;
            case 's':   que.enqueue(new Singer("Singer", 234, 1));
                break;
            case 't':   que.enqueue(new SingingWaiter("SingWaiter", 345, 1 ,2));
                break;
        }
        cin.get();
    }

    while (!que.isempty()) {
        Worker * w;
        que.dequeue(w);
        w->Show();
        delete w;
    }

    return 0;
}