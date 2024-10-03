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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {

            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            }

            // El nodo tiene dos hijos
            // Encontramos el sucesor in-order (el menor en el subárbol derecho)
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;  // Reemplazamos el valor del nodo con el sucesor
            // Eliminamos el sucesor del subárbol derecho
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
