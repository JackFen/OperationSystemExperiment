#include <windows.h>
#include <conio.h>
#include <stdio.h>

#define MAX 20 //���建��ص���������� 20
int count = 5; //��ʼ��Դ������Ϊ 5
void Proclucer()//�����ߺ���
{
    while (1) {
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
    while (1) {
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

HANDLE ahThread;
HANDLE bhThread;
HANDLE hThread;

int tStop() //ֹͣ����
{
    int l = getchar();
    return l;
}

void Start() //��ʼ����
{
    ahThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Proclucer, NULL, 0, NULL);
    bhThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Consumer, NULL, 0, NULL);
    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) tStop, NULL, 0, NULL); //���߳�
    int IsStop = tStop();
    if (IsStop == 0) //����ֹͣ����
    {
        CloseHandle(ahThread);
        CloseHandle(bhThread);
        CloseHandle(hThread);
    }
}

void shengcanzexiaofeize() //������
{
    printf("**********����ַ��ز�������������*********************\n");
    printf("**************����0����ģ��****************************\n");
    Start(); //��ʼ
}
int main()
{
    shengcanzexiaofeize();
}