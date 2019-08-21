///leetcode 226 ·­×ªÒ»¿Ã¶þ²æÊ÷
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

   TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* tmp=root->left;
        root->left=root->right;
        root->right=tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
   }
int main()
{
    
    
    return 0;
}