//九度书 第四章 数学问题 例4.10 二分求幂
#include <stdio.h>

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int res = 1;
        while(b!=0)
        {
            if(b % 2 == 1)
            {
                res *= a;
                res = res % 1000;
            }
            a = a * a;
            b = b / 2;
            a = a % 1000;//a平方后每次也取后三位 每次乘上去的都是取后三位之后的数值
        }
        printf("%d\n",res);
    }
    return 0;
}
