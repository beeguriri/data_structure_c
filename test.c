#include <stdio.h>

int main(void) {

 int a[][2] = {{100, 200}, {300, 400}}, b[4];
 int *p = &a[0][0];

 b[0] = p[0]++; //포인터의 값을 b[0]에 대입 후, 포인터 값 변경
 printf("b[0] = %d\n", b[0]);      //100
 printf("pointer = %d\n", *p);     //101

 b[1] = *p++ +1;    //포인터의 값 대입 후, 포인터 이동    
 printf("b[1] = %d\n", b[1]);      //102
 printf("pointer = %d\n", *p);     //200

 b[2] = (*p)++; //포인터의 값 변경
 printf("b[2] = %d\n", b[2]);      //200
 printf("pointer = %d\n", *p);     //201

 p+=1;  //포인터 이동
 b[3] = ++*p;   //포인터의 값 변경
 printf("b[3] = %d\n", b[3]);      //301
 printf("pointer = %d\n", *p);     //301

 return 0;

}