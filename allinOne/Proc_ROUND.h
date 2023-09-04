//
// Created by fengzhanwei on 2023/9/1.
//

#ifndef ALLINONE_PROC_ROUND_H
#define ALLINONE_PROC_ROUND_H

#include<iostream>
#include<set>
#include <windows.h>

namespace Round {
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

    //=======��ת���Ⱥ���=========
    //����ת���У���ִ����һ��ʱ��Ƭ��λ��Ϊ 2��������δ��ɵĽ��̵� PCB���嵽�������еĶ�β
    void INSERT2(WaitList &waitList, RunPoint &RUN, PCB *&READY, PCB *&TAIL);

    //CPU��ʼ���н��̡�����ת����
    void RUNPCBBYROUND(WaitList &waitList, RunPoint &RUN, PCB *&READY, PCB *&TAIL, PCB *&FINISH);

    // ��ʱ��Ƭ��ת�����Ƚ���
    void ROUNDSCH(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH, RunPoint &RUN);

    // ��ʼ������
    void InitProgram(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH);

    //��װ��ת�����㷨
    void ROUNDSCHAll();
}
#endif //ALLINONE_PROC_ROUND_H
