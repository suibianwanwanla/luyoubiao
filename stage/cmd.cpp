#include"global.h"
void print(MGraph *G);
void cmd()
{
    cout<<"ÇëÑ¡Ôñ£º  "<<endl;
    int op;
    cin>>op;
    while(op!=5)
    {
        switch(op)
        {
        case 1:
            A.ShortestPath_DIJ(&b);
            getchar();
            getchar();
            system("cls");
            break;
        case 2:
            A.alter1(&b);
            break;
            getchar();
            getchar();
            system("cls");
        case 3:
            A.CreatUDN0(&b);
            break;
            getchar();
            getchar();
            system("cls");
        case 4:
            print(&b);
            int ans;
            ans=prim();
//cout<<ans;
            getchar();
            getchar();
            system("cls");
            break;
        default:
            break;
        }
        menu();
        cout<<"ÇëÑ¡Ôñ£º  "<<endl;
        cin>>op;
        system("cls");
    }
}
