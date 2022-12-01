/*
 * file name:findnu.c
 * author:lihuax
 * version:1.0
 * discription:to find number in a group
 */
#include<stdio.h>
int findnu(int a[], int length, int nu);
int main(void)
{
	int a[] = { 0,5,13,19,21,27,56,64,75,80,88,92,105,121,160 };
	int length = sizeof(a) / 4;
	int flag1 = findnu(a, length, 21);
	int flag2 = findnu(a, length, 85);
	if (flag1 == 1)
		printf("21\n");
	else printf("no 21\n");
	if (flag2 == 1)
		printf("85\n");
	else printf("no 85\n");

}

int findnu(int a[], int length, int nu)
{
	int n, m, t;

	n = (length + 1) * 0.5;
	m = n;
	if (a[n - 1] == nu)
		return 1;
	else if (a[n - 1] < nu)
		t = 1;
	else t = -1;

	while (m!=0)
	{
		n = n + (t * m * 0.5);
		if (a[n - 1] == nu) return 1;
		else if (a[n - 1] < nu) t = 1;
		else t = -1;
		m *= 0.5;
	}
}
