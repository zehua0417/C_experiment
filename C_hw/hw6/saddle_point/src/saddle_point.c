/*
 * file name: saddle_point.c
 * author: lihuax
 * version: 1.0
 * discription: to find saddle_point
 */
#include<stdio.h>
int main (void)
{
	int gro[100][100];
	int n=0;

	//input array
	char ch;
	for(int i=0;i<100;i++)
	{	
		printf("请输入第%d行数字直至回车\n",i+1);
		int j=0,cnt=0;
		/*while((ch=getchar())!='\n')
		{
			cnt+=scanf("%d",&gro[i][j]);
			j++;
		}*/
		do
		{
			cnt+=scanf("%d",&gro[i][j++]);
		}while((ch=getchar())!='\n');
		if(i==cnt-1)
		{
			n=cnt;
			break;
		}
	}
	
	//find saddle point
	for(int i=0;i<n;i++)
	{
		int rows=0,cols=0;
		int temp=0;
		for(int j=0;j<n;j++)
		{
			if(gro[i][j]>temp)
			{
				temp=gro[i][j];
				rows=i;
				cols=j;
			}
		}

		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(gro[rows][cols]>gro[j][cols])
				flag+=1;
		}
		if(flag==0)
		{
			printf("第%d行第%d个数%d为鞍点数\n",rows+1,cols+1,gro[rows][cols]);
		}
		else printf("第%d行没有鞍点数\n",rows+1);
	}

	return 0;
}

