//110 ƽ�������
/*������Ƿ���������ƽ�⣬�򲻼���������ȣ�����ֱ�ӷ���-1����ô�Ż���ķ���Ϊ��
����ÿһ���ڵ㣬����ͨ�������ݹ���������������ȣ����������ƽ��ģ�
�򷵻���ʵ����ȣ�����ƽ�⣬ֱ�ӷ���-1���˷���ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(H)�� */
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
