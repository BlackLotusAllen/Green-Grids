#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, best;
int max[3];
typedef struct student
{
    char id[100];
    char name[100];
    int score[3];
    int sum;
}data;

void input(data stu[])
{
    for(int i = 0; i < n; i++)
    {
        scanf("%s", stu[i].id);
        scanf("%s", stu[i].name);
        stu[i].sum = 0;
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].score[j]);
            stu[i].sum += stu[i].score[j];
            max[j] += stu[i].score[j];
        }
    }
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        data stu[n];
        best = 0;
        max[0] = 0, max[1] = 0, max[2] = 0;
        input(stu);
        printf("%d %d %d\n", max[0] / n, max[1] / n, max[2] / n);

        stu[best].sum = stu[0].sum;
        for(int i = 1; i < n; i++)
        {
            if(stu[best].sum < stu[i].sum)
                best = i;
        }
        printf("%s %s %d %d %d\n", stu[best].id, stu[best].name, stu[best].score[0], stu[best].score[1], stu[best].score[2]);
    }
    return 0;
}
