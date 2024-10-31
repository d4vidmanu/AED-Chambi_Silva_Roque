class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;  // marcar ciudad como visitada
        for (size_t i = 0; i < isConnected.size(); ++i) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);  // realizar DFS en la ciudad conectada
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvinces = 0;
        vector<bool> visited(isConnected.size(), false);

        for (size_t i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);  // realizar DFS para descubrir todas las ciudades conectadas
                numProvinces++;  // contar una nueva provincia
            }
        }

        return numProvinces;
    }
};
