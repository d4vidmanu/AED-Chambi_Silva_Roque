class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Si solo hay una persona es  el juez
        if (n == 1) return 1;

        // Arrays para contar entradas y salidas de confianza
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        // Procesar la lista de confianza
        for (size_t i = 0; i < trust.size(); ++i) {
            int a = trust[i][0];
            int b = trust[i][1];
            outDegree[a]++;    // a confía en alguien
            inDegree[b]++;     // alguien confía en b
        }

        // Identificar si hay alguien que cumpla las condiciones de juez
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }

        return -1; // Si no hay juez
    }
};
