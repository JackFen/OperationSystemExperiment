//
// Created by fengzhanwei on 2023/9/1.
//

#ifndef ALLINONE_PROC_FCFS_H
#define ALLINONE_PROC_FCFS_H

#include<iostream>
#include<set>
#include <windows.h>

namespace FCFS {
    static int cputime = 0; //cpu占用时间片数
    typedef struct pcb {
        int NAME; //进程标识符
        int PRIO = 50; //进程优先数
        int ROUND = 2; //进程每次轮转的时间片数(设为常数 2)
        int CPUTIME; //进程累计占用 CPU 的时间片数
        int NEEDTIME; //进程到完成还需要的时间片数
        char STATE; //进程状态
        int time; //周转时间
        double weightTime; //带权周转时间
        struct pcb *NEXT; //链指针
    } PCB, *RunPoint, *WaitList, *FinishList;
    // 创建新进程，并将其插入到就绪队列
    void NewPCB(PCB *&TAIL, int name, int needtime);

    // 调度就绪队列的第一个进程投入运行
    void FIRSTIN(WaitList &waitList, PCB *&READY, PCB *&TAIL, RunPoint &RUN);

    // 显示每执行一次后所有进程的状态及有关信息。
    void PRINT(WaitList waitList, FinishList finishList, RunPoint RUN);

    //输出平均周转时间和平均带权周转时间
    void printTime(FinishList finishList);

    //CPU开始运行进程——先来先服务调度
    void RUNPCBBYFCFS(RunPoint &RUN, PCB *&TAIL, PCB *&FINISH);

    // 按先来先服务算法调度进程
    void FCFS(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH, RunPoint &RUN);

    // 初始化程序
    void InitProgram(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH);

    //封装先来先服务算法
    void FCFSAll();
}

#endif //ALLINONE_PROC_FCFS_H
