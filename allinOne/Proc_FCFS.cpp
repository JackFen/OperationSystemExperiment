//
// Created by fengzhanwei on 2023/9/1.
//
#include "Proc_FCFS.h"

using namespace std;
namespace FCFS {
    // �����½��̣���������뵽��������
    void NewPCB(PCB *&TAIL, int name, int needtime) {
        PCB *temp = new PCB;
        temp->NAME = name;
        temp->PRIO = 50 - needtime;
        temp->CPUTIME = 0;
        temp->NEEDTIME = needtime;
        temp->STATE = 'W';
        temp->NEXT = nullptr;
//    cout<<"flag"<<endl;

        TAIL->NEXT = temp;
        TAIL = temp;
    }

    // ���Ⱦ������еĵ�һ������Ͷ������
    void FIRSTIN(WaitList &waitList, PCB *&READY, PCB *&TAIL, RunPoint &RUN) {
        WaitList temp = waitList;
        RUN = temp->NEXT;
        temp->NEXT = temp->NEXT->NEXT;
        RUN->NEXT = nullptr;
        RUN->STATE = 'R';
        //���ȴ�����Ϊ��ʱ����ͷָ���βָ�붼ָ��ͷ���
        if (waitList->NEXT == nullptr) {
            READY = waitList;
            TAIL = waitList;
        } else {
            READY = temp->NEXT;
        }
//    cout << "FIRSTIN" << endl;
    }

    // ��ʾÿִ��һ�κ����н��̵�״̬���й���Ϣ��
    void PRINT(WaitList waitList, FinishList finishList, RunPoint RUN) {
        cout << "\n=================����״̬=================================" << endl;
        cout << "\n��ǰִ�н���\n" << endl;
        if (RUN == nullptr) {
            cout << "��" << endl;
        } else {
            cout << "name    cputime    needtime    priority    state" << endl;
            cout << RUN->NAME << "       " << RUN->CPUTIME << "           " << RUN->NEEDTIME << "           "
                 << RUN->PRIO << "           "
                 << RUN->STATE << endl;
        }
        cout << "\n��������\n" << endl;
        if (waitList->NEXT == nullptr) {
            cout << "��" << endl;
        } else {
            cout << "name    cputime    needtime    priority    state" << endl;
            PCB *temp = waitList->NEXT;
            while (temp != nullptr) {
                cout << temp->NAME << "       " << temp->CPUTIME << "           " << temp->NEEDTIME << "          "
                     << temp->PRIO
                     << "           " << temp->STATE << endl;
                temp = temp->NEXT;
            }
        }
        cout << "\n��ɶ���\n" << endl;
        if (finishList->NEXT == nullptr) {
            cout << "��" << endl;
        } else {
            cout << "name    cputime    needtime    priority    state" << endl;
            PCB *temp = finishList->NEXT;
            while (temp != nullptr) {
                cout << temp->NAME << "       " << temp->CPUTIME << "           " << temp->NEEDTIME << "          "
                     << temp->PRIO
                     << "           " << temp->STATE << endl;
                temp = temp->NEXT;
            }
        }
        cout << endl;
    }

    //���ƽ����תʱ���ƽ����Ȩ��תʱ��
    void printTime(FinishList finishList) {
        cout << endl;
        PCB *temp = finishList->NEXT;
        int sum = 0;
        double weightSum = 0;
        int count = 0;
        while (temp != nullptr) {
            sum += temp->time;
            weightSum += temp->weightTime;
            count++;
            temp = temp->NEXT;
        }
        cout << "ƽ����תʱ�䣺" << (double) sum / count << " ƽ����Ȩ��תʱ�䣺" << weightSum / count << endl;
    }

    //CPU��ʼ���н��̡��������ȷ������
    void RUNPCBBYFCFS(RunPoint &RUN, PCB *&TAIL, PCB *&FINISH) {
        cputime += RUN->NEEDTIME;
        RUN->CPUTIME = RUN->NEEDTIME;
        RUN->NEEDTIME = 0;
//    �����Ѿ�ִ����
        RUN->STATE = 'F';
        RUN->time = cputime;
        RUN->weightTime = (double) cputime / RUN->CPUTIME;
//        RUN->weightTime = 1.0 / RUN->CPUTIME;
        FINISH->NEXT = RUN;
        FINISH = FINISH->NEXT;
        RUN = nullptr;
    }

    // �������ȷ����㷨���Ƚ���
    void FCFS(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH, RunPoint &RUN) {
//    cout<<"βָ�� "<<TAIL->NAME<<endl;
        while (true) {
            //�����������޽����ҵ�ǰ���������еĽ��̣����ʾ���г���ִ�����
            if (READY == waitList && RUN == nullptr) {
                PRINT(waitList, finishList, RUN);
                cout << "���г�����ȫ��ִ����";
                printTime(finishList);
                break;
            } else {
                //���������еĵ�һ�����̵��뵽CPU��
                FIRSTIN(waitList, READY, TAIL, RUN);
                //�����ǰ��������״̬
                PRINT(waitList, finishList, RUN);
                //CPU��ʼ���е�һ������
                RUNPCBBYFCFS(RUN, TAIL, FINISH);

                //�ӳ�0.5��
                Sleep(500);
            }
        }
//    cout << "PRISCH" << endl;
    }

    // ��ʼ������
    void InitProgram(WaitList &waitList, FinishList &finishList, PCB *&READY, PCB *&TAIL, PCB *&FINISH) {
        waitList = new PCB;
        waitList->NEXT = nullptr;
        READY = waitList;
        TAIL = waitList;

        finishList = new PCB;
        finishList->NEXT = nullptr;
        FINISH = finishList;
    }

    //��װ�����ȷ����㷨
    void FCFSAll() {
        cputime=0;
        //�������ڼ���Ƿ����ظ�����ļ���
        set<int> names;
        //���嵱ǰ���н���ָ�롢�������к���ɶ��е�
        RunPoint RUN = nullptr;
        WaitList waitList;
        FinishList finishList;
        PCB *READY;
        PCB *TAIL;
        PCB *FINISH;
        //��ʶ���������С���ɶ��С���������ͷָ����βָ���Լ���ɶ��е�βָ��
        InitProgram(waitList, finishList, READY, TAIL, FINISH);
        //    ����PCB��Ϣ
        int name, needtime;
        //   ��ʹ�����ȼ������㷨ʱ���û�����PCB��Ϣ
        cout << "��ǰΪ�����ȷ�������㷨" << endl;
        cout << "������PCB��Ϣ������0 0����" << endl;
        cout << "��ʽ����\n������(����) ִ������ʱ��" << endl;
        while (true) {
            cin >> name >> needtime;
            if (name == 0) {
                cout << "��������" << endl;
                break;
            } else {
                int L1 = names.size();
                names.insert(name);
                if (names.size() != L1) {
                    NewPCB(TAIL, name, needtime);
                    cout << "������,���������" << endl;
                } else {
                    cout << "�ظ������˽��̱�ʶ��:" << name << endl;
                }
            }
        }
        // ������ָ���ͷ���������Ԫ���
        READY = waitList->NEXT;
        //��ʼִ�������ȷ�������㷨
        FCFS(waitList, finishList, READY, TAIL, FINISH, RUN);
    }
}

