//
// Created by fengzhanwei on 2023/9/1.
//

#ifndef ALLINONE_DEV_BANK_H
#define ALLINONE_DEV_BANK_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
namespace Device{
    #define M 5
    #define N 3
    #define FALSE 0
    #define TRUE 1
    //M 个进程对 N 类设备最大设备需求量
    static int MAX[M][N] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};
    //系统可用设备数
    static int AVAILABLE[N] = {10, 5, 7};
    //M 个进程对 N 类设备最大设备需求量
    static int ALLOCATION[M][N] = {{0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0}};
    //M 个进程已经得到 N 类设备的设备量
    static int NEED[M][N] = {{7, 5, 3},
                      {3, 2, 2},
                      {9, 0, 2},
                      {2, 2, 2},
                      {4, 3, 3}};
    //M 个进程还需要 N 类设备的设备量
    static int Request[N] = {0, 0, 0};//初始化需要申请的设备数目
    void YinHangJia();//银行家算法的实现
    void showdata();
    void changdata(int k);
    void rstordata(int k);
    int chkerr(int s);
}
#endif //ALLINONE_DEV_BANK_H
