#include"global.h"
int kruscal(int count) //ʹ��kruscal�㷨��������С�������������Ȩ·����
{
    int i;
    int sum = 0;//��sum����¼��Сs�������ı�Ȩ��

    for( i = 1 ; i < max ; ++i)
    {
        father[i] = i;
    }

    for( i = 0 ; i < count ; ++i) //ö������߼��е�ÿһ����
    {
        int fx = find(e[i].begin);
        int fy = find(e[i].end);

        if(fx != fy) //����k���ߵ������˵�i,j �ֱ��������Ų�ͬ������
        {
            father[fx] = fy;//�򽫽ڵ�i���ڵ���������ڵ�j���ڵ�������
            cout<<"����"<<fx<<"  ����"<<fy<<" ȨֵΪ�� "<<e[i].weight<<endl;
            sum += e[i].weight;
        }
    }

    return sum;
}
