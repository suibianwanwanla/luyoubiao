#include <iostream>
#include <fstream>
#define max 17
using namespace std;
typedef struct ArCell
{
int adj;    //·������
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];

typedef struct   //ͼ�ж����ʾ��Ҫ���У���ų��еı�š����ơ�������Ϣ��
{
int numrou;//·�ɱ��
char introduction[100]={0};//������Ϣ
//int money;
//int needtime;
}infotype;

typedef struct//����ͼ����Ϣ
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//·����Ŀ�� vexnum
}MGraph;
MGraph b;
void in_file()
{
    ifstream in("mingwang.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"can't find the file!"<<endl;
    }
    else
    {
        int i,j,k;
        k=i=0;
        b.vexs[i].numrou=i;
        while(!in.eof())
        {
            j=in.get();
            if(j=='\n')
            {
                i++;
                k=0;
                b.vexs[i].numrou=i;
            }
            else
            {
                b.vexs[i].introduction[k]=j;
                k++;
            }
        }
        b.vexnum=i;
    }
}
void show_group()
{
    int i=0;
    while(i<b.vexnum+1)
    {
        cout<<"·�����ı��Ϊ��"<<b.vexs[i].numrou<<"   ";
        cout<<"·�����������ַΪ��"<<b.vexs[i].introduction<<endl;
        i++;
    }
}
void out_file()
{
    ofstream out("mingkong.txt",ios::out);
    for(int i=0;i<b.vexnum+1;i++)
    {
        for(int k=0;b.vexs[i].introduction[k]!='\0';k++)
        {
            out.put(b.vexs[i].introduction[k]);
        }
        out.put(10);
    }
}
int main()
{
    in_file();
    show_group();
    out_file();
}
