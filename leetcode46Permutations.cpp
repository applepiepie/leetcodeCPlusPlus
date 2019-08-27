//leetcode46 数字的全排列
//给定一个没有重复数字的序列，返回其所有可能的全排列。

class Solution {
    
    void p(const vector<int>& nums,vector<int>& out,vector<vector<int>>& res, vector<bool>& used)
    {
        if(out.size() == nums.size()) 
        {//out中已有所有元素
            res.push_back(out);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(used[i] == false)
            {
                out.push_back(nums[i]);
                used[i] = true;
                p(nums,out,res,used);
                out.pop_back();
                used[i] =false;
            }
        }
        return;
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        vector<int> out;
        vector<bool> used = vector<bool>(nums.size(),false);
        p(nums,out,res,used);
        return res;
        
    }
};