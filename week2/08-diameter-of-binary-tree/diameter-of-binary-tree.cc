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
    tuple<int, int> dfs_worker(TreeNode* now) {
        if (!now) {
            return {0, 0};
        }
        auto [diameter_left, depth_left] = dfs_worker(now->left);
        auto [diameter_right, depth_right] = dfs_worker(now->right);
        int depth = max(depth_left, depth_right) + 1;
        int diameter = max(diameter_left, diameter_right);
        diameter = max(diameter, depth_left + depth_right);
        return {diameter, depth};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto [diameter, depth] = dfs_worker(root);
        return diameter;
    }
};