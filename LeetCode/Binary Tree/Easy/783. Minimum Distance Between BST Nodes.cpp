#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, minDiff);
        return minDiff;
    }

    void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) return;

        inorder(node->left, prev, minDiff);

        if (prev) {
            minDiff = min(minDiff, node->val - prev->val);
        }

        prev = node;

        inorder(node->right, prev, minDiff);
    }

};
