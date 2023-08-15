#include <stdio.h>

int Fibo(int n)
{
    if(n==1 || n==2)
        return 1;
    
    return Fibo(n-1) + Fibo(n-2);
}

int main(void) 
{
    int i;
    for(i=1; i<15; i++)
        printf("%d => %d : \n", i, Fibo(i));

    return 0;
}