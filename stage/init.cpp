#include"global.h"
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
}
