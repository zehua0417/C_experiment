#include<stdio.h>
int main()
{
	int x;
	int IsPrime = 1;     //定义变量IsPrime并赋初值1 即x为素数
	scanf("%d", &x);
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			IsPrime = 0;
			break;
		}
	}
	if (IsPrime == 0)
		printf("%d is not a prime number", x);
	else
		printf("%d is a prime number", x);
	
	return 0;
}
