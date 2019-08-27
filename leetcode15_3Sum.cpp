/*leetcode15 三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        sort(nums.begin(),nums.end());
        int k=nums.size()-2;
        for(int i=0;i<k && nums[i] <= 0 ;i++)
        {
            if(i !=0 && nums[i] == nums[i-1]) continue; //相同数字跳过
            int f=nums[i];
            int sum=0-f;
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                if(nums[r]+nums[l] > sum)
                    r--;
                else if(nums[l] + nums[r] < sum)
                    l++;
                else {
                    res.push_back(vector<int>({f,nums[l],nums[r]}));
                    while (l < r && nums[l] == nums[l + 1]) ++l;
				    while (l < r && nums[r] == nums[r - 1]) --r;
                    l++;
                    r--;
                }
            }
        }
        return res;
        
    }
};