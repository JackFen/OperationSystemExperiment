//
// Created by fengzhanwei on 2023/8/31.
//
#include "MemoryManage.h"
#include "Mem_FIFO.h"
#include "Mem_LRU.h"

using namespace std;

void MemoryMenu()
{
    int choice=0;
    while (true)
    {
        int flag=0;//标记是否退出循环
        cout<<"        ╭═══════════════╮"<<endl;
        cout<<"             存储管理"<<endl;
        cout<<"        请选择你要进入的目录"<<endl;
        cout<<"        1.先进先出淘汰算法"<<endl;
        cout<<"        2.最近最少使用淘汰算法"<<endl;
        cout<<"        0.退出"<<endl;
        cout<<"请输入：";
        cin>>choice;
        switch (choice) {
            case 1:FIFO::FIFOALL();
                break;
            case 2:LRU::LRUALL();
                break;
            default:flag=1;
        }
        if(flag)
        {
            break;
        }
    }
}