#include"global.h"
extern MGraph b;
void route::into_file()
{
    ofstream out("copy.txt",ios::out);
    char a;
    int o=0;
    while(o<num+1)
    {
        if(o==0)
            out.put(35);
        else
        {
            out.put(o+48);
        }
        o++;
        out.put(32);
    }
    out.put(10);
    o=1;
    for(int t=0;t<num;t++)
    {
        out.put(o+48);
        out.put(32);
        for(int i=0;i<num;i++)
        {
            if(table[t][i]==17)
                a='m';
            else
                a=table[t][i]+48;
            out.put(a);
            out.put(32);
        }
        out.put(10);
        o++;
    }
}
void in_file()
{
    ifstream in("mingwang.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"can't find the file!"<<endl;
    }
    else
    {
        int i,j,k;
        k=i=0;
        b.vexs[i].numrou=i;
        while(!in.eof())
        {
            j=in.get();
            if(j=='\n')
            {
                i++;
                k=0;
                b.vexs[i].numrou=i;
            }
            else
            {
                b.vexs[i].introduction[k]=j;
                k++;
            }
        }
        b.vexnum=i;
    }
}
void route::for_file()
{
    ifstream in("route.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"this is a empty file!"<<endl;
    }
    else
    {
        int i,j,k;
        i=0;
        while(!in.eof())
        {
            j=in.get();
            if(j==10)
                break;
            i++;
        }
        num=(i-1)/2;//路由器的数目为i;
        i=k=0;
        in.get();//把每次前面的路由器的名称删除。
        while(!in.eof())
        {
            j=in.get();
            if(j>48&&j<58)
            {
                j=j-48;
                table[i][k]=j;
                k++;
            }
            else if(j==109)
            {
                table[i][k]=max;
                k++;
            }
            else if(j==10)
            {
                i++;
                k=0;
                in.get();//把每次前面的路由器的名称删除。
            }
        }
    }
}
void out_file()
{
    ofstream out("mingkong.txt",ios::out);
    for(int i=0;i<b.vexnum+1;i++)
    {
        for(int k=0;b.vexs[i].introduction[k]!='\0';k++)
        {
            out.put(b.vexs[i].introduction[k]);
        }
        out.put(10);
    }
}
