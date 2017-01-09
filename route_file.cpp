#include <iostream>
#include <fstream>
#define n 100
#define max 17;
using namespace std;
class route
{
private:
    int table[n][n];//前面是行后面是列
    int num;
    int number[n]={0};
    int*creates();
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_file();
};
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
int*route::creates()
{
    for(int i=0;i<num;i++)
        number[i]=i+1;
    return number;
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
        num=i/2;//路由器的数目为i;
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
void route::show_table()
{
    for(int p=0;p<num;p++)
    {
        for (int t=0;t<num;t++)
            cout<<table[p][t]<<" ";
        cout<<endl;
    }
}
int main()
{
    route a;
    a.for_file();
    a.show_table();
    a.into_file();
    return 0;
}
