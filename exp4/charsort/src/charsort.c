/*
 * file name: charsort
 * author: lihuax
 * version: 1.0
 * discription: to sort a group of char(bubble sort and selection sort)
 */
#include<stdio.h>
#include"data_sort.h"

void bubble_sort(char* p,int n,int * cntgro);
void selection_sort(char* p,int n,int* cntgro);
void out_data(char data[],int n);

int main (void)
{
	int cntgro[5]={0};//记录比较次数与交换次数

	char gro1[]={'q','w','e','r','t','y','u','M','o','p','e'};//原数组1
	printf("bubble sort:\n");
	data_sort(gro1,11,bubble_sort,out_data,cntgro);
	printf("比较次数:%d,交换次数:%d\n",cntgro[0],cntgro[1]);

	char gro2[]={'q','w','e','r','t','y','u','M','o','p','e'};//原数组2
	printf("selection sort:\n");
	data_sort(gro2,11,selection_sort,out_data,cntgro);
	printf("比较次数:%d,交换次数:%d\n",cntgro[2],cntgro[3]);

	return 0;
}

void selection_sort(char* p, int n,int* cntgro)
{
	int i, j;
	for (i = 0;i < n - 1;i++)
	{
		int pos = i;
		for (j = i + 1;j < n;j++)
		{
			(*(cntgro+2))++;
			if (*(p + j) < *(p + pos))
			{
				pos = j;
			(*(cntgro+3))++;
			}
		}
		if (pos != i)
		{
			int temp;
			temp = *(p + pos);
			*(p + pos) = *(p + i);
			*(p + i) = temp;
		}
		out_data(p,n);
	}
}

void bubble_sort(char* p, int n,int* cntgro)
{
	int i, j;
	for (i = 0;i < n - 1;i++)
	{
		for (j = n - 1;j > i;j--)
		{
			(*cntgro)++;
			if (*(p + j) < *(p + j - 1))
			{
				int temp;
				temp=*(p + j);
				*(p+j)=* (p + j - 1);
				*(p + j - 1) = temp;
				(*(cntgro+1))++;
			}
			out_data( p, n);
		}
	}
}
void out_data(char data[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%c",data[i]);
	}
	printf("\n");
}
