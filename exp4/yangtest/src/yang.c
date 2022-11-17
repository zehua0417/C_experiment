/*
 * 文件名yang.c
 * 描述：利用函数指针，指针函数，可变数组写一个简单的回调函数，用来输出杨辉三角
 * 作者：lihuax
 * 依赖：data_yang.c
 * 注：可变数组只可在C99协议下编译，不支持vs等，建议在gcc下编译(-std=c99)，因为这是我的工作环境
*/

#include<stdio.h>
#include"data_yang.h"
void yang_produce(int n, int(*p)[n]);
void out_data(int n, int data[n][n]);

int main(void)
{
        int a;
        printf("How many lines?\n");
        scanf("%d", &a);
        int gro[a][a];

        data_yang( a, gro, yang_produce, out_data);

        return 0;
}

void yang_produce( int n, int (*p)[n])
{
        for (int i = 0;i < n;i++)
        {
for (int j = 0;j < n ;j++)
                {
                        if (j == 0 || j == i)
                                /*gro[i][j] = 1*/
                                *(*(p + i) + j )= 1;
                        else
                                /*gro[i][j] = gro[i - 1][j - 1] + gro[i - 1][j]*/
                                *(*(p + i) + j) = *(*(p + i - 1) + (j - 1)) + *(*(p + i - 1) + j);
                }
        }
}

void out_data(int n, int data[n][n])
{
        for (int i = 1;i <= n;i++)
        {
                for (int j = 1;j <= i;j++)
                {
                        printf("%d ", data[i-1][j-1]);
                }
                printf("\n");
        }
}

