/*
����һ��δ������������飬�ҵ�����������еĸ�����

ʾ�� 1:

����: [1,3,5,4,7]
���: 2
����: ����������������У��ֱ��� [1, 3, 4, 7] ��[1, 3, 5, 7]��
ʾ�� 2:

����: [2,2,2,2,2]
���: 5
����: ����������еĳ�����1�����Ҵ���5�������еĳ���Ϊ1��������5��
ע��:?���������鳤�Ȳ����� 2000 ���ҽ��һ����32λ�з���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    if(nums.size() ==0) return 0;
        int maxlen =0; //
        int res=0;
        vector<int> len(nums.size(),1); //��nums[i]Ϊ��β������������еĳ���
        vector<int> cnt(nums.size(),1); //��nums��i��Ϊ��β������������еĸ���
        for(int i=0; i<nums.size();i++)
        {
            for(int j=0;j < i;++j)
            {
                if( nums[i] > nums[j])
                {
                    if(len[i] == len[j]+1)
                    {
                        cnt[i]+=cnt[j];
                        
                    }
                    else if(len[i] < len[j]+1){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                        
                    }
                }
            }
            if(maxlen ==len[i]) res+=cnt[i];
            else if(maxlen <len[i]){
                maxlen=len[i];
                res=cnt[i];
            }
            
        }
        return res;
    }
};