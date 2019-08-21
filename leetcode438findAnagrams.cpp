//leetcode738 找到字符串中所有字母异位词
/*给定一个字符串?s?和一个非空字符串?p，找到?s?中所有是?p?的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串?s?和 p?的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]
 */
//不会 mmp 
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

    vector<int> findAnagrams(string s, string p) {
     if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for (char c : p) ++m[c];
        while (right < n) {
            if (m[s[right++]]-- >= 1) --cnt;
            if (cnt == 0) res.push_back(left);
            if (right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
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