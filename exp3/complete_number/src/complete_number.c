/*
 * file name: complete_number.c
 * suthor: lihuax
 * version :1.0
 * discription:求2-200以内的所有完全数，预测输出6、28、496.
 */

#include<stdio.h>

int main(void)
{
	int DscntFctr[100] = { 0 };          //因数数组
	int n = 0;                          //因数的数目
	int sum = 0;		                //因数之和

	for (int number = 2;number <= 2000;number++)
	{
		//找出因数，放入数组
		for (int i = 1; i < number; i++)
		{
			if (number % i == 0)
			{
				DscntFctr[n] = i;
				n++;
			}
		}

		//求因数的和，判断是否和与原数相同
		for (int i = 0;i <= n;i++)
		{
			sum += DscntFctr[i];
		}
		if (sum == number)
		{
			printf("%d是一个完全数\n", number);
		}

		//将数组、n、sum清零
		for (int i = 0; i <= n; i++)
		{
			DscntFctr[i] = 0;
		}
		n = 0;
		sum = 0;
	}

	return 0;
}
