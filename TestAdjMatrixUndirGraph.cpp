#include "Assistance.h"                    // 辅助软件包
#include "AdjMatrixUndirGraph.h"        // 邻接矩阵无向图

int main(void)
{
    try                                 // 用 try 封装可能出现异常的代码
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
            cout << endl << "1. 显示图.";
            cout << endl << "10. 输出整个矩阵的有向环顶点";
            cout << endl << "3. 删除顶点.";
            cout << endl << "4. 插入顶点.";
            cout << endl << "5. 删除边.";
            cout << endl << "6. 插入边.";
            cout << endl << "7. 输出顶点的出度";
            cout << endl << "8. 输出顶点的入度";
            cout << endl << "9. 输出某个顶点的邻接顶点";
            cout << endl << "11. 退出";
            cout << endl << "选择功能(1~10):";
            cin >> c;
            switch (c)        {
                case '1':
                    if (g.IsEmpty())
                        cout << "该图为空。" << endl;
                    else
                    {
                        g.Display();
                    }
                    break;
                case '2':
                    cout<<"检测矩阵中是否存在有向环，结果如下"<<endl;
                    g.GetCricle();
                    break;
                case '3':
                    cout << endl << "输入被删除顶点的值:";
                    cin >> e;
                    g.DeleteVex(e);
                    break;
                case '4':
                    cout << endl << "输入插入顶点的值:";
                    cin >> e;
                    g.InsertVex(e);
                    break;
                case '5':
                    cout << endl << "输入将要被删除的有向边所关联的两个顶点值:";
                    cin >> e1 >> e2;
                    v1 = g.GetOrder(e1);
                    v2 = g.GetOrder(e2);
                    g.DeleteArc(v1, v2);
                    break;
                case '6':
                    cout << endl << "输入与插入边关联的两个顶点值:";
                    cin >> e1 >> e2;
                    cout<< "请输入权的大小："<<endl;
                    int w;
                    cin >> w;
                    v1 = g.GetOrder(e1);
                    v2 = g.GetOrder(e2);
                    g.InsertArc(v1, v2, w);
                    break;
                case '7':
                    cout << endl << "输入顶点值:";
                    cin >> E;
                    if (g.GetCountOutDegree(E)==-1)
                        cout<< "NOT FOUND "<<endl;
                    else
                        cout<< E <<" 出度为："<<g.GetCountOutDegree(E)<<endl;
                    break;
                case '8':
                    cout << endl << "输入顶点值:";
                    cin >> E;
                    if (g.GetCountInDegree(E) == -1)
                        cout << "NOT FOUND" << endl;
                    else
                        cout << E << " 入度为：" << g.GetCountInDegree(E) << endl;
                    break;
                case '9':
                    cout << endl << "输入顶点值:";
                    cin >> E;
                    g.GetNeighborNode(E);
                    cout<<endl;

            }
        }
    }
    catch (Error err)                    // 捕捉并处理异常
    {
        err.Show();                        // 显示异常信息
    }

    system("PAUSE");                    // 调用库函数system()
    return 0;                            // 返回值0, 返回操作系统
}
