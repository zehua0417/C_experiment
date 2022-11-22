/*
 * file name: frogjumping_1.c
 * author: lihuax
 * version: 1.1
 * discription:to solve the problem of frogjumping
*/

#include<stdio.h>
int jump(int i,int n,int a[n]);
int main (void)
{
	int n;
	printf("please input your number\n");
	scanf("%d",&n);
	int a[100]={0};
	a[0]=1;
	a[1]=2;
	printf("%d",jump(2,10,a));
	return 0;
}
int jump(int i,int n,int a[n])
{
	if(i<n)
	{
		a[i]=a[i-1]+a[i-2];
		i++;
		jump(i,n,a);
	}
	else
	{
		return a[n-1];
	}
}
