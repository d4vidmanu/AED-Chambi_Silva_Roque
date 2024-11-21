class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr, *current = root;

        // Morris Traversal para recorrido in-order sin espacio adicional
        while (current) {
            if (!current->left) {
                // Verificar desorden
                if (prev && prev->val > current->val) {
                    if (!first) first = prev;
                    second = current;
                }
                prev = current;
                current = current->right;
            } else {
                // Encontrar el predecesor en in-order
                TreeNode* pred = current->left;
                while (pred->right && pred->right != current)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = current; // Crear enlace temporal
                    current = current->left;
                } else {
                    pred->right = nullptr; // Romper enlace temporal
                    // Verificar desorden
                    if (prev && prev->val > current->val) {
                        if (!first) first = prev;
                        second = current;
                    }
                    prev = current;
                    current = current->right;
                }
            }
        }

        // Intercambiar valores de los nodos desordenados
        if (first && second) swap(first->val, second->val);
    }
};
