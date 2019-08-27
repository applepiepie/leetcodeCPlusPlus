//131�ָ���Ĵ�
//����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���
//���� s ���п��ܵķָ����

#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
#include<string>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

  vector<vector<string>> res;
    
    //�ж��Ƿ��ǻ����ַ���
    bool isP(string a)
    {
        int len=a.size();
        int l= 0 ;
        int r= a.size()-1;
        while(l<r)
        {
            if(a[l] != a[r])
            {
                return false;
            }
            l++;r--;
        }
        return true;
    }
    
    //��string[index]��ʼ�ָ� out�Ƿָ���
    void part(string s, int index, vector<string>& out)
    {
      // cout<<s<<" "<<index<<" "<<out<<endl;
        if(index == s.size())
        {//û���ָܷ����
            res.push_back(out);
            return;
        }
        for(int i=index; i < s.size(); i++)
        {
            string subs = s.substr(index,i-index+1);
            if(isP(subs))
            {//�ǻ��ĵĻ�
               //cout<<subs<" "<<i<<" "<<out;
                out.push_back(subs);
                part(s,i+1,out);
                out.pop_back();
                
            }
        }
    }

    vector<vector<string>> partition(string s) {
        res.clear();
        if(s.size() == 0) return res;
        vector<string> out;
        part(s,0,out);
        return res;
    }

int main()
{
    string a ="aab";
    vector<vector<string>> res;
    res = partition(a);
    
    return 0;
}