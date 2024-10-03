#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }

    int checkBalance(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) return -1;  // Si el subárbol izquierdo no está balanceado, retornamos -1

        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) return -1;  // Si el subárbol derecho no está balanceado, retornamos -1

        int balanceFactor = leftHeight - rightHeight;

        if (abs(balanceFactor) > 1) return -1;

        // Si el nodo está balanceado, devolvemos la altura del nodo
        return max(leftHeight, rightHeight) + 1;
    }

};