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
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_file();
};
void route::into_file()
{
    fstream out;
    out.open("copy.txt",ios::out);
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
void route::show_table()
{
    cout<<num<<endl;
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
