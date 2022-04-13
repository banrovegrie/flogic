#include "my_dll.h"
#include <stdio.h>

/**
 * Driver c program
*/

int store = 0;

int check(char *s, char *t)
{
    return strncmp(s, t, strlen(t) - 1) == 0;
}

int get_token(char *str, int c)
{  
    char *p = strtok(str, " \n\t");
    while(p != NULL) {
        if (c == 1)
            store = atoi(p);
        if (c == 0)
            return atoi(p);
        c--;
        p = strtok(NULL, " \n\t");
    }
}

int main()
{
    struct my_dll* dll = (struct my_dll*)malloc(sizeof(struct my_dll));
    
    printf("Enter the operation you want to perform. Press x to exit at any point.\n");
    while (1)
    {
        char s[30];
        fgets(s, 30, stdin);

        if (check(s, "x\n"))
            break;
        else if (check(s, "print_reverse"))
            print_reverse(dll);
        else if (check(s, "print"))
            print(dll);
        else if (check(s, "get_size"))
            printf("%d\n", get_size(dll));
        else if (check(s, "prune"))
            prune(dll);
        else if (check(s, "insert_at"))
        {
            int i = get_token(s, 2);
            insert_at(dll, store, i);
        }
        else if (check(s, "insert"))
        {
            int x = get_token(s, 1);
            insert(dll, x);
        }
        else if (check(s, "del"))
        {
            int i = get_token(s, 1);
            del(dll, i);
        }
        else if (check(s, "find"))
        {
            int x = get_token(s, 1);
            printf("%d\n", find(dll, x));
        }
    }

    print(dll);
}