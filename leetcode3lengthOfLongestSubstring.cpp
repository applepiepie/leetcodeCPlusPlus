//leetcode 3 ���ظ�����Ӵ�
//��Ŀ������һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//˼·������һ�����鱣����ֹ����Ӵ���������
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

    int lengthOfLongestSubstring(string s) {
        int freq[258]={0}; //���ֹ����Ӵ��е��ַ�ASCII��
        int l=0,r=-1; //s[l,r]�����ʱ�������鷶Χ
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