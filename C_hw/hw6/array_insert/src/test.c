#include<stdio.h>
int main (void)
{
	int num[100];
	char ch;
	int i=0,cnt=0;
	do
	{
		cnt+=scanf("%d",&num[i++]);
	}while((ch=getchar())!='\n');
	printf("%d\n",cnt);
	return 0;
}
