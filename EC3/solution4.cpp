class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        // Recorremos los elementos en el vector 'pushed'
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);  // Empujamos el elemento actual a la pila

            // Mientras la pila no esté vacía y el elemento en la cima de la pila
            // sea igual al elemento en 'popped', sacamos el elemento de la pila
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;  // Avanzamos en la secuencia 'popped'
            }
        }

        // Si hemos sacado todos los elementos en el orden correcto, la pila estará vacía
        return st.empty();
    }
};
