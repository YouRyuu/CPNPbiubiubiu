bool divisorGame(int N){
    bool result[N+1];
    memset(result, 0, N+1);
    result[1] = false;
    for(int i=2;i<=N;i++)
        for(int j=1;j<i;j++)
            if(i%j==0 && !result[i-j])
                result[i] = true;
    return result[N];
}
