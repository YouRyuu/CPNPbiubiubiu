/*Runtime: 28 ms, faster than 10.10% of C online submissions for Unique Email Addresses.
Memory Usage: 8 MB, less than 100.00% of C online submissions for Unique Email Addresses.
*/
int numUniqueEmails(char** emails, int emailsSize) {
        int count = 1;
    char results[emailsSize][100];
    for(int i=0;i<emailsSize;i++)
    {
        int flag = 0;
        memset(results[i], 0, 100);
        for(int index=0;index<strlen(emails[i]);index++)
        {
            if(emails[i][index] == '@')
            {
                strncat(results[i], &emails[i][index], 1);
                flag = 1;
                continue;
            }
             if(emails[i][index]!='.' && emails[i][index]!='+')
                strncat(results[i], &emails[i][index], 1);
            else if(emails[i][index]=='.')
                if(!flag)
                    continue;
                else
                    strncat(results[i], &emails[i][index], 1);
            else if(emails[i][index]=='+')
                for(int j=index;j<strlen(emails[i]);j++)
                {
                    if(emails[i][j+1]=='@')
                    {
                        index = j;
                        flag = 1;
                        break;
                    }
                }
        }
    }
    for(int i=0;i<emailsSize-1;i++)
    {
        int seem = 0;
        for(int j=i+1;j<emailsSize;j++)
            if(!strcmp(results[i], results[j]))
                seem = 1;
        if(!seem)
            count++;
    }
    return count;
}