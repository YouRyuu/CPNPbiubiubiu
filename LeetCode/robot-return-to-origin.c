bool judgeCircle(char* moves) {
    int R=0,L=0,U=0,D=0;
    int length = strlen(moves);
    for(int index=0;index<length;index++)
    {
        if(moves[index]=='R')
            R++;
        else if(moves[index]=='L')
            L++;
        else if(moves[index]=='U')
            U++;
        else
            D++;
        
    }
    if(R==L&&U==D)
            return true;
        else
            return false;
}