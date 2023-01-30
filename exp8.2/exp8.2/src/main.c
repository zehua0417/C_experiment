#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"../include/student.h"
#define STU_FILE "D:\\vscode\\Project\\C project\\homework\\exp8.2\\exp8.2\\source\\stud.txt"


/**
 * @brief 学生链表节点
 */
struct student
{
	int id;
	char name[20];
	float chinese_score;
	float math_score;
	float english_score;
	float average_score;

	struct student* next;
};


void test(struct student* head)
{
	char cmd = 0;
	printf("      **************please select a commond*************\n");
	printf("      *a -------> type student infor\n");
	printf("      *b -------> print student infor\n");
	printf("      *c -------> upload student infor\n");
	printf("      **************************************************\n");
	cmd = getchar();
	getchar();

	switch (cmd)
	{
	case 'a':
		input_stuinfor(head);
		break;
	case 'b':
		print_student(head);
		break;
	case 'c':
		upload_student(head);
		break;
	}

}

int main(void)
{
	struct student* head = init_student();
	//print_student(head);
	printf("      **************************************************\n");
	printf("      *Welcome to student information management system*\n");
	printf("      **************************************************\n");
	while (1)
	{
		test(head);
	}

	return 0;
}

struct student* init_student()
{
	struct student* new_node = 
		(struct student*)malloc(sizeof(struct student));
	new_node->next = NULL;
	return new_node;
}

void stu_average(struct student* stu_ptr)
{
	float a = stu_ptr->chinese_score;
	float b = stu_ptr->math_score;
	float c = stu_ptr->english_score;
	stu_ptr->average_score = (float)1.0 * (a + b + c) / 3.0;

}

 void upload_student(struct student* head)
{
	 struct student* now = head->next;
	 FILE* fp;
	 fp = fopen(STU_FILE, "w+");
	 if (fp)
	 {
		 fprintf(fp, "ID \t name \t\t chinese \t math \t\t english \t average\n");
		 while (now)
		 {
			 fprintf(fp, "%d \t %s \t\t %3.1f \t\t %3.1f \t\t %3.1f \t\t %3.1f\n", (now->id), (now->name), (now->chinese_score),
				 (now->math_score), (now->english_score), (now->average_score));
			 now = now->next;
		 }
	 }
	 else
	 {
		 printf("Error, file not open!\n");
		 return;
	 }
	fclose(fp);
}

void input_stuinfor(struct student* head)
{
	struct student* new_node = add_new_node(head);
	printf("enter infor like:id name chinese_score math_score english_score\n");
	scanf("%d %19s %f %f %f",
		&(new_node->id), (new_node->name), &(new_node->chinese_score),
		&(new_node->math_score), &(new_node->english_score));
	getchar();
	stu_average(new_node);

}

void print_student(struct student* head)
{
	struct student* now = head->next;
	printf("ID \t name \t\t chinese \t math \t\t english \t average\n");
	while(now)
	{
		printf("%d \t %s \t\t %3.1f \t\t %3.1f \t\t %3.1f \t\t %3.1f\n", (now->id), (now->name), (now->chinese_score),
			(now->math_score), (now->english_score), (now->average_score));
		now = now->next;
	}

}

struct student* add_new_node(struct student* head)
{
	struct student* now = head;
	while (1)
	{
		if (now->next)
			now = now->next;
		else
			break;
	}

	struct student* new_node = 
		(struct student*)malloc(sizeof(struct student));
	new_node->next = NULL;
	now->next = new_node;

	return new_node;
}

