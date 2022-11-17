/*
 * file name: frogjumping.c
 * author: lihuax
 * version: 1.0
 * discription: to calculate the methods of frog jumping problem
 */

#include<stdio.h>
#include<math.h>
int jump();
int main (void)
{
	int a[100][100]={0};
	int n,w=0;
	printf("input\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int j=0;
		for(int t=0;t<=(pow(2,i)-2);t+=2)
		{
			a[i][t]=a[i-1][j]+1;
			a[i][t+1]=a[i-1][j]+2;
			if(a[i][t]==n)w++;
			if(a[i][t+1]==n)w++;
			j++;
		}
	}
	printf("%d\n",w);
	return 0;
}
