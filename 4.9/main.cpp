//�Ŷ��� ������ ��ѧ���� ��4.9 ����ɸ��
#include <stdio.h>
int prime[10000];
int num;
bool mark[10001];

void init()
{
    int i,j;
    for(i = 1; i <= 10000;i++)
    {
        mark[i]= false;
    }
    mark[1] = true;//1��������
    num = 0;
    for(i = 2;i <= 10000;i++)
    {
        if(mark[i] == true) continue;//markΪtrue��ʾ��������
        //������ ��Ǻ���ķ�����
        prime[num++] = i;
        for(j = i * i;j <=10000 ;j++)
            mark[j] = true;
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i = 2;i <=n;i++)
        {
            if(mark[i] == false && i%10 == 1)
                printf("%d\n",i);
        }
    }
    return 0;
}
