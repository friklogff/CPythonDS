#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <deque>  // Include deque header for queue

int main() {
	// ����������ʾ��
	std::stack<int, std::vector<int>> stack;
	std::queue<int, std::deque<int>> queue;  // ʹ�� deque ��� vector
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	// ���������
	for (int i = 1; i <= 5; ++i) {
		stack.push(i);
		queue.push(i);
		pq.push(i);
	}

	// ����������е�Ԫ��
	std::cout << "ջ��Ԫ��: " << stack.top() << std::endl;
	stack.pop();
	std::cout << "����Ԫ�غ��ջ��: " << stack.top() << std::endl;

	std::cout << "����Ԫ��: " << queue.front() << std::endl;
	queue.pop();
	std::cout << "����Ԫ�غ�Ķ���: " << queue.front() << std::endl;

	std::cout << "���ȶ��ж���Ԫ��: " << pq.top() << std::endl;
	pq.pop();
	std::cout << "����Ԫ�غ�����ȶ��ж���: " << pq.top() << std::endl;

	// ����ʾ��
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {1, 2, 3, 4, 5};
	std::set<int> st = {1, 2, 3, 4, 5};
	std::map<int, char> mp = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
	std::unordered_set<int> uset = {1, 2, 3, 4, 5};
	std::unordered_map<int, char> umap = {{1, 'a'}, {2, 'b'}, {3, 'c'}};

	// ������������ʾ��
	std::reverse_iterator<std::vector<int>::iterator> rit(vec.end());
	std::reverse_iterator<std::vector<int>::iterator> rbegin(vec.begin());
	std::cout << "����Ԫ�����෴˳������: ";
	for (; rit != rbegin; ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	// ����������ʾ��
	auto is_greater_than_3 = std::bind(std::greater<int>(), std::placeholders::_1, 3);
	auto it = std::find_if(vec.begin(), vec.end(), is_greater_than_3);
	if (it != vec.end()) {
		std::cout << "��һ������3��Ԫ��: " << *it << std::endl;
	}

	// �㷨ʾ��
	// �ճ��������㷨
	std::fill(vec.begin(), vec.end(), 10);
	std::cout << "���������: ";
	for (const auto &el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

// �������㷨
	it = std::find(vec.begin(), vec.end(), 10);
	if (it != vec.end()) {
		std::cout << "��λ���ҵ�Ԫ��10: " << std::distance(vec.begin(), it) << std::endl;
	}

	// �������㷨
	std::sort(lst.begin(), lst.end(), std::greater<int>());
	std::cout << "����������: ";
	for (const auto &el : lst) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	// �������㷨
	int sum = std::accumulate(st.begin(), st.end(), 0);
	std::cout << "������Ԫ�صĺ�: " << sum << std::endl;

	return 0;
}
