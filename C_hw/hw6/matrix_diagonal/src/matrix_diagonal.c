/*
 * file name: matrix_diagonal.c
 * author: lihuax
 * version:1.0
 * discription: to calc the sum of a 3*3 matrix diagonal
 */
#include<stdio.h>

int main (void)
{
	int matrix[3][3];
	for (int i=0;i<3;i++)
	{
		printf("please input 3 numbers in line%d\n",i+1);
		for (int j=0;j<3;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	int sum=0;
	for (int i=0;i<3;i++)
	{
		sum+=matrix[i][i];
	}
	printf("sum=%d\n",sum);
	return 0;
}
