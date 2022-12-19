/*
 * file name: array_trans.c
 * author: lihuax
 * version: 1.0
 * discription: 
 */

#include<stdio.h>

void trans(int(*p)[3]); 
void out(int(*p)[3]); 

int main (void)
{
	int a[3][3];
	for (int i=0;i<3;i++)
	{
		printf("input numbers in line %d\n",i+1);
		for(int j=0;j<3;j++)
		{
			//printf("please input the number in row %d and col %d:\n",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("*******************************************\n");
	out(a);
	printf("*******************************************\n");
	trans(a);
	out(a);
	return 0;
}

void trans(int(*p)[3]) 
{
	int temp=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			temp=*(*(p+i)+j);
			*(*(p+i)+j)=*(*(p+j)+i);
			*(*(p+j)+i)=temp;
		}
	}
}

void out(int(*p)[3]) 
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
		printf("\n");
	}
}
