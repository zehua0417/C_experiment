/*
 * file name: demical_conversion.c
 * author: lihuax
 * version: 1.0
 * discription: convert hex to decimal
*/

#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
   char a[N];
   int i=0,re=0;
   printf("Enter a string:");
   fgets(a,N,stdin);
   printf("New string:");
   while(a[i])       //当读取到输入的最后一个字符之后，读取到0，跳出循环
   {
       if(a[i]>='0'&&a[i]<='9'){
        printf("%c",a[i]);
        re=re*16+a[i]-'0';
       }          //a[i]-'0'利用ASCII码值差值求该位的值
       else if(a[i]>='a'&&a[i]<='f'){
        printf("%c",a[i]);
        re=re*16+a[i]+10-'a';
       }          //a[i]-'a'利用ASCII码值差值求该位的值
       else if(a[i]>='A'&&a[i]<='F'){
        printf("%c",a[i]);
        re=re*16+a[i]+10-'A';
       }          //a[i]-'A'利用ASCII码值差值求该位的值
       i++;       //从最高位依次往低一位遍历
 
   }
   printf("\nnumber=%d\n",re);
   return 0;
}
 

