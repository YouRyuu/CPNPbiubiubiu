int numRookCaptures(char** board, int boardRowSize, int *boardColSizes) {
        int locationX,locationY;
    int count = 0;
    for(int i=0;i<boardRowSize;i++)
        for(int j=0;j<boardColSizes;j++)
            if(board[i][j]=='R')
            {
                locationX = i;
                locationY = j;
                break;
            }
    for(int left=locationX-1;left>=0;left--)
    {
        if(board[left][locationY]=='.')
            continue;
        else if(board[left][locationY]=='p')
        {
            count+=1;
            break;
        }
        else
            break;
    }
    for(int right=locationX+1;right<boardColSizes;right++)
    {
        if(board[right][locationY]=='.')
            continue;
        else if(board[right][locationY]=='p')
        {
            count+=1;
            break;
        }
        else
            break;
    }
    for(int down=locationY-1;down>=0;down--)
    {
        if(board[locationX][down]=='.')
            continue;
        else if(board[locationX][down]=='p')
        {
            count+=1;
            break;
        }
        else
            break;
    }
    for(int up=locationY+1;up<boardRowSize;up++)
    {
        if(board[locationX][up]=='.')
            continue;
        else if(board[locationX][up]=='p')
        {
            count+=1;
            break;
        }
        else
            break;
    }
    return count;
}