/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    tuple<TreeNode*, bool, bool> dfs_worker(TreeNode *now, TreeNode* p, TreeNode* q) {
        if (!now) {
            return {nullptr, false, false};
        }
        
        auto [res_left, seen_p_left, seen_q_left] = dfs_worker(now->left, p, q);
        if (res_left) {
            return {res_left, true, true};
        }
        
        auto [res_right, seen_p_right, seen_q_right] = dfs_worker(now->right, p, q);
        if (res_right) {
            return {res_right, true, true};
        }
        
        bool seen_p = seen_p_left || seen_p_right || now == p;
        bool seen_q = seen_q_left || seen_q_right || now == q;
        if (seen_p && seen_q) {
            return {now, true, true};
        } else {
            return {nullptr, seen_p, seen_q};
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [ans, seen_p, seen_q] = dfs_worker(root, p, q);
        return ans;
    }
};