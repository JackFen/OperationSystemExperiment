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
        int flag=0;//标记是否退出循环
        cout<<"        ╭═══════════════╮"<<endl;
        cout<<"           模拟操作系统"<<endl;
        cout<<"        请选择你要进入的目录"<<endl;
        cout<<"          1.进程管理"<<endl;
        cout<<"          2.设备管理"<<endl;
        cout<<"          3.文件管理"<<endl;
        cout<<"          4.存储管理"<<endl;
        cout<<"          0.退出"<<endl;
        cout<<"请输入：";
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
            cout<<"期待再次相见^_^"<<endl;
            break;
        }
    }

    return 0;
}
