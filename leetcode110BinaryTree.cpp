//110 平衡二叉树
/*如果我们发现子树不平衡，则不计算具体的深度，而是直接返回-1。那么优化后的方法为：
对于每一个节点，我们通过方法递归获得左右子树的深度，如果子树是平衡的，
则返回真实的深度，若不平衡，直接返回-1，此方法时间复杂度O(N)，空间复杂度O(H)， */
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
    int Depth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left=Depth(root->left);
        if(left == -1) return -1;
        int right=Depth(root->right);
        if(right == -1) return -1;
        int diff=abs(left-right);
        if(diff > 1)
            return -1;
        else
            return max(left,right)+1;
    }
   
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(Depth(root) == -1) return false;
        else
            return true;
    }
};
