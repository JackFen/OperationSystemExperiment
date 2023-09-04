//
// Created by fengzhanwei on 2023/8/31.
//
#include "DeviceManage.h"
#include "Dev_Bank.h"
using namespace std;
void DeviceMenu()
{
    int choice=0;
    while (true)
    {
        cout<<"        ╭═══════════════╮"<<endl;
        cout<<"           设备管理"<<endl;
        cout<<"        请选择你要进入的目录"<<endl;
        cout<<"          1.银行家算法"<<endl;
        cout<<"          0.退出"<<endl;
        cout<<"请输入：";
        cin>>choice;
        if(choice)
        {
            Device::YinHangJia();
        }
        else
        {
            break;
        }
    }
}