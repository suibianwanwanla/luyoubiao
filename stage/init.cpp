#include"global.h"
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
}
