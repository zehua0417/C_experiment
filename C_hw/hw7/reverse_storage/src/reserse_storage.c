#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    char new_str[100];
    int i;
    fgets(str,100,stdin);
    int size = strlen(str);
    for (i = 0; i < size; i++)
    
        new_str[i] = str[size - i - 1];
    
    new_str[i] = 0;
    puts(new_str);
    return 0;
}


