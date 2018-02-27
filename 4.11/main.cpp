//九度书 第四章 数学问题 高精度整数 例4.11 高精度整数加法（大数加法?)
#include <stdio.h>
#include <string.h>

struct biginteger//封装一个大数结构体
{
    int digit[1000];//字符串中4个数字存成一个数值
    int size_;//第一个空位置

    //下面是struct你、里面封装的方法
    void init()
    {
        int i;
        for(i = 0;i < 1000;i++) digit[i] = 0;
        size_ = 0;
    }

    void set_(char str[])//将表示大整数的字符串存到数组digit中
    {
        init();
        int i;
        int j = 0,c = 1,t = 0;//t是用来算这四位最后的数值的 c表示权值 j用来计数(0-4)
        int l = strlen(str);
        for(i = l - 1;i >= 0; i--)//最后一个字符是最后的数字 是低位
        {
            t = t + (str[i] - '0') * c;
            c = c * 10;
            j ++;
            if(j == 4 || i == 0)//结束条件 数字没了或已经4位了
            {
                digit[size_++] = t;
                j = 0;
                t = 0;
                c = 1;//重置这些数值
            }
        }

    }

    void output()
    {
        int i;
        printf("%d",digit[size_ - 1]);
        for(i = size_ - 2;i >=0; i--)//如何保证打印顺序正确 画图可见
        {
            printf("%04d",digit[i]);
        }
        printf("\n");
    }

    biginteger operator + (const biginteger &A) const
    {
        biginteger res;
        res.init();//res是计算结果 只init就可以
        int carry = 0;//保存地位进位
        int i;
        for(i = 0;i < size_ || i < A.size_;i++)
        {
            int tmp = digit[i] + A.digit[i] + carry;//每组数字的计算结果
            carry = tmp / 10000;//计算下一组数字的进位
            res.digit[res.size_++] = tmp;
        }
        if(carry != 0)//算到最后还有进位
        {
            res.digit[res.size_++] = carry;
        }
        return res;
    }
}a,b,c;
char str1[1002],str2[1002];//存a,b的字符串表示
int main()
{
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        a.set_(str1);
        b.set_(str2);
        c = a + b;
        c.output();
    }
    return 0;
}
