/*0
 * file name: programe_rewriting.c
 * author: lihuax
 * version: 1.0
 * discription: input n, out put all the even facterials between 0 to n
 */

#include<stdio.h>
int even_facterials_sum(int n);

int main (void)
{
	int n,sum;
	printf("please input n\n");
	scanf("%d",&n);
	sum=even_facterials_sum(n);
	printf("sum=%d\n",sum);
	return 0;
}

int even_facterials_sum(int n)
{
	int i,j,k,sum=0;
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            for(j=1,k=1;j<=i;j++)
            {
                k=k*j;
            }
            sum+=k;
        }
    }
return sum;
}

