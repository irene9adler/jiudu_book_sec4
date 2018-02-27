//�Ŷ��� ������ ��ѧ���� ��4.8 �����ж�(���淽����
#include <stdio.h>
#include <math.h>
bool judge(int x)
{
    if(x <= 1) return false;
    int l = (int)sqrt(x) + 1;
    int i;
    for(i = 2;i < l;i++)
    {
        if(x%i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    bool res;
    while(scanf("%d",&n)!=EOF)
    {
        res = judge(n);
        if(res == false) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
