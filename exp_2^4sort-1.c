//��С�����������

#include<stdio.h>

int main()
{
    int a[100 ^ 10];
    int i;                                                 
    int j = 0;
    int cnt = 0;                                           
    int tmp;                                               
    char flag = 'a';
    printf("��������һ������ֱ���س�\n");
    for (i = 0;i < 100 ^ 10 && flag != '\n';i++)
    {
        scanf_s("%d", &a[i]);
        flag = getchar();
        j++;
    }
    while (cnt < j)
    {
        for (i = cnt;i < j;i++)
        {
            if (a[cnt] > a[i])
            {
                tmp = a[cnt];
                a[cnt] = a[i];
                a[i] = tmp;
            }
        }
        cnt++;
    }
    for (i = 0;i < j;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}


