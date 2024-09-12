

#ifndef INC_225_IMPLEMENT_STACK_USING_QUEUES_H
#define INC_225_IMPLEMENT_STACK_USING_QUEUES_H

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;  // Usaremos dos colas
public:
    MyStack() {
    }

    void push(int x) {
        q2.push(x);  // Insertar en la cola auxiliar (q2)
        while (!q1.empty()) {  // Transferir todos los elementos de q1 a q2
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);  // Intercambiar las colas, de modo que q1 tenga el orden correcto
    }

    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/*#include "LeetCode/225. Implement Stack using Queues.h"

int main() {
    MyStack* obj = new MyStack();

    // Case 1: ["MyStack","push","push","top","pop","empty"]
    obj->push(1);
    obj->push(2);

    cout << "Top element: " << obj->top() << endl;  // Should return 2
    cout << "Popped element: " << obj->pop() << endl;  // Should return 2
    cout << "Is empty: " << obj->empty() << endl;  // Should return false

    delete obj;
    return 0;
}*/

#endif //INC_225_IMPLEMENT_STACK_USING_QUEUES_H
