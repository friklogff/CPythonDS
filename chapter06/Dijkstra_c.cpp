#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
#define N 8 // ����������ʵ�ʽڵ�����1����1��ʼ����

int g[N][N]; // ͼ���ڽӾ���
int dist[N]; // ���·������
int b[N]; // ����Ƿ��ѷ���
int n = N - 1; // ʵ�ʵĽڵ���

// Dijkstra�㷨
int dijkstra(int start, int end) {
	memset(dist, 0x3f, sizeof(dist)); // ��ʼ��dist����
	memset(b, 0, sizeof(b)); // ��ʼ��b����
	dist[start] = 0; // �������ʼ��Ϊ0

	for (int i = 0; i < n; i++) {
		int t = -1;
		// �ҵ�δ���ʽڵ��о�����С�Ľڵ�
		for (int j = 1; j <= n; j++) {
			if ((t == -1 || dist[j] < dist[t]) && !b[j]) {
				t = j;
			}
		}

		// ����޷��ҵ������ĵ㣬����ѭ��
		if (t == -1)
			break;

		// �����ѷ��ʵĵ�
		b[t] = 1;

		// ���¸õ㵽������ľ���
		for (int j = 1; j <= n; j++) {
			if (g[t][j] != INF) { // ֻ�����бߵĽڵ�
				dist[j] = (dist[t] + g[t][j] < dist[j]) ? dist[t] + g[t][j] : dist[j];
			}
		}
	}

	return dist[end] != INF;
}

int main() {
	// ��ʼ��ͼ���ڽӾ���
	memset(g, 0x3f, sizeof(g));

	// ����ͼ�ı�,���磺g[��ʼ�ڵ�][�յ�ڵ�] = �ߵ�Ȩ��;
	int edges[][3] = {
		{1, 2, 10}, {1, 3, 2}, {3, 4, 2}, {3, 6, 11},
		{2, 5, 1}, {4, 5, 4}, {4, 6, 6}, {5, 7, 7}, {6, 7, 3}
	};

	int num_edges = sizeof(edges) / sizeof(edges[0]);

	for (int i = 0; i < num_edges; ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		if (w < g[u][v]) { // ֻ������С�ı�
			g[u][v] = w;
			g[v][u] = w; // ����ͼ
		}
	}

	int start = 1; // ���v1
	int end = 7; // �յ�v7

	bool reachable = dijkstra(start, end);

	if (reachable) {
		printf("Shortest distance from v%d to v%d is %d\n", start, end, dist[end]);
	} else {
		printf("v%d is not reachable from v%d\n", end, start);
	}

	for (int i = 1; i <= n; ++i) {
		printf("Distance from v%d to v%d is %d\n", start, i, dist[i]);
	}

	return 0;
}
