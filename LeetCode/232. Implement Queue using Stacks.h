//
// Created by david on 12/09/2024.
//

#ifndef INC_232_IMPLEMENT_QUEUE_USING_STACKS_H
#define INC_232_IMPLEMENT_QUEUE_USING_STACKS_H

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;  // Usamos dos pilas
public:
    MyQueue() {
    }

    void push(int x) {
        s1.push(x);  // Insertar siempre en la pila s1
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {  // Transferir elementos de s1 a s2 para mantener el orden de cola
                s2.push(s1.top());
                s1.pop();
            }
        }
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/*#include "LeetCode/232. Implement Queue using Stacks.h"

int main() {
    MyQueue* obj = new MyQueue();

    // Case 1: ["MyQueue","push","push","peek","pop","empty"]
    obj->push(1);
    obj->push(2);

    cout << "Front element: " << obj->peek() << endl;  // Should return 1
    cout << "Popped element: " << obj->pop() << endl;  // Should return 1
    cout << "Is empty: " << obj->empty() << endl;  // Should return false

    delete obj;
    return 0;
}*/

#endif //INC_232_IMPLEMENT_QUEUE_USING_STACKS_H
