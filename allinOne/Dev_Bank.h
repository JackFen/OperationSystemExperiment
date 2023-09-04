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
    //M �����̶� N ���豸����豸������
    static int MAX[M][N] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};
    //ϵͳ�����豸��
    static int AVAILABLE[N] = {10, 5, 7};
    //M �����̶� N ���豸����豸������
    static int ALLOCATION[M][N] = {{0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0}};
    //M �������Ѿ��õ� N ���豸���豸��
    static int NEED[M][N] = {{7, 5, 3},
                      {3, 2, 2},
                      {9, 0, 2},
                      {2, 2, 2},
                      {4, 3, 3}};
    //M �����̻���Ҫ N ���豸���豸��
    static int Request[N] = {0, 0, 0};//��ʼ����Ҫ������豸��Ŀ
    void YinHangJia();//���м��㷨��ʵ��
    void showdata();
    void changdata(int k);
    void rstordata(int k);
    int chkerr(int s);
}
#endif //ALLINONE_DEV_BANK_H
