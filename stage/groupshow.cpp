#include"global.h"
void show_group()
{
    int i=0;
    while(i<b.vexnum+1)
    {
        cout<<"路由器的编号为："<<b.vexs[i].numrou<<"   ";
        cout<<"路由器的网络地址为："<<b.vexs[i].introduction<<endl;
        i++;
    }
}
