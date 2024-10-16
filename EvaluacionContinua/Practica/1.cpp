

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* eliminar_con_backtracking(TreeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->val) {
        node->left = eliminar_con_backtracking(node->left, key);
    } else if (key > node->val) {
        node->right = eliminar_con_backtracking(node->right, key);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            return node->right;
        }
        if (node->right == nullptr) {
            return node->left;
        }

        TreeNode* sucesor = findMin(node->right);
        node->val = sucesor->val;
        node->right = eliminar_con_backtracking(node->right, sucesor->val);
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    return eliminar_con_backtracking(root, key);
}
