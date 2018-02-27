//九度书 第四章 数学问题 例4.4进制转换 这个包括十以上进制
#include <stdio.h>
#include <string.h>

int main()
{
    int m,n;//m是数字原来进制 n是转换后进制
    char str[50];//存原来的m进制数

    while(scanf("%d%s%d",&m,str,&n)!= EOF)
    {
        int tmp = 0;
        int c = 1;
        char res[50];
        int loc = 0;
        int i;
        int l = strlen(str);
        for(i = l-1;i >= 0 ;i--)//字符串i= 0是高位后面是低位
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                tmp += (str[i] - '0') * c;
                c = c * m;
            }
            else if(str[i] >= 'a' && str[i] <= 'z')
            {
                tmp += (str[i] - 'a' + 10) * c;
                c = c * m;
            }

            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                tmp += (str[i] - 'A' + 10) * c;
                c = c * m;
            }
        }
        if(tmp == 0) res[0] = '0';//用do while就不需要判这步
        while(tmp)
        {
            int x = tmp % n;//考虑n大于10的情况
            if(x >= 10)
            {
                res[loc++] = x - 10 + 'a';
            }
            else res[loc++] = x + '0';//注意结果不管是abcd还是数字位都要表示成字符 数字位尤其注意加减'0'
            tmp = tmp / n;
        }
        for(i = loc - 1;i >= 0;i--)
            printf("%c",res[i]);
        printf("\n");
    }
    return 0;
}
