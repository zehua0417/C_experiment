/*
 * file name: reverse_storage.c
 * author: lihuax
 * version:1.0
 * discription:to restorage in a reverse way.
 */
#include<stdio.h>

int main (void)
{
	int a[6]={1,2,3,4,5,6};
	int temp;
	int n=sizeof(a)/4;
	for (int i=0;i<(n/2);i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
