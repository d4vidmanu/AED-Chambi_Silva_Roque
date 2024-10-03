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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFrequency;
        int maxFrequency = 0;
        calculateSubtreeSums(root, sumFrequency, maxFrequency);

        // Encontrar todas las sumas con la frecuencia máxima
        vector<int> result;
        for (const auto& pair : sumFrequency) {
            if (pair.second == maxFrequency) {
                result.push_back(pair.first);
            }
        }

        return result;
    }

    int calculateSubtreeSums(TreeNode* node, unordered_map<int, int>& sumFrequency, int& maxFrequency) {
        if (!node) return 0;  // Si el nodo es nulo, la suma es 0

        int leftSum = calculateSubtreeSums(node->left, sumFrequency, maxFrequency);
        int rightSum = calculateSubtreeSums(node->right, sumFrequency, maxFrequency);

        // Suma del subárbol actual (nodo actual + suma del subárbol izquierdo + suma del subárbol derecho)
        int subtreeSum = node->val + leftSum + rightSum;

        sumFrequency[subtreeSum]++;

        maxFrequency = max(maxFrequency, sumFrequency[subtreeSum]);

        return subtreeSum;
    }
};
