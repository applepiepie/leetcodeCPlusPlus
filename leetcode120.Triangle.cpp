/* 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为?11（即，2?+?3?+?5?+?1?= 11）。
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        if( triangle.size() == 0) return 0;
        vector<int> res(triangle.back());
        for(int i=size-2; i >= 0;i--)
        {
            vector<int> line = triangle[i];
            int cols = line.size();
            for(int j=0; j<cols; j++)
            {
                res[j] = min(res[j],res[j+1])+line[j];
            }
        }
        return res[0];
      
    }
};