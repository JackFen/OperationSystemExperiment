//
// Created by fengzhanwei on 2023/8/31.
//
#include "FileManage.h"
using namespace std;
namespace File{

    void FileMenu() {
        int i;
        int DiscLine[10]; //声明准备要生成的随机磁道号的数组
        int Hand; //磁道数
        int Con = 1;
        int n;
        while (Con == 1) {
            Jage = 0;
            printf("\n 请输入初始的磁道数(0<n<65536):");
            scanf("%d", &Hand);
            printf("\n 输入寻找的范围:");
            scanf("%d", &Limit);
            if (Limit > 65536) {
                printf("超出范围!");
            } else {
                printf("     ╭═══════════════╮\n");
                printf("         文件管理\n");
                printf("║    ║               ║\n");
                printf("║    ╰═══════════════╯\n");
                printf("║   1.先来先服务算法(FCFS)\n");
                printf("║   2.最短寻道时间优先算法(SSTF)\n");
                printf("║   3.扫描算法(SCAN)\n");
                printf("║   4.循环扫描算法(CSCAN)\n");
                printf("║   5.N步扫描算法(NStepScan)\n");
                printf("║   6.各类算法的比较\n");
                printf("╰═┤ 请输入你的选择的算法(输入0离开):");
                scanf("%d", &n);
                printf("\n");
                switch (n) {
                    case 1:
                        SetDI(DiscLine); //随机生成磁道数
                        FCFS(Hand, DiscLine); //先来先服务算法(FCFS)
                        break;
                    case 2:
                        SetDI(DiscLine); //随机生成磁道数
                        SSTF(Hand, DiscLine); //最短寻道时间优先算法(SSTF)
                        break;
                    case 3:
                        SetDI(DiscLine); //随机生成磁道数
                        SCAN(Hand, DiscLine, 0, 9); //扫描算法(SCAN)
                        break;
                    case 4:
                        SetDI(DiscLine); //随机生成磁道数
                        CSCAN(Hand, DiscLine); //循环扫描算法(CSCAN)
                        break;
                    case 5:
                        SetDI(DiscLine); //随机生成磁道数
                        N_Step_SCAN(Hand, DiscLine); //N 步扫描算法(NStepScan)
                        break;
                    case 6:
                        SetDI(DiscLine); //随机生成磁道数
                        FCFS(Hand, DiscLine); //先来先服务算法(FCFS)
                        SSTF(Hand, DiscLine); //最短寻道时间优先算法(SSTF)
                        SCAN(Hand, DiscLine, 0, 9); //扫描算法(SCAN)
                        CSCAN(Hand, DiscLine); //循环扫描算法(CSCAN)
                        N_Step_SCAN(Hand, DiscLine); //N 步扫描算法(NStepScan)
                        PaiXu(); //寻道长度由低到高排序
                        printf("\n\n  寻道长度由低到高排序:");
                        for (i = 0; i < 5; i++) {
                            printf("%4d ", Best[i][0]);
                        }
                        break;
                    default:
                        return;
                }
                printf("\n\n  是否继续(按 0 结束,按 1 继续)?");
                scanf("%5d", &Con);
            }

        }
    }

    //数组 Sour 复制到数组 Dist，复制到 x 个数
    void CopyL(int Sour[], int Dist[], int x) {
        int i;
        for (i = 0; i <= x; i++) {
            Dist[i] = Sour[i];
        }
    }

    //打印输出数组 Pri
    void Print(int Pri[], int x) {
        int i;
        for (i = 0; i <= x; i++) {
            printf("%5d", Pri[i]);
        }
    }

    //随机生成磁道数
    void SetDI(int DiscL[]) {
        int i;
        for (i = 0; i <= 9; i++) {
            DiscL[i] = rand() % Limit;//随机生成 10 个磁道号
        }
        printf("  需要寻找的磁道号:");
        Print(DiscL, 9); //输出随机生成的磁道号
        printf("\n");
    }

    //数组 Sour 把 x 位置的数删除，并把 y 前面的数向前移动，y 后的数保持不变(即会出现 2个 y)
    void DelInq(int Sour[], int x, int y) {
        int i;
        for (i = x; i < y; i++) {
            Sour[i] = Sour[i + 1];
            x++;
        }
    }

    //先来先服务算法(FCFS)
    void FCFS(int Han, int DiscL[]) {
        int RLine[10]; //将随机生成的磁道数数组 Discl[]复制给数组 RLine[]
        int i, k, All, Temp; //Temp 是计算移动的磁道距离的临时变量
        All = 0; //统计全部的磁道数变量
        k = 9; //限定 10 个的磁道数
        CopyL(DiscL, RLine, 9); //复制磁道号到临时数组 RLine
        printf("\n  按照 FCFS 算法磁道的访问顺序为:");
        All = Han - RLine[0];
        for (i = 0; i <= 9; i++) {
            Temp = RLine[0] - RLine[1];//求出移动磁道数,前一个磁道数减去后一个磁道数得出临时的移动距离
            if (Temp < 0)
                Temp = (-Temp);//移动磁道数为负数时,算出相反数作为移动磁道数
            printf("%5d", RLine[0]);
            All = Temp + All;//求全部磁道数的总和
            DelInq(RLine, 0, k);//每个磁道数向前移动一位
            k--;
        }
        Best[Jage][1] = All;//Best[][1]存放移动磁道数
        Best[Jage][0] = 1; //Best[][0]存放算法的序号为:1
        Jage++;//排序的序号加 1
        Aver = ((float) All) / 10;//求平均寻道次数
        printf("\n  移动磁道数:<%5d> ", All);
        printf("\n  平均寻道长度:*%0.2f* ", Aver);
    }

    //最短寻道时间优先算法(SSTF)
    void SSTF(int Han, int DiscL[]) {
        int i, j, k, h, All;
        int Temp; //Temp 是计算移动的磁道距离的临时变量
        int RLine[10]; //将随机生成的磁道数数组 Discl[]复制给数组 RLine[]
        int Min;
        All = 0; //统计全部的磁道数变量
        k = 9; //限定 10 个的磁道数
        CopyL(DiscL, RLine, 9); //复制磁道号到临时数组 RLine
        printf("\n  按照 SSTF 算法磁道的访问顺序为:");
        for (i = 0; i <= 9; i++) {
            Min = 64000;
            for (j = 0; j <= k; j++) //内循环寻找与当前磁道号最短寻道的时间的磁道号
            {
                if (RLine[j] > Han) //如果第一个随机生成的磁道号大于当前的磁道号，执行下一句
                    Temp = RLine[j] - Han; //求出临时的移动距离
                else
                    Temp = Han - RLine[j]; //求出临时的移动距离
                if (Temp < Min) //如果每求出一次的移动距离小于 Min，执行下一句
                {
                    Min = Temp; //Temp 临时值赋予 Min
                    h = j; //把最近当前磁道号的数组下标赋予 h
                }
            }
            All = All + Min; //统计一共移动的距离
            printf("%5d", RLine[h]);
            Han = RLine[h];
            DelInq(RLine, h, k); //每个磁道数向前移动一位
            k--;
        }
        Best[Jage][1] = All;//Best[][1]存放移动磁道数
        Best[Jage][0] = 2;//Best[][0]存放算法的序号为:2
        Jage++;//排序序号加 1
        Aver = ((float) All) / 10;//求平均寻道次数
        printf("\n  移动磁道数:<%5d> ", All);
        printf("\n  平均寻道长度:*%0.2f* ", Aver);
    }

    //扫描算法(SCAN)
    int SCAN(int Han, int DiscL[], int x, int y) {
        int j, n, k, h, m, All;
        int t = 0;
        int Temp;
        int Min;
        int RLine[10]; //将随机生成的磁道数数组 Discl[]复制给数组 RLine[]
        int Order;
        Order = 1;
        k = y;
        m = 2; //控制 while 语句的执行，即是一定要使当前磁道向内向外都要扫描到
        All = 0; //统计全部的磁道数变量
        CopyL(DiscL, RLine, 9); //复制磁道号到临时数组 RLine
        printf("\n  按照 SCAN 算法磁道的访问顺序为:");
        Min = 64000;
        for (j = x; j <= y; j++) //寻找与当前磁道号最短寻道的时间的磁道号
        {
            if (RLine[j] > Han) //如果第一个随机生成的磁道号大于当前的磁道号，执行下一句
                Temp = RLine[j] - Han; //求出临时的移动距离
            else
                Temp = Han - RLine[j]; //求出临时的移动距离
            if (Temp < Min) {
                Min = Temp; //Temp 临时值赋予 Min
                h = j; //把最近当前磁道号的数组下标赋予 h
            }
        }
        All = All + Min;
        printf("%5d", RLine[h]);
        if (RLine[h] >= Han) { //判断磁道的移动方向，即是由里向外还是由外向里
            Order = 0;
            t = 1;
        }
        Han = RLine[h];
        DelInq(RLine, h, k); //每个磁道数向前移动一位
        k--;
        while (m > 0) {
            if (Order == 1) //order 是判断磁盘扫描的方向标签，order 是 1 的话，磁道向内移动
            {
                for (j = x; j <= y; j++) {
                    h = -1;
                    Min = 64000;
                    for (n = x; n <= k; n++) //判断离当前磁道最近的磁道号
                    {
                        if (RLine[n] <= Han) {
                            Temp = Han - RLine[n];
                            if (Temp < Min) {
                                Min = Temp; //Temp 临时值赋予 Min
                                h = n; //把最近当前磁道号的数组下标赋予 h
                            }
                        }
                    }
                    if (h != -1) {
                        All = All + Min; //叠加移动距离
                        printf("%5d", RLine[h]);
                        Han = RLine[h]; //最近的磁道号作为当前磁道
                        DelInq(RLine, h, k);
                        k--;
                    }
                }
                Order = 0; //当完成向内的移动，order 赋予 0，执行 else 语句，使磁道向外移动
                m--; //向内完成一次，m 减一次，保证 while 循环执行两次
            } else //order 是 0 的话，磁道向外移动
            {
                for (j = x; j <= y; j++) {
                    h = -1;
                    Min = 64000;
                    for (n = x; n <= k; n++) //判断离当前磁道最近的磁道号
                    {
                        if (RLine[n] >= Han) {
                            Temp = RLine[n] - Han;
                            if (Temp < Min) {
                                Min = Temp; //Temp 临时值赋予 Min
                                h = n; //把最近当前磁道号的数组下标赋予 h
                            }
                        }
                    }
                    if (h != -1) {
                        All = All + Min; //叠加移动距离
                        printf("%5d", RLine[h]);
                        Han = RLine[h]; //最近的磁道号作为当前磁道
                        DelInq(RLine, h, k);
                        k--;
                    }
                }
                Order = 1; //当完成向内的移动，order 赋予 0，执行 else 语句，使磁道向外移动
                m--; //向内完成一次，m 减一次，保证 while 循环执行两次
            }
        }
        NAll = NAll + All;
        if ((y - x) > 5) {
            Best[Jage][1] = All;//Best[][1]存放移动磁道数
            Best[Jage][0] = 3;//Best[][0]存放算法的序号为:3
            Jage++;//排序序号加 1
            Aver = ((float) All) / 10;//求平均寻道次数
            printf("\n  移动磁道数:<%5d> ", All);
            printf("\n  平均寻道长度:*%0.2f* ", Aver);
        }
        if (t == 1) printf("\n  磁道由内向外移动");
        else printf("\n  磁道由外向内移动");
        return (Han);
    }

    //循环扫描算法(CSCAN)
    void CSCAN(int Han, int DiscL[]) {

        int j, h, n, Temp, m, k, All, Last, i;
        int RLine[10]; //将随机生成的磁道数数组 Discl[]复制给数组 RLine[]

        int Min;
        int tmp = 0;
        m = 2;
        k = 9;
        All = 0; //统计全部的磁道数变量
        Last = Han;
        CopyL(DiscL, RLine, 9); //复制磁道号到临时数组 RLine
        printf("\n  按照 CSCAN 算法磁道的访问顺序为:");
        while (k >= 0) {
            for (j = 0; j <= 9; j++) //从当前磁道号开始，由内向外搜索离当前磁道最近的磁道号
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
                    All = All + Min; //统计一共移动的距离
                    printf("%5d", RLine[h]);
                    Han = RLine[h];
                    Last = RLine[h];
                    DelInq(RLine, h, k);
                    k--;
                }
            }
            if (k >= 0) {
                tmp = RLine[0];
                for (i = 0; i < k; i++)//算出剩下磁道号的最小值
                {
                    if (tmp > RLine[i]) tmp = RLine[i];
                }
                Han = tmp;//把最小的磁道号赋给 Han
                Temp = Last - tmp;//求出最大磁道号和最小磁道号的距离差
                All = All + Temp;
            }
        }
        Best[Jage][1] = All;//Best[][1]存放移动磁道数
        Best[Jage][0] = 4;//Best[][0]存放算法的序号为:4
        Jage++;//排序序号加 1
        Aver = ((float) All) / 10;//求平均寻道次数
        printf("\n  移动磁道数:<%5d> ", All);
        printf("\n  平均寻道长度:*%0.2f* ", Aver);
    }

    //N 步扫描算法(NStepScan)
    void N_Step_SCAN(int Han1, int DiscL[]) {
        int i, m, k;
        int RLine1[10];
        NAll = 0;
        m = 2;
        k = 9; //限定 10 个的磁道数
        i = -1;
        CopyL(DiscL, RLine1, 9); //复制磁道号到临时数组 RLine
        printf("\n  按照 N_Step_SCAN 算法磁道的访问顺序为:");
        for (m = 0; m < 2; m++) //由于限定 10 磁道数，将 10 个磁道数分为两组，每组5个磁道数，每个组按照SCAN算法执行，该循环循环2次
        {
            Han1 = SCAN(Han1, RLine1, i + 1, i + 5);
            i = i + 5;
        }
        Best[Jage][1] = NAll;//Best[][1]存放移动磁道数
        Best[Jage][0] = 5;//Best[][0]存放算法的序号为:5
        Aver = ((float) NAll) / 10;//求平均寻道次数
        printf("\n  移动磁道数:<%5d> ", NAll);
        printf("\n  平均寻道长度:*%0.2f* ", Aver);
    }

    //寻道长度由低到高排序
    void PaiXu() {
        int i, j, Temp;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                if (Best[j][1] > Best[j + 1][1]) //如果前一个算法的移动磁道距离大于后一个移动磁道数，执行下面语句
                {
                    Temp = Best[j + 1][1]; //从这起下三行执行冒泡法将移动距离大小排序，排完后则执行每个算法的排序
                    Best[j + 1][1] = Best[j][1];
                    Best[j][1] = Temp;
                    Temp = Best[j + 1][0]; //将每个算法的序号用冒泡法排序
                    Best[j + 1][0] = Best[j][0];
                    Best[j][0] = Temp;
                }
            }
        }
    }

}
