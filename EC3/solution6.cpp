//
// Created by LUIS FERNANDO on 12/09/2024.
//
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> A(m + 1, vector<int>(n + 1));
        vector<vector<int>> fit(m, vector<int>(n, 0));

        // Calcular la matriz acumulativa (prefix sum)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i + 1][j + 1] = A[i + 1][j] + A[i][j + 1] - A[i][j] + grid[i][j];
                if (i + 1 >= stampHeight && j + 1 >= stampWidth) {
                    int x = i - stampHeight + 1, y = j - stampWidth + 1;
                    if (A[i + 1][j + 1] - A[x][j + 1] - A[i + 1][y] + A[x][y] == 0)
                        fit[i][j] = 1;
                }
            }
        }

        // Crear matriz acumulativa de los sellos (B)
        vector<vector<int>> B(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + fit[i][j];

        // Verificar si todas las celdas vacías están cubiertas
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int x = min(i + stampHeight, m), y = min(j + stampWidth, n);
                    if (B[x][y] - B[i][y] - B[x][j] + B[i][j] == 0)
                        return false;
                }
            }
        }

        return true;
    }
};

