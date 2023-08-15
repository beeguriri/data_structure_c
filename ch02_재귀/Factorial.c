#include <stdio.h>

int Factorial(int n)
{
    //재귀함수 탈출조건
    if(n==0)
        return 1;
    
    return n * Factorial(n-1);
}

int main(void)
{
    printf("1! = %d\n", Factorial(1));
    printf("2! = %d\n", Factorial(2));
    printf("3! = %d\n", Factorial(3));
    printf("4! = %d\n", Factorial(4));
    printf("5! = %d\n", Factorial(5));
    printf("9! = %d\n", Factorial(9));
    printf("10! = %d\n", Factorial(10));
    printf("15! = %d\n", Factorial(15));

    return 0;
}