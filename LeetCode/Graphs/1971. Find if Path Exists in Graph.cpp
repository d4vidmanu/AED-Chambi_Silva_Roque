class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Crear lista de adyacencia para el grafo
        vector<vector<int>> adjList(n);
        for (size_t i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Verificación si el origen y el destino son el mismo
        if (source == destination) return true;

        // BFS
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Explorar los vecinos del nodo actual
            for (size_t i = 0; i < adjList[node].size(); ++i) {
                int neighbor = adjList[node][i];

                // Si llegamos al destino, retornamos true
                if (neighbor == destination) {
                    return true;
                }

                // Si el vecino no ha sido visitado, lo agregamos a la cola
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Si no encontramos el destino, retornamos false
        return false;
    }
};
