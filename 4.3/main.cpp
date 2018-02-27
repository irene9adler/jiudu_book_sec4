//九度书 第四章 例4.3进制转换 此题只考虑十进制以内
#include <stdio.h>
long long a,b;//输入的a,b要防止溢出

int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        if(m == 0) break;
        scanf("%I64d%I64d",&a,&b);
        a = a + b;
        int res[10];
        int loc = 0;
        while(a)//将十进制的数a转换成m进制并打印 先用m对a做数位拆解 拆解后存到数组里 之后打印
        {
            res[loc++] = a % m;
            a = a / m;
        }
        int i;
        for(i = loc - 1;i >= 0;i--)
        {
            printf("%d",res[i]);
        }
        printf("\n");
    }
    return 0;
}
