//�Ŷ��� ������ ��ѧ���� ��4.10 ��������
#include <stdio.h>

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int res = 1;
        while(b!=0)
        {
            if(b % 2 == 1)
            {
                res *= a;
                res = res % 1000;
            }
            a = a * a;
            b = b / 2;
            a = a % 1000;//aƽ����ÿ��Ҳȡ����λ ÿ�γ���ȥ�Ķ���ȡ����λ֮�����ֵ
        }
        printf("%d\n",res);
    }
    return 0;
}
