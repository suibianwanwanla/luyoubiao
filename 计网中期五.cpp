#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define n 100
#define max 17
#define MaxInt 0x3f3f3f3f
using namespace std;

typedef struct ArCell
{
int adj;    //路径长度
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];

struct edge{
    int begin;//端点
    int end;//端点
    int weight;//两个端点的权值
};
typedef struct   //图中顶点表示主要城市，存放城市的编号、名称、简介等信息，
{
//char name[30];//路由名称
int numrou;//路由编号
char introduction[100];//网络信息
//int money;
//int needtime;
}infotype;

typedef struct//整体图的信息
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//路由数目是 vexnum
}MGraph;

class route
{
private:
    int table[n][n];//前面是行后面是列
    int num;
    int number[n]={0};
    int*creates();
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_file();//把代码信息导入文件
    void init(MGraph *G);//将文件中信息导入代码
    void ShortestPath_DIJ(MGraph * G);//最短路线算法
    void alter1(MGraph *G);//修改路由信息
    void CreatUDN0(MGraph *G);//增加路由
    void complet(MGraph *G);//将代码信息导入文件函数
};
const int maxn = 110;
MGraph b;
route A;
int times;
char internap[40][40];
int father[maxn];//父节点
edge e[maxn*maxn];//边
int map[maxn][maxn];//代表结点之间的权值
int low[maxn],visited[maxn];
//int n=b.vexnum;

void route::init(MGraph *G){
    G->vexnum=A.num;
    //cout<<G->vexnum<<" !!!";
    for(int i=0;i<G->vexnum;i++)//将二维矩阵内容放入图中
     for(int j=0;j<G->vexnum;j++)
      G->arcs[i][j].adj=A.table[i][j];
      for(int i=0;i<G->vexnum;i++)//将二维矩阵内容放入图中
     for(int j=0;j<G->vexnum;j++)
        if(j!=G->vexnum-1)
      cout<<G->arcs[i][j].adj<<" ";
     else cout<<G->arcs[i][j].adj<<endl;
      for(int i=0;i<G->vexnum;i++)//将存在路由标记
        for(int j=0;j<G->vexnum;j++)
        if(G->arcs[i][j].adj!=max)
        G->vexs[i].numrou=i;
    for(int i=0;i<G->vexnum;i++)
        for(int j=0;j<G->vexnum;j++)
        internap[i][j]=false;
}
void route::into_file()
{
    fstream out;
    out.open("route.txt",ios::out);
    int k;
    k=0;
    out<<num;
    while(k<num)
    {
        k++;
        out<<" "<<k;
    }
    out<<'\n';
    for(int i=0;i<num;i++)
    {
        out<<i+1;
        for(int j=0;j<num;j++)
            out<<" "<<table[i][j];
        out<<'\n';
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
    fstream in;
    in.open("route.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"this is a empty file!"<<endl;
    }
    else
    {
        int i,j,k;
        i=j=0;
        in>>num;
        while(i<num)
        {
            in>>k;
            i++;
        }
        i=0;
        in>>k;
        while(!in.eof())
        {
            in>>table[i][j];
            j++;
            if(j==num)
            {
                i++;
                in>>k;
                j=0;
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
    ofstream out("mingwang.txt",ios::out);
    for(int i=0;i<b.vexnum+1;i++)
    {

        for(int k=0;b.vexs[i].introduction[k]!='\0';k++)
        {
            //cout<<b.vexs[i].introduction[k];
            out.put(b.vexs[i].introduction[k]);
        }
        out.put(10);
    }
}

void menu(){
cout<<"|------------菜单---------------|"<<endl;
cout<<"|                               |"<<endl;
cout<<"|        1-查询路由表           |"<<endl;
cout<<"|        2-修改路由表           |"<<endl;
cout<<"|        3-增加路由器           |"<<endl;
cout<<"|        4-拓扑图信息           |"<<endl;
cout<<"|        5-结束                 |"<<endl;
cout<<"|                               |"<<endl;
cout<<"|-------------------------------|"<<endl;
}

int find(int x){//沿着父节点一直寻找初始父节点
    if( x == father[x]){
        return x;
    }

    father[x] = find(father[x]);
    return father[x];
}

int kruscal(int count){//使用kruscal算法来生成最小生成树并计算带权路径和
    int i;
    int sum = 0;//用sum来记录最小s生成树的边权和

    for( i = 1 ; i < maxn ; ++i){
        father[i] = i;
    }

    for( i = 0 ; i < count ; ++i){//枚举有序边集中的每一条边
        int fx = find(e[i].begin);
        int fy = find(e[i].end);

        if(fx != fy){//若第k条边的两个端点i,j 分别属于两颗不同的子树
            father[fx] = fy;//则将节点i所在的子树并入节点j所在的子树中
            //cout<<"顶点"<<fx<<"  顶点"<<fy<<" 权值为： "<<e[i].weight<<endl;
            sum += e[i].weight;
        }
    }

    return sum;
}

bool compare(const edge& a , const edge& b){
    return a.weight < b.weight;
}
void print(MGraph *G){
    int n1;
    n1=G->vexnum;
       // int i,j;
        for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                map[i][j]=G->arcs[i-1][j-1].adj;
            }
        }
        for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(j==n1&&map[i][j]!=max)
             cout<<map[i][j]<<endl;//将已有边的权值设为0
            else if(j!=n1&&map[i][j]!=max)
            cout<<map[i][j]<<" ";
            else if(j==n1&&map[i][j]==max)
             cout<<"0"<<endl;//将已有边的权值设为0
            else if(j!=n1&&map[i][j]==max)
            cout<<"0"<<" ";
            }
        }
        int mm=0;
       for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(map[i][j]!=0) mm++;
            }}
            mm=mm/2;
            while(mm--){
                for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(map[i][j]!=max) map[j][i]=max;
            }
            }}
            for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(map[i][j]==max) map[i][j]=0;
            }}
        /*for(int i=1;i<=n1;i++)
            for(int j=1;j<=n1;j++)
       if(map[i][j]!=max)
             map[j][i] =max;//将已有边的权值设为0
for(int i=1;i<=n1;i++)
            for(int j=1;j<=n1;j++)
                if(map[i][j]==max)
             map[i][j] =0;//将已有边的权值设为0*/
            /* for(int i=1;i<=n1;i++)//检验
            for(int j=1;j<=n1;j++)
                if(j==n1)
             cout<<map[i][j]<<endl;//将已有边的权值设为0
            else cout<<map[i][j]<<" ";
            getchar();
            getchar();*/
        int count = 0;
        /*for(int i = 1 ; i <= n1 ; ++i){//距离矩阵的处理方式
            for(int j = i+1 ; j <= n1 ; ++j){
                e[count].begin = i;
                e[count].end = j;
                cout<<map[i][j]<<"!!!";
                e[count++].weight = map[i][j];
                //cout<< e[count++].weight <<" !!!!!!";
            }
        }*/
        sort(e,e+count,compare);//kruscal算法要求边有序

        int sum = kruscal(count);

       // printf("%d\n",sum);

}

//prim最小生成树
int prim()
{
    int i,j,pos,min,result=0;
   // memset(visited,0,sizeof(visited));
//从某点开始，分别标记和记录该点
    visited[1]=1;pos=1;
//第一次给low数组赋值
    for(i=1;i<=b.vexnum;i++)
        if(i!=pos) low[i]=map[pos][i];
//再运行n-1次
    for(i=1;i<b.vexnum;i++)
    {
//找出最小权值并记录位置
     min=MaxInt;
     for(j=1;j<=b.vexnum;j++)
         if(visited[j]==0&&min>low[j])
         {
             min=low[j];pos=j;
            // cout<<"顶点 "<<i<<"顶点 "<<j<<endl;
         }
//最小权值累加
    result+=min;
//标记该点
    visited[pos]=1;
//更新权值
    for(j=1;j<=b.vexnum;j++)
        if(visited[j]==0&&low[j]>map[pos][j])
            low[j]=map[pos][j];
    }
    return result;
}

void cmd(){
    cout<<"请选择：  "<<endl;
    int op;
    cin>>op;
    while(op!=5){
    switch(op){
        case 1:
 A.ShortestPath_DIJ(&b);
 getchar();
 getchar();
 system("cls");
 break;
 case 2:
    A.alter1(&b);break;
    getchar();
    getchar();
     system("cls");
    case 3:
    A.CreatUDN0(&b);break;
    getchar();
    getchar();
     system("cls");
    case 4:
    print(&b);
    int ans;
    ans=prim();
//cout<<ans;
    getchar();
    getchar();
     system("cls");
    break;
    default:break;
    }
    menu();
    cout<<"请选择：  "<<endl;
     cin>>op;
      system("cls");
    }
}
int main()
{
menu();
    A.for_file();
    //A.show_table();

    in_file();
    //show_group();
    A.init(&b);
    cmd();
    A.complet(&b);
    out_file();
    A.into_file();
    return 0;
}
void route::ShortestPath_DIJ(MGraph * G)
{
 int v,w,i,min,t=0,x,flag=1,v0;
    int final[20], D[20], p[20][20];
    //cout<<G->vexnum<<"!!";
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
 int flagnum[max];
 for(int i=0;i<max;i++){
    flagnum[i]=-1;
 }
 int flagnum1=-1;
 for(v=0;v<G->vexnum;v++)//将找出来的最短路径长度依次打印出来.
 {
 int flags=0;flagnum1=-1;
  for(w=0;w<G->vexnum;w++)
  {
   if(p[v][w]&&w!=v0)  {printf("-->%d",G->vexs[w].numrou);if(flags==0)flags=1;}
   if(flags==1){//for(int i=0;i<G->vexnum;i++)
                    flags=2;
                flagnum1=w;
               // cout<<flagnum1<<"!!!";
   }
   t++;
  }
  if(t>G->vexnum-1&&v0!=v){printf("       总路线长%dkm\n\n",D[v]);
  if(flagnum1!=-1)
  flagnum[v]=flagnum1;
  }
 }
 for(int i=0;i<max;i++)
    for(int j=0;j<40;j++)
                    internap[i][j]=G->vexs[i].introduction[j];
 int mid;
 cout<<"--------------------------路由表----------------------------"<<endl;
 cout<<"|    目的主机所在网络          下一跳路由                  | "<<endl;
 cout<<"|                                                          | "<<endl;
 cout<<"|                                                          | "<<endl;
  int jjj;
 for(int i=0;i<max;i++)
 if(flagnum[i]!=-1){
 jjj=flagnum[i];
 if(internap[i][0]=='n') cout<<"      "<<internap[i]<<"                     "<<jjj<<"但无法交付"<<endl;else
    cout<<"|     "<<internap[i]<<"         "<<jjj<<endl;
 }
   cout<<"|                                                          | "<<endl;
cout<<"|                                                          | "<<endl;
cout<<"|                                                          | "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
}//ShortestPath_DIJ  end

void route::alter1(MGraph *G)//路由修改
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
 printf("路由器所在网络:");
 scanf("%s",G->vexs[i].introduction);
 cout<<G->vexs[i].introduction;
 //getchar();
 //getchar();
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

void route:: CreatUDN0(MGraph *G)//增加路由信息
{
 int i,j,k,w,midnums;
 char v1[20],v2[20];
 //printf("请输入路由的编号:、名称、简介:\n");
 times=G->vexnum;
 printf("分配到的路由编号:");
 ++times;
 cout<<times<<endl;
 G->vexs[times].numrou=times;
 i=times-1;
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
void route::complet(MGraph *G){
for(int i=0;i<G->vexnum;i++)
    for(int j=0;j<G->vexnum;j++)
    A.table[i][j]=G->arcs[i][j].adj;
A.num=G->vexnum;
/*for(int i=0;i<G->vexnum;i++)
        for(int j=0;j<G->vexnum;j++)
        if(j!=G->vexnum-1)
        cout<<G->arcs[i][j].adj<<" ";
    else cout<<G->arcs[i][j].adj<<" "<<endl;
    for(int i=0;i<G->vexnum;i++)
        for(int j=0;j<G->vexnum;j++)
        if(j!=G->vexnum-1)
        cout<<A.table[i][j]<<" ";
    else cout<<A.table[i][j]<<" "<<endl;
    A.into_file();*/
}
