#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[20];
    struct student *next;
}stu;

stu *creat(int n)
{
    stu *head = NULL;
    stu *previous, *current;

    for(int i = 0; i < n; i++)
    {
        current = (struct student *)malloc(sizeof(struct student));
        scanf("%s", &current->name);
        current->next = NULL;

        if(head == NULL)
            head = current;
        else
            previous->next = current;
        previous = current;
    }
    return head;
}

void print(stu *current)
{
    printf("%s", current->name);
    current = current->next;
    while(current != NULL)
    {
        printf(" %s", current->name);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n1, n2, n3, flag;
    stu *a, *b, *c, *temp;
    stu *previous, *current, *i;
    while(scanf("%d %d %d", &n1, &n2, &n3) != EOF)
    {
        a = creat(n1);
        b = creat(n2);
        c = creat(n3);

        current = b;
        while(current != NULL)
        {
            i = a;
            flag = 0;
            while(i != NULL)
            {
                if((strcmp(current->name, i->name)) == 0)
                {
                    flag = 1;
                    break;
                }
                i = i->next;
            }

            if(flag == 0)
            {
                if(current == b)
                    b = b->next;
                else
                    previous->next = current->next;
                current = current->next;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        current = b;
        while(current != NULL)
        {
            i = c;
            flag = 0;
            while(i != NULL)
            {
                if((strcmp(current->name, i->name)) == 0)
                {
                    flag = 1;
                    break;
                }
                i = i->next;
            }

            if(flag == 1)
            {
                if(current == b)
                    b = b->next;
                else
                    previous->next = current->next;
                current = current->next;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        if(b != NULL)
            print(b);
        else
            printf("No enemy spy\n");
    }
    return 0;
}
