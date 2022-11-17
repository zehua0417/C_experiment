/*
 * file name: charsort
 * author: lihuax
 * version: 1.0
 * discription: to sort a group of char(bubble sort and selection sort)
 */
#include<stdio.h>
#include"data_sort.h"

void bubble_sort(char* p,int n);
void selection_sort(char* p,int n);
void out_data(char data[],int n);

int main (void)
{
	char gro[]={'q','w','e','r','t','y','u','M','o','p','e'};
	data_sort(gro,11,bubble_sort,out_data);
	data_sort(gro,11,selection_sort,out_data);

	return 0;
}

void selection_sort(char* p, int n)
{
	int i, j;
	for (i = 0;i < n - 1;i++)
	{
		int pos = i;
		for (j = i + 1;j < n;j++)
		{
			if (*(p + j) < *(p + pos))
			{
				pos = j;
			}
		}
		if (pos != i)
		{
			int temp;
			temp = *(p + pos);
			*(p + pos) = *(p + i);
			*(p + i) = temp;
		}
	}
}

void bubble_sort(char* p, int n)
{
	int i, j;
	for (i = 0;i < n - 1;i++)
	{
		for (j = n - 1;j > i;j--)
		{
			if (*(p + j) < *(p + j - 1))
			{
				int temp;
				temp=*(p + j);
				*(p+j)=* (p + j - 1);
				*(p + j - 1) = temp;
			}
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
