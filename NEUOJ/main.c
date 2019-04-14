#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    int score;
    struct student * next;
};

int main()
{
    int a, b, n, temp;
    struct student * head = NULL;
    struct student * previous, * current;
    struct student * times, * min;

    while(scanf("%d %d", &a, &b) != EOF)
    {
        n = a + b;
        for(int i = 0; i < n; i++)
        {
            current = (struct student *)malloc(sizeof(struct student));
            if(head == NULL)
                head = current;
            else
                previous->next = current;
            current->next = NULL;
            scanf("%d %d", &current->id, &current->score);
            previous = current;
        }

        times = head;
        while(times->next != NULL)
        {
            min = times;
            current = times->next;

            while(current != NULL)
            {
                if(min->id > current->id)
                    min = current;
                current = current->next;
            }

            temp = times->id;
            times->id = min->id;
            min->id = temp;

            temp = times->score;
            times->score = min->score;
            min->score = temp;

            times = times->next;
        }

        current = head;
        while(current != NULL)
        {
            printf("%d %d\n", current->id, current->score);
            free(current);
            current = current->next;
        }
    }
    return 0;
}
