//leetcode738 �ҵ��ַ�����������ĸ��λ��
/*����һ���ַ���?s?��һ���ǿ��ַ���?p���ҵ�?s?��������?p?����ĸ��λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ������

�ַ���ֻ����СдӢ����ĸ�������ַ���?s?�� p?�ĳ��ȶ������� 20100��

˵����

��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
�����Ǵ������˳��
����:
s: "cbaebabacd" p: "abc"

���:
[0, 6]
 */
//���� mmp 
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