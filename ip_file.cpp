#include <iostream>
#include <fstream>
#define max 17
using namespace std;
typedef struct ArCell
{
int adj;    //路径长度
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];

typedef struct   //图中顶点表示主要城市，存放城市的编号、名称、简介等信息，
{
int numrou;//路由编号
char introduction[100]={0};//网络信息
//int money;
//int needtime;
}infotype;

typedef struct//整体图的信息
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//路由数目是 vexnum
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
        cout<<"路由器的编号为："<<b.vexs[i].numrou<<"   ";
        cout<<"路由器的网络地址为："<<b.vexs[i].introduction<<endl;
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
