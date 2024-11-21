class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // Pila para almacenar índices
        int water = 0;

        for (int i = 0; i < height.size(); ++i) {
            // Mientras la pila no esté vacía y encontremos un valle (pared más alta al lado derecho)
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; // No hay pared izquierda para formar un valle

                int distance = i - st.top() - 1; // Distancia horizontal entre paredes
                int boundedHeight = min(height[i], height[st.top()]) - height[top]; // Altura del agua
                water += distance * boundedHeight; // Área de agua atrapada
            }
            st.push(i); // Agregar el índice actual
        }

        return water;
    }
};
