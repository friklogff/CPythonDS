#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

const int INF = INT_MAX;

// ����ͼ���ڽӱ�ṹ
typedef pair<int, int> PII; // first��ʾ�ڵ��ţ�second��ʾ�ߵ�Ȩ��
vector<vector<PII>> graph;

// Dijkstra�㷨
vector<int> dijkstra(int start, int n) {
	vector<int> dist(n, INF); // �������飬��ʼΪ�����
	vector<bool> visited(n, false); // ���ʱ��
	priority_queue<PII, vector<PII>, greater<PII>> pq; // ���ȶ��У��洢��ǰ���·���Ľڵ�;���

	dist[start] = 0; // ������Ϊ0
	pq.emplace(0, start);

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u])
			continue; // ����ڵ��ѷ��ʣ�����
		visited[u] = true; // ��Ǹýڵ�Ϊ�ѷ���

		for (auto edge : graph[u]) {
			int v = edge.first;
			int weight = edge.second;

			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				pq.emplace(dist[v], v);
			}
		}
	}

	return dist; // �������·����������
}

int main() {
	int n = 8; // �ڵ�������ʵ�ʽڵ�����1����1��ʼ����
	graph.resize(n);

	// ��ӱ� (ע��ڵ��Ŵ�1��ʼ)
	tuple<int, int, int> edgeArray[] = {
		{1, 2, 10}, {1, 3, 2}, {3, 4, 2}, {3, 6, 11},
		{2, 5, 1}, {4, 5, 4}, {4, 6, 6}, {5, 7, 7}, {6, 7, 3}
	};
	// ����ʱ���鿽����vector��
	vector<tuple<int, int, int>> edges(edgeArray, edgeArray + sizeof(edgeArray) / sizeof(edgeArray[0]));

	for (auto edge : edges) {
		int u, v, w;
		tie(u, v, w) = edge;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w); // ����ͼ�����˫���
	}

	int start = 1; // ���Ϊv1
	vector<int> dist = dijkstra(start, n);

	// �������㵽�������ڵ����̾���
	for (int i = 1; i < n; ++i) {
		cout << "Distance from v" << start << " to v" << i << " is " << dist[i] << endl;
	}

	return 0;
}
