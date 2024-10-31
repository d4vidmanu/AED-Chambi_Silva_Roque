class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;  // marcar habitación como visitada
        for (size_t i = 0; i < rooms[room].size(); ++i) {
            int nextRoom = rooms[room][i];
            if (!visited[nextRoom]) {
                dfs(nextRoom, rooms, visited);  // visitar habitación
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);  // inicializar todas las habitaciones como no visitadas
        dfs(0, rooms, visited);  // empezar desde la habitación 0

        // Verificar si todas las habitaciones fueron visitadas
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
