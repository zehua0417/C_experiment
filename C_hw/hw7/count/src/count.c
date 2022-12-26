#include<stdio.h>
#include<ctype.h>
int alpha,num,space,other;
void find(char *str);

int main (void)
{

	alpha=num=space=other=0;
	char str[100]={0};
	char ch;
	int i =0;
	while((ch=getchar())!='\n')
	{
		str[i++]=ch;
	}
		find(str);
	printf("number:%d\nalpha:%d\nspace:%d\nother:%d\n",num,alpha,space,other);
}
void find(char *str)
{
	for(int i=0;str[i]!=0;i++)
	{
		if(isalpha(str[i]))
			alpha++;
		else if(isspace(str[i]))
			space++;
		else if(isdigit(str[i]))
			num++;
		else
			other++;
	}
}
