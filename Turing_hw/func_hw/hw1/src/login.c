/*
 * file name: login.c
 * author: lihuax
 * version: 1.0
 * discription: see in file "./login,txt"
 */
#include<stdio.h>
#include<string.h>
#include<conio.h>

int id[5] ={10001,10002,10003,10004};
char name[5][10]={"张三","李四","王五","赵六"};
char password[5][16]={"aaaaa","bbbbb","ccccc","ddddd"};
int uNum=4;

char* selectUserById(int uid);
void doselectById(int * p);
char* selectPassById(int uid);
void printSelectPassById(int * p);
void login(int *p);

int main (void)
{
	int id;
	int * p_id=&id;
	doselectById(p_id);
	login(p_id);
	//printSelectPassById(p_id);
}

char* selectUserById(int uid)
{
	//search and return 
	for(int i=0;i<uNum;i++)
	{
		int temp=id[i];
		if(uid==temp)
		{
			return name[i]; 
		}
	}	
	return NULL;
}
void doselectById(int *p)
{
	printf("please input your id ubtil ENTER\nID:");
	scanf("%d",p);
	int id_input=*p;
	printf("User Name: %s\n",selectUserById(id_input));

}

void printSelectPassById(int *p)
{
	printf("passwd: %s\n",selectPassById(*p));
}

char* selectPassById(int uid)
{
	//search and return 
	for(int i=0;i<uNum;i++)
	{
		int temp=id[i];
		if(uid==temp)
		{
			return password[i]; 
		}
	}	
	return NULL;
}

void login(int * p)
{
	char password_input[6];
	char ch;
	int cnt=0;
	printf("Please input your password\nPassword:");
	getchar();
	while((ch=_getch())!='\n')
	{
		password_input[cnt]=ch;
		cnt++;
	}
	strcpy(password[0],selectPassById(*p));
	if(!strcmp(password[0],password_input))
		printf("login successfully\n");
	else 
		printf("worry password\n");

}
