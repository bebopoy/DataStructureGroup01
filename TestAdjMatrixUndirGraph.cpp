#include "Assistance.h"                    // ���������
#include "AdjMatrixUndirGraph.h"        // �ڽӾ�������ͼ

int main(void)
{
    try                                 // �� try ��װ���ܳ����쳣�Ĵ���
    {
        char vexs[] = {'A', 'B', 'C', 'D', 'E'};
        int m[5][5] = {
            {0, 1, 3, 2, 9},
            {1, 0, 5, 6, 10},
            {0, 9, 3, 1, 1},
            {1, 1, 0, 0, 0},
            {1, 0, 4, 0, 0},
        };
        char c = '0', e, e1, e2,E;
        int n = 5, v, v1, v2;

        AdjMatrixUndirGraph<char> g(vexs, n, 7);

        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (m[u][v] != 0 )
                    g.InsertArc(u, v, m[u][v]);

        while (c != '11')    {
            cout << endl << "1. ��ʾͼ.";
            cout << endl << "10. ���������������򻷶���";
            cout << endl << "3. ɾ������.";
            cout << endl << "4. ���붥��.";
            cout << endl << "5. ɾ����.";
            cout << endl << "6. �����.";
            cout << endl << "7. �������ĳ���";
            cout << endl << "8. �����������";
            cout << endl << "9. ���ĳ��������ڽӶ���";
            cout << endl << "11. �˳�";
            cout << endl << "ѡ����(1~10):";
            cin >> c;
            switch (c)        {
                case '1':
                    if (g.IsEmpty())
                        cout << "��ͼΪ�ա�" << endl;
                    else
                    {
                        g.Display();
                    }
                    break;
                case '2':
                    cout<<"���������Ƿ�������򻷣��������"<<endl;
                    g.GetCricle();
                    break;
                case '3':
                    cout << endl << "���뱻ɾ�������ֵ:";
                    cin >> e;
                    g.DeleteVex(e);
                    break;
                case '4':
                    cout << endl << "������붥���ֵ:";
                    cin >> e;
                    g.InsertVex(e);
                    break;
                case '5':
                    cout << endl << "���뽫Ҫ��ɾ�������������������������ֵ:";
                    cin >> e1 >> e2;
                    v1 = g.GetOrder(e1);
                    v2 = g.GetOrder(e2);
                    g.DeleteArc(v1, v2);
                    break;
                case '6':
                    cout << endl << "���������߹�������������ֵ:";
                    cin >> e1 >> e2;
                    cout<< "������Ȩ�Ĵ�С��"<<endl;
                    int w;
                    cin >> w;
                    v1 = g.GetOrder(e1);
                    v2 = g.GetOrder(e2);
                    g.InsertArc(v1, v2, w);
                    break;
                case '7':
                    cout << endl << "���붥��ֵ:";
                    cin >> E;
                    if (g.GetCountOutDegree(E)==-1)
                        cout<< "NOT FOUND "<<endl;
                    else
                        cout<< E <<" ����Ϊ��"<<g.GetCountOutDegree(E)<<endl;
                    break;
                case '8':
                    cout << endl << "���붥��ֵ:";
                    cin >> E;
                    if (g.GetCountInDegree(E) == -1)
                        cout << "NOT FOUND" << endl;
                    else
                        cout << E << " ���Ϊ��" << g.GetCountInDegree(E) << endl;
                    break;
                case '9':
                    cout << endl << "���붥��ֵ:";
                    cin >> E;
                    g.GetNeighborNode(E);
                    cout<<endl;

            }
        }
    }
    catch (Error err)                    // ��׽�������쳣
    {
        err.Show();                        // ��ʾ�쳣��Ϣ
    }

    system("PAUSE");                    // ���ÿ⺯��system()
    return 0;                            // ����ֵ0, ���ز���ϵͳ
}
