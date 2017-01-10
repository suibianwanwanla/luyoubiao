#include <iostream>
#include"global.h"
using namespace std;
MGraph b;
route A;
int times;
char internap[40][40];
int father[max];//父节点
edge e[max*max];//边
int map[max][max];
void print(MGraph *G);
extern void menu();
void menu()
{
    cout<<"|------------菜单---------------|"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|        1-查询路由表           |"<<endl;
    cout<<"|        2-修改路由表           |"<<endl;
    cout<<"|        3-增加路由器           |"<<endl;
    cout<<"|        4-拓扑图信息           |"<<endl;
    cout<<"|        5-结束                 |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|-------------------------------|"<<endl;
}
int main()
{
    menu();
    A.for_file();
    //A.show_table();
    A.init(&b);
    in_file();
    //show_group();
    out_file();
    cmd();
    A.complet(&b);
    return 0;
}

