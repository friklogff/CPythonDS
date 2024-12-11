#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef int VertexType;
typedef int EdgeType;

// 图的邻接矩阵存储结构
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM]; // 存放顶点信息
	EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 存放边的权值
	int vexnum, arcnum; // 顶点数和边数
} MGraph;

// 判断图G是否存在边<x, y>或(x, y)
int Adjacent(MGraph G, int x, int y) {
	return G.edges[x][y] != 0;
}

// 列出图G中与结点x邻接的边
void Neighbors(MGraph G, int x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.edges[x][i] != 0) {
			printf("%d ", i);
		}
	}
}

// 在图G中插入顶点x
void InsertVertex(MGraph *G, VertexType x) {
	G->vexs[G->vexnum++] = x;
}

// 从图G中删除顶点x
void DeleteVertex(MGraph *G, int x) {
	for (int i = x; i < G->vexnum - 1; i++) {
		G->vexs[i] = G->vexs[i + 1];
	}
	G->vexnum--;
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = x; j < G->vexnum; j++) {
			G->edges[i][j] = G->edges[i][j + 1];
		}
	}
}

// 若无向边(x, y)或有向边<x, y>不存在，则向图G中添加该边
void AddEdge(MGraph *G, int x, int y) {
	if (G->edges[x][y] == 0) {
		G->edges[x][y] = 1; // 假设权值为1
	}
}

// 若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
void RemoveEdge(MGraph *G, int x, int y) {
	if (G->edges[x][y] != 0) {
		G->edges[x][y] = 0;
	}
}

// 求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1
int FirstNeighbor(MGraph G, int x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.edges[x][i] != 0) {
			return i;
		}
	}
	return -1;
}

// 返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1
int NextNeighbor(MGraph G, int x, int y) {
	for (int i = y + 1; i < G.vexnum; i++) {
		if (G.edges[x][i] != 0) {
			return i;
		}
	}
	return -1;
}

// 获取图G中边(x, y)或<x, y>对应的权值
EdgeType Get_edge_value(MGraph G, int x, int y) {
	return G.edges[x][y];
}

// 设置图G中边(x, y)或<x, y>对应的权值为v
void Set_edge_value(MGraph *G, int x, int y, EdgeType v) {
	G->edges[x][y] = v;
}

int main() {
	MGraph G;
	G.vexnum = 0;
	G.arcnum = 0;

	InsertVertex(&G, 1);
	InsertVertex(&G, 2);

	AddEdge(&G, 0, 1);
	AddEdge(&G, 1, 0);

	printf("是否存在边<0, 1>: %d\n", Adjacent(G, 0, 1));

	printf("顶点0的邻接顶点有: ");
	Neighbors(G, 0);
	printf("\n");

	DeleteVertex(&G, 0);

	printf("顶点1的第一个邻接顶点: %d\n", FirstNeighbor(G, 1));

	return 0;
}