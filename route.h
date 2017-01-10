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
int adj;    //·������
}ArCell,AdjMatrix[max][max];
//train t[MAX_VERTEX_NUM];
struct edge{
    int begin;//�˵�
    int end;//�˵�
    int weight;//�����˵��Ȩֵ
};
typedef struct   //ͼ�ж����ʾ��Ҫ���У���ų��еı�š����ơ�������Ϣ��
{
//char name[30];//·������
int numrou;//·�ɱ��
char introduction[100];//������Ϣ
//int money;
//int needtime;
}infotype;
typedef struct//����ͼ����Ϣ
{
infotype vexs[max];
AdjMatrix arcs;
int vexnum,arcnum;//·����Ŀ�� vexnum
}MGraph;
class route
{
private:
    int table[n][n];//ǰ�����к�������
    int num;
    int number[n]={0};
    int*creates();
public:
    void for_file();
    void show_table();
    void addcode();
    void dcecode();
    void into_file();//�Ѵ�����Ϣ�����ļ�
    void init(MGraph *G);//���ļ�����Ϣ�������
    void ShortestPath_DIJ(MGraph * G);//���·���㷨
    void alter1(MGraph *G);//�޸�·����Ϣ
    void CreatUDN0(MGraph *G);//����·��
    void complet(MGraph *G);//��������Ϣ�����ļ�����
};


#endif // ROUTE_H_INCLUDED
