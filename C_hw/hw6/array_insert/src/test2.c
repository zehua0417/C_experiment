#include<stdio.h>
#include<memory.h>
int main (void)
{
	char a1[5]="asdf";
	char a2[100];
	memcpy(a2, a1, sizeof a1);
	printf("%s\n", a2);
	char a3[5]="qwer";
	memcpy((a2+4), a3, sizeof a3);
	printf("%s\n", a2);
	
}
