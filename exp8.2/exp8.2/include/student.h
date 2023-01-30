#ifndef _STUDENT_H
#define _STUDENT_H

/**
 * @brief 初始化学生信息链表
 *
 * @return 学生链表表头地址
 */
struct student* init_student();

/**
 * @brief 在末尾添加新student节点 
 * @param head 学生信息链表表头
 */
struct student* add_new_node(struct student* head);

/**
 * @brief 从文件读入学生信息 直到EOF
 * @param head 学生信息链表表头
 */
 //void load_student(struct student* head);

/**
 * @brief 写入学生信息
 * @param head 学生信息链表表头
 */
void upload_student(struct student* head);

 /**
  * @brief 为student类计算平均数
  * @param stu_ptr 链表节点地址
  */
void stu_average(struct student* stu_ptr);


//===============================================================//


/**
 * @brief 根据链表逐一输入数据
 * @param head 学生信息链表表头
 */
void input_stuinfor(struct student* head);

/**
 * @brief 打印学生链表所有信息
 * @param head 学生信息链表表头
 */
void print_student(struct student* head);

#endif