/*����һ��������?n��������Ϊ���������������ĺͣ���ʹ��Щ�����ĳ˻���󻯡� ��������Ի�õ����˻���

ʾ�� 1:

����: 2
���: 1
����: 2 = 1 + 1, 1 �� 1 = 1��
ʾ��?2:

����: 10
���: 36
����: 10 = 3 + 3 + 4, 3 ��?3 ��?4 = 36��
˵��: ����Լ���?n?��С�� 2 �Ҳ����� 58��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/integer-break
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� */

class Solution {
public:
    int integerBreak(int n) {
        vector<int>  mul(n+1,-1);
        mul[1]=1;
        mul[2]=1;
        for(int i=3;i<=n;i++)
        { //��mul[i]
            int k=0;
            for(int j=1; j<=i/2;j++) {
                k=max(j,mul[j])*max((i-j),mul[i-j]);
                mul[i]=max(mul[i],k);
            }
        }
        return mul[n];
        
    }
};