//�Ŷ��� ������ ��ѧ���� ��4.10 �ֽ�������
#include <stdio.h>

bool mark[100001];
int prime[100001];
int primeSize;

void init()
{
    primeSize = 0;
    int i,j;
    for(i = 2;i < 100001;i++)
    {
        if(mark[i] == true) continue;
        prime[primeSize++] = i;
        printf("prime[%d] = %d\n",primeSize,i);
        if(i >= 1000) continue;//ֻ��¼1000�ڵ����� Ӧ����Ϊ�����ܣ�

        for(j = i * i;j <= 100000; j+=i)//ע��j+=i
        {
            mark[j] = true;
        }
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        int ansPrime[30];//��ŷֽ����������
        int ansSize = 0;//�ֽ�����������м������ظ������룩
        int ansNum[30];//�ֽ������������Ӧ����ָ��
        int i;
        for(i = 0;i < primeSize; i++)//��ÿ������
        {
            if(n % prime[i] == 0)
                {
                    ansPrime[ansSize] = prime[i];
                    printf("ansPrime[%d] = %d\n",ansSize,prime[i]);
                    ansNum[ansSize] = 0;//��ָ����ʼֵΪ0
                    while(n % prime[i] == 0)//����������ӵ���
                    {
                        ansNum[ansSize] ++;
                        n = n / prime[i];
                    }
                    ansSize ++;
                    if(n == 1) break;//forѭ����������
                }
        }
        if(n!=1)//1000����ȫ������������ n��û�е�1 ʣ��һ������1000�Ĵ����� ��ָ��Ϊ1
        {
            ansPrime[ansSize] = n;
            ansNum[ansSize++] = 1;//�����д++Ҳ�а�
        }
        int res = 0;
        for(i = 0;i < ansSize;i++)
        {
            printf("ansNum[%d] = %d\n",i,ansNum[i]);
            res += ansNum[i];
        }
        printf("%d\n",res);
    }
    return 0;
}
