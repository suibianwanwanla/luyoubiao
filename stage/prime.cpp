#include"global.h"
int low[maxn],visited[maxn];
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
