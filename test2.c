#include <stdio.h>

void func(int *a, int b, int *c) {
    int x;
    x = *a;
    printf("x=%d\n", x);

    *a = x++;
    printf("함수 내에서 a=%d\n", *a);
    printf("x=%d\n", x);
    x = b;
    b = ++x;
    printf("함수 내에서 b=%d\n", b);
    printf("x=%d\n", x);
    --(*c);
    printf("함수 내에서 c=%d\n", *c);
    printf("x=%d\n", x);
}

int main(void) {

    int a, b, c[1];
    a = 20;
    b = 20;
    c[0] = 20;
    
    func(&a, b, c);
    printf("a=%d, b=%d, c=%d", a, b, *c);

    return 0;
}