/* ����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�

���磬���������Σ�

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
�Զ����µ���С·����Ϊ?11������2?+?3?+?5?+?1?= 11����
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