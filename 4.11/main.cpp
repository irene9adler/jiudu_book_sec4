//�Ŷ��� ������ ��ѧ���� �߾������� ��4.11 �߾��������ӷ��������ӷ�?)
#include <stdio.h>
#include <string.h>

struct biginteger//��װһ�������ṹ��
{
    int digit[1000];//�ַ�����4�����ִ��һ����ֵ
    int size_;//��һ����λ��

    //������struct�㡢�����װ�ķ���
    void init()
    {
        int i;
        for(i = 0;i < 1000;i++) digit[i] = 0;
        size_ = 0;
    }

    void set_(char str[])//����ʾ���������ַ����浽����digit��
    {
        init();
        int i;
        int j = 0,c = 1,t = 0;//t������������λ������ֵ�� c��ʾȨֵ j��������(0-4)
        int l = strlen(str);
        for(i = l - 1;i >= 0; i--)//���һ���ַ����������� �ǵ�λ
        {
            t = t + (str[i] - '0') * c;
            c = c * 10;
            j ++;
            if(j == 4 || i == 0)//�������� ����û�˻��Ѿ�4λ��
            {
                digit[size_++] = t;
                j = 0;
                t = 0;
                c = 1;//������Щ��ֵ
            }
        }

    }

    void output()
    {
        int i;
        printf("%d",digit[size_ - 1]);
        for(i = size_ - 2;i >=0; i--)//��α�֤��ӡ˳����ȷ ��ͼ�ɼ�
        {
            printf("%04d",digit[i]);
        }
        printf("\n");
    }

    biginteger operator + (const biginteger &A) const
    {
        biginteger res;
        res.init();//res�Ǽ����� ֻinit�Ϳ���
        int carry = 0;//�����λ��λ
        int i;
        for(i = 0;i < size_ || i < A.size_;i++)
        {
            int tmp = digit[i] + A.digit[i] + carry;//ÿ�����ֵļ�����
            carry = tmp / 10000;//������һ�����ֵĽ�λ
            res.digit[res.size_++] = tmp;
        }
        if(carry != 0)//�㵽����н�λ
        {
            res.digit[res.size_++] = carry;
        }
        return res;
    }
}a,b,c;
char str1[1002],str2[1002];//��a,b���ַ�����ʾ
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
