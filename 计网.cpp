#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define n 100
#define max 17
using namespace std;

typedef struct ArCell
{
int adj;    //路径长度
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];

typedef struct   //图中顶点表示主要城市，存放城市的编号、名称、简介等信息，
{
//char name[30];//路由名称
int numrou;//路由编号
char introduction[100];//网络信息
//int money;
//int needtime;
}infotype;

typedef struct MGraph//整体图的信息
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//路由数目是 vexnum
}MGraph1;

class route
{
private:
    int table[n][n];//前面是行后面是列
    int num;
    int number[n]={0};
    int*creates();
    struct MGraph b;
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_ifon();//以下为网络信息导入
    void output_ifon();
    void show_code();
    void into_file();//把代码信息导入文件
    void init(MGraph1 *G);//将文件中信息导入代码
    void ShortestPath_DIJ(MGraph1 * G);//最短路线算法
    void alter1(MGraph1 *G);//修改路由信息
    void CreatUDN0(MGraph1 *G);//增加路由
    void complet(MGraph1 *G);//将代码信息导入文件函数
};
route A;
int times;
char internap[40][40];
void route::into_ifon()
{
    ifstream in("mingwang.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"this is a empty file!"<<endl;
    }
    else
    {
        int i,j,k,p;
        j=k=p=0;
        while(!in.eof())
        {
            if(k==0)
                b.vexs[j]=new infotype;
            i=in.get();
            if(i<58&&i>48&&k==0)
            {
                i=i-48;
                b.vexs[j]->number=i;
                cout<<b.vexs[j]->number;
                k=1;//标志着路由器的号码
            }
            else if(i==10)
            {
                k=0;//k换行的标志信息
                p=0;//字符串在第二个数组中重新开始输入
                j++;//进入第二个结构体数组
                cout<<endl;
            }
            else if(k==1&&i!=10)
            {
                char b1;
                b1=i;
                //cout<<i<<" ";
                cout<<b1;
                b.vexs[j].introduction[p]=b1;
                //cout<<ifon[j]->a[p];
                p++;
            }
        }
        num=j+1;
    }
}
void route::show_code()
{
    for(int i=0;i<num;i++)
    {
        cout<<"路由器的号码为："<<mid.vexs[i].numrou<<"  ";
        cout<<"网络号为："<<mid.vexs[i].introduction<<endl;
    }
}
void route::output_ifon()
{
    ofstream out("mingkong.txt",ios::out);
    for(int i=0;i<num;i++)
    {
        out.put(ifon[i]->number+48);
        out.put(32);
        for(int k=0;ifon[i]->a[k]!='\0';k++)
        {
            out.put(ifon[i]->a[k]);
        }
        out.put(10);
    }
}
void route::init(MGraph *G){
    G->vexnum=A.num;
    for(int i=0;i<G->vexnum;i++)//将二维矩阵内容放入图中
     for(int j=0;j<G->vexnum;j++)
      G->arcs[i][j].adj=A.table[i][j];
      for(int i=0;i<G->vexnum;i++)//将存在路由标记
        for(int j=0;j<G->vexnum;j++)
        if(G->arcs[i][j].adj!=max)
        G->vexs[i].numrou=i;
    for(int i=0;i<G->vexnum;i++)
        for(int j=0;j<G->vexnum;j++)
        internap[i][j]=false;
        //for(int i=0;i<G->vexnum;i++)
          //  for(int j=0;j<40;j++)
           // G->vexs[i].introduction[j]=A.ifon[i].a[j];
}
void route::into_file()
{
    ofstream out("copy.txt",ios::out);
    char a;
    int o=0;
    while(o<num+1)
    {
        if(o==0)
            out.put(35);
        else
        {
            out.put(o+48);
        }
        o++;
        out.put(32);
    }
    out.put(10);
    o=1;
    for(int t=0;t<num;t++)
    {
        out.put(o+48);
        out.put(32);
        for(int i=0;i<num;i++)
        {
            if(table[t][i]==17)
                a='m';
            else
                a=table[t][i]+48;
            out.put(a);
            out.put(32);
        }
        out.put(10);
        o++;
    }
}
int*route::creates()
{
    for(int i=0;i<num;i++)
        number[i]=i+1;
    return number;
}
void route::for_file()
{
    ifstream in("route.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"this is a empty file!"<<endl;
    }
    else
    {
        int i,j,k;
        i=0;
        while(!in.eof())
        {
            j=in.get();
            if(j==10)
                break;
            i++;
        }
        num=(i-1)/2;//路由器的数目为i;
        i=k=0;
        in.get();//把每次前面的路由器的名称删除。
        while(!in.eof())
        {
            j=in.get();
            if(j>48&&j<58)
            {
                j=j-48;
                table[i][k]=j;
                k++;
            }
            else if(j==109)
            {
                table[i][k]=max;
                k++;
            }
            else if(j==10)
            {
                i++;
                k=0;
                in.get();//把每次前面的路由器的名称删除。
            }
        }
    }
}
void route::show_table()
{
    for(int p=0;p<num;p++)
    {
        for (int t=0;t<num;t++)
            cout<<table[p][t]<<" ";
        cout<<endl;
    }
}
int main()
{

    A.for_file();
    A.show_table();
     A.into_ifon();
    A.show_code();
    A.output_ifon();
    A.init(&A.b);
    A.ShortestPath_DIJ(&A.b);
    A.alter1(&A.b);
    A.CreatUDN0(&A.b);
    A.complet(&A.b);
    return 0;
}
void route::ShortestPath_DIJ(MGraph1 * G)
{
 int v,w,i,min,t=0,x,flag=1,v0;
    int final[20], D[20], p[20][20];
 while(flag)
 {
  printf("请输入一个起始路由编号:");
  scanf("%d",&v0);
  if(v0<0||v0>G->vexnum)
  {
     printf("路由编号不存在!请重新输入路由编号:");
     scanf("%d",&v0);
  }
  if(v0>=0&&v0<G->vexnum)
  flag=0;
 }
 for(v=0;v<G->vexnum;v++)
 {
      final[v]=0;
  D[v]=G->arcs[v0][v].adj;//从起始点到其他顶点有没有边，，进行记录
  for(w=0;w<G->vexnum;w++)
      p[v][w]=0;//初始化全部置为0
  if(D[v]<max)//边存在置为1
  {
   p[v][v0]=1;p[v][v]=1;
  }
 }
 D[v0]=0;final[v0]=1;
 for(i=1;i<G->vexnum;i++)
 {
      min=max;
  for(w=0;w<G->vexnum;w++)
      if(!final[w])
       if(D[w]<min){v=w;min=D[w];}//找出与起点相连最短的边
        final[v]=1;//标记此次找出最短边所代表的顶点。
     for(w=0;w<G->vexnum;w++)
       if(!final[w]&&(min+G->arcs[v][w].adj<D[w]))//如果此相连最短边到目的顶点比记录的小
       {
        D[w]=min+G->arcs[v][w].adj;//更新每个顶点长度.
        for(x=0;x<G->vexnum;x++)//更新记录的到达路径
          p[w][x]=p[v][x];
       p[w][w]=1;
   }
 }//循环完毕，D中记录的是起始顶点到各个顶点的最短路径长度
 for(v=0;v<G->vexnum;v++)//将找出来的最短路径长度依次打印出来.
 {
  //if(v0!=v) printf("%s",G->vexs[v0].name);
  //cout<<endl;
  //cout<<"时刻       城市        路程时间  "<<endl;
 // cout<<"------------------------------------"<<endl;
 int flags=0;
  for(w=0;w<G->vexnum;w++)
  {
   if(p[v][w]&&w!=v0)  {printf("-->%d",G->vexs[w].numrou);if(flags==0)flags=1;}
   if(flags==1){//for(int i=0;i<G->vexnum;i++)
                for(int j=0;j<40;j++)
                    internap[w][j]=G->vexs[w].introduction[j];
                    flags=2;
   }
   t++;
  }
  if(t>G->vexnum-1&&v0!=v){printf("       总路线长%dkm\n\n",D[v]);
  for(int i=0;i<40;i++)
    cout<<internap[i];
  /*int long1;
  long1=D[v];
  int taketime;
  taketime=long1/run;
  taketime=taketime*60;
  for(int i=0;i<G->vexnum;i++){
  if(G->arcs[v][i].adj!=INFINITY){
  taketime=taketime+G->vexs[v].needtime;
  float hour;
  hour=taketime/60;
  hour=starttime[v][i]+hour;
  cout<<hour<<"到站      "<<G->vexs[i].name;
  cout<<"       "<<taketime<<"分钟"<<endl;
  }
  }
  cout<<"------------------------------------"<<endl;
  cout<<endl<<endl<<endl;
  //cout<<"需要花费"<<taketime<<"分钟"<<endl;*/
  }
 }

}//ShortestPath_DIJ  end

void route::alter1(MGraph1 *G)//路由修改
{
 int i,j,k,w;
 char v1[20],v2[20];
 printf("路由编号:");
 cin>>i;
 int jk;
 cout<<"--------请选择修改内容--------"<<endl;
 cout<<"|        1->路线长度          "<<endl;
 cout<<"|        2->删除路线          "<<endl;
 cout<<"|        3->修改网络          "<<endl;
 cout<<"|        4->删除顶点          "<<endl;
 cout<<"|        5->退出              "<<endl;
 cout<<"------------菜单--------------"<<endl;
 cout<<"请选择要修改的内容："<<endl;
 cin>>jk;
 while(jk!=5){
 switch(jk){
 case 1:
 while(1)
 {
    cout<<"相连路由情况："<<endl;
    cout<<"路由编号：";
    cin>>j;
    cout<<"路由长度:";
    cin>>w;
    G->arcs[i][j].adj=w;
    G->arcs[j][i].adj=G->arcs[i][j].adj;
    cout<<"修改成功！！！"<<endl;
    cout<<"是否有其他路由 1、有 2、无"<<endl;
    int have;
    cin>>have;
    if(have==2) break;
    else if(have==1) continue;
    else cout<<"出错啦！"<<endl;
 }
 break;
 case 2:
     while(1){
    cout<<"相连路由情况："<<endl;
    cout<<"路由编号：";
    cin>>j;
    G->arcs[i][j].adj=max;
    G->arcs[j][i].adj=G->arcs[i][j].adj;
    cout<<"修改成功！！！"<<endl;
    cout<<"是否有其他路由 1、有 2、无"<<endl;
    int have;
    cin>>have;
    if(have==2) break;
    else if(have==1) continue;
    else cout<<"出错啦！"<<endl;}
    break;
case 3:
 printf("城市简介:");
 scanf("%s",G->vexs[i].introduction);
 break;
case 4:
    for(int j=0;j<G->vexnum;j++){
    G->arcs[i][j].adj=max;
    G->arcs[j][i].adj=G->arcs[i][j].adj;}
    for(int j=0;j<100;j++)
        G->vexs[i].introduction[j]=false;
    G->vexs[i].numrou=max;
    cout<<"删除成功！！！"<<endl;
   break;
 default: break;
 }
 system("cls");
 cout<<"--------请选择修改内容--------"<<endl;
 cout<<"|        1->路线长度          "<<endl;
 cout<<"|        2->删除路线          "<<endl;
 cout<<"|        3->修改网络          "<<endl;
 cout<<"|        4->删除顶点          "<<endl;
 cout<<"|        5->退出              "<<endl;
 cout<<"------------菜单--------------"<<endl;
 cin>>jk;
     }
}

void route:: CreatUDN0(MGraph1 *G)//增加路由信息
{
 int i,j,k,w,midnums;
 char v1[20],v2[20];
 printf("请输入路由的编号:、名称、简介:\n");
 times=G->vexnum;
 printf("路由编号:");
 ++times;
 cin>>midnums;
 G->vexs[times].numrou=times;
 i=midnums-1;
 printf("路由网络:");
 scanf("%s",G->vexs[i].introduction);
 G->vexnum=times;
 while(1)
    {
    cout<<"此路由和哪个路由新建路由线路"<<endl;
    cout<<"路由编号：";
    cin>>j;
    printf("长度：");
    scanf("%d",&w);
    G->arcs[i][j].adj=w;
    G->arcs[j][i].adj=G->arcs[i][j].adj;
    for(int z=0;z<G->vexnum;z++){
            if(z!=j){
    G->arcs[i][z].adj=max;
    G->arcs[z][i].adj=G->arcs[i][z].adj;}}
    cout<<"是否有其他路由 1、有 2、无"<<endl;
    int have;
    cin>>have;
    if(have==2) break;
    else if(have==1) continue;
    else cout<<"出错啦！"<<endl;
    }
}
void route::complet(MGraph1 *G){
for(int i=0;i<G->vexnum;i++)
    for(int j=0;j<G->vexnum;j++)
    A.table[i][j]=G->arcs[i][j].adj;
A.num=G->vexnum;
for(int i=0;i<G->vexnum;i++)
        for(int j=0;j<G->vexnum;j++)
        if(j!=G->vexnum-1)
        cout<<G->arcs[i][j].adj<<" ";
    else cout<<G->arcs[i][j].adj<<" "<<endl;
    for(int i=0;i<G->vexnum;i++)
        for(int j=0;j<G->vexnum;j++)
        if(j!=G->vexnum-1)
        cout<<A.table[i][j]<<" ";
    else cout<<A.table[i][j]<<" "<<endl;
    A.into_file();
}
