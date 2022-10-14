/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    tuple<int, bool> dfs_worker(TreeNode* now) {
        if (!now) {
            return {0, true};
        }
        auto [height_left, balanced_left] = dfs_worker(now->left);
        auto [height_right, balanced_right] = dfs_worker(now->right);
        int height = max(height_left, height_right) + 1;
        bool balanced = balanced_left && balanced_right && abs(height_left - height_right) <= 1;
        return {height, balanced};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto [height, balanced] = dfs_worker(root);
        return balanced;
    }
};