//131分割回文串
//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//返回 s 所有可能的分割方案。

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
    
    //判断是否是回文字符串
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
    
    //从string[index]开始分割 out是分割结果
    void part(string s, int index, vector<string>& out)
    {
      // cout<<s<<" "<<index<<" "<<out<<endl;
        if(index == s.size())
        {//没有能分割的了
            res.push_back(out);
            return;
        }
        for(int i=index; i < s.size(); i++)
        {
            string subs = s.substr(index,i-index+1);
            if(isP(subs))
            {//是回文的话
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