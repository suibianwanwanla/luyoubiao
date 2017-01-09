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
int adj;    //·������
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];

typedef struct   //ͼ�ж����ʾ��Ҫ���У���ų��еı�š����ơ�������Ϣ��
{
//char name[30];//·������
int numrou;//·�ɱ��
char introduction[100];//������Ϣ
//int money;
//int needtime;
}infotype;

typedef struct MGraph//����ͼ����Ϣ
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//·����Ŀ�� vexnum
}MGraph1;

class route
{
private:
    int table[n][n];//ǰ�����к�������
    int num;
    int number[n]={0};
    int*creates();
    struct MGraph b;
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_ifon();//����Ϊ������Ϣ����
    void output_ifon();
    void show_code();
    void into_file();//�Ѵ�����Ϣ�����ļ�
    void init(MGraph1 *G);//���ļ�����Ϣ�������
    void ShortestPath_DIJ(MGraph1 * G);//���·���㷨
    void alter1(MGraph1 *G);//�޸�·����Ϣ
    void CreatUDN0(MGraph1 *G);//����·��
    void complet(MGraph1 *G);//��������Ϣ�����ļ�����
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
                k=1;//��־��·�����ĺ���
            }
            else if(i==10)
            {
                k=0;//k���еı�־��Ϣ
                p=0;//�ַ����ڵڶ������������¿�ʼ����
                j++;//����ڶ����ṹ������
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
        cout<<"·�����ĺ���Ϊ��"<<mid.vexs[i].numrou<<"  ";
        cout<<"�����Ϊ��"<<mid.vexs[i].introduction<<endl;
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
    for(int i=0;i<G->vexnum;i++)//����ά�������ݷ���ͼ��
     for(int j=0;j<G->vexnum;j++)
      G->arcs[i][j].adj=A.table[i][j];
      for(int i=0;i<G->vexnum;i++)//������·�ɱ��
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
        num=(i-1)/2;//·��������ĿΪi;
        i=k=0;
        in.get();//��ÿ��ǰ���·����������ɾ����
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
                in.get();//��ÿ��ǰ���·����������ɾ����
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
 for(v=0;v<G->vexnum;v++)//���ҳ��������·���������δ�ӡ����.
 {
  //if(v0!=v) printf("%s",G->vexs[v0].name);
  //cout<<endl;
  //cout<<"ʱ��       ����        ·��ʱ��  "<<endl;
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
  if(t>G->vexnum-1&&v0!=v){printf("       ��·�߳�%dkm\n\n",D[v]);
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
  cout<<hour<<"��վ      "<<G->vexs[i].name;
  cout<<"       "<<taketime<<"����"<<endl;
  }
  }
  cout<<"------------------------------------"<<endl;
  cout<<endl<<endl<<endl;
  //cout<<"��Ҫ����"<<taketime<<"����"<<endl;*/
  }
 }

}//ShortestPath_DIJ  end

void route::alter1(MGraph1 *G)//·���޸�
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
 printf("���м��:");
 scanf("%s",G->vexs[i].introduction);
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

void route:: CreatUDN0(MGraph1 *G)//����·����Ϣ
{
 int i,j,k,w,midnums;
 char v1[20],v2[20];
 printf("������·�ɵı��:�����ơ����:\n");
 times=G->vexnum;
 printf("·�ɱ��:");
 ++times;
 cin>>midnums;
 G->vexs[times].numrou=times;
 i=midnums-1;
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
