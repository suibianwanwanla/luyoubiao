#include"global.h"
extern int father[max];
int find(int x) //沿着父节点一直寻找初始父节点
{
    if( x == father[x])
    {
        return x;
    }

    father[x] = find(father[x]);
    return father[x];
}
