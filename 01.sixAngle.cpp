/*
Don't delete this comment!
이 주석을 지우지 마십시오.
------------------------------
이름 : 01.sixAngle.cpp
설명 : 육각형 타일 채우기
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getHexagon(int a, int b, int c)
{
        return b * c + c * (a - 1) + (a - 1) * (b - 1);
}

int main(void)
{
        int a, b, c;
        printf("%d %d %d", sin((double)0), cos((double)0), tan((double)45));
        scanf("%d %d %d", &a, &b, &c);
        printf("%d", getHexagon(a, b, c));
        system("pause>nul");
    return 0;
}
