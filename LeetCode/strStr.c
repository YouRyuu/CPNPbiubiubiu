int strStr(char* haystack, char* needle) {
    if(!*(needle)) return 0;
    int index = 0;
    int i = 0;
    int j = 0;
    while(*(needle+j))
    {
        if(!*(haystack+i+j)) return -1;
        if(*(needle+j)==*(haystack+j+i))
        {
            j++;
        }
        else
        {
            i++;
            if(!*(haystack+i)) return -1;
            j = 0;
        }
    }    
    return i;
}