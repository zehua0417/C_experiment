/*
 * file name: data_sort.c
 * author: lilhuax
 * version: 1.0
 */

void data_sort(char data[],int n,
		void(*p)(char data[],int n,int * cntgro),
		void(*out)(char data[],int n),
		int* cntgro)
{
	p(data,n,cntgro);
	out(data,n);
}
