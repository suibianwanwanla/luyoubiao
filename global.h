#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include"route.h"
extern route A;
extern int times;
extern char internap[40][40];
extern MGraph b;
extern int father[max];
extern edge e[max*max];//边
extern int map[max][max];//代表结点之间的权值
const int maxn = 110;
void in_file();
void out_file();
int find(int x);
int kruscal(int count);
void cmd();
void menu();
int prim();
#define MaxInt 0x3f3f3f3f
#endif // GLOBAL_H_INCLUDED
