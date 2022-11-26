/*
 * file name: light_on.c
 * author: lihuax
 * version:1.0
 * discription: to solve the problem of truning on light
*/

#include<stdio.h>
#define ON 1
#define OFF 0
int main (void)
{
	int n,k;
	printf("please input n&k\n");
	scanf("%d%d",&n,&k);
	int light[100]={OFF};
	for(int i=0;i<n;i++)
	{
		for(int j=1;((i+1)*j)<=k;j++)
		{
			if(light[((i+1)*j)-1]==OFF) 
				light[((i+1)*j)-1]=ON;
			else light[((i+1)*j)-1]=OFF;
		}
	}
	for(int i=0;i<k;i++)
	{
		printf("%d ",light[i]);
	}
	return 0;
}
