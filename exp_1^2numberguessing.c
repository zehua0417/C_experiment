#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main(void)
{
	int number, ask, times = 1;
	long t;
	srand((unsigned)time(NULL));
	number = rand() % 100;
	printf("���������µ����֣�1~100)��");
	scanf_s("%d", &ask);
	t = time(NULL);

	while (ask != number)
	{
		if (ask > number)printf(" ���µ����ִ��ˡ��������룺");
		if (ask < number)printf(" ���µ�����С�ˡ��������룺");
		scanf_s("%d", &ask);
		times++;
	}
	t = time(NULL) - t;
	printf("��ϲ�����ش���ȷ��������%d�Σ���ʱ%d\n��.", times, t);

	return 0;
}