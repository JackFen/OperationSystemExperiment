//
// Created by fengzhanwei on 2023/9/1.
//
#include "Mem_FIFO.h"

using namespace std;
namespace FIFO{
    //��ʼ��������
    void InitData(int (&randomData)[MAX],int n)
    {
        srand((unsigned)time(NULL));
        for(int i = 0; i < n;i++ )
        {
            randomData[i]=rand() % n;
        }
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
    //�Ƚ��ȳ������㷨
    void FIFOSCH(int randomDataNo,Block* &memory,int memorySize)
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
            cout<<"��ǰ���������δ���У��Ѳ���FIFO�滻���"<<endl;
            //����δ������ȱʧ���������
            Block *Add = new Block;
            Add->No=randomDataNo;
            Add->next= nullptr;
            temp->next=Add;
            //�ڴ��������滻����һ������������
            if(count==memorySize)
            {
                Block *q=memory->next;
                memory->next=q->next;
                free(q);
            }
            cout<<"�滻��ɺ�";
            PrintStatus(memory,memorySize);
        }
    }
    //��ӡ���д�����������
    void PrintPrecision()
    {
        cout<<"�����������Ϊ��"<<num<<" ���д�����"<<hitcount<<" �����ʣ�"<<((double)hitcount/num)*100<<"%"<<endl;
    }
    //��װ�Ƚ��ȳ������㷨
    void FIFOALL()
    {
        hitcount=0;
        num=0;
        //Ҫ���ʵ�����������
        int randomData[MAX]={0};
        //ģ������
        BlockList memory=new Block;
        memory->No=-1;
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
            FIFOSCH(randomData[i],memory,m);
        }
        PrintPrecision();
    }
}