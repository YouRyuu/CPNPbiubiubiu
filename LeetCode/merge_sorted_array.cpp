class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first0 = 0;
        int length = m+n;
        int i,j;
        if(n+m==1)
        {
            if(!n)
                return;
            nums1[0] = nums2[0];
            return;
        }
        for(i=m;i<length;i++)
        {
            nums1[i] = nums2[i-m];
        }
        i=0,j=m;
        while(j!=length&&i<j)
        {
            if(nums1[i]>nums1[j])
            {
                int temp = nums1[j];
                for(int x=j;x>i;x--)
                {
                    nums1[x] = nums1[x-1];
                }
                nums1[i] = temp;
                i++;
                j++;
            }
            else
            {
                i++;
            }
           
        }
    }
};
