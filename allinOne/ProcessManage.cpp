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
        int flag=0;//����Ƿ��˳�ѭ��
        cout<<"        �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r"<<endl;
        cout<<"           ���̹���"<<endl;
        cout<<"     ��ѡ����Ҫ�����Ŀ¼"<<endl;
        cout<<"        1.����������������"<<endl;
        cout<<"        2.�����ȷ�������㷨"<<endl;
        cout<<"        3.������Ȩ���ȵ����㷨"<<endl;
        cout<<"        4.��ת�����㷨"<<endl;
        cout<<"        0.�˳�"<<endl;
        cout<<"�����룺";
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
