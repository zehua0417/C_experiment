/*
 * file name: long_letter.c
 * author: lihuax
 * version:1.0
 * description: to find the longest word in a sentence
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct returnvalue 
{
	//int ln;//word numbers in the sentence
	int lgp;//position of the longest word 
	int lgn;//letter number of the longest word
};

struct returnvalue fword(char* stc);

int main (void)
{
	printf("please input a sentence:\n");
	char stc[100];
	char ch;
	int cnt=0;
	while((ch=getchar())!='\n')
	{
		stc[cnt++]=ch;
	}

	struct returnvalue result=fword(stc);
	printf("最长单词在第%d字符处，长度为%d\n",result.lgp,result.lgn);
	return 0;
}

struct returnvalue fword(char* stc)
{
	char ch;
	int n=strlen(stc);
	int length[100]={0};

	int j=0;
	for(int i=0;i<n;i++)
	{
		ch=*(stc+i);
		if(isalpha(ch))
		{
			length[j]++;	
		}
		if(isspace(ch))
		{
			j++;
		}
	}

	int lgn=0,lgp=0,temp=0;
	for(int i=0;i<=j;i++)
	{
		temp+=(1+length[i]);
		if(length[i]>lgn)
		{
			lgn=length[i];
			lgp=temp-length[i];
		}
	}
		struct returnvalue v={lgp,lgn};
		return v;
}

