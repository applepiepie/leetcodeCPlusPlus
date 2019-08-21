//leetcode110 判断一棵树是否是平衡二叉树
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

int high(TreeNode* root)
    {//求二叉树的高度
        if(!root) return 0;
        return max(high(root->left),high(root->right))+1;      
        
    }
bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh=high(root->left);
        int rh=high(root->right);
        if(abs(lh-rh) <= 1)
            return isBalanced(root->left)&&isBalanced(root->right);
        else 
            return false;
        
    }
int main()
{
    TreeNode root(3);
    TreeNode a(9);
    TreeNode b(20);
    TreeNode c(15);
    TreeNode d(7);
    root.left=&a;
    root.right=&b;
    b.left=&c;
    b.right=&d;
    
    isBalanced(&root);
    return 0;
}