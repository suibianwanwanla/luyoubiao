#include"route.h"
#include"global.h"
int*route::creates()
{
    for(int i=0; i<num; i++)
        number[i]=i+1;
    return number;
}
void route::show_table()
{
    for(int p=0; p<num; p++)
    {
        for (int t=0; t<num; t++)
            cout<<table[p][t]<<" ";
        cout<<endl;
    }
}
void route::ShortestPath_DIJ(MGraph * G)
{
    int v,w,i,min,t=0,x,flag=1,v0;
    int final[20], D[20], p[20][20];
    //cout<<G->vexnum<<"!!";
    while(flag)
    {
        printf("请输入一个起始路由编号:");
        scanf("%d",&v0);
        if(v0<0||v0>G->vexnum)
        {
            printf("路由编号不存在!请重新输入路由编号:");
            scanf("%d",&v0);
        }
        if(v0>=0&&v0<G->vexnum)
            flag=0;
    }
    for(v=0; v<G->vexnum; v++)
    {
        final[v]=0;
        D[v]=G->arcs[v0][v].adj;//从起始点到其他顶点有没有边，，进行记录
        for(w=0; w<G->vexnum; w++)
            p[v][w]=0;//初始化全部置为0
        if(D[v]<max)//边存在置为1
        {
            p[v][v0]=1;
            p[v][v]=1;
        }
    }
    D[v0]=0;
    final[v0]=1;
    for(i=1; i<G->vexnum; i++)
    {
        min=max;
        for(w=0; w<G->vexnum; w++)
            if(!final[w])
                if(D[w]<min)
                {
                    v=w;    //找出与起点相连最短的边
                    min=D[w];
                }
        final[v]=1;//标记此次找出最短边所代表的顶点。
        for(w=0; w<G->vexnum; w++)
            if(!final[w]&&(min+G->arcs[v][w].adj<D[w]))//如果此相连最短边到目的顶点比记录的小
            {
                D[w]=min+G->arcs[v][w].adj;//更新每个顶点长度.
                for(x=0; x<G->vexnum; x++) //更新记录的到达路径
                    p[w][x]=p[v][x];
                p[w][w]=1;
            }
    }//循环完毕，D中记录的是起始顶点到各个顶点的最短路径长度
    int flagnum[max];
    for(int i=0; i<max; i++)
    {
        flagnum[i]=-1;
    }
    int flagnum1=-1;
    for(v=0; v<G->vexnum; v++) //将找出来的最短路径长度依次打印出来.
    {
        int flags=0;
        flagnum1=-1;
        for(w=0; w<G->vexnum; w++)
        {
            if(p[v][w]&&w!=v0)
            {
                printf("-->%d",G->vexs[w].numrou);
                if(flags==0)flags=1;
            }
            if(flags==1) //for(int i=0;i<G->vexnum;i++)
            {
                flags=2;
                flagnum1=w;
                // cout<<flagnum1<<"!!!";
            }
            t++;
        }
        if(t>G->vexnum-1&&v0!=v)
        {
            printf("       总路线长%dkm\n\n",D[v]);
            if(flagnum1!=-1)
                flagnum[v]=flagnum1;
        }
    }
    for(int i=0; i<max; i++)
        for(int j=0; j<40; j++)
            internap[i][j]=G->vexs[i].introduction[j];
    int mid;
    cout<<"--------------------------路由表----------------------------"<<endl;
    cout<<"|    目的主机所在网络          下一跳路由                  | "<<endl;
    cout<<"|                                                          | "<<endl;
    cout<<"|                                                          | "<<endl;
    int jjj;
    for(int i=0; i<max; i++)
        if(flagnum[i]!=-1)
        {
            jjj=flagnum[i];
            if(internap[i][0]=='n') cout<<"      "<<internap[i]<<"                     "<<jjj<<"但无法交付"<<endl;
            else
                cout<<"|     "<<internap[i]<<"         "<<jjj<<endl;
        }
    cout<<"|                                                          | "<<endl;
    cout<<"|                                                          | "<<endl;
    cout<<"|                                                          | "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
}//ShortestPath_DIJ  end

void route::alter1(MGraph *G)//路由修改
{
    int i,j,k,w;
    char v1[20],v2[20];
    printf("路由编号:");
    cin>>i;
    int jk;
    cout<<"--------请选择修改内容--------"<<endl;
    cout<<"|        1->路线长度          "<<endl;
    cout<<"|        2->删除路线          "<<endl;
    cout<<"|        3->修改网络          "<<endl;
    cout<<"|        4->删除顶点          "<<endl;
    cout<<"|        5->退出              "<<endl;
    cout<<"------------菜单--------------"<<endl;
    cout<<"请选择要修改的内容："<<endl;
    cin>>jk;
    while(jk!=5)
    {
        switch(jk)
        {
        case 1:
            while(1)
            {
                cout<<"相连路由情况："<<endl;
                cout<<"路由编号：";
                cin>>j;
                cout<<"路由长度:";
                cin>>w;
                G->arcs[i][j].adj=w;
                G->arcs[j][i].adj=G->arcs[i][j].adj;
                cout<<"修改成功！！！"<<endl;
                cout<<"是否有其他路由 1、有 2、无"<<endl;
                int have;
                cin>>have;
                if(have==2) break;
                else if(have==1) continue;
                else cout<<"出错啦！"<<endl;
            }
            break;
        case 2:
            while(1)
            {
                cout<<"相连路由情况："<<endl;
                cout<<"路由编号：";
                cin>>j;
                G->arcs[i][j].adj=max;
                G->arcs[j][i].adj=G->arcs[i][j].adj;
                cout<<"修改成功！！！"<<endl;
                cout<<"是否有其他路由 1、有 2、无"<<endl;
                int have;
                cin>>have;
                if(have==2) break;
                else if(have==1) continue;
                else cout<<"出错啦！"<<endl;
            }
            break;
        case 3:
            printf("路由器所在网络:");
            scanf("%s",G->vexs[i].introduction);
            break;
        case 4:
            for(int j=0; j<G->vexnum; j++)
            {
                G->arcs[i][j].adj=max;
                G->arcs[j][i].adj=G->arcs[i][j].adj;
            }
            for(int j=0; j<100; j++)
                G->vexs[i].introduction[j]=false;
            G->vexs[i].numrou=max;
            cout<<"删除成功！！！"<<endl;
            break;
        default:
            break;
        }
        system("cls");
        cout<<"--------请选择修改内容--------"<<endl;
        cout<<"|        1->路线长度          "<<endl;
        cout<<"|        2->删除路线          "<<endl;
        cout<<"|        3->修改网络          "<<endl;
        cout<<"|        4->删除顶点          "<<endl;
        cout<<"|        5->退出              "<<endl;
        cout<<"------------菜单--------------"<<endl;
        cin>>jk;
    }
}

void route:: CreatUDN0(MGraph *G)//增加路由信息
{
    int i,j,k,w,midnums;
    char v1[20],v2[20];
//printf("请输入路由的编号:、名称、简介:\n");
    times=G->vexnum;
    printf("分配到的路由编号:");
    ++times;
    cout<<times-1<<endl;
    G->vexs[times].numrou=times;
    i=times-1;
    printf("路由网络:");
    scanf("%s",G->vexs[i].introduction);
    G->vexnum=times;
    while(1)
    {
        cout<<"此路由和哪个路由新建路由线路"<<endl;
        cout<<"路由编号：";
        cin>>j;
        printf("长度：");
        scanf("%d",&w);
        G->arcs[i][j].adj=w;
        G->arcs[j][i].adj=G->arcs[i][j].adj;
        for(int z=0; z<G->vexnum; z++)
        {
            if(z!=j)
            {
                G->arcs[i][z].adj=max;
                G->arcs[z][i].adj=G->arcs[i][z].adj;
            }
        }
        cout<<"是否有其他路由 1、有 2、无"<<endl;
        int have;
        cin>>have;
        if(have==2) break;
        else if(have==1) continue;
        else cout<<"出错啦！"<<endl;
    }
}
void route::complet(MGraph *G)
{
    for(int i=0; i<G->vexnum; i++)
        for(int j=0; j<G->vexnum; j++)
            A.table[i][j]=G->arcs[i][j].adj;
    A.num=G->vexnum;
    /*for(int i=0;i<G->vexnum;i++)
            for(int j=0;j<G->vexnum;j++)
            if(j!=G->vexnum-1)
            cout<<G->arcs[i][j].adj<<" ";
        else cout<<G->arcs[i][j].adj<<" "<<endl;
        for(int i=0;i<G->vexnum;i++)
            for(int j=0;j<G->vexnum;j++)
            if(j!=G->vexnum-1)
            cout<<A.table[i][j]<<" ";
        else cout<<A.table[i][j]<<" "<<endl;
        A.into_file();*/
}
