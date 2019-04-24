bool isOneBitCharacter(int* bits, int bitsSize) {
        for(int i=0;i<bitsSize;i++)
    {
        if(bits[i]==1)
        {
            if(i==bitsSize-2)
                return false;
            else
            {
                ++i;
                continue;
            }
        }
        else
        {
            if(i==bitsSize-1)
                return true;
            else
            {
                continue;
            }
        }
    }
    return true;
}