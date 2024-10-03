#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        if (!root) return modes;

        int maxCount = 0, currentCount = 0;
        TreeNode* prev = nullptr;
        
        inorder(root, prev, currentCount, maxCount, modes);
        
        return modes;
    }

    void inorder(TreeNode* node, TreeNode*& prev, int& currentCount, int& maxCount, vector<int>& modes) {
        if (!node) return;

        inorder(node->left, prev, currentCount, maxCount, modes);

        if (prev && prev->val == node->val) { // Como inicia en nullptr debemos hacer la validación
            currentCount++;  // Incrementamos el contador si es el mismo valor que el nodo anterior
        } else {
            currentCount = 1;  // Reiniciamos el contador si encontramos un nuevo valor
        }

        // Actualizamos la moda si encontramos un valor con mayor frecuencia
        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes = {node->val};  // Limpiamos la lista de modas y añadimos el nuevo valor
        } else if (currentCount == maxCount) {
            modes.push_back(node->val);  // Si tiene la misma frecuencia, lo añadimos a las modas
        }

        // Actualizamos el nodo anterior
        prev = node;

        inorder(node->right, prev, currentCount, maxCount, modes);
    }
    
};