#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main(void)
{
	int number, ask, times = 1;
	long t;
	srand((unsigned)time(NULL));
	number = rand() % 100;
	printf("请输入您猜的数字（1~100)：");
	scanf_s("%d", &ask);
	t = time(NULL);

	while (ask != number)
	{
		if (ask > number)printf(" 您猜的数字大了。请重输入：");
		if (ask < number)printf(" 您猜的数字小了。请重输入：");
		scanf_s("%d", &ask);
		times++;
	}
	t = time(NULL) - t;
	printf("恭喜您！回答正确。您猜了%d次，用时%d\n秒.", times, t);

	return 0;
}