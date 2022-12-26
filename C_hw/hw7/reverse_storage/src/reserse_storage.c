#include <stdio.h>
#include <string.h>
void reverse(char *str, char *new_str);
int main()
{
    char str[100];
    char new_str[100];
    fgets(str, 100, stdin);
    reverse(str,new_str);
    puts(new_str);
    return 0;
}

void reverse(char *str, char *new_str)
{
    int i;
    int size = strlen(str);
    for (i = 0; i < size; i++)
    {
        new_str[i] = str[size - i - 1];
    }
    new_str[i] = 0;
}
