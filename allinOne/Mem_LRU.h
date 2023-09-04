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
        int No;//������
        int count=0;//���ʴ���
        struct block *next;//ָ����һ�������
    }Block,*BlockList;
    static int hitcount=0;//���д���
    static int num=0;//������������
    //��ʼ��������
    void InitData(int (&randomData)[MAX],int n);
    //��ӡ��������״̬
    void PrintStatus(Block* &memory,int memorySize);
    //�������ʹ�õ����㷨
    void LRUSCH(int randomDataNo,Block* &memory,int memorySize);
    //��ӡ���д�����������
    void PrintPrecision();
    //��װ�������ʹ�õ����㷨
    void LRUALL();
}
#endif //ALLINONE_MEM_LRU_H
