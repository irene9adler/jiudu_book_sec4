//�Ŷ��� ������ ��ѧ���� ��4.5 4.6 4.7���Լ�� ��С������
#include <stdio.h>
int gcd(int a,int b)
{
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int gcd_ = gcd(m,n);
        printf("gcd = %d\n",gcd_);
        int lcm = m * n / gcd_;
        printf("lcm = %d\n",lcm);
    }
    return 0;
}
