#include <stdio.h>

void HanoiTower(int num, char from, char by, char to)
{
    //원반 한개가 남으면 무조건 A -> C로 옮김
    if(num==1)
    {
        printf("원반1을 %c에서 %c로 이동\n", from, to);
        return;
    }

    //n-1개를 A -> B로 옮긴 후,
    HanoiTower(num-1, from, to, by);

    //제일 큰 원반이 나오면 제일 큰 원반을 A ->C 로 옮기고
    printf("원반%d를 %c에서 %c로 이동\n", num, from, to);

    //남은 n-1개 원반을 B -> C로 옮김
    HanoiTower(num-1, by, from, to);

}

int main(void)
{
    HanoiTower(4, 'A', 'B', 'C');
    return 0;
}