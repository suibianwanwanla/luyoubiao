#include <iostream>
#include"global.h"
using namespace std;
MGraph b;
route A;
int times;
char internap[40][40];
int father[max];//���ڵ�
edge e[max*max];//��
int map[max][max];
void print(MGraph *G);
extern void menu();
void menu()
{
    cout<<"|------------�˵�---------------|"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|        1-��ѯ·�ɱ�           |"<<endl;
    cout<<"|        2-�޸�·�ɱ�           |"<<endl;
    cout<<"|        3-����·����           |"<<endl;
    cout<<"|        4-����ͼ��Ϣ           |"<<endl;
    cout<<"|        5-����                 |"<<endl;
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

