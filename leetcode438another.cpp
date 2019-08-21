#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
///不对 有问题
using namespace std;

    vector<int> findAnagrams(string s, string p) {
     if (s.empty()) return {};
        vector<int> res;
        int k[256]={0};
        int left = 0, right = 0, cnt = p.size();
       for(int i=0;i<p.size();i++)
       {
           k[p[i]]++;
       }
        while(right < s.size())
        {
            if(k[s[right++]] >=1)
            {
                k[s[right]]--;
                cnt--;
                right++;
            }
            if(cnt ==0)
            {
                res.push_back(left);
            }
            if(right - left ==p.size() && k[s[left]]>= 0)
            {
                cnt++;
                k[s[left]]++;
                left++;
            }
        }
        return res;
    }

int main()
{
     string s="cbaebabacd";
    string p="abc";
    findAnagrams(s,p);
    
    
    return 0;
}