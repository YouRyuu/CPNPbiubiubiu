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
        a[i] = (char *)malloc(sizeof(char)*12);
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
