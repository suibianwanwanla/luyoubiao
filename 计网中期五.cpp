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
int adj;    //·������
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];

struct edge{
    int begin;//�˵�
    int end;//�˵�
    int weight;//�����˵��Ȩֵ
};
typedef struct   //ͼ�ж����ʾ��Ҫ���У���ų��еı�š����ơ�������Ϣ��
{
//char name[30];//·������
int numrou;//·�ɱ��
char introduction[100];//������Ϣ
//int money;
//int needtime;
}infotype;

typedef struct//����ͼ����Ϣ
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//·����Ŀ�� vexnum
}MGraph;

class route
{
private:
    int table[n][n];//ǰ�����к�������
    int num;
    int number[n]={0};
    int*creates();
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_file();//�Ѵ�����Ϣ�����ļ�
    void init(MGraph *G);//���ļ�����Ϣ�������
    void ShortestPath_DIJ(MGraph * G);//���·���㷨
    void alter1(MGraph *G);//�޸�·����Ϣ
    void CreatUDN0(MGraph *G);//����·��
    void complet(MGraph *G);//��������Ϣ�����ļ�����
};
const int maxn = 110;
MGraph b;
route A;
int times;
char internap[40][40];
int father[maxn];//���ڵ�
edge e[maxn*maxn];//��
int map[maxn][maxn];//������֮���Ȩֵ
int low[maxn],visited[maxn];
//int n=b.vexnum;

void route::init(MGraph *G){
    G->vexnum=A.num;
    //cout<<G->vexnum<<" !!!";
    for(int i=0;i<G->vexnum;i++)//����ά�������ݷ���ͼ��
     for(int j=0;j<G->vexnum;j++)
      G->arcs[i][j].adj=A.table[i][j];
      for(int i=0;i<G->vexnum;i++)//����ά�������ݷ���ͼ��
     for(int j=0;j<G->vexnum;j++)
        if(j!=G->vexnum-1)
      cout<<G->arcs[i][j].adj<<" ";
     else cout<<G->arcs[i][j].adj<<endl;
      for(int i=0;i<G->vexnum;i++)//������·�ɱ��
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
        cout<<"·�����ı��Ϊ��"<<b.vexs[i].numrou<<"   ";
        cout<<"·�����������ַΪ��"<<b.vexs[i].introduction<<endl;
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
cout<<"|------------�˵�---------------|"<<endl;
cout<<"|                               |"<<endl;
cout<<"|        1-��ѯ·�ɱ�           |"<<endl;
cout<<"|        2-�޸�·�ɱ�           |"<<endl;
cout<<"|        3-����·����           |"<<endl;
cout<<"|        4-����ͼ��Ϣ           |"<<endl;
cout<<"|        5-����                 |"<<endl;
cout<<"|                               |"<<endl;
cout<<"|-------------------------------|"<<endl;
}

int find(int x){//���Ÿ��ڵ�һֱѰ�ҳ�ʼ���ڵ�
    if( x == father[x]){
        return x;
    }

    father[x] = find(father[x]);
    return father[x];
}

int kruscal(int count){//ʹ��kruscal�㷨��������С�������������Ȩ·����
    int i;
    int sum = 0;//��sum����¼��Сs�������ı�Ȩ��

    for( i = 1 ; i < maxn ; ++i){
        father[i] = i;
    }

    for( i = 0 ; i < count ; ++i){//ö������߼��е�ÿһ����
        int fx = find(e[i].begin);
        int fy = find(e[i].end);

        if(fx != fy){//����k���ߵ������˵�i,j �ֱ��������Ų�ͬ������
            father[fx] = fy;//�򽫽ڵ�i���ڵ���������ڵ�j���ڵ�������
            //cout<<"����"<<fx<<"  ����"<<fy<<" ȨֵΪ�� "<<e[i].weight<<endl;
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
             cout<<map[i][j]<<endl;//�����бߵ�Ȩֵ��Ϊ0
            else if(j!=n1&&map[i][j]!=max)
            cout<<map[i][j]<<" ";
            else if(j==n1&&map[i][j]==max)
             cout<<"0"<<endl;//�����бߵ�Ȩֵ��Ϊ0
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
             map[j][i] =max;//�����бߵ�Ȩֵ��Ϊ0
for(int i=1;i<=n1;i++)
            for(int j=1;j<=n1;j++)
                if(map[i][j]==max)
             map[i][j] =0;//�����бߵ�Ȩֵ��Ϊ0*/
            /* for(int i=1;i<=n1;i++)//����
            for(int j=1;j<=n1;j++)
                if(j==n1)
             cout<<map[i][j]<<endl;//�����бߵ�Ȩֵ��Ϊ0
            else cout<<map[i][j]<<" ";
            getchar();
            getchar();*/
        int count = 0;
        /*for(int i = 1 ; i <= n1 ; ++i){//�������Ĵ���ʽ
            for(int j = i+1 ; j <= n1 ; ++j){
                e[count].begin = i;
                e[count].end = j;
                cout<<map[i][j]<<"!!!";
                e[count++].weight = map[i][j];
                //cout<< e[count++].weight <<" !!!!!!";
            }
        }*/
        sort(e,e+count,compare);//kruscal�㷨Ҫ�������

        int sum = kruscal(count);

       // printf("%d\n",sum);

}

//prim��С������
int prim()
{
    int i,j,pos,min,result=0;
   // memset(visited,0,sizeof(visited));
//��ĳ�㿪ʼ���ֱ��Ǻͼ�¼�õ�
    visited[1]=1;pos=1;
//��һ�θ�low���鸳ֵ
    for(i=1;i<=b.vexnum;i++)
        if(i!=pos) low[i]=map[pos][i];
//������n-1��
    for(i=1;i<b.vexnum;i++)
    {
//�ҳ���СȨֵ����¼λ��
     min=MaxInt;
     for(j=1;j<=b.vexnum;j++)
         if(visited[j]==0&&min>low[j])
         {
             min=low[j];pos=j;
            // cout<<"���� "<<i<<"���� "<<j<<endl;
         }
//��СȨֵ�ۼ�
    result+=min;
//��Ǹõ�
    visited[pos]=1;
//����Ȩֵ
    for(j=1;j<=b.vexnum;j++)
        if(visited[j]==0&&low[j]>map[pos][j])
            low[j]=map[pos][j];
    }
    return result;
}

void cmd(){
    cout<<"��ѡ��  "<<endl;
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
    cout<<"��ѡ��  "<<endl;
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
  printf("������һ����ʼ·�ɱ��:");
  scanf("%d",&v0);
  if(v0<0||v0>G->vexnum)
  {
     printf("·�ɱ�Ų�����!����������·�ɱ��:");
     scanf("%d",&v0);
  }
  if(v0>=0&&v0<G->vexnum)
  flag=0;
 }
 for(v=0;v<G->vexnum;v++)
 {
      final[v]=0;
  D[v]=G->arcs[v0][v].adj;//����ʼ�㵽����������û�бߣ������м�¼
  for(w=0;w<G->vexnum;w++)
      p[v][w]=0;//��ʼ��ȫ����Ϊ0
  if(D[v]<max)//�ߴ�����Ϊ1
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
       if(D[w]<min){v=w;min=D[w];}//�ҳ������������̵ı�
        final[v]=1;//��Ǵ˴��ҳ���̱�������Ķ��㡣
     for(w=0;w<G->vexnum;w++)
       if(!final[w]&&(min+G->arcs[v][w].adj<D[w]))//�����������̱ߵ�Ŀ�Ķ���ȼ�¼��С
       {
        D[w]=min+G->arcs[v][w].adj;//����ÿ�����㳤��.
        for(x=0;x<G->vexnum;x++)//���¼�¼�ĵ���·��
          p[w][x]=p[v][x];
       p[w][w]=1;
   }
 }//ѭ����ϣ�D�м�¼������ʼ���㵽������������·������
 int flagnum[max];
 for(int i=0;i<max;i++){
    flagnum[i]=-1;
 }
 int flagnum1=-1;
 for(v=0;v<G->vexnum;v++)//���ҳ��������·���������δ�ӡ����.
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
  if(t>G->vexnum-1&&v0!=v){printf("       ��·�߳�%dkm\n\n",D[v]);
  if(flagnum1!=-1)
  flagnum[v]=flagnum1;
  }
 }
 for(int i=0;i<max;i++)
    for(int j=0;j<40;j++)
                    internap[i][j]=G->vexs[i].introduction[j];
 int mid;
 cout<<"--------------------------·�ɱ�----------------------------"<<endl;
 cout<<"|    Ŀ��������������          ��һ��·��                  | "<<endl;
 cout<<"|                                                          | "<<endl;
 cout<<"|                                                          | "<<endl;
  int jjj;
 for(int i=0;i<max;i++)
 if(flagnum[i]!=-1){
 jjj=flagnum[i];
 if(internap[i][0]=='n') cout<<"      "<<internap[i]<<"                     "<<jjj<<"���޷�����"<<endl;else
    cout<<"|     "<<internap[i]<<"         "<<jjj<<endl;
 }
   cout<<"|                                                          | "<<endl;
cout<<"|                                                          | "<<endl;
cout<<"|                                                          | "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
}//ShortestPath_DIJ  end

void route::alter1(MGraph *G)//·���޸�
{
 int i,j,k,w;
 char v1[20],v2[20];
 printf("·�ɱ��:");
 cin>>i;
 int jk;
 cout<<"--------��ѡ���޸�����--------"<<endl;
 cout<<"|        1->·�߳���          "<<endl;
 cout<<"|        2->ɾ��·��          "<<endl;
 cout<<"|        3->�޸�����          "<<endl;
 cout<<"|        4->ɾ������          "<<endl;
 cout<<"|        5->�˳�              "<<endl;
 cout<<"------------�˵�--------------"<<endl;
 cout<<"��ѡ��Ҫ�޸ĵ����ݣ�"<<endl;
 cin>>jk;
 while(jk!=5){
 switch(jk){
 case 1:
 while(1)
 {
    cout<<"����·�������"<<endl;
    cout<<"·�ɱ�ţ�";
    cin>>j;
    cout<<"·�ɳ���:";
    cin>>w;
    G->arcs[i][j].adj=w;
    G->arcs[j][i].adj=G->arcs[i][j].adj;
    cout<<"�޸ĳɹ�������"<<endl;
    cout<<"�Ƿ�������·�� 1���� 2����"<<endl;
    int have;
    cin>>have;
    if(have==2) break;
    else if(have==1) continue;
    else cout<<"��������"<<endl;
 }
 break;
 case 2:
     while(1){
    cout<<"����·�������"<<endl;
    cout<<"·�ɱ�ţ�";
    cin>>j;
    G->arcs[i][j].adj=max;
    G->arcs[j][i].adj=G->arcs[i][j].adj;
    cout<<"�޸ĳɹ�������"<<endl;
    cout<<"�Ƿ�������·�� 1���� 2����"<<endl;
    int have;
    cin>>have;
    if(have==2) break;
    else if(have==1) continue;
    else cout<<"��������"<<endl;}
    break;
case 3:
 printf("·������������:");
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
    cout<<"ɾ���ɹ�������"<<endl;
   break;
 default: break;
 }
 system("cls");
 cout<<"--------��ѡ���޸�����--------"<<endl;
 cout<<"|        1->·�߳���          "<<endl;
 cout<<"|        2->ɾ��·��          "<<endl;
 cout<<"|        3->�޸�����          "<<endl;
 cout<<"|        4->ɾ������          "<<endl;
 cout<<"|        5->�˳�              "<<endl;
 cout<<"------------�˵�--------------"<<endl;
 cin>>jk;
     }
}

void route:: CreatUDN0(MGraph *G)//����·����Ϣ
{
 int i,j,k,w,midnums;
 char v1[20],v2[20];
 //printf("������·�ɵı��:�����ơ����:\n");
 times=G->vexnum;
 printf("���䵽��·�ɱ��:");
 ++times;
 cout<<times<<endl;
 G->vexs[times].numrou=times;
 i=times-1;
 printf("·������:");
 scanf("%s",G->vexs[i].introduction);
 G->vexnum=times;
 while(1)
    {
    cout<<"��·�ɺ��ĸ�·���½�·����·"<<endl;
    cout<<"·�ɱ�ţ�";
    cin>>j;
    printf("���ȣ�");
    scanf("%d",&w);
    G->arcs[i][j].adj=w;
    G->arcs[j][i].adj=G->arcs[i][j].adj;
    for(int z=0;z<G->vexnum;z++){
            if(z!=j){
    G->arcs[i][z].adj=max;
    G->arcs[z][i].adj=G->arcs[i][z].adj;}}
    cout<<"�Ƿ�������·�� 1���� 2����"<<endl;
    int have;
    cin>>have;
    if(have==2) break;
    else if(have==1) continue;
    else cout<<"��������"<<endl;
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
