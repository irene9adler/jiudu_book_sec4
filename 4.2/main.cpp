//九度书 第四章例4.2 数位拆解 用字符串存数字
#include <stdio.h>
#include <string.h>

int main()
{
    char buf1[10];
    char buf2[10];
    int loc1,loc2;
    int n,m;
    int res;
    while(scanf("%s%s",buf1,buf2)!= EOF)
    {
        res = 0;
        int i,j;
        loc1 = strlen(buf1);
        loc2 = strlen(buf2);
        for(i = 0;i < loc1;i++)
        {
            for(j = 0;j < loc2;j++)
            {
                res = res + (buf1[i] - '0') * (buf2[j] - '0');
            }
        }
        printf("result:%d\n",res);
    }
    return 0;
}
