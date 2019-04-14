#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
typedef struct student
{
    char id[100];
    char name[100];
    int score[3];
}data;

void input(data stu[])
{
    for(int i = 0; i < n; i++)
    {
        scanf("%s", stu[i].id);
        scanf("%s", stu[i].name);
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].score[j]);
        }
    }
}

void print(data stu[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%s", stu[i].id);
        printf(",%s", stu[i].name);
        for(int j = 0; j < 3; j++)
        {
            printf(",%d", stu[i].score[j]);
        }
        printf("\n");
    }
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        data stu[n];
        input(stu);
        print(stu);
    }
    return 0;
}
