#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stack1, stack2;

    MyQueue() {

    }

    // Pusha un elemento al final de la cola.
    void push(int x) {
        stack1.push(x);
    }

    // Remueve el elemento al frente de la cola y lo retorna.
    int pop() {
        if (stack2.empty()) {
            // Pasamos todos los elementos de stack1 a stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // Al hacer esto, el tope de stack2 es el frente de la cola
        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }

    // Retorna el elemento al frente de la cola.
    int peek() {
        if (stack2.empty()) {
            // Pasamos todos los elementos de stack1 a stack2 si stack2 está vacío
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    // Retorna si la cola está vacía o no.
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Tu objeto MyQueue será instanciado y usado de esta manera:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
