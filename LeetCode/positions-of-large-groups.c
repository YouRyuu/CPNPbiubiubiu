//ok,但是速度不是很快
int** largeGroupPositions(char* S,int** columnSizes, int* returnSize) {
    int begin=0,end=0;
    int count = 0;
    char pre = *S;
    int **result = (int **)malloc(sizeof(int *));
    //*columnSizes = malloc(sizeof(int *));
    for(int i=1;*(S+i);i++) {
        if (*(S + i) != pre || (!*(S+(i+1))&&++end ) ) {
            if ((end - begin + 1) >= 3) {
                count++;
                int *row = (int *) malloc(sizeof(int) * 2);
                row[0] = begin;
                row[1] = end;
                result = realloc(result, sizeof(int *) * count);
                *columnSizes = realloc(*columnSizes, sizeof(int*)*count);//这里一开始写错了,写成了*columnSizes = realloc(columnSizes, sizeof(int*)*count);发生错误,哎,对指针还是了解的不够多啊
                result[count - 1] = row;
                (*columnSizes)[count-1] = 2;
            }
            begin = i;
            pre = *(S + i);
        }
        end = i;
    }
    *returnSize = count;
    return result;
}

//更正后的
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    int begin=0,end=0;
    int count = 0;
    char pre = *S;
    
    
    for(int i=1;*(S+i);i++)
    {
        if (*(S + i) != pre || (!*(S+(i+1))&&++end ) )
        {
            if(end-begin+1>=3)
            {
                count++;
            }
            begin = i;
            pre = *(S+i);
        }
        end = i;
    }
    *returnSize = count;
    int **result = (int **)malloc(sizeof(int *)*count);
    *columnSizes = malloc(sizeof(int *)*count);
    count = 0;
    end = 0;
    begin = 0;
    pre = *S;
    for(int i=1;*(S+i);i++)
    {
        if (*(S + i) != pre || (!*(S+(i+1))&&++end ) )
        {
            if(end-begin+1>=3)
            {
                count++;
                int *row = (int*)malloc(sizeof(int)*2);
                row[0] = begin;
                row[1] = end;
                result[count-1] = row;
                (*columnSizes)[count-1] = 2;
            }
            begin = i;
            pre = *(S+i);
        }
        end = i;
    }
    return result;
}

//最后看一下最快的
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    
    int strSize = 0;
    while(*(S+strSize)!='\0')   ++strSize;
    
    int **res = NULL;
    *columnSizes = NULL;
    
    int gc = -1;
    int start = 0, end = 0;
    
    for(int i=1; i<strSize; ++i){
        
        if((*(S+i)==*(S+i-1)))  ++end;
        
        // edge
        if((*(S+i)!=*(S+i-1))||(i==(strSize-1))){
            
            if(end>1){
                ++gc;
                res = (int**)realloc(res, (gc+1)*sizeof(int*));
                *(res+gc) = (int*)malloc(2*sizeof(int));
                *(*(res+gc)+0) = start;
                *(*(res+gc)+1) = (start+end);
                
                *columnSizes = (int*)realloc(*columnSizes, (gc+1)*sizeof(int));
                *(*(columnSizes)+gc) = 2;
            }
            
            start = i;
            end = 0;
        }
    }
    
    *returnSize = gc+1;
    
    return res;
}