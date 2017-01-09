#include <iostream>
#include <fstream>
using namespace std;
struct vex
{
    int number;
    char a[20]={0};//路由信息
};
class route
{
private:
    struct vex*ifon[100];
    int num=0;//路由器的个数
public:
    void into_ifon();
    void output_ifon();
    void show_code();
};
void route::into_ifon()
{
    ifstream in("mingwang.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"this is a empty file!"<<endl;
    }
    else
    {
        int i,j,k,p;
        j=k=p=0;
        while(!in.eof())
        {
            if(k==0)
                ifon[j]=new vex;
            i=in.get();
            if(i<58&&i>48&&k==0)
            {
                i=i-48;
                ifon[j]->number=i;
                cout<<ifon[j]->number;
                k=1;//标志着路由器的号码
            }
            else if(i==10)
            {
                k=0;//k换行的标志信息
                p=0;//字符串在第二个数组中重新开始输入
                j++;//进入第二个结构体数组
                cout<<endl;
            }
            else if(k==1&&i!=10)
            {
                char b;
                b=i;
                //cout<<i<<" ";
                cout<<b;
                ifon[j]->a[p]=b;
                //cout<<ifon[j]->a[p];
                p++;
            }
        }
        num=j+1;
    }
}
void route::show_code()
{
    for(int i=0;i<num;i++)
    {
        cout<<"路由器的号码为："<<ifon[i]->number<<"  ";
        cout<<"网络号为："<<ifon[i]->a<<endl;
    }
}
void route::output_ifon()
{
    ofstream out("mingkong.txt",ios::out);
    for(int i=0;i<num;i++)
    {
        out.put(ifon[i]->number+48);
        out.put(32);
        for(int k=0;ifon[i]->a[k]!='\0';k++)
        {
            out.put(ifon[i]->a[k]);
        }
        out.put(10);
    }
}
int main()
{
    route a;
    a.into_ifon();
    a.show_code();
    a.output_ifon();
    return 0;
}
