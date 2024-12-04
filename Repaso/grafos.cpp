#include <iostream>
#include <vector>
using namespace std;

// Clase Union-Find (Estructura de Conjuntos Disjuntos)
class DisjointSet {
private:
    vector<int> root; // Representa el nodo raíz de cada conjunto
    vector<int> depth; // Representa la profundidad de cada conjunto

public:
    // Constructor
    DisjointSet(int numNodes) {
        root.resize(numNodes + 1);
        depth.resize(numNodes + 1, 0);
        for (int i = 0; i <= numNodes; ++i) {
            root[i] = i; // Inicializamos cada nodo como su propia raíz
        }
    }

    // Encuentra la raíz de un nodo con compresión de caminos
    int findRoot(int node) {
        if (node != root[node]) {
            root[node] = findRoot(root[node]); // Compresión para optimizar
        }
        return root[node];
    }

    // Une dos nodos en un mismo conjunto y retorna si fue exitoso
    bool connect(int nodeA, int nodeB) {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);

        if (rootA == rootB) {
            return false; // Ya están conectados, indica ciclo
        }

        // Unión por profundidad para optimizar la estructura
        if (depth[rootA] > depth[rootB]) {
            root[rootB] = rootA;
        } else if (depth[rootA] < depth[rootB]) {
            root[rootA] = rootB;
        } else {
            root[rootB] = rootA;
            depth[rootA]++;
        }

        return true;
    }
};

// Función para encontrar la arista redundante
vector<int> detectCycleEdge(vector<vector<int>>& connections) {
    int numEdges = connections.size();
    DisjointSet ds(numEdges);

    for (const auto& link : connections) {
        if (!ds.connect(link[0], link[1])) {
            return link; // Retorna la arista que genera el ciclo
        }
    }

    return {};
}

