//leetcode77 �������
//������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�
//ע��������� ������˳�� 2��1 ��1,2 ��һ����
class Solution {
    
    //��index-n��ѡ��һ�����֣�����out�У�kΪ����Ҫѡ�����֣�
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