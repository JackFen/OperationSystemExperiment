//
// Created by fengzhanwei on 2023/8/31.
//

#ifndef ALLINONE_PROC_PRIORITY_H
#define ALLINONE_PROC_PRIORITY_H

#include<iostream>
#include<set>
#include <windows.h>
namespace Priority{
    static int cputime = 0; //cpuռ��ʱ��Ƭ��
    typedef struct pcb {
        int NAME; //���̱�ʶ��
        int PRIO = 50; //����������
        int ROUND = 2; //����ÿ����ת��ʱ��Ƭ��(��Ϊ���� 2)
        int CPUTIME; //�����ۼ�ռ�� CPU ��ʱ��Ƭ��
        int NEEDTIME; //���̵���ɻ���Ҫ��ʱ��Ƭ��
        char STATE; //����״̬
        int time; //��תʱ��
        double weightTime; //��Ȩ��תʱ��
        struct pcb *NEXT; //��ָ��
    } PCB, *RunPoint, *WaitList, *FinishList;
    // �����½��̣���������뵽��������
    void NewPCB(PCB *&TAIL, int name, int needtime);
    // ���Ⱦ������еĵ�һ������Ͷ������
    void FIRSTIN(WaitList &waitList, PCB *&READY, PCB *&TAIL, RunPoint &RUN);
    // ��ʾÿִ��һ�κ����н��̵�״̬���й���Ϣ��
    void PRINT(WaitList waitList, FinishList finishList, RunPoint RUN);
    //���ƽ����תʱ���ƽ����Ȩ��תʱ��
    void printTime(FinishList finishList);
    //���ƽ����תʱ���ƽ����Ȩ��תʱ��
    void printTime(FinishList finishList);
    //=======���������Ⱥ���========
    //���������㷨�У�����δ��ɵ� PCB ��������˳��Ծ������н�������
    void INSERT1(WaitList &waitList, PCB *&READY, PCB *&TAIL);
    //CPU��ʼ���н��̡�������������
    void RUNPCBBYPRIO(RunPoint &RUN, PCB *&TAIL, PCB *&FINISH);
    // ���������㷨���Ƚ���
    void PRISCH(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH, RunPoint &RUN);
    // ��ʼ������
    void InitProgram(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH);
    //��װ������Ȩ�����㷨
    void PRISCHAll();
}

#endif //ALLINONE_PROC_PRIORITY_H
