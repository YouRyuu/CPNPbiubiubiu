int numJewelsInStones(char* J, char* S) {
        int count = 0;
    int map[128] = {0};
    int index = 0;
    while(*(J+index))
    {
        map[*(J+index)] = 1;
        index++;
    }
    index = 0;
    while(*(S+index))
    {
        if(map[*(S+index)])
            count++;
        index++;
    }
    return count;
}