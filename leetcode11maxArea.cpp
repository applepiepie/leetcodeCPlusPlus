//����ҵ�һ��ʢˮ�������������ö�ײָ��ķ�ʽ��
class Solution {
public:
    //�ҵ���С�߶�
    int findMin(int a ,int b)
    {
        return a<b? a:b;
    }
    int maxArea(vector<int>& height) {
        int tmp=0;
        int maxSize=0;
        
        for(int i =0;i<height.size()-1; i++)
        {
            int maxh=0;
            for(int j=height.size()-1;j>i;j--)
            {
              //  if(j !=height.size()-1 && s[j])
                if(height[j] < maxh) continue;
                else{
                    tmp=(j-i)*findMin(height[i],height[j]);
                    if(tmp > maxSize) maxSize = tmp;
                    maxh=height[j];
                }
                
            }
            
        }
        return maxSize;
    }
};