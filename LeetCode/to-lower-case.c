char* toLowerCase(char* str) {
    int index = 0;
    while(*(str+index))
    {
        if(*(str+index)<91&&*(str+index)>64)
            *(str+index) = *(str+index)+32;
        index++;
    }
    return str;
}