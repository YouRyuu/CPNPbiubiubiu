//在我电脑上可以，但是在leetcode上缓冲区溢出，暂时不知道为什么
int uniqueMorseRepresentations(char **words, int wordsSize) {
    if(wordsSize==0) return 0;
    char *password[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char *a[wordsSize];
    int count = 1;
    for(int i=0;i<wordsSize;i++)
    {
        int length = strlen(words[i]);
        char temp[12] = {0};
        a[i] = (char *)malloc(sizeof(char)*12);//这里分配内存的原因：如果不分配内存，a[i]就使用a[i]=temp，但是这样的话
                                                //a[i]的值就是指向temp的地址，下次改变temp的值的话a[i]的值也会随之变化
        for(int j=0;j<length;j++)
        {
            strcat(temp, password[words[i][j]-'a']);
        }
        strcpy(a[i], temp);
    }
    for(int i=0;i<wordsSize-1;i++)
    {
        int seem = 0;
        for(int j=i+1;j<wordsSize;j++)
        {
            if(!strcmp(a[i],a[j]))
                seem = 1;
        }
        if(seem==0) count++;
    }
    return count;
}

/*!!!!leetcode上正确解法。
上面的方法错误的原因是leetcode分配的堆栈空间很小，所以出现栈、堆溢出
因此要少使用动态变量（malloc）
修改后的方法如下
Runtime: 4 ms, faster than 89.44% of C online submissions for Unique Morse Code Words.
Memory Usage: 6.9 MB, less than 100.00% of C online submissions for Unique Morse Code Words.
*/
int uniqueMorseRepresentations(char** words, int wordsSize) {
       if(wordsSize==0) return 0;
    char *password[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char a[wordsSize][48];
    int count = 1;
    for(int i=0;i<wordsSize;i++)
    {
        memset(a[i], 0, 48);
        int length = strlen(words[i]);
//        char temp[12] = {0};
//        a[i] = (char *)malloc(sizeof(char)*12);
        for(int j=0;j<length;j++)
        {
//            printf("%s\n", password[words[i][j]-'a']);
            strncat(a[i], password[words[i][j]-'a'], strlen(password[words[i][j]-'a']));
        }
//        strcpy(a[i], temp);
    }
    for(int i=0;i<wordsSize-1;i++)
    {
        int seem = 0;
        for(int j=i+1;j<wordsSize;j++)
        {
            if(!strcmp(a[i],a[j]))
                seem = 1;
        }
        if(seem==0) count++;
    }
    return count;
}
