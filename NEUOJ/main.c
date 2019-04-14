#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    int mouth;
    int day;
}TValue;
TValue t;

int main()
{
    int mValue[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int runFlag, dValue;
    while(scanf("%d %d %d", &t.year, &t.mouth, &t.day) != EOF)
    {
        runFlag = 0;
        dValue = 0;
        if((t.year % 4 == 0 && t.year % 100 != 0) || (t.year % 400 == 0))
        {
            runFlag = 1;
        }
        for(int i = 0; i < t.mouth - 1; i++)
        {
            dValue = dValue + mValue[i];
        }
        dValue = dValue + t.day;
        if(runFlag && t.mouth > 2)
        {
            dValue++;
        }
        printf("%d\n", dValue);
    }
    return 0;
}
