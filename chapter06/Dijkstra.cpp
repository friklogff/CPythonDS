#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

const int INF = INT_MAX;

// 定义图的邻接表结构
typedef pair<int, int> PII; // first表示节点编号，second表示边的权重
vector<vector<PII>> graph;

// Dijkstra算法
vector<int> dijkstra(int start, int n) {
	vector<int> dist(n, INF); // 距离数组，初始为无穷大
	vector<bool> visited(n, false); // 访问标记
	priority_queue<PII, vector<PII>, greater<PII>> pq; // 优先队列，存储当前最短路径的节点和距离

	dist[start] = 0; // 起点距离为0
	pq.emplace(0, start);

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u])
			continue; // 如果节点已访问，跳过
		visited[u] = true; // 标记该节点为已访问

		for (auto edge : graph[u]) {
			int v = edge.first;
			int weight = edge.second;

			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				pq.emplace(dist[v], v);
			}
		}
	}

	return dist; // 返回最短路径距离数组
}

int main() {
	int n = 8; // 节点数，比实际节点数多1，从1开始索引
	graph.resize(n);

	// 添加边 (注意节点编号从1开始)
	tuple<int, int, int> edgeArray[] = {
		{1, 2, 10}, {1, 3, 2}, {3, 4, 2}, {3, 6, 11},
		{2, 5, 1}, {4, 5, 4}, {4, 6, 6}, {5, 7, 7}, {6, 7, 3}
	};
	// 将临时数组拷贝到vector中
	vector<tuple<int, int, int>> edges(edgeArray, edgeArray + sizeof(edgeArray) / sizeof(edgeArray[0]));

	for (auto edge : edges) {
		int u, v, w;
		tie(u, v, w) = edge;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w); // 无向图，添加双向边
	}

	int start = 1; // 起点为v1
	vector<int> dist = dijkstra(start, n);

	// 输出从起点到其他各节点的最短距离
	for (int i = 1; i < n; ++i) {
		cout << "Distance from v" << start << " to v" << i << " is " << dist[i] << endl;
	}

	return 0;
}
