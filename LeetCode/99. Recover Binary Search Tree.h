class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr, *current = root;

        while (current) {
            if (!current->left) {
                if (prev && prev->val > current->val) {
                    if (!first) first = prev;
                    second = current;
                }
                prev = current;
                current = current->right;
            } else {
                TreeNode* pred = current->left;
                while (pred->right && pred->right != current)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = current;
                    current = current->left;
                } else {
                    pred->right = nullptr;
                    if (prev && prev->val > current->val) {
                        if (!first) first = prev;
                        second = current;
                    }
                    prev = current;
                    current = current->right;
                }
            }
        }

        if (first && second) swap(first->val, second->val);
    }
};
