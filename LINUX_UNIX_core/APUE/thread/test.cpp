#include<iostream>

using namespace std;

void *func(void *args)
{
    cout << "thread runing" << endl;
    return (void *)0;
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func, NULL);
    
    return 0;
}