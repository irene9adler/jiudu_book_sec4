//九度书 第四章 数学问题 高精度整数 例4.13 进制转换 因为进制转换问题需要用到 + * / % 运算 所以转化为
//两个大整数相加和
//高精度整数与普通整数的*/%运算

//////////此处吐槽 素数筛和高精度整数的题太难了
//a进制转b进制简要回顾
//tmp = tmp + str[i] *c;
//c = c *a
/////
//res[i] = tmp % b;
//tmp = tmp / b

#include <stdio.h>
#include <string.h>

struct biginteger
{
    int digit[100];
    int size_;

    void init()
    {
        int i;
        for(i = 0;i < 100;i++)
        {
            digit[i] = 0;
        }
        size_ = 0;
    }

    void set_(int x)//用x set integer 此处是把4位存到一个digit[i]
    {
        while(x)
        {
            digit[size_ ++] = x % 10000;
            x = x / 10000;
        }
    }

    void output()
    {
        printf("%d",digit[size_ - 1]);
        int i;
        for(i = size_ - 2;i >=0 ;i--)
            printf("%04d",digit[i]);

        printf("\n");
    }

    //+(两个biginteger)
    biginteger operator + (const biginteger &A) const{
    biginteger res;
    res.init();
    int carry = 0;
    int i;
    for(i = 0;i < size_|| i < A.size_;i++)
    {
        int tmp = digit[i] + A.digit[i] + carry;
        res.digit[res.size_ ++] = tmp % 10000;
        carry = tmp / 10000;
    }
    if(carry != 0)
    {
        res.digit[res.size_ ++ ] = carry;
    }
    return res;
  }

  //*
  biginteger operator * (int x) const{
  biginteger res;
  res.init();
  int carry = 0;
  int i;
  for(i = 0;i < size_;i++)
  {
      int tmp = digit[i] * x + carry;
      res.digit[res.size_++] = tmp %10000;
      carry = tmp / 10000;
  }
  if(carry != 0)
  {
      res.digit[res.size_ ++] = carry;
  }
  return res;
 }

 // /
 biginteger operator / (int x) const{
 biginteger res;
 res.init();
 int remainder = 0;//余数
 int i;
 for(i = size_ - 1;i >= 0; i--)//从高位向低位算
 {
     int tmp = (remainder * 10000 + digit[i]) / x;
     int r = (remainder * 10000 + digit[i]) % x;
     //res.digit[res.size_++] = tmp;
     res.digit[i] = tmp;
     remainder = r;

 }
 //////////////////
 res.size_ = 0;
 for(i = 0;i < 100;i++)
 {
     if(digit[i] != 0) res.size_ = i;//找最高非零位 为什么这么做 因为上面的for循环结束不一定是最高非零位
 }
 res.size_ ++;
 //////////////////
 return res;
 }

 int operator % (int x) const{//过程和求/一致 但最后返回的是余数
     int res;
     int remainder = 0;
     int i;
    for(i = size_ - 1;i >= 0;i--)
        {
            int tmp = (remainder * 10000 + digit[i]) / x;
            int r = (remainder * 10000 + digit[i]) % x;
            remainder = r;
        }
        return remainder;
 }
}a,b,c;

char str[10000];//输入的m进制数
char res[10000];//转换结果n进制数
int main()
{
    int m,n;//m进制转n进制
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        scanf("%s",str);
        int l = strlen(str);
        ///////下面是m进制数str[]转换成十进制的a
        a.set_(0);//a是用来存m进制数转换成十进制结果的biginteger
        b.set_(1);//b是用来存权重的biginteger 用1 set
        int i;
        for(i = l - 1;i >=0;i--)
        {
            int tmp;
            if(str[i] >= '0' && str[i] <= '9')
                tmp = str[i] - '0';
            else//十进制以上有字母
                tmp = str[i] - 'A' + 10;
            a = a + b * tmp;//operator +是重载的不能写成+=
            b = b * m;

        }

         //////////下面是十进制的a转n进制的res[]
         int loc = 0;
         while(a.size_!= 1 || a.digit[0] != 0)///////a不为0时重复该过程 为什么这么写条件
         {
             int tmp = a % n;
             if(tmp >= 10) res[loc ++] = tmp - 10 + 'A';
             else res[loc ++] = tmp + '0';
             a = a / n;
         }

         for(i = loc - 1;i >= 0;i--)
            printf("%c",res[i]);

         printf("\n");

    }
    return 0;
}
