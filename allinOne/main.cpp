#include <iostream>
#include <stdlib.h>
#include "ProcessMange.h"
#include "DeviceManage.h"
#include "FileManage.h"
#include "MemoryManage.h"
using namespace std;
int main() {
    int choice=0;
    while (true)
    {
        int flag=0;//����Ƿ��˳�ѭ��
        cout<<"        �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r"<<endl;
        cout<<"           ģ�����ϵͳ"<<endl;
        cout<<"        ��ѡ����Ҫ�����Ŀ¼"<<endl;
        cout<<"          1.���̹���"<<endl;
        cout<<"          2.�豸����"<<endl;
        cout<<"          3.�ļ�����"<<endl;
        cout<<"          4.�洢����"<<endl;
        cout<<"          0.�˳�"<<endl;
        cout<<"�����룺";
        cin>>choice;
        switch (choice) {
            case 1:system("cls");ProcMenu();system("cls");
                break;
            case 2:system("cls");DeviceMenu();system("cls");
                break;
            case 3:system("cls");File::FileMenu();system("cls");
                break;
            case 4:system("cls");MemoryMenu();system("cls");
                break;
            default:flag=1;
        }
        if(flag)
        {
            cout<<"�ڴ��ٴ����^_^"<<endl;
            break;
        }
    }

    return 0;
}
