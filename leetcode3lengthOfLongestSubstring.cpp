//leetcode 3 无重复的最长子串
//题目：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//思路：借助一个数组保存出现过的子串的数量。
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

    int lengthOfLongestSubstring(string s) {
        int freq[258]={0}; //出现过的子串中的字符ASCII码
        int l=0,r=-1; //s[l,r]代表此时的子数组范围
        int res=0;
        while(r+1 < s.size() && l < s.size())
        {
            if( freq[s[r+1]]==0){
                r++;
                freq[s[r]]++;
            }
            else
                freq[s[l++]]--;
            res=max(res,r-l+1);
        }
        return res;
    }
int main()
{
    
    
    return 0;
}