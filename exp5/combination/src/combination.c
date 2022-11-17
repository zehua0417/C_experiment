/*
 * file name:combination.c
 * author: lihuax
 * version:1.0
 * discription: to calc combination number
 */

#include<stdio.h>

int facterials(int n);

int main (void)
{
	int n,r;
	float c;
	printf("please input n & r: ");
	scanf("%d%d",&n,&r);
	if(n<r) printf("Error!!! n should greater than r!!!\n");
	else 
	{
		c=(facterials(n))/(facterials(r)*facterials(n-r))*1.0;
			printf("C(r,n)=%.2f\n",c);
	}
	return 0;
}

int facterials(int n)
{
	int result=1;
	for(int i=2;i<=n;i++)
	{
		result*=i;
	}
	return result;
}
