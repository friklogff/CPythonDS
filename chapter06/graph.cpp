#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef int VertexType;
typedef int EdgeType;

// ͼ���ڽӾ���洢�ṹ
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM]; // ��Ŷ�����Ϣ
	EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ��űߵ�Ȩֵ
	int vexnum, arcnum; // �������ͱ���
} MGraph;

// �ж�ͼG�Ƿ���ڱ�<x, y>��(x, y)
int Adjacent(MGraph G, int x, int y) {
	return G.edges[x][y] != 0;
}

// �г�ͼG������x�ڽӵı�
void Neighbors(MGraph G, int x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.edges[x][i] != 0) {
			printf("%d ", i);
		}
	}
}

// ��ͼG�в��붥��x
void InsertVertex(MGraph *G, VertexType x) {
	G->vexs[G->vexnum++] = x;
}

// ��ͼG��ɾ������x
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

// �������(x, y)�������<x, y>�����ڣ�����ͼG����Ӹñ�
void AddEdge(MGraph *G, int x, int y) {
	if (G->edges[x][y] == 0) {
		G->edges[x][y] = 1; // ����ȨֵΪ1
	}
}

// �������(x, y)�������<x, y>���ڣ����ͼG��ɾ���ñ�
void RemoveEdge(MGraph *G, int x, int y) {
	if (G->edges[x][y] != 0) {
		G->edges[x][y] = 0;
	}
}

// ��ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���š���xû���ڽӵ��ͼ�в�����x���򷵻�-1
int FirstNeighbor(MGraph G, int x) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.edges[x][i] != 0) {
			return i;
		}
	}
	return -1;
}

// ���س�y֮�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1
int NextNeighbor(MGraph G, int x, int y) {
	for (int i = y + 1; i < G.vexnum; i++) {
		if (G.edges[x][i] != 0) {
			return i;
		}
	}
	return -1;
}

// ��ȡͼG�б�(x, y)��<x, y>��Ӧ��Ȩֵ
EdgeType Get_edge_value(MGraph G, int x, int y) {
	return G.edges[x][y];
}

// ����ͼG�б�(x, y)��<x, y>��Ӧ��ȨֵΪv
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

	printf("�Ƿ���ڱ�<0, 1>: %d\n", Adjacent(G, 0, 1));

	printf("����0���ڽӶ�����: ");
	Neighbors(G, 0);
	printf("\n");

	DeleteVertex(&G, 0);

	printf("����1�ĵ�һ���ڽӶ���: %d\n", FirstNeighbor(G, 1));

	return 0;
}