/**
 * leetcode404 一棵二叉树上的左叶子之和
 * 利用递归的方式，主要是想好如何判断是左叶子点，
 * 其实是判断叶子点的上一个节点A的左节点B存在，
 * 并且这个左节点B没有子节点。然后在遍历A的右节点。
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
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left && !root->left->left && !root->left->right)
        {
            return root->left->val+sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        
    }
};
