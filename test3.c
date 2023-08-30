#include <stdio.h>

int *func(int a, int *x) {
    a = a+5;
    x = x+1;
    *x = *x * 2;
    return x;
}

int main(void) {

    int i;
    int x = 10;
    int *p;
    int a[100];

    for(i=0; i<100; i++)
        a[i] = i*10;

    p = func(x, a);
    printf("x=%d, a[0]=%d, a[1]=%d, a[2]=%d\n", x, a[0], a[1], a[2]);
    printf("p[0]=%d, p[1]=%d, p[2]=%d, p[3]=%d\n", p[0], p[1], p[2], p[3]);
    printf("p=%x, *p=%d", p, *p);

    return 0;
}