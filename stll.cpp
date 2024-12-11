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
	// 容器适配器示例
	std::stack<int, std::vector<int>> stack;
	std::queue<int, std::deque<int>> queue;  // 使用 deque 替代 vector
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	// 填充适配器
	for (int i = 1; i <= 5; ++i) {
		stack.push(i);
		queue.push(i);
		pq.push(i);
	}

	// 输出适配器中的元素
	std::cout << "栈顶元素: " << stack.top() << std::endl;
	stack.pop();
	std::cout << "弹出元素后的栈顶: " << stack.top() << std::endl;

	std::cout << "队首元素: " << queue.front() << std::endl;
	queue.pop();
	std::cout << "弹出元素后的队首: " << queue.front() << std::endl;

	std::cout << "优先队列顶部元素: " << pq.top() << std::endl;
	pq.pop();
	std::cout << "弹出元素后的优先队列顶部: " << pq.top() << std::endl;

	// 容器示例
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {1, 2, 3, 4, 5};
	std::set<int> st = {1, 2, 3, 4, 5};
	std::map<int, char> mp = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
	std::unordered_set<int> uset = {1, 2, 3, 4, 5};
	std::unordered_map<int, char> umap = {{1, 'a'}, {2, 'b'}, {3, 'c'}};

	// 迭代器适配器示例
	std::reverse_iterator<std::vector<int>::iterator> rit(vec.end());
	std::reverse_iterator<std::vector<int>::iterator> rbegin(vec.begin());
	std::cout << "向量元素以相反顺序排列: ";
	for (; rit != rbegin; ++rit) {
		std::cout << *rit << " ";
	}
	std::cout << std::endl;

	// 泛函适配器示例
	auto is_greater_than_3 = std::bind(std::greater<int>(), std::placeholders::_1, 3);
	auto it = std::find_if(vec.begin(), vec.end(), is_greater_than_3);
	if (it != vec.end()) {
		std::cout << "第一个大于3的元素: " << *it << std::endl;
	}

	// 算法示例
	// 日常事务类算法
	std::fill(vec.begin(), vec.end(), 10);
	std::cout << "填充后的向量: ";
	for (const auto &el : vec) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

// 查找类算法
	it = std::find(vec.begin(), vec.end(), 10);
	if (it != vec.end()) {
		std::cout << "在位置找到元素10: " << std::distance(vec.begin(), it) << std::endl;
	}

	// 排序类算法
	std::sort(lst.begin(), lst.end(), std::greater<int>());
	std::cout << "排序后的链表: ";
	for (const auto &el : lst) {
		std::cout << el << " ";
	}
	std::cout << std::endl;

	// 工作类算法
	int sum = std::accumulate(st.begin(), st.end(), 0);
	std::cout << "集合中元素的和: " << sum << std::endl;

	return 0;
}
