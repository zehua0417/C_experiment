#include<stdio.h>
#include<ctype.h>
int alpha,num,space,other;
void find();

int main (void)
{
	find();
	printf("number:%d\nalpha:%d\nspace:%d\nother:%d\n",num,alpha,space,other);
}
void find()
{
	alpha=num=space=other=0;
	char ch;
	while((ch=getchar())!='\n')
	{
		if(isalpha(ch))
			alpha++;
		else if(isspace(ch))
			space++;
		else if(isdigit(ch))
			num++;
		else
			other++;
	}

}
