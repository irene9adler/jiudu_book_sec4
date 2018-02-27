//九度书 第四章 数学问题 代码4.9 求n整除a^k的最大k
#include <stdio.h>
bool mark[1010];
int prime[1010];
int primeSize;

void init()
{
    primeSize = 0;
    int i,j;
    for(i = 2;i < 1000; i++)
    {
        if(mark[i] == true) continue;
        //mark[i] = true;
        prime[primeSize ++] = i;
        for(j = i * i;j < 1000; j += i)
        {
            mark[j] = true;
        }
    }
}

int cnt [1010];//存放分解n!时1-primeSize每个质数对应的幂指数
int cnt2[1010];//存放分解a时1-primeSize每个质数对应的幂指数

int main()
{
    int n,a;
    init();
    while(scanf("%d%d",&n,&a))
    {
        int i;
        for(i = 0;i < primeSize; i++)
        {
            cnt[i] = cnt2[i] = 0;
        }
        for(i = 0;i < primeSize; i++)//计算n!中p^k的幂指数的算法 [n/p^k]累加
        {
            int tmp = n;
            while(tmp)
            {
                cnt[i] += tmp / prime[i];
                tmp = tmp / prime[i];
            }
        }

        int res = 111111111;
        for(i = 0;i < primeSize; i++)
        {
            while(a % prime[i] == 0)
            {
                cnt2[i] ++;
                a = a / prime[i];
            }
            if(cnt2[i] == 0) continue;//a中分解不出prime[i] 不影响判断 continue避免下面除0
            if(cnt[i] / cnt2[i] < res)//计算k的方法 比较n!中每个p的指数是a中该p指数的几倍 最小的倍数是k
            {
                res = cnt[i] / cnt2[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
