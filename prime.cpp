#include"global.h"
int low[maxn],visited[maxn];
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
