//�Ŷ��� ������ ��4.3����ת�� ����ֻ����ʮ��������
#include <stdio.h>
long long a,b;//�����a,bҪ��ֹ���

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
        while(a)//��ʮ���Ƶ���aת����m���Ʋ���ӡ ����m��a����λ��� ����浽������ ֮���ӡ
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
