//
// Created by fengzhanwei on 2023/9/1.
//
#include "Mem_LRU.h"
using namespace std;
namespace LRU{
    //��ʼ��������
    void InitData(int (&randomData)[MAX],int n)
    {
        srand((unsigned)time(NULL));
        for(int i = 0; i < n;i++ )
        {
            randomData[i]=rand() % n;
        }
//    randomData[0]=3;
//    randomData[1]=7;
//    randomData[2]=4;
//    randomData[3]=4;
//    randomData[4]=2;
//    randomData[5]=1;
//    randomData[6]=1;
//    randomData[7]=0;
//    randomData[8]=1;
//    randomData[9]=3;
        num=n;
        cout<<"������������Ϊ��";
        for (int i = 0; i < n; ++i) {
            cout<<randomData[i]<<" ";
        }
        cout<<endl;
    }
    //��ӡ��������״̬
    void PrintStatus(Block* &memory,int memorySize)
    {
        cout<<"�������Ѵ��ڵ�����飺";
        Block* temp=memory->next;
        while (temp)
        {
            cout<<temp->No<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    //�������ʹ�õ����㷨
    void LRUSCH(int randomDataNo,Block* &memory,int memorySize)
    {
        cout<<endl;
        PrintStatus(memory,memorySize);
        cout<<"��ǰ���������ţ�"<<randomDataNo<<endl;
        Block* temp=memory;
        int count=0;
        int flag=1;//����ڴ���Ƿ�����
        while (temp->next)
        {
            if (temp->next->No==randomDataNo)
            {
                hitcount+=1;
                flag=0;
                Block *q=memory->next;
                while (q)
                {
                    if(q->count<temp->next->count)
                    {
                        q->count++;
                    }
                    q=q->next;
                }
                temp->next->count=0;
                cout<<"��ǰ�������������"<<endl;
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
            cout<<"��ǰ���������δ���У��Ѳ���LRU�滻���"<<endl;
            Block *q=memory->next;
            while (q)
            {
                q->count++;
                q=q->next;
            }
            Block *Add = new Block;
            Add->No=randomDataNo;
            Add->next= nullptr;
            //����δ������ȱʧ���������
            if(count<memorySize)
            {
                temp->next=Add;
            }
            //�ڴ��������滻��������δʹ�õ������
            if(count==memorySize)
            {
                Block *p=memory->next;
                Block *maxPre=memory;
                while (p->next)
                {
                    if(p->next->count>maxPre->next->count)
                    {
                        maxPre=p;
                    }
                    p=p->next;
                }
                Add->next=maxPre->next->next;
                p=maxPre->next;
                maxPre->next=Add;
                free(p);
            }
            cout<<"�滻���";
            PrintStatus(memory,memorySize);
        }
    }
    //��ӡ���д�����������
    void PrintPrecision()
    {
        cout<<"�����������Ϊ��"<<num<<" ���д�����"<<hitcount<<" �����ʣ�"<<((double)hitcount/num)*100<<"%"<<endl;
    }
    //��װ�������ʹ�õ����㷨
    void LRUALL()
    {
        hitcount=0;
        num=0;
        //Ҫ���ʵ�����������
        int randomData[MAX]={0};
        //ģ������
        BlockList memory=new Block;
        memory->No=-1;
        memory->count=-1;
        memory->next= nullptr;
        //Ҫ���ʵ�����������
        int n=0;
        //�������������������������
        int m=0;
        while (true)
        {
            cout<<"������Ҫ��������������(1~20)��";
            cin>>n;
            if(n>=1&&n<=20)
            {
                break;
            }
            else
            {
                cout<<"����Ƿ�������������"<<endl;
            }
        }
        while (true)
        {
            cout<<"���������������������������������";
            cin>>m;
            if(m<=1)
            {
                cout<<"����Ƿ�������������"<<endl;
            }
            else
            {
                break;
            }
        }
        InitData(randomData,n);
        for(int i=0;i<n;i++)
        {
            LRUSCH(randomData[i],memory,m);
        }
        PrintPrecision();
    }
}