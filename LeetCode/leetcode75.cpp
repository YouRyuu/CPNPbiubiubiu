class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int p0=0, p1=0;
        for(int i=0;i<size;++i)
        {
            if(nums[i]==1)
            {
                ex(&nums[i], &nums[p1]);
                ++p1;
            }
            else if(nums[i]==0)
            {
                ex(&nums[i], &nums[p0]);
                if(p0<p1)
                {
                    ex(&nums[i], &nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
        }

    void ex(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size-1;
        for(int i=0;i<size;++i)
        {
            if(nums[i]==0)
            {
                ex(&nums[i], &nums[left]);
                ++left;
            }
        }
        for(int i=left;i<size;++i)
        {
            if(nums[i]==1)
            {
                ex(&nums[i], &nums[left]);
                left++;
            }
        }
        }

    void ex(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
  }
};
