#include"global.h"
void show_group()
{
    int i=0;
    while(i<b.vexnum+1)
    {
        cout<<"·�����ı��Ϊ��"<<b.vexs[i].numrou<<"   ";
        cout<<"·�����������ַΪ��"<<b.vexs[i].introduction<<endl;
        i++;
    }
}
