class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Creamos una lista de adyacencia y grados para cada curso
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        // grafo
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adjList[u].push_back(v);  // agregamos conexión u -> v
            inDegree[v]++;  // incrementa el grado de entrada de v
        }

        // Cola de cursos sin prerrequisitos
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        //  BFS
        int coursesTaken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            // Actualizar grados de entrada de los vecinos
            for (size_t i = 0; i < adjList[course].size(); ++i) {
                int neighbor = adjList[course][i];
                inDegree[neighbor]--;

                // Si el grado de entrada es 0, se puede tomar
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Verificar si se tomaron todos los cursos
        return coursesTaken == numCourses;
    }
};
