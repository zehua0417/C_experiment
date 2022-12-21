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
 *         char stu_sex[2];   //性别
 *         int stu_score;     //成绩
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
#include<string.h>
#define NUM_SIZE 10
#define NAME_SIZE 8
#define GENDER_SIZE 7

struct stu_infor
{
    char stu_num[NUM_SIZE];       //学号
    char stu_name[NAME_SIZE];     //姓名
    char stu_gender[GENDER_SIZE]; //性别
    int stu_score;                //成绩
    struct stu_infor *next;
};

void test();
char *s_gets(char *st,int n);
//输入数据并初始化链表
struct stu_infor *InitStuinfor_linklist();
//遍历链表
void Foreach_linklist(struct stu_infor *header);
//根据stu_num删除学生信息
void DelByNum_stuinfor_linklist(struct stu_infor *header, char *dev_num);
/**
 * @brief    根据学号查询学生信息
 * @param header    链表表头
 * @param search_num    查询的学号
 * 
 * @return   返回所查询学号信息的前一个节点的地址
 */
struct stu_infor *SearchById_linklist(struct stu_infor *header, char *search_num);

int main (void)
{
    test();
    return 0;
}

void test()
{
    struct stu_infor *header = InitStuinfor_linklist();
    Foreach_linklist(header);
    char del_num[NUM_SIZE] ={0};
    printf("which student do you want to del?\nID:");
    s_gets(del_num,NUM_SIZE);
    DelByNum_stuinfor_linklist(header, del_num);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    Foreach_linklist(header);
    printf("====================================\n");
    printf("input id to search student\nID:");
    char search_num[NUM_SIZE]={0};
    s_gets(search_num,NUM_SIZE);
    Foreach_linklist(SearchById_linklist(header, search_num)->next);
}

char *s_gets(char *st,int n)
{
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

struct stu_infor *InitStuinfor_linklist()
{
    struct stu_infor *header = (struct stu_infor*) malloc(sizeof(struct stu_infor));
    header -> next = NULL;
    struct stu_infor *pRear = header;
    char input_id[NUM_SIZE] = {0};
        
    printf("please input ID\n");
    while(s_gets(input_id,NUM_SIZE) != NULL &&input_id[0] != '\0')
    {
        struct stu_infor *newinfor = (struct stu_infor *) malloc(sizeof(struct stu_infor));
        if(header -> next == NULL)
            header -> next = newinfor;
        else
            pRear -> next = newinfor;
        newinfor -> next = NULL;
        strcpy(newinfor -> stu_num, input_id);
        printf("please input name\n");
        scanf("%s",&newinfor -> stu_name);
        printf("please input gender\n");
        scanf("%s",&newinfor -> stu_gender);
        printf("please inout score\n");
        scanf("%d",&newinfor -> stu_score);
        while(getchar()!='\n')
            continue;
        printf("please input next ID\n");
        pRear = newinfor;
    }
    return header;
}

void Foreach_linklist(struct stu_infor *header)
{
    if(header == NULL)
	{
		return;
	}
	struct stu_infor *pCurrent = (header -> next);
	while(pCurrent!=NULL)
	{
		printf("ID:%s\n",pCurrent->stu_num);
		printf("name:%s\n",pCurrent->stu_name);
		printf("gender:%s\n",pCurrent->stu_gender);
		printf("score:%d\n************************\n",pCurrent->stu_score);
		pCurrent = pCurrent->next;
	}
}

void DelByNum_stuinfor_linklist(struct stu_infor *header, char *del_num)
{
    struct stu_infor *pPrev = SearchById_linklist(header, del_num);
    struct stu_infor *pCurrent = (struct stu_infor*)pPrev->next;
    if(pCurrent == NULL)
    {
        return;
    }
    //删除操作:重组,释放
    pPrev -> next = pCurrent -> next;
    free (pCurrent);
    pCurrent = NULL;
}

struct stu_infor *SearchById_linklist(struct stu_infor *header, char *search_num)
{
    if (header == NULL)
        return NULL;
    //两个辅助指针
    struct stu_infor *pPrev = header;
    struct stu_infor *pCurrent = header-> next;

    while (pCurrent != NULL)
    {
        //判断
        if(pCurrent -> stu_num == search_num)
        {
            return pPrev;
        }
        //移动两个辅助指针的值
        pPrev = pCurrent;
        pCurrent = pCurrent -> next;
    }
    return NULL;
}