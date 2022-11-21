/*
 * file name: frogjumping_2.c
 * author: lihuax
 * version: 1.2
 * discription: to solve the problem of frogjumping
*/

#include<stdio.h>
int jump (int n,int a[n]);
int main (void)
{
	int n;
	printf("please input n:");
	scanf("%d",&n);
	int a[n];
	a[0]=1;
	a[1]=2;
	printf("%d\n",jump(n,a));

	return 0;
}
int jump (int n,int a[n])
{
	for(int i=2;i<n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
	return a[n-1];
}
