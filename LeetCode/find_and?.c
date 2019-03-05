char* longestCommonPrefix(char** strs, int strsSize) {
    int j = 0;
    int n = j+5;
    int diff = 0;
    char *a = (char*)malloc(n*sizeof(char));
    while(1)
    {
    for(int i=1;i<strsSize;i++)
    {
        if(j==n)
        {
            n = j+5;
            a = (char *)realloc(a,n*sizeof(char));
        }
        
        if(*(strs[i]+j)!=*(strs[0]+j))
        {
            diff = 1;
            break;
        }
        *(a+j) = *(strs[0]+j);
    }