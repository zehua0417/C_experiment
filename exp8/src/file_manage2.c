
#include <stdio.h>
#include <stdlib.h>

int compare(char *s1, char *s2)
{
    if (*s1 != *s2)
    {
        return 0;
    }
    while (*(s1++))
    {
        if (*(++s2) != *s1)
        {
            return 0;
        }
    }
    if (*s2)
    {
        return 0;
    }
    return 1;
}

struct stu_info
{
    char stu_num[10]; // 学号
    char stu_name[8]; //
    int chi_score;    //
    int math_score;   //
    int eng_score;    //
    struct stu_info *next;
};

struct stu_info *init_stu_info()
{
    struct stu_info *new_node = (struct stu_info *)malloc(sizeof(struct stu_info));
    new_node->next = NULL;
    return new_node;
}

void add_new_stu(struct stu_info **head, struct stu_info **new_node, int pos)
{
    struct stu_info *now;
    now = *head;
    if (pos < 0)
    {
        pos = 0;
    }
    for (int i = 1; i < pos; i++)
    {
        if (now->next)
        {
            now = now->next;
        }
    }
    if (pos)
    {
        (*new_node)->next = now->next;
        now->next = *new_node;
    }
    else
    {
        (*new_node)->next = *head;
        *head = *new_node;
    }
}

void del_stu_info_bypos(struct stu_info **head, int pos)
{
    struct stu_info *now;
    now = *head;
    if (!now)
    {
        return;
    }
    if (pos < 0)
    {
        pos = 0;
    }
    for (int i = 1; i < pos; i++)
    {
        if (now->next)
        {
            now = now->next;
        }
    }
    if (pos)
    {
        struct stu_info *aim_node = now->next;
        if (now->next)
        {
            now->next = aim_node->next;
        }
        else
        {
            now->next = NULL;
        }
        free(aim_node);
    }
    else
    {
        *head = now->next;
        free(now);
    }
}

void del_stu_info_bynum(struct stu_info **head, char *num)
{
    struct stu_info *now = *head;
    if (!now)
    {
        return;
    }
    if (compare((*head)->stu_num, num))
    {
        *head = now->next;
        free(now);
    }
    else
    {
        for (; now->next; now = now->next)
        {
            if (compare(now->next->stu_num, num))
            {
                struct stu_info *aim_node = now->next;
                now->next = aim_node->next;
                free(aim_node);
                break;
            }
        }
    }
}

void search(struct stu_info *head)
{
    char stu_num[10];
    scanf("%9s", &stu_num);
    getchar();

    struct stu_info *now;
    now = head;
    int yes = 0;
    while (now)
    {
        compare(now->stu_num, stu_num);
        if (compare(now->stu_num, stu_num))
        {
            printf("%s %s %d %d %d\n", now->stu_num, now->stu_name, now->chi_score, now->math_score, now->eng_score);
            yes++;
        }
        now = now->next;
    }
    if (yes)
    {
        if (yes != 1)
        {
            printf("find more than one student\n");
        }
    }
    else
    {
        printf("not such student\n");
    }
}

void print_list(struct stu_info *head)
{
    struct stu_info *now;
    now = head;
    while (now)
    {
        printf("%s %s %d %d %d\n", now->stu_num, now->stu_name, now->chi_score, now->math_score, now->eng_score);
        now = now->next;
    }
}

struct stu_info *get_input()
{
    struct stu_info *now = init_stu_info();
    scanf("%9s %7s %10d %10d %10d", &(now->stu_num), &(now->stu_name), &(now->chi_score), &(now->math_score), &(now->eng_score));
    getchar();
    return now;
}

void SaveData(struct stu_info *head)
{
    struct stu_info *ptr = head->next;
    FILE *fp = fopen("./stud.txt", "r+");
    if (fp == NULL)
    {
        printf("ERROR!!!\n");
        return;
    }
    while (ptr != NULL)
    {
        fprintf(fp, "%9s %7s %10d %10d %10d\n", ptr->stu_num, ptr->stu_name, ptr->chi_score, ptr->math_score, ptr->eng_score);
        ptr = ptr->next;
    }
    fclose(fp);
}

void LoadData(struct stu_info *head)
{
    FILE *fp = fopen("./stud.txt","a+");
    struct stu_info *ptr;
    struct stu_info *now = get_input();
    if (fp == NULL)
    {
        printf("ERROR！！！ 无数据");
        return;
    }
    ptr = (struct stu_info *)malloc(sizeof(struct stu_info));
    ptr->next = NULL;
    int pos = 0;
    while (fscanf(fp, "%9s %7s %10d %10d %10d\n", &ptr->stu_num, &ptr->stu_name, &ptr->chi_score, &ptr->math_score, &ptr->eng_score) != EOF)
    {
        // if (Head->next == NULL)
        //{
        //     Head->next = ptr;
        //     End = ptr;
        // }
        // else
        //{
        //     End->next = ptr;
        //     End = End->next;
        // }
        // ptr = (struct stu*)malloc(sizeof(struct stu));
        // ptr->next = NULL;
        if (head)
        {

            add_new_stu(&head, &now, pos);
        }
        else
        {
            head = now;
        }
        free(ptr);
        fclose(fp);
    }
}

int main()
{
    struct stu_info *head;
    head = NULL;

    char input_del = '\0';
    int pos = 0;
    char stu_num[10];
    struct stu_info *now;
    for (;;)
    {
        printf("\nplease input del:\n    (a) add a student\n    (b) del a student by pos\n    (c) del a student by stu_num\n    (d) check all student\n    (e) find a student by stu_num\n    (f) load student data\n    (g) save student data\n   your input:");
        scanf("%c", &input_del);
        printf("%c\n", input_del);
        getchar(); // 清除缓冲区

        switch (input_del)
        {
        case 'a':
            printf("enter infos like:stu_num stu_name stu_sex stu_score\nenter:");
            now = get_input();
            if (head)
            {
                printf("enter a pos you want to insert, zeros is before the head:");
                scanf("%d", &pos);
                getchar();
                add_new_stu(&head, &now, pos);
            }
            else
            {
                head = now;
            }
            break;
        case 'b':
            printf("enter a pos you want to del, zeros is the head:");
            scanf("%d", &pos);
            getchar();
            del_stu_info_bypos(&head, pos);
            break;
        case 'c':
            printf("enter a stu_num you want to del:");
            scanf("%s", &stu_num);
            getchar();
            del_stu_info_bynum(&head, stu_num);
            break;
        case 'd':
            printf("stu_num stu_name stu_sex stu_score\n");
            print_list(head);
            break;
        case 'e':
            printf("enter the stu_num:");
            search(head);
            break;
        case 'f':
            LoadData(head);
            break;
        case 'g':
            SaveData(head);
            break;
        default:
            printf("no sense\n");
        }
    }
    return 0;
}