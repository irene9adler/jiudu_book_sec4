//九度书 第四章 数学问题 例4.1数位拆解
#include <stdio.h>


int main()
{
    int m,n;
    int buf1[10];
    int buf2[10];
    int loc1;
    int loc2;
    int res;
    while(scanf("%d%d",&m,&n))
    {
        loc1 = loc2 = 0;
        res = 0;
        while(m)
        {
            buf1[loc1++] = m%10;
            m = m / 10;
        }

        while(n)
        {
            buf2[loc2++] = n%10;
            n = n / 10;
        }

        int i,j;
        for(i = 0;i < loc1;i ++)
        {
            for(j = 0;j < loc2; j++)
            {
                res = res + buf1[i] * buf2[j];
            }
        }

        printf("result:%d\n",res);
    }
    return 0;
}
