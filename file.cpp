#include"global.h"
extern MGraph b;
void route::into_file()
{
    fstream out;
    out.open("route.txt",ios::out);
    int k;
    k=0;
    out<<num;
    while(k<num)
    {
        k++;
        out<<" "<<k;
    }
    out<<'\n';
    for(int i=0;i<num;i++)
    {
        out<<i+1;
        for(int j=0;j<num;j++)
            out<<" "<<table[i][j];
        out<<'\n';
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
        b.vexnum=i-1;
    }
}
void route::for_file()
{
    fstream in;
    in.open("route.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"this is a empty file!"<<endl;
    }
    else
    {
        int i,j,k;
        i=j=0;
        in>>num;
        while(i<num)
        {
            in>>k;
            i++;
        }
        i=0;
        in>>k;
        while(!in.eof())
        {
            in>>table[i][j];
            j++;
            if(j==num)
            {
                i++;
                in>>k;
                j=0;
            }
        }
    }

}
void out_file()
{
    ofstream out("mingwang.txt",ios::out);
    for(int i=0;i<b.vexnum+1;i++)
    {

        for(int k=0;b.vexs[i].introduction[k]!='\0';k++)
        {
            //cout<<b.vexs[i].introduction[k];
            out.put(b.vexs[i].introduction[k]);
        }
        out.put(10);
    }
}
