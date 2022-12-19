#include <stdio.h>
int common_multiple(int m,int n);
int common_divisor(int m,int n);
int main()
{
	int m,n;
	printf("pleaseinput:");
	scanf("%d%d",&m,&n);
	printf("%d ",common_multiple(m,n));
	printf("%d ",common_divisor(m,n)); 
	return 0;
} 

int common_divisor(int m,int n)
{
	int t,a,b;
	if(m<n){
      t=m;m=n;n=t;
	}
	a=m;
	b=n;
	while(b!=0){
	   t=a%b;
	   a=b;
	   b=t;	
	}
	return a;
}

int common_multiple(int m,int n)
{
	int a=common_divisor(m,n);
	int re;
	re=m*n/a; 
	return re;
} 



