#include <iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAX_VEXNUM = 20;
const int LARGEST = 43526;
struct VAGraph
{
	int vexnum;
	int arcnum;
	char* vexs[MAX_VEXNUM];
	int ars[MAX_VEXNUM][MAX_VEXNUM];
};
int LocateVex(VAGraph G, char* v)
{
	int vfind = -1;
	for (int i = 0; i <= G.vexnum; i++)
	{
		if (strcmp(G.vexs[i], v) == 0)
		{
			vfind = i; //顶点找到，s 赋i，退出循环 
			break;
		}
	}
	while (vfind == -1) //不存在则重新输入 
	{
		cout << "This vertex " << *v << " don't exist,please input again:\n";
		exit(1);
	}
	return vfind; //返回顶点位置 
}

void CreateWXW(VAGraph& GRA)
{//采用数组表示法，构造无向网 GRA
	int i, j, k, w; //定义循环变量 
	cout << "Please input Vertexs and Arcs number:\n"; //输入图的顶点 
	cin >> GRA.vexnum >> GRA.arcnum;
	while (GRA.vexnum<MAX_VEXNUM && !(GRA.vexnum > 2) ||
		GRA.arcnum>GRA.vexnum * (GRA.vexnum - 1) / 2)
	{ //弧数不能超过顶点数阶乘的一半，否则重新输入
		cout << "This is a Wrong Arc number.please input again:n";
		cin >> GRA.vexnum >> GRA.arcnum;
		cout << "Please input Vertex value:\n"; //输入顶点的值
	}
	cout << "Please input Vertex value:\n"; //输入顶点的值
	for (i = 0; i < GRA.vexnum; ++i) //输入顶点信息(名称) 
	{
		GRA.vexs[i] = new char[10];
		cin >> GRA.vexs[i];
	}
	for (i = 0; i < GRA.vexnum; ++i) //初始化邻接矩阵 
	{
		for (j = 0; j < GRA.vexnum; ++j)
		{
			if (i != j)
				GRA.ars[i][j] = LARGEST;
			else
				GRA.ars[i][j] = 0;
		}
	}
	for (k = 0; k < GRA.arcnum; ++k)
	{ //构造邻接矩阵
		char v1[10];
		char v2[10];
		cout << "Please input two Vertexs and Arc weight,Group" << k + 1 << ":\n";
		cin >> v1 >> v2 >> w;//输入顶点 v1、v2 的名称,边 vlv2 的权值 w
		i = LocateVex(GRA, v1);
		j = LocateVex(GRA, v2);
		GRA.ars[i][j] = w; //边<vl,v2>的权值 
		GRA.ars[j][i] = GRA.ars[i][j]; //此矩阵是对称矩阵 
	}
}
void FloydGetResult(VAGraph GRA)
{ //用Floved 算法求有向网G中个对顶点的最短路径长度D[v] [w
	int D[MAX_VEXNUM][MAX_VEXNUM];//最短路径的带权长度矩阵 
	static int P[MAX_VEXNUM]; //各顶点到最远点的距离 P[I 
	int v, u, w;
	for (v = 0; v < GRA.vexnum; ++v)
	{//各对节点之间初始已知距离 
		for (w = 0; w < GRA.vexnum; ++w)
		{
			D[v][w] = GRA.ars[v][w]; //给矩阵赋值 
		}
	}
	for (u = 0; u < GRA.vexnum; ++u)
	{
		//求各对顶点的最短路径，如果直接的路径不是最短就找合路径

		for (v = 0; v < GRA.vexnum; ++v)
		{
			for (w = 0; w < GRA.vexnum; ++w)
			{
				if (D[v][u] + D[u][w] < D[v][w])
				{
					D[v][w] = D[v][u] + D[u][w];
				}
			}
		}
	}
	cout << "The Adiacent Matrix is:\n"; //输出结果矩阵 
	for (u = 0; u < GRA.vexnum; ++u)
	{
		cout << setiosflags(ios::left);
		for (v = 0; v < GRA.vexnum; ++v)
		{ //输出最短路径长度矩阵D[v][w]，并求 P[u]
			cout << setw(4) << D[u][v];
			if (P[u] < D[u][v])
				P[u] = D[u][v];
		}
	}
	cout << endl;

	//求P[u]的最小值, 并输出其对应的顶点信息
	char* result;
	int i, temp = LARGEST;
	for (u = 0; u < GRA.vexnum; ++u)
	{//求P[u]的最小值，并记录它的位置{
		if (temp > P[u])
		{
			i = u;
			temp = P[u];
		}
	}

	result = GRA.vexs[i];//所选村庄顶点为 P[u]对应的顶点m
	cout << "The result is: " << result << endl;
	for (u = 0; u < GRA.vexnum; ++u)
	{//输出所选顶点到其它顶点的最短距离{
		if (u != i)
		{
			cout << result << " to " << GRA.vexs[u] << "is:" << D[i][u] << endl;
		}
	}
}

void main()
{
	VAGraph GRA;
	CreateWXW(GRA); //构造无向网 G 
	FloydGetResult(GRA);
}//求顶点result,使result到其它顶点的距离最短}//End main
