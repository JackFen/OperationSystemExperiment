#include <windows.h>
#include <conio.h>
#include <stdio.h>

#define MAX 20 //定义缓冲池的最大容量是 20
int count = 5; //初始资源的数量为 5
void Proclucer()//生产者函数
{
    while (1) {
        if (count >= MAX) {
            printf("缓冲池已满!等待 3 秒!\n");
            Sleep(3000);
        } else {
            count++;
            printf("一个资源被释放! 当前资源的总数量是: %d\n", count);
            Sleep(1300); //注意毫秒为单位
        }
    }
}

void Consumer() //消费者函数
{
    while (1) {
        if (count == 0) {
            printf("缓冲池已空!等待 2 秒!\n");
            Sleep(2000);
        } else {
            count--;
            printf("一个资源被占用! 当前资源的数量是: %d \n", count);
            Sleep(2000);
        }
    }
}

HANDLE ahThread;
HANDLE bhThread;
HANDLE hThread;

int tStop() //停止函数
{
    int l = getchar();
    return l;
}

void Start() //开始函数
{
    ahThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Proclucer, NULL, 0, NULL);
    bhThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) Consumer, NULL, 0, NULL);
    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) tStop, NULL, 0, NULL); //多线程
    int IsStop = tStop();
    if (IsStop == 0) //满足停止条件
    {
        CloseHandle(ahThread);
        CloseHandle(bhThread);
        CloseHandle(hThread);
    }
}

void shengcanzexiaofeize() //主函数
{
    printf("**********会出现返回不了主界面的情况*********************\n");
    printf("**************输入0结束模拟****************************\n");
    Start(); //开始
}
int main()
{
    shengcanzexiaofeize();
}