int myAtoi(char* str) {
    long result = 0;
    int is_ = 1;
    int i=0;
    int havenum = 0;
    if((str[0]<'0'||str[0]>'9')&&str[0]!=' '&&str[0]!='-' &&str[0]!='+') return 0;
    while(str[i])
    {
        if(str[i]=='-') 
        {
            if(havenum==0)
            {
                if(str[i+1]<'0'||str[i+1]>'9') break;
                else
                {
                    is_ = -1;
                    i++;
                    continue;
                }
            }
            else break;
        }
        if(str[i]=='+')
        {
            if(havenum==0)
            {
                if(str[i+1]<'0'||str[i+1]>'9') break;
                else
                {
                    i++;
                    continue;
                }
            }
            else break;
        }
         if(str[i]==' ')
        {
             if(havenum==0)
             {i++;
            continue;}
             else break;
        }
        if(str[i]>'9' || str[i]<'0') 
        {
             break;
        }
       
        else
        {
            havenum = 1;
            result = result*10 + str[i]- '0';
            i++;
            if(result>INT_MAX) 
            {
                if(is_==-1)
                return INT_MAX*is_-1;
                else
                    return INT_MAX;
            }
                                
        }
    }
    return result*is_;
}