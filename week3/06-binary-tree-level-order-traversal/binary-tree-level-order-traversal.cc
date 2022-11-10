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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> curr;
        queue<TreeNode*> next;
        if (root) {
            curr.push(root);
        }

        vector<vector<int>> ans;
        while (curr.size() + next.size() > 0) {
            vector<int> curr_ans;
            while (curr.size() > 0) {
                TreeNode *now = curr.front();
                curr.pop();
                curr_ans.push_back(now->val);
                if (now->left) {
                    next.push(now->left);
                }
                if (now->right) {
                    next.push(now->right);
                }
            }
            ans.push_back(curr_ans);
            swap(curr, next);
        }
        return ans;
    }
};