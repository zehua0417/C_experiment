/*
 * file name: find_count_nu.c
 * author:lihuax
 * version:1.0
 * discription:找到并输出具有以下特性的十进制的千位数及统计个数：
 * 具体特性：该数字十进制时四位数字的和等于该数字以16进制表示时的四位数字的和，同时也等于这个数以12进制表示时的四位数字的和。如2991的（十进制）四位数字之和是21，对应的十二进制是1893，四位数字之和是21，对应的十六进制是BAF16，四位数字之和为0+11+10+15=36，因此2991不符合要求。2992符合题目要求的特性，因此在输出的结果中。
 */
#include<stdio.h>
#include<math.h>

void dec_trans(int dec,int base,int n,char transed[n]);
int find(int dec, int base,int n,char transed[n]);
int main (void)
{
	char hex[4]={0},duo[4]={0};
	int dec=1000,cnt=0;

	while(dec<10000)
	{
		int flag=0;
		if((flag=find(dec,12,4,duo))==1&&(flag=find(dec,16,4,hex))==1) 
		{
			printf("%d\t",dec);
			cnt++;
		}
		dec++;
	}
	printf("tatal:%d\n",cnt);

	return 0;
}

void dec_trans(int dec,int base,int n,char transed[n])
{
	//trans dec into base
	int t = 0,nu=0;
	for (int i = dec;i > 0;i /= base)
	{
		nu=(i % base);
		if(nu<=9)
		{
			transed[t]=nu;
		}
		else
		{
			switch(nu)
			{
				case 10:transed[t]='A';
					break;
				case 11:transed[t]='B';
					break;
				case 12:transed[t]='C';
					break;
				case 13:transed[t]='D';
					break;
				case 14:transed[t]='E';
					break;
				case 15:transed[t]='F';
					break;
			}
		}
		t++;
	}
}

int find(int dec, int base,int n,char transed[n])
{
	dec_trans(dec,base,n,transed);

	//sum of dec digits
	int sum_dec=0;
	while(dec>0)
	{
		sum_dec+=(dec%10);
		dec/=10;
	}

	//sum of transed nu
	int sum_tn=0;
	for(int i=0;i<4;i++)
	{
		if(transed[i]<10) sum_tn+=transed[i];
		else
		{
			switch(transed[i])
			{
				case'A':sum_tn+=10;
					break;
				case'B':sum_tn+=11;
					break;
				case'C':sum_tn+=12;
					break;
				case'D':sum_tn+=13;
					break;
				case'E':sum_tn+=14;
					break;
				case'F':sum_tn+=15;
					break;
			}
		}
	}

	//judge
	if(sum_dec==sum_tn) return 1;
	else return 0;

}
