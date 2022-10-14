//由小到大输出数组

#include<stdio.h>

int main()
{
    int a[100 ^ 10];
    int i;                                                 
    int j = 0;
    int cnt = 0;                                           
    int tmp;                                               
    char flag = 'a';
    printf("连续输入一组数据直至回车\n");
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


