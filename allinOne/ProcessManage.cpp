//
// Created by fengzhanwei on 2023/8/31.
//
#include "ProcessMange.h"
#include "Proc_Priority.h"
#include "Proc_FCFS.h"
#include "Proc_ROUND.h"
using namespace std;
void ProcMenu()
{
    int choice=0;
    while (true)
    {
        int flag=0;//标记是否退出循环
        cout<<"        ╭═══════════════╮"<<endl;
        cout<<"           进程管理"<<endl;
        cout<<"     请选择你要进入的目录"<<endl;
        cout<<"        1.生产者消费者问题"<<endl;
        cout<<"        2.先来先服务调度算法"<<endl;
        cout<<"        3.高优先权优先调度算法"<<endl;
        cout<<"        4.轮转调度算法"<<endl;
        cout<<"        0.退出"<<endl;
        cout<<"请输入：";
        cin>>choice;
        switch (choice) {
            case 1:PC::shengcanzexiaofeize();
                break;
            case 2:FCFS::FCFSAll();
                break;
            case 3:Priority::PRISCHAll();
                break;
            case 4:Round::ROUNDSCHAll();
                break;
            default:flag=1;
        }
        if(flag)
        {
            break;
        }
    }
}
