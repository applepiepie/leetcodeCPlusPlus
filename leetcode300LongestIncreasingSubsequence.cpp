/*����һ��������������飬�ҵ���������������еĳ��ȡ�

ʾ��:

����: [10,9,2,5,3,7,101,18]
���: 4 
����: ���������������?[2,3,7,101]�����ĳ����� 4��
˵��:

���ܻ��ж�������������е���ϣ���ֻ��Ҫ�����Ӧ�ĳ��ȼ��ɡ�
���㷨��ʱ�临�Ӷ�Ӧ��Ϊ?O(n2) ��
����: ���ܽ��㷨��ʱ�临�ӶȽ��͵�?O(n log n) ��?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-increasing-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() ==0) return 0;
        int res =0;
        vector<int> len(nums.size(),1);
        for(int i=0; i<nums.size();i++)
        {
            for(int j=i-1;j >=0;j--)
            {
                if( nums[i] > nums[j])
                {
                    int cur = len[j]+1;
                    len[i] =max(cur,len[i]);
                }
            }
            res =max(len[i],res);
        }
        return res;
    }
};