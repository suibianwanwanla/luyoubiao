#include"global.h"
extern edge e[max*max];//��
bool compare(const edge& a , const edge& b)
{
    return a.weight < b.weight;
}
void print(MGraph *G){
    int n1;
    n1=G->vexnum;
       // int i,j;
        for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                map[i][j]=G->arcs[i-1][j-1].adj;
            }
        }
        //cout<<n1<<"!!!";
        for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(j==n1&&map[i][j]!=max)
             cout<<map[i][j]<<endl;//�����бߵ�Ȩֵ��Ϊ0
            else if(j!=n1&&map[i][j]!=max)
            cout<<map[i][j]<<" ";
            else if(j==n1&&map[i][j]==max)
             cout<<"0"<<endl;//�����бߵ�Ȩֵ��Ϊ0
            else if(j!=n1&&map[i][j]==max)
            cout<<"0"<<" ";
            }
        }
        int mm=0;
       for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(map[i][j]!=0) mm++;
            }}
            mm=mm/2;
            while(mm--){
                for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(map[i][j]!=max) map[j][i]=max;
            }
            }}
            for(int i = 1 ; i <= n1 ; ++i){
            for(int j = 1 ; j <= n1 ; ++j){
                if(map[i][j]==max) map[i][j]=0;
            }}
        /*for(int i=1;i<=n1;i++)
            for(int j=1;j<=n1;j++)
       if(map[i][j]!=max)
             map[j][i] =max;//�����бߵ�Ȩֵ��Ϊ0
for(int i=1;i<=n1;i++)
            for(int j=1;j<=n1;j++)
                if(map[i][j]==max)
             map[i][j] =0;//�����бߵ�Ȩֵ��Ϊ0*/
            /* for(int i=1;i<=n1;i++)//����
            for(int j=1;j<=n1;j++)
                if(j==n1)
             cout<<map[i][j]<<endl;//�����бߵ�Ȩֵ��Ϊ0
            else cout<<map[i][j]<<" ";
            getchar();
            getchar();*/
        int count = 0;
        /*for(int i = 1 ; i <= n1 ; ++i){//�������Ĵ���ʽ
            for(int j = i+1 ; j <= n1 ; ++j){
                e[count].begin = i;
                e[count].end = j;
                cout<<map[i][j]<<"!!!";
                e[count++].weight = map[i][j];
                //cout<< e[count++].weight <<" !!!!!!";
            }
        }*/
        sort(e,e+count,compare);//kruscal�㷨Ҫ�������

        int sum = kruscal(count);

       // printf("%d\n",sum);

}
