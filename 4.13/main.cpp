//�Ŷ��� ������ ��ѧ���� �߾������� ��4.13 ����ת�� ��Ϊ����ת��������Ҫ�õ� + * / % ���� ����ת��Ϊ
//������������Ӻ�
//�߾�����������ͨ������*/%����

//////////�˴��²� ����ɸ�͸߾�����������̫����
//a����תb���Ƽ�Ҫ�ع�
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

    void set_(int x)//��x set integer �˴��ǰ�4λ�浽һ��digit[i]
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

    //+(����biginteger)
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
 int remainder = 0;//����
 int i;
 for(i = size_ - 1;i >= 0; i--)//�Ӹ�λ���λ��
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
     if(digit[i] != 0) res.size_ = i;//����߷���λ Ϊʲô��ô�� ��Ϊ�����forѭ��������һ������߷���λ
 }
 res.size_ ++;
 //////////////////
 return res;
 }

 int operator % (int x) const{//���̺���/һ�� ����󷵻ص�������
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

char str[10000];//�����m������
char res[10000];//ת�����n������
int main()
{
    int m,n;//m����תn����
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        scanf("%s",str);
        int l = strlen(str);
        ///////������m������str[]ת����ʮ���Ƶ�a
        a.set_(0);//a��������m������ת����ʮ���ƽ����biginteger
        b.set_(1);//b��������Ȩ�ص�biginteger ��1 set
        int i;
        for(i = l - 1;i >=0;i--)
        {
            int tmp;
            if(str[i] >= '0' && str[i] <= '9')
                tmp = str[i] - '0';
            else//ʮ������������ĸ
                tmp = str[i] - 'A' + 10;
            a = a + b * tmp;//operator +�����صĲ���д��+=
            b = b * m;

        }

         //////////������ʮ���Ƶ�aתn���Ƶ�res[]
         int loc = 0;
         while(a.size_!= 1 || a.digit[0] != 0)///////a��Ϊ0ʱ�ظ��ù��� Ϊʲô��ôд����
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
