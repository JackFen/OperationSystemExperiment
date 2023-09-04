//
// Created by fengzhanwei on 2023/9/1.
//
#include "Dev_Bank.h"
namespace Device{
    void YinHangJia()//���м��㷨��ʵ��
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
                printf("�������������豸�Ľ��̺ţ��� 0 ��");
                printf("%d", M - 1);
                printf("������������!��:");
                scanf("%d", &i);
                if (i < 0 || i >= M)printf("����Ľ��̺Ų����ڣ���������!\n");
            }
            printf("���������");
            printf("%d", i);
            printf("������豸��\n");
            for (j = 0; j < N; j++) {
                printf("�豸");
                printf("%d", j);
                printf(":");
                scanf("%d", &Request[j]);
                if (Request[j] > NEED[i][j])//��һ���ж�������豸���Ƿ������Ҫ���豸��
                {
                    printf("����");
                    printf("%d", i);
                    printf("������豸�����ڽ���");
                    printf("%d", i);
                    printf("����Ҫ");
                    printf("%d", j);
                    printf("���豸���豸��!���벻��������!������ѡ��!\n");
                    flag = 'N';
                    break;
                } else {
                    if (Request[j] > AVAILABLE[j])//�ڶ����ж�������豸���Ƿ���ڿ����豸��
                    {
                        printf("����");
                        printf("%d", i);
                        printf("������豸������ϵͳ����");
                        printf("%d", j);
                        printf("���豸���豸��!���벻��������!������ѡ��!\n");
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
        printf("ϵͳ���õ��豸��Ϊ:\n");
        printf(" ");
        for (j = 0; j < N; j++) {
            printf(" �豸");
            printf("%d", j);
            printf(":");
            printf("%d", AVAILABLE[j]);
        }
        printf("\n");
        printf("�����̻���Ҫ���豸��:\n");
        for (i = 0; i < M; i++) {
            printf(" ����");
            printf("%d", i);
            printf(":");
            for (j = 0; j < N; j++) {
                printf(" �豸");
                printf("%d", j);
                printf(":");
                printf("%d", NEED[i][j]);
            }
            printf("\n");
        }
        printf("�������Ѿ��õ����豸��: \n");
        for (i = 0; i < M; i++) {
            printf(" ����");
            printf("%d", i);
/*printf(":\n");*/
            for (j = 0; j < N; j++) {
                printf(" �豸");
                printf("%d", j);
                printf(":");
                printf("%d", ALLOCATION[i][j]);
            }
            printf("\n");
        }
    }

    void changdata(int k) {
        int j;
        for (j = 0; j < N; j++)//�޸����ݽṹ��ֵ
        {
            AVAILABLE[j] = AVAILABLE[j] - Request[j];
            ALLOCATION[k][j] = ALLOCATION[k][j] + Request[j];
            NEED[k][j] = NEED[k][j] - Request[j];
        }
    };

    void rstordata(int k) {
        int j;
        for (j = 0; j < N; j++)//�޸����ݽṹ��ֵ
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
        for (j = 0; j < N; j++)//�ð�ȫ�Լ���㷨�ж�ϵͳ�Ƿ�ȫ�����Ƿ�Ϊ true��
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
                    printf("ϵͳ����ȫ!!! �����豸���벻�ɹ�!!!\n");
                    printf("\n");
                    return 1;
                }
        }
        printf("\n");
        printf("����ȫ�Լ�飬ϵͳ��ȫ�����η���ɹ���\n");
        printf("\n");
        printf(" ���ΰ�ȫ���У�");
        for (i = 0; i < M; i++) {
            printf("����");
            printf("%d", temp[i]);
            printf("->");
        }
        printf("\n");
        return 0;
    }
}