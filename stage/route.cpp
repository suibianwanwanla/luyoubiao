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
        printf("������һ����ʼ·�ɱ��:");
        scanf("%d",&v0);
        if(v0<0||v0>G->vexnum)
        {
            printf("·�ɱ�Ų�����!����������·�ɱ��:");
            scanf("%d",&v0);
        }
        if(v0>=0&&v0<G->vexnum)
            flag=0;
    }
    for(v=0; v<G->vexnum; v++)
    {
        final[v]=0;
        D[v]=G->arcs[v0][v].adj;//����ʼ�㵽����������û�бߣ������м�¼
        for(w=0; w<G->vexnum; w++)
            p[v][w]=0;//��ʼ��ȫ����Ϊ0
        if(D[v]<max)//�ߴ�����Ϊ1
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
                    v=w;    //�ҳ������������̵ı�
                    min=D[w];
                }
        final[v]=1;//��Ǵ˴��ҳ���̱�������Ķ��㡣
        for(w=0; w<G->vexnum; w++)
            if(!final[w]&&(min+G->arcs[v][w].adj<D[w]))//�����������̱ߵ�Ŀ�Ķ���ȼ�¼��С
            {
                D[w]=min+G->arcs[v][w].adj;//����ÿ�����㳤��.
                for(x=0; x<G->vexnum; x++) //���¼�¼�ĵ���·��
                    p[w][x]=p[v][x];
                p[w][w]=1;
            }
    }//ѭ����ϣ�D�м�¼������ʼ���㵽������������·������
    int flagnum[max];
    for(int i=0; i<max; i++)
    {
        flagnum[i]=-1;
    }
    int flagnum1=-1;
    for(v=0; v<G->vexnum; v++) //���ҳ��������·���������δ�ӡ����.
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
            printf("       ��·�߳�%dkm\n\n",D[v]);
            if(flagnum1!=-1)
                flagnum[v]=flagnum1;
        }
    }
    for(int i=0; i<max; i++)
        for(int j=0; j<40; j++)
            internap[i][j]=G->vexs[i].introduction[j];
    int mid;
    cout<<"--------------------------·�ɱ�----------------------------"<<endl;
    cout<<"|    Ŀ��������������          ��һ��·��                  | "<<endl;
    cout<<"|                                                          | "<<endl;
    cout<<"|                                                          | "<<endl;
    int jjj;
    for(int i=0; i<max; i++)
        if(flagnum[i]!=-1)
        {
            jjj=flagnum[i];
            if(internap[i][0]=='n') cout<<"      "<<internap[i]<<"                     "<<jjj<<"���޷�����"<<endl;
            else
                cout<<"|     "<<internap[i]<<"         "<<jjj<<endl;
        }
    cout<<"|                                                          | "<<endl;
    cout<<"|                                                          | "<<endl;
    cout<<"|                                                          | "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
}//ShortestPath_DIJ  end

void route::alter1(MGraph *G)//·���޸�
{
    int i,j,k,w;
    char v1[20],v2[20];
    printf("·�ɱ��:");
    cin>>i;
    int jk;
    cout<<"--------��ѡ���޸�����--------"<<endl;
    cout<<"|        1->·�߳���          "<<endl;
    cout<<"|        2->ɾ��·��          "<<endl;
    cout<<"|        3->�޸�����          "<<endl;
    cout<<"|        4->ɾ������          "<<endl;
    cout<<"|        5->�˳�              "<<endl;
    cout<<"------------�˵�--------------"<<endl;
    cout<<"��ѡ��Ҫ�޸ĵ����ݣ�"<<endl;
    cin>>jk;
    while(jk!=5)
    {
        switch(jk)
        {
        case 1:
            while(1)
            {
                cout<<"����·�������"<<endl;
                cout<<"·�ɱ�ţ�";
                cin>>j;
                cout<<"·�ɳ���:";
                cin>>w;
                G->arcs[i][j].adj=w;
                G->arcs[j][i].adj=G->arcs[i][j].adj;
                cout<<"�޸ĳɹ�������"<<endl;
                cout<<"�Ƿ�������·�� 1���� 2����"<<endl;
                int have;
                cin>>have;
                if(have==2) break;
                else if(have==1) continue;
                else cout<<"��������"<<endl;
            }
            break;
        case 2:
            while(1)
            {
                cout<<"����·�������"<<endl;
                cout<<"·�ɱ�ţ�";
                cin>>j;
                G->arcs[i][j].adj=max;
                G->arcs[j][i].adj=G->arcs[i][j].adj;
                cout<<"�޸ĳɹ�������"<<endl;
                cout<<"�Ƿ�������·�� 1���� 2����"<<endl;
                int have;
                cin>>have;
                if(have==2) break;
                else if(have==1) continue;
                else cout<<"��������"<<endl;
            }
            break;
        case 3:
            printf("·������������:");
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
            cout<<"ɾ���ɹ�������"<<endl;
            break;
        default:
            break;
        }
        system("cls");
        cout<<"--------��ѡ���޸�����--------"<<endl;
        cout<<"|        1->·�߳���          "<<endl;
        cout<<"|        2->ɾ��·��          "<<endl;
        cout<<"|        3->�޸�����          "<<endl;
        cout<<"|        4->ɾ������          "<<endl;
        cout<<"|        5->�˳�              "<<endl;
        cout<<"------------�˵�--------------"<<endl;
        cin>>jk;
    }
}

void route:: CreatUDN0(MGraph *G)//����·����Ϣ
{
    int i,j,k,w,midnums;
    char v1[20],v2[20];
//printf("������·�ɵı��:�����ơ����:\n");
    times=G->vexnum;
    printf("���䵽��·�ɱ��:");
    ++times;
    cout<<times-1<<endl;
    G->vexs[times].numrou=times;
    i=times-1;
    printf("·������:");
    scanf("%s",G->vexs[i].introduction);
    G->vexnum=times;
    while(1)
    {
        cout<<"��·�ɺ��ĸ�·���½�·����·"<<endl;
        cout<<"·�ɱ�ţ�";
        cin>>j;
        printf("���ȣ�");
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
        cout<<"�Ƿ�������·�� 1���� 2����"<<endl;
        int have;
        cin>>have;
        if(have==2) break;
        else if(have==1) continue;
        else cout<<"��������"<<endl;
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
