bool buddyStrings(char* A, char* B) {
    int aindex = 0;
    int bindex = 0;
    int cindex = 0;
    int length = strlen(A)!=strlen(B)?0:strlen(A);
    if(length==0) return false;
    while(aindex<length)
    {
        if(A[aindex]==B[aindex])
        {
            if(aindex!=bindex)
                aindex++;
            else
            {
                aindex++;
                bindex++;
            }
        }
        else
        {
            if(aindex!=bindex)
                if(A[bindex]!=B[aindex]||A[aindex]!=B[bindex])
                    return false;
                else
                {
                    cindex += 1;
                    aindex++;
                }
            aindex++;
        }
    }
    if(aindex==bindex)
    {
        if(aindex==1) return true;
        int flag = 0;
        for(int i=0;i<length;i++)
        {
            flag = A[i]^flag;
        }
        return flag == 0;
    }
    return cindex==1;
}