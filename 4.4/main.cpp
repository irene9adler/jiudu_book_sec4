//�Ŷ��� ������ ��ѧ���� ��4.4����ת�� �������ʮ���Ͻ���
#include <stdio.h>
#include <string.h>

int main()
{
    int m,n;//m������ԭ������ n��ת�������
    char str[50];//��ԭ����m������

    while(scanf("%d%s%d",&m,str,&n)!= EOF)
    {
        int tmp = 0;
        int c = 1;
        char res[50];
        int loc = 0;
        int i;
        int l = strlen(str);
        for(i = l-1;i >= 0 ;i--)//�ַ���i= 0�Ǹ�λ�����ǵ�λ
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                tmp += (str[i] - '0') * c;
                c = c * m;
            }
            else if(str[i] >= 'a' && str[i] <= 'z')
            {
                tmp += (str[i] - 'a' + 10) * c;
                c = c * m;
            }

            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                tmp += (str[i] - 'A' + 10) * c;
                c = c * m;
            }
        }
        if(tmp == 0) res[0] = '0';//��do while�Ͳ���Ҫ���ⲽ
        while(tmp)
        {
            int x = tmp % n;//����n����10�����
            if(x >= 10)
            {
                res[loc++] = x - 10 + 'a';
            }
            else res[loc++] = x + '0';//ע����������abcd��������λ��Ҫ��ʾ���ַ� ����λ����ע��Ӽ�'0'
            tmp = tmp / n;
        }
        for(i = loc - 1;i >= 0;i--)
            printf("%c",res[i]);
        printf("\n");
    }
    return 0;
}
