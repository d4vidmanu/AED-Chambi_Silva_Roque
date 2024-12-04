#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]]; // Compresión de caminos
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (size[rootX] < size[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX, size[rootX] += size[rootY];
        return true;
    }

    int countComponents() {
        int components = 0;
        for (int i = 0; i < parent.size(); ++i)
            if (i == parent[i]) components++;
        return components;
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
        return -1; // No hay suficientes cables para conectar todas las computadoras
    }

    UnionFind uf(n);
    int extraCables = 0;

    // Procesar todas las conexiones
    for (const auto& conn : connections) {
        if (!uf.unite(conn[0], conn[1])) {
            extraCables++; // Contar cables extra
        }
    }

    // Contar los componentes conectados
    int components = uf.countComponents();
    int requiredCables = components - 1;

    // Verificar si los cables extra son suficientes
    if (extraCables >= requiredCables) {
        return requiredCables;
    } else {
        return -1;
    }
}


// Ejemplo de uso
int main() {
    // Ejemplo 1
    int n1 = 4;
    vector<vector<int>> connections1 = {{0, 1}, {0, 2}, {1, 2}};
    cout << "Ejemplo 1 Output: " << makeConnected(n1, connections1) << endl;

    // Ejemplo 2
    int n2 = 6;
    vector<vector<int>> connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << "Ejemplo 2 Output: " << makeConnected(n2, connections2) << endl;

    return 0;
}
