#include"global.h"
int kruscal(int count) //使用kruscal算法来生成最小生成树并计算带权路径和
{
    int i;
    int sum = 0;//用sum来记录最小s生成树的边权和

    for( i = 1 ; i < max ; ++i)
    {
        father[i] = i;
    }

    for( i = 0 ; i < count ; ++i) //枚举有序边集中的每一条边
    {
        int fx = find(e[i].begin);
        int fy = find(e[i].end);

        if(fx != fy) //若第k条边的两个端点i,j 分别属于两颗不同的子树
        {
            father[fx] = fy;//则将节点i所在的子树并入节点j所在的子树中
            cout<<"顶点"<<fx<<"  顶点"<<fy<<" 权值为： "<<e[i].weight<<endl;
            sum += e[i].weight;
        }
    }

    return sum;
}
