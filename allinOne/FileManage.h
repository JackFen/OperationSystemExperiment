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
    static int Best[5][2]; //����Ѱ�������ɵ͵�������ʱ��ŵ�����
    static int Limit = 0; //����Ѱ�ҵķ�Χ�ŵ��� i
    static int Jage;
    static float Aver = 0;

    void CopyL(int Sour[], int Dist[], int x); //���� Sour ���Ƶ����� Dist�����Ƶ� x����
    void SetDI(int DiscL[]); //������ɴŵ���
    void Print(int Pri[], int x); //��ӡ������� Pri
    void DelInq(int Sour[], int x, int y);

    //���� Sour �� x λ�õ���ɾ�������� y ǰ�������ǰ�ƶ���y ��������ֲ���(������� 2�� y)

    void FCFS(int Han, int DiscL[]); //�����ȷ����㷨(FCFS)
    void SSTF(int Han, int DiscL[]); //���Ѱ��ʱ�������㷨(SSTF)
    int SCAN(int Han, int DiscL[], int x, int y); //ɨ���㷨(SCAN)
    void CSCAN(int Han, int DiscL[]); //ѭ��ɨ���㷨(CSCAN)
    void N_Step_SCAN(int Han1, int DiscL[]); //N ��ɨ���㷨
    void PaiXu(); //Ѱ�������ɵ͵�������
    void FileMenu();
}

#endif //ALLINONE_FILEMANAGE_H
