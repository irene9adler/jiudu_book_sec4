//九度书 第四章 数学问题 例4.10 分解素因数
#include <stdio.h>

bool mark[100001];
int prime[100001];
int primeSize;

void init()
{
    primeSize = 0;
    int i,j;
    for(i = 2;i < 100001;i++)
    {
        if(mark[i] == true) continue;
        prime[primeSize++] = i;
        printf("prime[%d] = %d\n",primeSize,i);
        if(i >= 1000) continue;//只记录1000内的素数 应该是为了性能？

        for(j = i * i;j <= 100000; j+=i)//注意j+=i
        {
            mark[j] = true;
        }
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        int ansPrime[30];//存放分解出的质因数
        int ansSize = 0;//分解出的质因数有几个（重复不计入）
        int ansNum[30];//分解出的质因数对应的幂指数
        int i;
        for(i = 0;i < primeSize; i++)//对每个质数
        {
            if(n % prime[i] == 0)
                {
                    ansPrime[ansSize] = prime[i];
                    printf("ansPrime[%d] = %d\n",ansSize,prime[i]);
                    ansNum[ansSize] = 0;//幂指数初始值为0
                    while(n % prime[i] == 0)//计算这个因子的幂
                    {
                        ansNum[ansSize] ++;
                        n = n / prime[i];
                    }
                    ansSize ++;
                    if(n == 1) break;//for循环结束条件
                }
        }
        if(n!=1)//1000以内全部素数测试完 n还没有到1 剩下一个超过1000的大素数 幂指数为1
        {
            ansPrime[ansSize] = n;
            ansNum[ansSize++] = 1;//这儿不写++也行吧
        }
        int res = 0;
        for(i = 0;i < ansSize;i++)
        {
            printf("ansNum[%d] = %d\n",i,ansNum[i]);
            res += ansNum[i];
        }
        printf("%d\n",res);
    }
    return 0;
}
