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