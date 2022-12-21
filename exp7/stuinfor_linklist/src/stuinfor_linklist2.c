/****************************************************************
 * file name: stuinfor_linklist.c
 * author: lihuax
 * version: 2.0
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
#include<ctype.h>
#include<stdlib.h>
#define NUM_SIZE 10
#define NAME_SIZE 8
#define GENDER_SIZE 2;

struct stu_infor
{
    char stu_num[NUM_SIZE];       //
    char stu_name[NAME_SIZE];     //
    char stu_gender[GENDER_SIZE]; //
    struct stu_infor *next;
};

int main (void)
{
    test();
    return 0;
}

void test();
char *s_gets();
//
struct stu_infor *InitStuinfor();

void test()
{
    struct stuinfor *header = InitStuinfor();
}

char *s_gets(char *st,int n){
	char *ret_val;
	int i = 0;
	
	ret_val = fgets(st,n,stdin);
	if(ret_val){//与*ret_val!='\0'相同，当ret_val指向空字符时，ret_val的值是0，即测试条件为假，while循环结束
            while(st[i] != '\n' && st[i] != '\0')
                i++;
            if(st[i] == '\n')
                st[i] = '\0';
            else  //如果检测到结束标志'\0'，则读取但不储存输入，包括\n。  
              //丢弃的目的，不让多出来的留在缓冲区，保证了读取语句与键盘输入同步   
                while(getchar() != '\n')
            continue;
        }
	return ret_val;
}

struct stu_infor *InitStuinfor()
{
    struct stu_infor *header = NULL;
    struct stu_header *pRear = header;
    char ch = 0;

    printf("please input ID\n");
    while()
}