class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Lista de adyacencia de caminos entre jardines
        vector<vector<int>> adjList(n);
        for (size_t i = 0; i < paths.size(); ++i) {
            int u = paths[i][0] - 1;  // Convertir a índice 0
            int v = paths[i][1] - 1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Vector para almacenar el tipo de flor de cada jardín
        vector<int> result(n, 0);  // 0 indica sin asignar

        // Asignar flores
        for (int i = 0; i < n; ++i) {
            // Verificar tipos de flores usados por los vecinos
            vector<bool> used(5, false);  // Usamos índices 1 a 4
            for (size_t j = 0; j < adjList[i].size(); ++j) {
                int neighbor = adjList[i][j];
                if (result[neighbor] != 0) {  // Si el vecino tiene una flor
                    used[result[neighbor]] = true;  // Marcar tipo de flor como usado
                }
            }

            // Asignar el primer tipo de flor disponible
            for (int flower = 1; flower <= 4; ++flower) {
                if (!used[flower]) {
                    result[i] = flower;
                    break;
                }
            }
        }

        return result;
    }
};
