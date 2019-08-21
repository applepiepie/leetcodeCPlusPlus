///leetcode209 找到符合条件的最短子数组
//测试已经通过
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>


using namespace std;

     int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r=-1; //numw[l…r]表示当前考虑的子数组
        int res=nums.size()+1; //表示当前最大的数组个数，初始化一个肯定取不到的大值。
        int sum=0;//目前的数组和
        int tmpres=0; //当前的数组个数
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