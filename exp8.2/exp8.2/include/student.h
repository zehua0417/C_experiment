#ifndef _STUDENT_H
#define _STUDENT_H

/**
 * @brief ��ʼ��ѧ����Ϣ����
 *
 * @return ѧ�������ͷ��ַ
 */
struct student* init_student();

/**
 * @brief ��ĩβ�����student�ڵ� 
 * @param head ѧ����Ϣ�����ͷ
 */
struct student* add_new_node(struct student* head);

/**
 * @brief ���ļ�����ѧ����Ϣ ֱ��EOF
 * @param head ѧ����Ϣ�����ͷ
 */
 //void load_student(struct student* head);

/**
 * @brief д��ѧ����Ϣ
 * @param head ѧ����Ϣ�����ͷ
 */
void upload_student(struct student* head);

 /**
  * @brief Ϊstudent�����ƽ����
  * @param stu_ptr ����ڵ��ַ
  */
void stu_average(struct student* stu_ptr);


//===============================================================//


/**
 * @brief ����������һ��������
 * @param head ѧ����Ϣ�����ͷ
 */
void input_stuinfor(struct student* head);

/**
 * @brief ��ӡѧ������������Ϣ
 * @param head ѧ����Ϣ�����ͷ
 */
void print_student(struct student* head);

#endif