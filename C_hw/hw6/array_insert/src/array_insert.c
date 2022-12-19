/*
 * file name: array_insert.c
 * author: lihuax
 * version: 1.0
 * discription: insert a number in an array according to its old sorting methord
 * P.S.use gcc(-std=c99) to compile! Cus it has VLA! Do not use VS!
*/
#include<stdio.h>
#include<memory.h>
void sort(int n,int a[n]);//选择排序
void out_gro(int n,int a[]);

int main (void)
{
	//定义原数组，并排序
	int a[]={99,32,65,43,77,91,27,3,7,58};
	int na=sizeof(a)/4;
	sort(na,a);
	printf("old array:");
	out_gro(na,a);
	
	//将新n2个数字输入数组in[100]
	int in[100];
	char ch;
	int cnt=0,ni=0;
	printf("please inset numbers untill enter\n");
	do
	{
		ni+=scanf("%d",&in[cnt++]);
	}while((ch=getchar())!='\n');

	//将原数字和新数字插入新数组b[na+nb],再排序输出
	int b[100000]={100};
	memcpy(b,a,4*na);
	memcpy((b+na),in,4*ni);
	sort(na+ni,b);
	printf("new array:");
	out_gro(na+ni,b);

	return 0;
}

void sort(int n,int a[n])
{
	for(int i=0;i<n-1;i++)
	{
		int pos =i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[pos])
			{
				pos=j;
			}
		}
		if (pos!=i)
		{
			int temp;
			temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
		}
	}
}

void out_gro(int n,int a[])
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
