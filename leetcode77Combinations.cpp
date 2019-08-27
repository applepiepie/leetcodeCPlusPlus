//leetcode77 组合问题
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//注意组合问题 不考虑顺序 2，1 和1,2 是一样的
class Solution {
    
    //从index-n中选出一个数字，放入out中，k为还需要选的数字，
    void subC(int n,int k,int index,vector<int>& out,vector<vector<int>>& res)
    {
        if(k == 0)
        {
            res.push_back(out);
            return;
        }
        for(int i=index;i<=n;i++)
        {
           
            {
                out.push_back(i);
                subC(n,k-1,i+1,out,res);
                out.pop_back();
                
            }
        }
        return;
        
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if( k > n) return res;
        vector<int> out;
        subC(n,k,1,out,res);
        return res;
    }
};