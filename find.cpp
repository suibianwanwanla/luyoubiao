#include"global.h"
extern int father[max];
int find(int x) //���Ÿ��ڵ�һֱѰ�ҳ�ʼ���ڵ�
{
    if( x == father[x])
    {
        return x;
    }

    father[x] = find(father[x]);
    return father[x];
}
