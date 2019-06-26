#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define P 4                     //定义寄存机级数
#define NP ((2<<(P - 1)) - 1)   //定义M序列长度

//-------------------------------------------------------------------------*
//函数名: M_Sequence_Generator
//功  能: 生成并输出M序列和逆M序列
//参  数: regInit[]:寄存器的初始化数据
//        regNum: 输出第几级寄存器的M序列
//返  回: 无
//简  例: M_Sequence_Generator(regInit, 1);
//-------------------------------------------------------------------------*
void M_Sequence_Generator(int regInit[], int regNum)
{
    //定义寄存器数组，M序列数组, 逆M序列数组
    int reg[P], MSeq[NP], IMSeq[2 * NP];
    //temp用于存放中间变量, s是周期为2的取值为0和1的方波序列
    int temp, s = 0;

    //初始化寄存器
    for(int i = 0; i < P; i++)
        reg[i] = regInit[i];

    for(int i = 0; i < NP; i++)
    {
        //生成M序列
        MSeq[i] = reg[regNum - 1];
        //生成逆M序列
        IMSeq[i] = MSeq[i] ^ s;
        IMSeq[i + NP] = (MSeq[i] ^ s) ^ 1;
		//时钟信号电平转换
        s = s ^ 1;

        //寄存器移位
        temp = reg[P - 1] ^ reg[P - 2];
        for(int j = P - 1; j > 0; j--)
            reg[j] = reg[j - 1];
        reg[0] = temp;
    }

    //输出M序列
    printf("第%d级寄存器M序列:   ", regNum);
    for(int i = 0; i < NP; i++)
        printf("%2d ", MSeq[i] * 2 - 1);
    printf("\n");

    //输出逆M序列
    printf("第%d级寄存器逆M序列: ", regNum);
    for(int i = 0; i < 2 * NP; i++)
        printf("%2d ", IMSeq[i] * 2 - 1);
    printf("\n");
    printf("\n");
}

int main()
{
    int regInit[P] = {0, 1, 0, 1};

    M_Sequence_Generator(regInit, 1);
    M_Sequence_Generator(regInit, 2);
    M_Sequence_Generator(regInit, 3);
    M_Sequence_Generator(regInit, 4);

    return 0;
}
