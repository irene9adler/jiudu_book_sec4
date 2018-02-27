//�Ŷ��� ������ ��ѧ���� ����4.9 ��n����a^k�����k
#include <stdio.h>
bool mark[1010];
int prime[1010];
int primeSize;

void init()
{
    primeSize = 0;
    int i,j;
    for(i = 2;i < 1000; i++)
    {
        if(mark[i] == true) continue;
        //mark[i] = true;
        prime[primeSize ++] = i;
        for(j = i * i;j < 1000; j += i)
        {
            mark[j] = true;
        }
    }
}

int cnt [1010];//��ŷֽ�n!ʱ1-primeSizeÿ��������Ӧ����ָ��
int cnt2[1010];//��ŷֽ�aʱ1-primeSizeÿ��������Ӧ����ָ��

int main()
{
    int n,a;
    init();
    while(scanf("%d%d",&n,&a))
    {
        int i;
        for(i = 0;i < primeSize; i++)
        {
            cnt[i] = cnt2[i] = 0;
        }
        for(i = 0;i < primeSize; i++)//����n!��p^k����ָ�����㷨 [n/p^k]�ۼ�
        {
            int tmp = n;
            while(tmp)
            {
                cnt[i] += tmp / prime[i];
                tmp = tmp / prime[i];
            }
        }

        int res = 111111111;
        for(i = 0;i < primeSize; i++)
        {
            while(a % prime[i] == 0)
            {
                cnt2[i] ++;
                a = a / prime[i];
            }
            if(cnt2[i] == 0) continue;//a�зֽⲻ��prime[i] ��Ӱ���ж� continue���������0
            if(cnt[i] / cnt2[i] < res)//����k�ķ��� �Ƚ�n!��ÿ��p��ָ����a�и�pָ���ļ��� ��С�ı�����k
            {
                res = cnt[i] / cnt2[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
