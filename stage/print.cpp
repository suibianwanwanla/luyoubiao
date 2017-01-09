#include"global.h"
extern edge e[max*max];//边
bool compare(const edge& a , const edge& b)
{
    return a.weight < b.weight;
}
void print(MGraph *G)
{
    int n1;
    n1=G->vexnum;
    int i,j;
    for(i = 1 ; i <= n1 ; ++i)
    {
        for(j = 1 ; j <= n1 ; ++j)
        {
            map[i][j]=G->arcs[i][j].adj;
        }
    }
    for(int i=0; i<max; i++)
        for(int j=0; j<max; j++)
            if(map[i][j]!=max)
                map[j][i] =max;//将已有边的权值设为0
    for(int i=0; i<max; i++)
        for(int j=0; j<max; j++)
            if(map[i][j]==max)
                map[i][j] =0;//将已有边的权值设为0
    int count = 0;
    for(i = 1 ; i <= n1 ; ++i) //距离矩阵的处理方式
    {
        for(j = i+1 ; j <= n1 ; ++j)
        {
            e[count].begin = i;
            e[count].end = j;
            e[count++].weight = map[i][j];
        }
    }
    sort(e,e+count,compare);//kruscal算法要求边有序

    int sum = kruscal(count);

    printf("%d\n",sum);

}
