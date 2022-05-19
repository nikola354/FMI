#include <iostream>

#include "Queue.h"

using namespace std;

int main() {
    Queue<int> queue;

    try {
        queue.push(1);
        queue.push(2);
        queue.push(3);


        cout << queue.pull() << endl;
        cout << queue.pull() << endl;
        cout << queue.pull() << endl;
        cout << queue.pull() << endl;
    } catch (const char *e) {
        cout << e << endl;
    }


    return 0;
}
