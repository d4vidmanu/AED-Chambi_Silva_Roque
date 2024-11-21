class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_set<int> guardsSet, wallsSet, guardedSet;

        // Helper to encode (x, y) into a single integer for the set
        auto encode = [&](int x, int y) { return x * n + y; };

        // Marcar guardias y muros en los sets
        for (auto& g : guards) guardsSet.insert(encode(g[0], g[1]));
        for (auto& w : walls) wallsSet.insert(encode(w[0], w[1]));

        // Direcciones: arriba, abajo, izquierda, derecha
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Expandir vigilancia desde los guardias
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int encoded = encode(nx, ny);
                    if (guardsSet.count(encoded) || wallsSet.count(encoded)) break;
                    guardedSet.insert(encoded);
                    nx += dx;
                    ny += dy;
                }
            }
        }

        // Contar celdas no vigiladas
        int totalCells = m * n;
        int guardedOrBlocked = guardedSet.size() + guardsSet.size() + wallsSet.size();
        return totalCells - guardedOrBlocked;
    }
};



class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 0)); // 0: libre, 1: muro, 2: guardia, 3: vigilada

        // Marcar guardias y muros en la cuadrícula
        for (auto& g : guards) grid[g[0]][g[1]] = 2; // Guardia
        for (auto& w : walls) grid[w[0]][w[1]] = 1; // Muro

        // Direcciones para expandir vigilancia: arriba, abajo, izquierda, derecha
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Expandir vigilancia desde los guardias
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] == 1 || grid[nx][ny] == 2) break; // Detener en muros o guardias
                    if (grid[nx][ny] == 0) grid[nx][ny] = 3; // Marcar como vigilada
                    nx += dx;
                    ny += dy;
                }
            }
        }

        // Contar celdas no vigiladas
        int unguarded = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) ++unguarded;
            }
        }

        return unguarded;
    }
};
