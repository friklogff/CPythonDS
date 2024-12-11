#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF 0x3f3f3f3f
#define N 8 // 顶点数，比实际节点数多1，从1开始索引

int g[N][N]; // 图的邻接矩阵
int dist[N]; // 最短路径数组
int b[N]; // 标记是否已访问
int n = N - 1; // 实际的节点数

// Dijkstra算法
int dijkstra(int start, int end) {
	memset(dist, 0x3f, sizeof(dist)); // 初始化dist数组
	memset(b, 0, sizeof(b)); // 初始化b数组
	dist[start] = 0; // 起点距离初始化为0

	for (int i = 0; i < n; i++) {
		int t = -1;
		// 找到未访问节点中距离最小的节点
		for (int j = 1; j <= n; j++) {
			if ((t == -1 || dist[j] < dist[t]) && !b[j]) {
				t = j;
			}
		}

		// 如果无法找到这样的点，跳出循环
		if (t == -1)
			break;

		// 更新已访问的点
		b[t] = 1;

		// 更新该点到其它点的距离
		for (int j = 1; j <= n; j++) {
			if (g[t][j] != INF) { // 只更新有边的节点
				dist[j] = (dist[t] + g[t][j] < dist[j]) ? dist[t] + g[t][j] : dist[j];
			}
		}
	}

	return dist[end] != INF;
}

int main() {
	// 初始化图的邻接矩阵
	memset(g, 0x3f, sizeof(g));

	// 定义图的边,例如：g[起始节点][终点节点] = 边的权重;
	int edges[][3] = {
		{1, 2, 10}, {1, 3, 2}, {3, 4, 2}, {3, 6, 11},
		{2, 5, 1}, {4, 5, 4}, {4, 6, 6}, {5, 7, 7}, {6, 7, 3}
	};

	int num_edges = sizeof(edges) / sizeof(edges[0]);

	for (int i = 0; i < num_edges; ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		if (w < g[u][v]) { // 只保留最小的边
			g[u][v] = w;
			g[v][u] = w; // 无向图
		}
	}

	int start = 1; // 起点v1
	int end = 7; // 终点v7

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
