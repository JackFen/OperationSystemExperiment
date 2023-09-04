//
// Created by fengzhanwei on 2023/9/1.
//
#include "Dev_Bank.h"
namespace Device{
    void YinHangJia()//银行家算法的实现
    {
        int i = 0, j = 0;
        char flag = 'Y';
        void showdata();
        void changdata(int);
        void rstordata(int);
        int chkerr(int);
        showdata();
        while (flag == 'Y' || flag == 'y') {
            i = -1;
            while (i < 0 || i >= M) {
                printf("请输入需申请设备的进程号（从 0 到");
                printf("%d", M - 1);
                printf("，否则重输入!）:");
                scanf("%d", &i);
                if (i < 0 || i >= M)printf("输入的进程号不存在，重新输入!\n");
            }
            printf("请输入进程");
            printf("%d", i);
            printf("申请的设备数\n");
            for (j = 0; j < N; j++) {
                printf("设备");
                printf("%d", j);
                printf(":");
                scanf("%d", &Request[j]);
                if (Request[j] > NEED[i][j])//第一步判断申请的设备数是否大于需要的设备数
                {
                    printf("进程");
                    printf("%d", i);
                    printf("申请的设备数大于进程");
                    printf("%d", i);
                    printf("还需要");
                    printf("%d", j);
                    printf("类设备的设备量!申请不合理，出错!请重新选择!\n");
                    flag = 'N';
                    break;
                } else {
                    if (Request[j] > AVAILABLE[j])//第二步判断申请的设备数是否大于可用设备数
                    {
                        printf("进程");
                        printf("%d", i);
                        printf("申请的设备数大于系统可用");
                        printf("%d", j);
                        printf("类设备的设备量!申请不合理，出错!请重新选择!\n");
                        flag = 'N';
                        break;
                    }
                }
            }
            if (flag == 'Y' || flag == 'y') {
                changdata(i);
                if (chkerr(i)) {
                    rstordata(i);
                    showdata();
                } else
                    showdata();
            } else
                showdata();
            printf("\n");
            scanf("%c", &flag);
        }
    }

    void showdata() {
        int i, j;
        printf("系统可用的设备数为:\n");
        printf(" ");
        for (j = 0; j < N; j++) {
            printf(" 设备");
            printf("%d", j);
            printf(":");
            printf("%d", AVAILABLE[j]);
        }
        printf("\n");
        printf("各进程还需要的设备量:\n");
        for (i = 0; i < M; i++) {
            printf(" 进程");
            printf("%d", i);
            printf(":");
            for (j = 0; j < N; j++) {
                printf(" 设备");
                printf("%d", j);
                printf(":");
                printf("%d", NEED[i][j]);
            }
            printf("\n");
        }
        printf("各进程已经得到的设备量: \n");
        for (i = 0; i < M; i++) {
            printf(" 进程");
            printf("%d", i);
/*printf(":\n");*/
            for (j = 0; j < N; j++) {
                printf(" 设备");
                printf("%d", j);
                printf(":");
                printf("%d", ALLOCATION[i][j]);
            }
            printf("\n");
        }
    }

    void changdata(int k) {
        int j;
        for (j = 0; j < N; j++)//修改数据结构的值
        {
            AVAILABLE[j] = AVAILABLE[j] - Request[j];
            ALLOCATION[k][j] = ALLOCATION[k][j] + Request[j];
            NEED[k][j] = NEED[k][j] - Request[j];
        }
    };

    void rstordata(int k) {
        int j;
        for (j = 0; j < N; j++)//修改数据结构的值
        {
            AVAILABLE[j] = AVAILABLE[j] + Request[j];
            ALLOCATION[k][j] = ALLOCATION[k][j] - Request[j];
            NEED[k][j] = NEED[k][j] + Request[j];
        }
    };

    int chkerr(int s) {
        int WORK, FINISH[M], temp[M];
        int i, j, k = 0;
        for (i = 0; i < M; i++)FINISH[i] = FALSE;
        for (j = 0; j < N; j++)//用安全性检查算法判断系统是否安全（即是否为 true）
        {
            WORK = AVAILABLE[j];
            i = s;
            while (i < M) {
                if (FINISH[i] == FALSE && NEED[i][j] <= WORK) {
                    WORK = WORK + ALLOCATION[i][j];
                    FINISH[i] = TRUE;
                    temp[k] = i;
                    k++;
                    i = 0;
                } else {
                    i++;
                }
            }
            for (i = 0; i < M; i++)
                if (FINISH[i] == FALSE) {
                    printf("\n");
                    printf("系统不安全!!! 本次设备申请不成功!!!\n");
                    printf("\n");
                    return 1;
                }
        }
        printf("\n");
        printf("经安全性检查，系统安全，本次分配成功。\n");
        printf("\n");
        printf(" 本次安全序列：");
        for (i = 0; i < M; i++) {
            printf("进程");
            printf("%d", temp[i]);
            printf("->");
        }
        printf("\n");
        return 0;
    }
}