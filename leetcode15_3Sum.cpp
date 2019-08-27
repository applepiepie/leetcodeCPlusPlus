/*leetcode15 ����֮��
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

����, �������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
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
            if(i !=0 && nums[i] == nums[i-1]) continue; //��ͬ��������
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