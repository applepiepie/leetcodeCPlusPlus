/*给定一个正整数?n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例?2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 ×?3 ×?4 = 36。
说明: 你可以假设?n?不小于 2 且不大于 58。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int>  mul(n+1,-1);
        mul[1]=1;
        mul[2]=1;
        for(int i=3;i<=n;i++)
        { //求mul[i]
            int k=0;
            for(int j=1; j<=i/2;j++) {
                k=max(j,mul[j])*max((i-j),mul[i-j]);
                mul[i]=max(mul[i],k);
            }
        }
        return mul[n];
        
    }
};