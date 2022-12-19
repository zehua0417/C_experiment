/*
 * file name:findnu.c
 * author:lihuax
 * version:1.0
 * discription:to find number in a group
*/
#include<stdio.h>

int findnu(int a[], int length, int nu,int cnt[]);
int main(void)
{
	int cnt[2]={0};
	int a[] = { 0,5,13,19,21,27,56,64,75,80,88,92,105,121,160 };
	int length = sizeof(a) / 4;
	printf("pleaseinput the number you are looking for:");
	int n;
	scanf("%d",&n);
	int flag1 = findnu(a, length, n,cnt);
	if (flag1 == 1)
		printf("number %d=%d\n",cnt[0],n);
	else printf("no %d\n",n);

}

int findnu(int a[], int length, int nu,int cnt[])
{
	int n, m, t;

	n = (length + 1) * 0.5;
	m = n;
	if (a[n - 1] == nu)
		{
			cnt[0]=n;
			return 1;
		}
	else if (a[n - 1] < nu)
		t = 1;
	else t = -1;

	while (m!=0)
	{
		n = n + (t * m * 0.5);
		if (a[n - 1] == nu)
		{	
			cnt[0]=n;
			return 1;
		}
		else if (a[n - 1] < nu) t = 1;
		else t = -1;
		m *= 0.5;
	}
}
