#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false; // No hay suficientes elementos para formar el patrón

        stack<int> st;  // Pila para almacenar candidatos a nums[k]
        int second = INT_MIN; // El mejor candidato actual para nums[k]

        // Recorremos el array de derecha a izquierda
        for (int i = n - 1; i >= 0; --i) {
            // Si encontramos un nums[i] que es menor que `second`, hemos encontrado el patrón 132
            if (nums[i] < second) {
                return true;
            }

            // Actualizamos la pila y el valor `second`
            // Desapilamos todos los valores mayores que nums[i]
            while (!st.empty() && nums[i] > st.top()) {
                second = st.top(); // Actualizamos el mejor candidato para nums[k]
                st.pop();
            }

            // Empujamos el valor nums[i] a la pila
            st.push(nums[i]);
        }

        return false; // Si no encontramos ningún patrón 132
    }
};
