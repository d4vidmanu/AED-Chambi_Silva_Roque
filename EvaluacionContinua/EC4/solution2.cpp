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