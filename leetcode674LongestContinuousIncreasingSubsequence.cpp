/*
����һ��δ��������������飬�ҵ���������ĵĵ������С�

ʾ�� 1:

����: [1,3,5,4,7]
���: 3
����: ��������������� [1,3,5], ����Ϊ3��
���� [1,3,5,7] Ҳ�������������, �������������ģ���Ϊ5��7��ԭ�����ﱻ4������ 
ʾ�� 2:

����: [2,2,2,2,2]
���: 1
����: ��������������� [2], ����Ϊ1��
ע�⣺���鳤�Ȳ��ᳬ��10000��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res=0;
        if(nums.size() == 0) return res;
        int cur=nums[0];
        res++;
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1]) cnt++;
            else{
                cur = nums[i];
                cnt=1;
            }
            res=max(res,cnt);
        }
        return res;
      
    }
};