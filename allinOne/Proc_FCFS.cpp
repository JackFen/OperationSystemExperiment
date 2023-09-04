//
// Created by fengzhanwei on 2023/9/1.
//
#include "Proc_FCFS.h"

using namespace std;
namespace FCFS {
    // 创建新进程，并将其插入到就绪队列
    void NewPCB(PCB *&TAIL, int name, int needtime) {
        PCB *temp = new PCB;
        temp->NAME = name;
        temp->PRIO = 50 - needtime;
        temp->CPUTIME = 0;
        temp->NEEDTIME = needtime;
        temp->STATE = 'W';
        temp->NEXT = nullptr;
//    cout<<"flag"<<endl;

        TAIL->NEXT = temp;
        TAIL = temp;
    }

    // 调度就绪队列的第一个进程投入运行
    void FIRSTIN(WaitList &waitList, PCB *&READY, PCB *&TAIL, RunPoint &RUN) {
        WaitList temp = waitList;
        RUN = temp->NEXT;
        temp->NEXT = temp->NEXT->NEXT;
        RUN->NEXT = nullptr;
        RUN->STATE = 'R';
        //当等待队列为空时，将头指针和尾指针都指向头结点
        if (waitList->NEXT == nullptr) {
            READY = waitList;
            TAIL = waitList;
        } else {
            READY = temp->NEXT;
        }
//    cout << "FIRSTIN" << endl;
    }

    // 显示每执行一次后所有进程的状态及有关信息。
    void PRINT(WaitList waitList, FinishList finishList, RunPoint RUN) {
        cout << "\n=================运行状态=================================" << endl;
        cout << "\n当前执行进程\n" << endl;
        if (RUN == nullptr) {
            cout << "无" << endl;
        } else {
            cout << "name    cputime    needtime    priority    state" << endl;
            cout << RUN->NAME << "       " << RUN->CPUTIME << "           " << RUN->NEEDTIME << "           "
                 << RUN->PRIO << "           "
                 << RUN->STATE << endl;
        }
        cout << "\n就绪队列\n" << endl;
        if (waitList->NEXT == nullptr) {
            cout << "无" << endl;
        } else {
            cout << "name    cputime    needtime    priority    state" << endl;
            PCB *temp = waitList->NEXT;
            while (temp != nullptr) {
                cout << temp->NAME << "       " << temp->CPUTIME << "           " << temp->NEEDTIME << "          "
                     << temp->PRIO
                     << "           " << temp->STATE << endl;
                temp = temp->NEXT;
            }
        }
        cout << "\n完成队列\n" << endl;
        if (finishList->NEXT == nullptr) {
            cout << "无" << endl;
        } else {
            cout << "name    cputime    needtime    priority    state" << endl;
            PCB *temp = finishList->NEXT;
            while (temp != nullptr) {
                cout << temp->NAME << "       " << temp->CPUTIME << "           " << temp->NEEDTIME << "          "
                     << temp->PRIO
                     << "           " << temp->STATE << endl;
                temp = temp->NEXT;
            }
        }
        cout << endl;
    }

    //输出平均周转时间和平均带权周转时间
    void printTime(FinishList finishList) {
        cout << endl;
        PCB *temp = finishList->NEXT;
        int sum = 0;
        double weightSum = 0;
        int count = 0;
        while (temp != nullptr) {
            sum += temp->time;
            weightSum += temp->weightTime;
            count++;
            temp = temp->NEXT;
        }
        cout << "平均周转时间：" << (double) sum / count << " 平均带权周转时间：" << weightSum / count << endl;
    }

    //CPU开始运行进程——先来先服务调度
    void RUNPCBBYFCFS(RunPoint &RUN, PCB *&TAIL, PCB *&FINISH) {
        cputime += RUN->NEEDTIME;
        RUN->CPUTIME = RUN->NEEDTIME;
        RUN->NEEDTIME = 0;
//    进程已经执行完
        RUN->STATE = 'F';
        RUN->time = cputime;
        RUN->weightTime = (double) cputime / RUN->CPUTIME;
//        RUN->weightTime = 1.0 / RUN->CPUTIME;
        FINISH->NEXT = RUN;
        FINISH = FINISH->NEXT;
        RUN = nullptr;
    }

    // 按先来先服务算法调度进程
    void FCFS(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH, RunPoint &RUN) {
//    cout<<"尾指针 "<<TAIL->NAME<<endl;
        while (true) {
            //若就绪队列无进程且当前无正在运行的进程，则表示所有程序执行完毕
            if (READY == waitList && RUN == nullptr) {
                PRINT(waitList, finishList, RUN);
                cout << "所有程序已全部执行完";
                printTime(finishList);
                break;
            } else {
                //将就绪队列的第一个进程调入到CPU中
                FIRSTIN(waitList, READY, TAIL, RUN);
                //输出当前各个队列状态
                PRINT(waitList, finishList, RUN);
                //CPU开始运行第一个进程
                RUNPCBBYFCFS(RUN, TAIL, FINISH);

                //延迟0.5秒
                Sleep(500);
            }
        }
//    cout << "PRISCH" << endl;
    }

    // 初始化程序
    void InitProgram(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH) {
        waitList = new PCB;
        waitList->NEXT = nullptr;
        READY = waitList;
        TAIL = waitList;

        finishList = new PCB;
        finishList->NEXT = nullptr;
        FINISH = finishList;
    }

    //封装先来先服务算法
    void FCFSAll() {
        cputime=0;
        //定义用于检查是否有重复输入的集合
        set<int> names;
        //定义当前运行进程指针、就绪队列和完成队列等
        RunPoint RUN = nullptr;
        WaitList waitList;
        FinishList finishList;
        PCB *READY;
        PCB *TAIL;
        PCB *FINISH;
        //初识化就绪队列、完成队列、就绪队列头指针与尾指针以及完成队列的尾指针
        InitProgram(waitList, finishList, READY, TAIL, FINISH);
        //    定义PCB信息
        int name, needtime;
        //   在使用优先级调度算法时，用户输入PCB信息
        cout << "当前为先来先服务调度算法" << endl;
        cout << "请输入PCB信息，输入0 0结束" << endl;
        cout << "格式如下\n进程名(数字) 执行所需时间" << endl;
        while (true) {
            cin >> name >> needtime;
            if (name == 0) {
                cout << "结束输入" << endl;
                break;
            } else {
                int L1 = names.size();
                names.insert(name);
                if (names.size() != L1) {
                    NewPCB(TAIL, name, needtime);
                    cout << "添加完成,请继续输入" << endl;
                } else {
                    cout << "重复输入了进程标识符:" << name << endl;
                }
            }
        }
        // 将队首指针从头结点移向首元结点
        READY = waitList->NEXT;
        //开始执行先来先服务调度算法
        FCFS(waitList, finishList, READY, TAIL, FINISH, RUN);
    }
}

