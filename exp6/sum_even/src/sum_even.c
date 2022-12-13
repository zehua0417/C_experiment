/*
 * file name: sum_even.c
 * author: lihuax
 * version: 1.0
 * description: calc the sum of even numbers
 */

#include<stdio.h>

int evensum(int a[6]);

int main (void)
{
	int a[6];
	printf("input 5 numbers:");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("sum of even numbers = %d",evensum(a));
	return 0;
}

int evensum(int a[6])
{
	int result=0;
	for(int i=0;i<5;i++)
	{
		if(a[i]%2==0)
		{
			result+=a[i];
		}
	}
	return result;
}
