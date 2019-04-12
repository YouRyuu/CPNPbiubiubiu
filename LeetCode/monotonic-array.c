///my answer
bool isMonotonic(int* A, int ASize) {
        int flag,index;
    for(index=0;index<ASize-1;index++)
    {
        if(A[index]<A[index+1])
        {
            flag = 0;
            break;
        }
        else if(A[index]>A[index+1])
        {
            flag = 1;
            break;
        }
    }
    if(index==ASize) return true;
    if(flag==0)
    {
    for(int i=index;i<ASize-1;i++)
    {
        if(A[i]>A[i+1])
            return false;
    }
    }
    else
     {
    for(int i=index;i<ASize-1;i++)
    {
        if(A[i]<A[i+1])
            return false;
    }
    } 
    return true;
}

//d100 answer
bool isMonotonic(int* A, int ASize) {
    if(ASize==1)return true;
    int flag=0;
    for(int i=1;i<ASize;++i){
        if(A[i]>A[i-1]){
            if(flag<0){
                return false;
            }
            else{
                flag=1;
            }
        }
        else if(A[i]<A[i-1]){
            if(flag>0){
                return false;
            }
            else{
                flag=-1;
            }
        }
    }
    return true;
}