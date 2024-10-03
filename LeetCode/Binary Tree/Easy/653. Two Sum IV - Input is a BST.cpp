#include<unordered_set>
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen; // Usamos un unordered_set ya que permite acceso constante
        return find(root, k, seen);
    }

    bool find(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;

        // Verificamos si el complemento ya está en el set
        if (seen.count(k - node->val)) {
            return true;
        }

        seen.insert(node->val);

        return find(node->left, k, seen) || find(node->right, k, seen);
    }
};
