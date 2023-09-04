//
// Created by fengzhanwei on 2023/8/31.
//
#include "Proc_PC.h"
#include <windows.h>

namespace PC {
    #define MAX 20 //���建��ص���������� 20
    static int count = 5; //��ʼ��Դ������Ϊ 5
    static int flag=1;
    static HANDLE ahThread;
    static HANDLE bhThread;
    static HANDLE hThread;

    void Proclucer()//�����ߺ���
    {
        while (flag) {
            if (count >= MAX) {
                printf("���������!�ȴ� 3 ��!\n");
                Sleep(3000);
            } else {
                count++;
                printf("һ����Դ���ͷ�! ��ǰ��Դ����������: %d\n", count);
                Sleep(1300); //ע�����Ϊ��λ
            }
        }
    }

    void Consumer() //�����ߺ���
    {
        while (flag) {
            if (count == 0) {
                printf("������ѿ�!�ȴ� 2 ��!\n");
                Sleep(2000);
            } else {
                count--;
                printf("һ����Դ��ռ��! ��ǰ��Դ��������: %d \n", count);
                Sleep(2000);
            }
        }
    }

    int tStop() //ֹͣ����
    {
        int count=5;
        while (count)
        {
            Sleep(1000);
            count--;
        }
        flag=0;
        return 0;
    }

    void Start() //��ʼ����
    {
        //���߳�
        ahThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Proclucer, NULL, 0, NULL);
        bhThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Consumer, NULL, 0, NULL);
        hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) tStop, NULL, 0, NULL);
    }

    void shengcanzexiaofeize() //������
    {
        printf("**********��ģ��5���ֹͣ*********************\n");
        Start(); //��ʼ
        while (flag);
        printf("ģ���Ѿ�������\n");
    }
}
