int romanToInt(char* s) {
    int result = 0;
    int length = 0;
    while(*(s+length)) length++;
    for(int i=0;i<length;i++)
    {
        if(*(s+i)=='I')
            if(*(s+i+1)=='V') {
                result = result + 4;
                ++i;              }
            else if(*(s+i+1)=='X') {
                result = result + 9;
                ++i;}
            else result = result + 1;
        else if(*(s+i)=='X')
            if(*(s+i+1)=='L') {
                result += 40;++i;}
            else if(*(s+i+1)=='C') {result += 90;++i;}
            else result+=10;
        else if(*(s+i)=='C')
            if(*(s+i+1)=='D') {result+=400;++i;}
            else if(*(s+i+1)=='M') {result += 900;++i;}
            else result += 100;
        else if(*(s+i)=='V') result += 5;
        else if(*(s+i)=='L') result+=50;
        else if(*(s+i)=='D') result+=500;
        else result+=1000;
    }
    return result;
}