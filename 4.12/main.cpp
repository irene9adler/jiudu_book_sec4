//�Ŷ��� ������ ��ѧ���� �߾������� ��4.12 С���� * �߾�������->n!
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

    void set_(int x)//��һ��С����set biginteger �����ӷ���set�������ַ����浽digit��
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

    biginteger operator * (int x) const//ÿ����λ����x �ӽ�λ
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
            carry = tmp / 10000;//��λ�ǳ�10000
        }
        if(carry != 0)//���λ�н�λ ���ܶ�
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
