//九度书 第四章 数学问题 例4.9 素数筛法
#include <stdio.h>
int prime[10000];
int num;
bool mark[10001];

void init()
{
    int i,j;
    for(i = 1; i <= 10000;i++)
    {
        mark[i]= false;
    }
    mark[1] = true;//1不是素数
    num = 0;
    for(i = 2;i <= 10000;i++)
    {
        if(mark[i] == true) continue;//mark为true表示不是素数
        //是素数 标记后面的非素数
        prime[num++] = i;
        for(j = i * i;j <=10000 ;j++)
            mark[j] = true;
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i = 2;i <=n;i++)
        {
            if(mark[i] == false && i%10 == 1)
                printf("%d\n",i);
        }
    }
    return 0;
}
