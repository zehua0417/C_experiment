/*
 * file name :frogjumping_3.c
 * author: lihuax
 * version:1.3
 * discription:由于之前那个递归调用算法没有逼格，升级一下
 */

#include<stdio.h>
int fibonacci(int n);

int main (void)
{
	printf("please input n:");
	int n;
	scanf("%d",&n);
	printf("%d\n",fibonacci(n+1));

	return 0;
}

int fibonacci(int n)
{
	if(n<=2)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}
