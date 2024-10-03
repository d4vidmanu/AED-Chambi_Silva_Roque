#include <vector>
#include <unordered_map>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeCount;
        vector<TreeNode*> result;
        serializeSubtree(root, subtreeCount, result);
        return result;
    }


    string serializeSubtree(TreeNode* node, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& result) {
        if (!node) return "#";  // Un nodo nulo se representa con un "#"

        // Serializar el subárbol: (valor del nodo, serialización del subárbol izquierdo, serialización del subárbol derecho)
        string serialized = to_string(node->val) + "," + serializeSubtree(node->left, subtreeCount, result) + "," + serializeSubtree(node->right, subtreeCount, result);

        subtreeCount[serialized]++;

        if (subtreeCount[serialized] == 2) {
            result.push_back(node);
        }

        return serialized;
    }
};
