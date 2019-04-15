//老外的答案   快速排序之后找不同
int* comparator (void* n1, void* n2)
{
    int num1 = *((int*)n1);
    int num2 = *((int*)n2);
    return (num1 - num2);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comparator);
    
    for(int i = 0; i< (numsSize-1); i++)
    {
        if(nums[i] == nums[i+1])
        {
            return true;
        }
    }
    return false;
}

/*
void qsort(void * base,size_t nmemb,size_t size ,int(*compar)(const void *,const void *));

参数说明：

base,要排序的数组

nmemb,数组中元素的数目

size,每个数组元素占用的内存空间，可使用sizeof函数获得

compar,指向函数的指针也即函数指针。这个函数用来比较两个数组元素，第一个参数大于，等于，小于第二个参数时，分别显示正值，零，负值。
*/

//手动c语言哈希表
int min = nums[0], max = nums[0], len;

    
      for (int i = 1; i < numsSize; i++) 
{
        if (nums[i] > max)
                        //找到数组最大值
            max = nums[i];
                         
         if (nums[i] < min)
                        //找到数组最小值
           min = nums[i];
   
 }
    
    // 哈希表。
  
  len = max-min+1;
                              //确认哈希表范围
  int* hash = calloc(len,sizeof(int));
    
    // 初始化哈希表。
     
 for (int i = 0; i < numsSize; i++) 
  {
        // 判断元素是否已经出现过。
      
  if (hash[nums[i]-min] == 1)
                 //以min为起点，构建哈希表
       return true;
        
      
  hash[nums[i]-min] = 1;
    
  }
    
 
   return false;


///
bool containsDuplicate(int* nums, int numsSize) {
    int i, j, tmp;
    for (i = 1; i < numsSize; i++) {
        tmp = nums[i];
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] == tmp) {
                return true;
            } else if (nums[j] < tmp) {
                nums[j + 1] = tmp;
                break;
            } else {
                nums[j + 1] = nums[j];
            }   
        }   
    }   
    return false;
}