/*
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意:?给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    if(nums.size() ==0) return 0;
        int maxlen =0; //
        int res=0;
        vector<int> len(nums.size(),1); //以nums[i]为结尾的最长上升子序列的长度
        vector<int> cnt(nums.size(),1); //以nums【i】为结尾的最长递增子序列的个数
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