class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Revisamos las dos primeras aristas para identificar el nodo común
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];

        // El nodo que aparece en ambas aristas es el centro
        if (a == c || a == d) return a;
        return b;
    }
};
