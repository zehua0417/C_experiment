/*
 * file name: char_linklist.c
 * author: lihuax>_
 * version; 1.0
 * description: 
 */

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

//定义链表节点
struct LinkNode
{
	char data;
	struct LinkNode *next;
};

void test();
//初始化链表
struct LinkNode *InitLinkList();
//遍历链表
void Foreach_LinkList(struct LinkNode *header);
//删除链表
void Del_LinkList(struct LinkNode *header);

int main (void)
{
	test();

	return 0;
}

void test()
{
      	//Foreach_LinkList(InitLinkList());
	struct LinkNode *header=InitLinkList();
	Foreach_LinkList(header);
	printf("\n**********************\n");
	Del_LinkList(header);
}

struct LinkNode *InitLinkList()
{
	char ch;
	//头节点
	struct LinkNode *header = malloc(sizeof(struct LinkNode));
	header->data = 0;
	header->next = NULL;
	//
	struct LinkNode *pRear = header;

	//初始化并输入信息
	printf("please input data\n");
	while((ch=getchar())!='\n')
	{
		if(isspace(ch))
			continue;
		//先创建新节点
		struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
		newnode ->data = ch;
		newnode ->next = NULL;

		//插入链表
		pRear->next = newnode;
		//更改尾部指针指向
		pRear = newnode;
	}
	return header;
}

void Foreach_LinkList(struct LinkNode *header)
{
	if(header==NULL)
	{
		return;
	}
	struct LinkNode *pCurrent = header->next;
	while(pCurrent!=NULL)
	{
		printf("%c ",pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void Del_LinkList(struct LinkNode *header)
{
	if(header==NULL)
		return;
	struct LinkNode *pCurrent = header;
	while(pCurrent!=NULL)
	{
		struct LinkNode *pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	printf("Linked list deleted\n");
}
