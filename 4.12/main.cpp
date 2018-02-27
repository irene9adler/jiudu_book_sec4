//九度书 第四章 数学问题 高精度整数 例4.12 小整数 * 高精度整数->n!
#include <stdio.h>

struct biginteger
{
    int digit[1000];
    int size_;

    void init()
    {
        int i;
        for(i = 0;i < 1000; i++)
        {
            digit[i] = 0;
        }
        size_ = 0;
    }

    void set_(int x)//用一个小整数set biginteger 大数加法是set用来把字符串存到digit中
    {
        init();
        while(x)
        {
            digit[size_++] = x % 10000;
            x = x / 10000;
        }
    }

    void output()
    {
        int i;
        printf("%d",digit[size_ - 1]);
        for(i = size_ - 2;i >= 0; i--)
        {
            printf("%04d",digit[i]);
        }
        printf("\n");
    }

    biginteger operator * (int x) const//每个四位都乘x 加进位
    {
        biginteger res;
        res.init();
        int carry = 0;
        int i;
        int tmp;
        for(i = 0;i < size_;i++)
        {
            tmp = digit[i] * x + carry;

            res.digit[res.size_++] = tmp % 10000;
            carry = tmp / 10000;//进位是除10000
        }
        if(carry != 0)//最高位有进位 不能丢
        {
            printf("carry = %d\n",carry);
            res.digit[res.size_++] = carry;
        }
        return res;
    }

}a;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        a.init();
        a.set_(1);
        int i;
        for(i = 1;i <= n;i++)
        {
            a = a * i;
        }
        printf("a.size = %d\n",a.size_);
        a.output();
    }
    return 0;
}
