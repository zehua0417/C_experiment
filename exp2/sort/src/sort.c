/* 
* 文件名：PointerAndFx.c
* 描述：函数指针和指针函数的案例
* 作者：lihuax
* 依赖：sort.h
* 利用回调函数调用不同的排序算法完成对数组元素的排序
* 使用冒泡和选择两种排序算法
* 利用回调函数机制来选择上述两种算法对数组元素进行排序并输出
* 利用函数指针去调用两个实现排序算法的回调函数，将结果再通过回调函数输出
*/
#include <stdio.h>
#include "data_sort.h"

void bubble_sort(int* p, int n);    //冒泡排序
void selection_sort(int* p, int n); //选择排序
void out_data(int data[], int n);   //输出

int main(void)
{
	int data1[] = { 4,3,5,6,1 };
	int n = sizeof(data1) / 4;
	data_sort(data1, n, bubble_sort, out_data);

	int data2[] = { 6,3,8,99,2,1 };
	n = sizeof(data2) / 4;
	data_sort(data2, n, selection_sort, out_data);

	return 0;
}

void out_data(int data[], int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

void bubble_sort(int* p, int n)
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

void selection_sort(int* p, int n)
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
