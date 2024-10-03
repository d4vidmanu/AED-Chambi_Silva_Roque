#include <algorithm>
#include <climits>
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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;

        inorder(root, prev, minDiff);

        return minDiff;
    }

    void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) return;

        inorder(node->left, prev, minDiff);

        // Verificamos si el nodo anterior no es nulo
        if (prev) {
            int diff = abs(node->val - prev->val);
            minDiff = min(minDiff, diff);
        }

        prev = node;

        inorder(node->right, prev, minDiff);
    }

};
