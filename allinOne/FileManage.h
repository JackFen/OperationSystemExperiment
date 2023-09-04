//
// Created by fengzhanwei on 2023/8/31.
//

#ifndef ALLINONE_FILEMANAGE_H
#define ALLINONE_FILEMANAGE_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
namespace File{
    static int NAll = 0;
    static int Best[5][2]; //用作寻道长度由低到高排序时存放的数组
    static int Limit = 0; //输入寻找的范围磁道数 i
    static int Jage;
    static float Aver = 0;

    void CopyL(int Sour[], int Dist[], int x); //数组 Sour 复制到数组 Dist，复制到 x个数
    void SetDI(int DiscL[]); //随机生成磁道数
    void Print(int Pri[], int x); //打印输出数组 Pri
    void DelInq(int Sour[], int x, int y);

    //数组 Sour 把 x 位置的数删除，并把 y 前面的数向前移动，y 后的数保持不变(即会出现 2个 y)

    void FCFS(int Han, int DiscL[]); //先来先服务算法(FCFS)
    void SSTF(int Han, int DiscL[]); //最短寻道时间优先算法(SSTF)
    int SCAN(int Han, int DiscL[], int x, int y); //扫描算法(SCAN)
    void CSCAN(int Han, int DiscL[]); //循环扫描算法(CSCAN)
    void N_Step_SCAN(int Han1, int DiscL[]); //N 步扫描算法
    void PaiXu(); //寻道长度由低到高排序
    void FileMenu();
}

#endif //ALLINONE_FILEMANAGE_H
