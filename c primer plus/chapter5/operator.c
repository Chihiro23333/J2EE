//递增和递减运算符
//递增和递减运算符在前面表示先变化，再参与计算
//递增和递减运算符在后面表示先参与计算，再变化

#include <stdio.h>
int main(void)
{

    int n = 1;
    int m = 1;
    int x, y, a, b, c;

    x = n++;
    y = ++n;

    a = 2*m++;
    b = 2*++m;

    printf("n=%d,m=%d,x=%d,y=%d,a=%d,b=%d", n, m, x, y, a, b);

    return 0;
}