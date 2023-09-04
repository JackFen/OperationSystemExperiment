//
// Created by fengzhanwei on 2023/8/31.
//
#include "FileManage.h"
using namespace std;
namespace File{

    void FileMenu() {
        int i;
        int DiscLine[10]; //����׼��Ҫ���ɵ�����ŵ��ŵ�����
        int Hand; //�ŵ���
        int Con = 1;
        int n;
        while (Con == 1) {
            Jage = 0;
            printf("\n �������ʼ�Ĵŵ���(0<n<65536):");
            scanf("%d", &Hand);
            printf("\n ����Ѱ�ҵķ�Χ:");
            scanf("%d", &Limit);
            if (Limit > 65536) {
                printf("������Χ!");
            } else {
                printf("     �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
                printf("         �ļ�����\n");
                printf("�U    �U               �U\n");
                printf("�U    �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
                printf("�U   1.�����ȷ����㷨(FCFS)\n");
                printf("�U   2.���Ѱ��ʱ�������㷨(SSTF)\n");
                printf("�U   3.ɨ���㷨(SCAN)\n");
                printf("�U   4.ѭ��ɨ���㷨(CSCAN)\n");
                printf("�U   5.N��ɨ���㷨(NStepScan)\n");
                printf("�U   6.�����㷨�ıȽ�\n");
                printf("�t�T�� ���������ѡ����㷨(����0�뿪):");
                scanf("%d", &n);
                printf("\n");
                switch (n) {
                    case 1:
                        SetDI(DiscLine); //������ɴŵ���
                        FCFS(Hand, DiscLine); //�����ȷ����㷨(FCFS)
                        break;
                    case 2:
                        SetDI(DiscLine); //������ɴŵ���
                        SSTF(Hand, DiscLine); //���Ѱ��ʱ�������㷨(SSTF)
                        break;
                    case 3:
                        SetDI(DiscLine); //������ɴŵ���
                        SCAN(Hand, DiscLine, 0, 9); //ɨ���㷨(SCAN)
                        break;
                    case 4:
                        SetDI(DiscLine); //������ɴŵ���
                        CSCAN(Hand, DiscLine); //ѭ��ɨ���㷨(CSCAN)
                        break;
                    case 5:
                        SetDI(DiscLine); //������ɴŵ���
                        N_Step_SCAN(Hand, DiscLine); //N ��ɨ���㷨(NStepScan)
                        break;
                    case 6:
                        SetDI(DiscLine); //������ɴŵ���
                        FCFS(Hand, DiscLine); //�����ȷ����㷨(FCFS)
                        SSTF(Hand, DiscLine); //���Ѱ��ʱ�������㷨(SSTF)
                        SCAN(Hand, DiscLine, 0, 9); //ɨ���㷨(SCAN)
                        CSCAN(Hand, DiscLine); //ѭ��ɨ���㷨(CSCAN)
                        N_Step_SCAN(Hand, DiscLine); //N ��ɨ���㷨(NStepScan)
                        PaiXu(); //Ѱ�������ɵ͵�������
                        printf("\n\n  Ѱ�������ɵ͵�������:");
                        for (i = 0; i < 5; i++) {
                            printf("%4d ", Best[i][0]);
                        }
                        break;
                    default:
                        return;
                }
                printf("\n\n  �Ƿ����(�� 0 ����,�� 1 ����)?");
                scanf("%5d", &Con);
            }

        }
    }

    //���� Sour ���Ƶ����� Dist�����Ƶ� x ����
    void CopyL(int Sour[], int Dist[], int x) {
        int i;
        for (i = 0; i <= x; i++) {
            Dist[i] = Sour[i];
        }
    }

    //��ӡ������� Pri
    void Print(int Pri[], int x) {
        int i;
        for (i = 0; i <= x; i++) {
            printf("%5d", Pri[i]);
        }
    }

    //������ɴŵ���
    void SetDI(int DiscL[]) {
        int i;
        for (i = 0; i <= 9; i++) {
            DiscL[i] = rand() % Limit;//������� 10 ���ŵ���
        }
        printf("  ��ҪѰ�ҵĴŵ���:");
        Print(DiscL, 9); //���������ɵĴŵ���
        printf("\n");
    }

    //���� Sour �� x λ�õ���ɾ�������� y ǰ�������ǰ�ƶ���y ��������ֲ���(������� 2�� y)
    void DelInq(int Sour[], int x, int y) {
        int i;
        for (i = x; i < y; i++) {
            Sour[i] = Sour[i + 1];
            x++;
        }
    }

    //�����ȷ����㷨(FCFS)
    void FCFS(int Han, int DiscL[]) {
        int RLine[10]; //��������ɵĴŵ������� Discl[]���Ƹ����� RLine[]
        int i, k, All, Temp; //Temp �Ǽ����ƶ��Ĵŵ��������ʱ����
        All = 0; //ͳ��ȫ���Ĵŵ�������
        k = 9; //�޶� 10 ���Ĵŵ���
        CopyL(DiscL, RLine, 9); //���ƴŵ��ŵ���ʱ���� RLine
        printf("\n  ���� FCFS �㷨�ŵ��ķ���˳��Ϊ:");
        All = Han - RLine[0];
        for (i = 0; i <= 9; i++) {
            Temp = RLine[0] - RLine[1];//����ƶ��ŵ���,ǰһ���ŵ�����ȥ��һ���ŵ����ó���ʱ���ƶ�����
            if (Temp < 0)
                Temp = (-Temp);//�ƶ��ŵ���Ϊ����ʱ,����෴����Ϊ�ƶ��ŵ���
            printf("%5d", RLine[0]);
            All = Temp + All;//��ȫ���ŵ������ܺ�
            DelInq(RLine, 0, k);//ÿ���ŵ�����ǰ�ƶ�һλ
            k--;
        }
        Best[Jage][1] = All;//Best[][1]����ƶ��ŵ���
        Best[Jage][0] = 1; //Best[][0]����㷨�����Ϊ:1
        Jage++;//�������ż� 1
        Aver = ((float) All) / 10;//��ƽ��Ѱ������
        printf("\n  �ƶ��ŵ���:<%5d> ", All);
        printf("\n  ƽ��Ѱ������:*%0.2f* ", Aver);
    }

    //���Ѱ��ʱ�������㷨(SSTF)
    void SSTF(int Han, int DiscL[]) {
        int i, j, k, h, All;
        int Temp; //Temp �Ǽ����ƶ��Ĵŵ��������ʱ����
        int RLine[10]; //��������ɵĴŵ������� Discl[]���Ƹ����� RLine[]
        int Min;
        All = 0; //ͳ��ȫ���Ĵŵ�������
        k = 9; //�޶� 10 ���Ĵŵ���
        CopyL(DiscL, RLine, 9); //���ƴŵ��ŵ���ʱ���� RLine
        printf("\n  ���� SSTF �㷨�ŵ��ķ���˳��Ϊ:");
        for (i = 0; i <= 9; i++) {
            Min = 64000;
            for (j = 0; j <= k; j++) //��ѭ��Ѱ���뵱ǰ�ŵ������Ѱ����ʱ��Ĵŵ���
            {
                if (RLine[j] > Han) //�����һ��������ɵĴŵ��Ŵ��ڵ�ǰ�Ĵŵ��ţ�ִ����һ��
                    Temp = RLine[j] - Han; //�����ʱ���ƶ�����
                else
                    Temp = Han - RLine[j]; //�����ʱ���ƶ�����
                if (Temp < Min) //���ÿ���һ�ε��ƶ�����С�� Min��ִ����һ��
                {
                    Min = Temp; //Temp ��ʱֵ���� Min
                    h = j; //�������ǰ�ŵ��ŵ������±긳�� h
                }
            }
            All = All + Min; //ͳ��һ���ƶ��ľ���
            printf("%5d", RLine[h]);
            Han = RLine[h];
            DelInq(RLine, h, k); //ÿ���ŵ�����ǰ�ƶ�һλ
            k--;
        }
        Best[Jage][1] = All;//Best[][1]����ƶ��ŵ���
        Best[Jage][0] = 2;//Best[][0]����㷨�����Ϊ:2
        Jage++;//������ż� 1
        Aver = ((float) All) / 10;//��ƽ��Ѱ������
        printf("\n  �ƶ��ŵ���:<%5d> ", All);
        printf("\n  ƽ��Ѱ������:*%0.2f* ", Aver);
    }

    //ɨ���㷨(SCAN)
    int SCAN(int Han, int DiscL[], int x, int y) {
        int j, n, k, h, m, All;
        int t = 0;
        int Temp;
        int Min;
        int RLine[10]; //��������ɵĴŵ������� Discl[]���Ƹ����� RLine[]
        int Order;
        Order = 1;
        k = y;
        m = 2; //���� while ����ִ�У�����һ��Ҫʹ��ǰ�ŵ��������ⶼҪɨ�赽
        All = 0; //ͳ��ȫ���Ĵŵ�������
        CopyL(DiscL, RLine, 9); //���ƴŵ��ŵ���ʱ���� RLine
        printf("\n  ���� SCAN �㷨�ŵ��ķ���˳��Ϊ:");
        Min = 64000;
        for (j = x; j <= y; j++) //Ѱ���뵱ǰ�ŵ������Ѱ����ʱ��Ĵŵ���
        {
            if (RLine[j] > Han) //�����һ��������ɵĴŵ��Ŵ��ڵ�ǰ�Ĵŵ��ţ�ִ����һ��
                Temp = RLine[j] - Han; //�����ʱ���ƶ�����
            else
                Temp = Han - RLine[j]; //�����ʱ���ƶ�����
            if (Temp < Min) {
                Min = Temp; //Temp ��ʱֵ���� Min
                h = j; //�������ǰ�ŵ��ŵ������±긳�� h
            }
        }
        All = All + Min;
        printf("%5d", RLine[h]);
        if (RLine[h] >= Han) { //�жϴŵ����ƶ����򣬼����������⻹����������
            Order = 0;
            t = 1;
        }
        Han = RLine[h];
        DelInq(RLine, h, k); //ÿ���ŵ�����ǰ�ƶ�һλ
        k--;
        while (m > 0) {
            if (Order == 1) //order ���жϴ���ɨ��ķ����ǩ��order �� 1 �Ļ����ŵ������ƶ�
            {
                for (j = x; j <= y; j++) {
                    h = -1;
                    Min = 64000;
                    for (n = x; n <= k; n++) //�ж��뵱ǰ�ŵ�����Ĵŵ���
                    {
                        if (RLine[n] <= Han) {
                            Temp = Han - RLine[n];
                            if (Temp < Min) {
                                Min = Temp; //Temp ��ʱֵ���� Min
                                h = n; //�������ǰ�ŵ��ŵ������±긳�� h
                            }
                        }
                    }
                    if (h != -1) {
                        All = All + Min; //�����ƶ�����
                        printf("%5d", RLine[h]);
                        Han = RLine[h]; //����Ĵŵ�����Ϊ��ǰ�ŵ�
                        DelInq(RLine, h, k);
                        k--;
                    }
                }
                Order = 0; //��������ڵ��ƶ���order ���� 0��ִ�� else ��䣬ʹ�ŵ������ƶ�
                m--; //�������һ�Σ�m ��һ�Σ���֤ while ѭ��ִ������
            } else //order �� 0 �Ļ����ŵ������ƶ�
            {
                for (j = x; j <= y; j++) {
                    h = -1;
                    Min = 64000;
                    for (n = x; n <= k; n++) //�ж��뵱ǰ�ŵ�����Ĵŵ���
                    {
                        if (RLine[n] >= Han) {
                            Temp = RLine[n] - Han;
                            if (Temp < Min) {
                                Min = Temp; //Temp ��ʱֵ���� Min
                                h = n; //�������ǰ�ŵ��ŵ������±긳�� h
                            }
                        }
                    }
                    if (h != -1) {
                        All = All + Min; //�����ƶ�����
                        printf("%5d", RLine[h]);
                        Han = RLine[h]; //����Ĵŵ�����Ϊ��ǰ�ŵ�
                        DelInq(RLine, h, k);
                        k--;
                    }
                }
                Order = 1; //��������ڵ��ƶ���order ���� 0��ִ�� else ��䣬ʹ�ŵ������ƶ�
                m--; //�������һ�Σ�m ��һ�Σ���֤ while ѭ��ִ������
            }
        }
        NAll = NAll + All;
        if ((y - x) > 5) {
            Best[Jage][1] = All;//Best[][1]����ƶ��ŵ���
            Best[Jage][0] = 3;//Best[][0]����㷨�����Ϊ:3
            Jage++;//������ż� 1
            Aver = ((float) All) / 10;//��ƽ��Ѱ������
            printf("\n  �ƶ��ŵ���:<%5d> ", All);
            printf("\n  ƽ��Ѱ������:*%0.2f* ", Aver);
        }
        if (t == 1) printf("\n  �ŵ����������ƶ�");
        else printf("\n  �ŵ����������ƶ�");
        return (Han);
    }

    //ѭ��ɨ���㷨(CSCAN)
    void CSCAN(int Han, int DiscL[]) {

        int j, h, n, Temp, m, k, All, Last, i;
        int RLine[10]; //��������ɵĴŵ������� Discl[]���Ƹ����� RLine[]

        int Min;
        int tmp = 0;
        m = 2;
        k = 9;
        All = 0; //ͳ��ȫ���Ĵŵ�������
        Last = Han;
        CopyL(DiscL, RLine, 9); //���ƴŵ��ŵ���ʱ���� RLine
        printf("\n  ���� CSCAN �㷨�ŵ��ķ���˳��Ϊ:");
        while (k >= 0) {
            for (j = 0; j <= 9; j++) //�ӵ�ǰ�ŵ��ſ�ʼ���������������뵱ǰ�ŵ�����Ĵŵ���
            {
                h = -1;
                Min = 64000;
                for (n = 0; n <= k; n++) {
                    if (RLine[n] >= Han) {
                        Temp = RLine[n] - Han;
                        if (Temp < Min) {
                            Min = Temp;
                            h = n;
                        }
                    }
                }
                if (h != -1) {
                    All = All + Min; //ͳ��һ���ƶ��ľ���
                    printf("%5d", RLine[h]);
                    Han = RLine[h];
                    Last = RLine[h];
                    DelInq(RLine, h, k);
                    k--;
                }
            }
            if (k >= 0) {
                tmp = RLine[0];
                for (i = 0; i < k; i++)//���ʣ�´ŵ��ŵ���Сֵ
                {
                    if (tmp > RLine[i]) tmp = RLine[i];
                }
                Han = tmp;//����С�Ĵŵ��Ÿ��� Han
                Temp = Last - tmp;//������ŵ��ź���С�ŵ��ŵľ����
                All = All + Temp;
            }
        }
        Best[Jage][1] = All;//Best[][1]����ƶ��ŵ���
        Best[Jage][0] = 4;//Best[][0]����㷨�����Ϊ:4
        Jage++;//������ż� 1
        Aver = ((float) All) / 10;//��ƽ��Ѱ������
        printf("\n  �ƶ��ŵ���:<%5d> ", All);
        printf("\n  ƽ��Ѱ������:*%0.2f* ", Aver);
    }

    //N ��ɨ���㷨(NStepScan)
    void N_Step_SCAN(int Han1, int DiscL[]) {
        int i, m, k;
        int RLine1[10];
        NAll = 0;
        m = 2;
        k = 9; //�޶� 10 ���Ĵŵ���
        i = -1;
        CopyL(DiscL, RLine1, 9); //���ƴŵ��ŵ���ʱ���� RLine
        printf("\n  ���� N_Step_SCAN �㷨�ŵ��ķ���˳��Ϊ:");
        for (m = 0; m < 2; m++) //�����޶� 10 �ŵ������� 10 ���ŵ�����Ϊ���飬ÿ��5���ŵ�����ÿ���鰴��SCAN�㷨ִ�У���ѭ��ѭ��2��
        {
            Han1 = SCAN(Han1, RLine1, i + 1, i + 5);
            i = i + 5;
        }
        Best[Jage][1] = NAll;//Best[][1]����ƶ��ŵ���
        Best[Jage][0] = 5;//Best[][0]����㷨�����Ϊ:5
        Aver = ((float) NAll) / 10;//��ƽ��Ѱ������
        printf("\n  �ƶ��ŵ���:<%5d> ", NAll);
        printf("\n  ƽ��Ѱ������:*%0.2f* ", Aver);
    }

    //Ѱ�������ɵ͵�������
    void PaiXu() {
        int i, j, Temp;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                if (Best[j][1] > Best[j + 1][1]) //���ǰһ���㷨���ƶ��ŵ�������ں�һ���ƶ��ŵ�����ִ���������
                {
                    Temp = Best[j + 1][1]; //������������ִ��ð�ݷ����ƶ������С�����������ִ��ÿ���㷨������
                    Best[j + 1][1] = Best[j][1];
                    Best[j][1] = Temp;
                    Temp = Best[j + 1][0]; //��ÿ���㷨�������ð�ݷ�����
                    Best[j + 1][0] = Best[j][0];
                    Best[j][0] = Temp;
                }
            }
        }
    }

}
