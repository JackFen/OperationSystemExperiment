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
        int flag=0;//����Ƿ��˳�ѭ��
        cout<<"        �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r"<<endl;
        cout<<"             �洢����"<<endl;
        cout<<"        ��ѡ����Ҫ�����Ŀ¼"<<endl;
        cout<<"        1.�Ƚ��ȳ���̭�㷨"<<endl;
        cout<<"        2.�������ʹ����̭�㷨"<<endl;
        cout<<"        0.�˳�"<<endl;
        cout<<"�����룺";
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