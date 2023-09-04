//
// Created by fengzhanwei on 2023/9/1.
//
#include "Mem_FIFO.h"

using namespace std;
namespace FIFO{
    //初始化主存块号
    void InitData(int (&randomData)[MAX],int n)
    {
        srand((unsigned)time(NULL));
        for(int i = 0; i < n;i++ )
        {
            randomData[i]=rand() % n;
        }
        num=n;
        cout<<"主存块访问序列为：";
        for (int i = 0; i < n; ++i) {
            cout<<randomData[i]<<" ";
        }
        cout<<endl;
    }
    //打印主存块调度状态
    void PrintStatus(Block* &memory,int memorySize)
    {
        cout<<"主存中已存在的主存块：";
        Block* temp=memory->next;
        while (temp)
        {
            cout<<temp->No<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    //先进先出调度算法
    void FIFOSCH(int randomDataNo,Block* &memory,int memorySize)
    {
        cout<<endl;
        PrintStatus(memory,memorySize);
        cout<<"当前访问主存块号："<<randomDataNo<<endl;
        Block* temp=memory;
        int count=0;
        int flag=1;//标记内存块是否命中
        while (temp->next)
        {
            if (temp->next->No==randomDataNo)
            {
                hitcount+=1;
                flag=0;
                cout<<"当前访问主存块命中"<<endl;
                break;
            }
            else
            {
                count++;
            }
            temp=temp->next;
        }
        if(flag)
        {
            cout<<"当前访问主存块未命中，已采用FIFO替换完成"<<endl;
            //主存未满，将缺失块调入主存
            Block *Add = new Block;
            Add->No=randomDataNo;
            Add->next= nullptr;
            temp->next=Add;
            //内存已满，替换掉第一个进入的主存块
            if(count==memorySize)
            {
                Block *q=memory->next;
                memory->next=q->next;
                free(q);
            }
            cout<<"替换完成后";
            PrintStatus(memory,memorySize);
        }
    }
    //打印命中次数及命中率
    void PrintPrecision()
    {
        cout<<"访问主存块数为："<<num<<" 命中次数："<<hitcount<<" 命中率："<<((double)hitcount/num)*100<<"%"<<endl;
    }
    //封装先进先出调度算法
    void FIFOALL()
    {
        hitcount=0;
        num=0;
        //要访问的主存块号序列
        int randomData[MAX]={0};
        //模拟主存
        BlockList memory=new Block;
        memory->No=-1;
        memory->next= nullptr;
        //要访问的主存块号总数
        int n=0;
        //主存可用来存放主存块的最大数量
        int m=0;
        while (true)
        {
            cout<<"请输入要访问主存块的数量(1~20)：";
            cin>>n;
            if(n>=1&&n<=20)
            {
                break;
            }
            else
            {
                cout<<"输入非法，请重新输入"<<endl;
            }
        }
        while (true)
        {
            cout<<"请输入主存可用来存放主存块的最大数量：";
            cin>>m;
            if(m<=1)
            {
                cout<<"输入非法，请重新输入"<<endl;
            }
            else
            {
                break;
            }
        }
        InitData(randomData,n);
        for(int i=0;i<n;i++)
        {
            FIFOSCH(randomData[i],memory,m);
        }
        PrintPrecision();
    }
}