class Solution {
public:
    unordered_map<Node*, Node*> clones;  // Para guardar los nodos ya clonados

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Lo retornamos si ya fue clonado
        if (clones.find(node) != clones.end()) {
            return clones[node];
        }

        // Clonamos el actual
        Node* cloneNode = new Node(node->val);
        clones[node] = cloneNode;

        // Clonamos los vecinos usando DFS
        for (size_t i = 0; i < node->neighbors.size(); ++i) {
            Node* neighbor = node->neighbors[i];
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
