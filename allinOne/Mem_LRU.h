//
// Created by fengzhanwei on 2023/9/1.
//

#ifndef ALLINONE_MEM_LRU_H
#define ALLINONE_MEM_LRU_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace LRU{
    #define MAX 20
    typedef struct block
    {
        int No;//主存块号
        int count=0;//访问次数
        struct block *next;//指向下一个主存块
    }Block,*BlockList;
    static int hitcount=0;//命中次数
    static int num=0;//访问主存块次数
    //初始化主存块号
    void InitData(int (&randomData)[MAX],int n);
    //打印主存块调度状态
    void PrintStatus(Block* &memory,int memorySize);
    //最近最少使用调度算法
    void LRUSCH(int randomDataNo,Block* &memory,int memorySize);
    //打印命中次数及命中率
    void PrintPrecision();
    //封装最近最少使用调度算法
    void LRUALL();
}
#endif //ALLINONE_MEM_LRU_H
