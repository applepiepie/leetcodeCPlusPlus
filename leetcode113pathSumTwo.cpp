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
public:
    
    void Sum(TreeNode* root, int sum,vector<int>& out, vector<vector<int>>& res)
    {        
        if(root == NULL) return;
        out.push_back(root->val);
        if(root->val == sum && root->left ==NULL &&root->right == NULL)
        {
            res.push_back(out);
        }
        Sum(root->left,sum-root->val,out,res);
        Sum(root->right,sum-root->val,out,res);
        out.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        Sum(root,sum,out,res);
        return res;
        
    }
};