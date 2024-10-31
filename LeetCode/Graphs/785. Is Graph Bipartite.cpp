class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // Inicializar todos los nodos sin color (-1)

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {  // Si el nodo no ha sido coloreado
                queue<int> q;
                q.push(start);
                color[start] = 0;  // Asignar el primer color

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Revisar todos los vecinos del nodo
                    for (size_t i = 0; i < graph[node].size(); ++i) {
                        int neighbor = graph[node][i];

                        if (color[neighbor] == -1) {  // Si el vecino no está coloreado
                            color[neighbor] = 1 - color[node];  // Asignar el color opuesto
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            // Si el vecino tiene el mismo color, no es bipartito
                            return false;
                        }
                    }
                }
            }
        }

        return true;  // Si no encontramos conflictos, es bipartito
    }
};
