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
        cout<<"        �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r"<<endl;
        cout<<"           �豸����"<<endl;
        cout<<"        ��ѡ����Ҫ�����Ŀ¼"<<endl;
        cout<<"          1.���м��㷨"<<endl;
        cout<<"          0.�˳�"<<endl;
        cout<<"�����룺";
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