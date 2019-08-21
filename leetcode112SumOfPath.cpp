/**
 * leetcode112 路径之和是否存在，相对简单，是需要判断true false
 * 思考关键 什么时候是递归终止条件。
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right)
        {
            if(root->val == sum)
                return true;
            else
                return false;
        }
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
        
    }
};