///leetcode209 �ҵ��������������������
//�����Ѿ�ͨ��
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>


using namespace std;

     int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r=-1; //numw[l��r]��ʾ��ǰ���ǵ�������
        int res=nums.size()+1; //��ʾ��ǰ���������������ʼ��һ���϶�ȡ�����Ĵ�ֵ��
        int sum=0;//Ŀǰ�������
        int tmpres=0; //��ǰ���������
        while(l<nums.size())
        {
            if((r+1) < nums.size() && sum < s)
            {
                sum+=nums[++r];
                tmpres++;
            }else
            {
                sum-=nums[l++];
                tmpres--;
            }
            if(sum >= s){ //sum == s
                res = min(res,tmpres);
            }  
        }
        if( res == nums.size()+1) return 0;
        return res;
        
    }

int main()
{
    int s=7;
    vector<int> nums={2,3,1,2,4,3};
    minSubArrayLen(s,nums);
    
    return 0;
}