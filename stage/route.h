#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED
#include<iostream>
#include <fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define n 100
#define max 17
typedef struct ArCell
{
int adj;    //路径长度
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];
struct edge{
    int begin;//端点
    int end;//端点
    int weight;//两个端点的权值
};
typedef struct   //图中顶点表示主要城市，存放城市的编号、名称、简介等信息，
{
//char name[30];//路由名称
int numrou;//路由编号
char introduction[100];//网络信息
//int money;
//int needtime;
}infotype;
typedef struct//整体图的信息
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//路由数目是 vexnum
}MGraph;
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
    void into_file();//把代码信息导入文件
    void init(MGraph *G);//将文件中信息导入代码
    void ShortestPath_DIJ(MGraph * G);//最短路线算法
    void alter1(MGraph *G);//修改路由信息
    void CreatUDN0(MGraph *G);//增加路由
    void complet(MGraph *G);//将代码信息导入文件函数
};


#endif // ROUTE_H_INCLUDED
