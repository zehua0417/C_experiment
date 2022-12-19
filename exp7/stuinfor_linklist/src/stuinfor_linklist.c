/****************************************************************
 * file name: stuinfor_linklist.c
 * author: lihuax
 * version: 1.0
 * description: 创建一个 单向链表 来记录学生信息，人数3--5人；链表结点为结构变量，结构的要求如下：
 *****************************************************************
 *struct stu_info
 *{
 *         char stu_num[10];  //学号
 *         char stu_name[8];  //姓名
 *         char stu_sex[2];    //性别
 *         int stu_score;    //成绩
 *         struct stu_info *next;
 * };
 *****************************************************************
 * *************************程序设计要求**************************
 *（1）插入新的学生信息(插入节点的位置可任意指定）
 *（2）删除指定的学生信息
 *（3）根据学号查询并显示查询到的学生信息
 *（4）以上三项任务分别自定义函数实现，执行后显示执行结果
 *（5）程序运行后要求可以循环执行前三项操作，直到选择退出时结束程序
 ******************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct stu_infor
{
	char stu_num[10];  //学号
	char stu_name[10];  //姓名
	char stu_sex[8];    //性别
	int stu_score;    //成绩
	struct stu_infor *next;
};

void test();
//初始化链表
struct stu_infor *InitStuInfor();
//插入数据
//Insert
//删除指定信息
//void DelByNum(struct stu_infor *header);
//根据学号查询信息
//void SearchByNum(struct stu_infor *header);

int main (void)
{
	test();
	return 0;
}

void test()
{
	//struct stu_infor *header =
	       	InitStuInfor();
//	DelByNum(header);
}	

struct stu_infor *InitStuInfor()
{
	struct stu_infor *header = malloc(sizeof(struct stu_infor));
	header -> next = NULL;
	struct stu_infor *pRear = header;

	char ch=0;
	printf("请依次输入学生的学号、姓名和性别，请用逗号隔开\n");
	while((ch=getchar())!='')
	{
		//printf("请依次输入学生的学号、姓名和性别，请用逗号隔开");
		struct stu_infor *new_stuinfor = malloc(sizeof(struct stu_infor));
		while (ch!='\n')
		{
			for(int i=0;1;i++)
			{
				if(ispunct(ch))
					break;
				(new_stuinfor -> stu_num[i])=ch;
			}
			for(int i=0;1;i++)
			{
				if(ispunct(ch))
					break;
				new_stuinfor -> stu_name[i]=ch;
			}
			for(int i=0;1;i++)
			{
				if(ispunct(ch))
					break;
				new_stuinfor -> stu_sex[i]=ch;

			}
			
		}
		printf("please input the student's score:");
		scanf("%d",&new_stuinfor -> stu_score);
		new_stuinfor -> next = NULL;
		pRear->next = new_stuinfor;
		pRear = new_stuinfor;
	}
	return header;
}
