#include <iostream>
#include <iostream>
#include <vector>


#define PRIORITY_NUMBER 100 // 定义优先级数量为100
//模板是一种通用编程技术，允许您编写泛化的代码，能够处理多种不同类型的数据。通过模板，您可以实现数据结构、算法等可重用且支持不同数据类型的功能。
//template <class T>
//T add(T a, T b) {
//    return a + b;
//}
//
//int result1 = add(5, 3); // 使用模板函数添加整数
//double result2 = add(2.5, 3.7); // 使用模板函数添加浮点数

template <class T>
struct PriorityNode { // 定义存储数据和优先级的节点结构体
	short priority; // 优先级
	T data; // 数据
	struct PriorityNode<T> *next; // 指向下一个节点的指针
};

template <class T>
class PriorityQueue { // 定义优先队列类
	public:
		PriorityQueue() { // 构造函数
			front = nullptr; // 队列头指针为空
			for (int i = 0; i < PRIORITY_NUMBER; ++i) { // 初始化最后一个节点数组，用于记录每个优先级的最后一个节点
				lastNodeArray[i] = nullptr;
			}
		}

		~PriorityQueue() { // 析构函数
			while (front != nullptr) { // 释放队列中所有节点占用的内存
				PriorityNode<T> *temp = front;
				front = front->next;
				delete temp;
			}
		}

		void Push(T x, short pri) { // 插入节点到优先队列
			PriorityNode<T> *newNode = new PriorityNode<T>; // 创建新节点
			newNode->priority = pri; // 设置优先级
			newNode->data = x; // 设置数据
			newNode->next = nullptr; // 新节点指向空

			if (front == nullptr) { // 如果队列为空
				front = newNode; // 新节点成为第一个节点
			} else {
				if (pri < front->priority) { // 如果新节点优先级比第一个节点高
					newNode->next = front;
					front = newNode; // 新节点成为第一个节点
				} else {
					PriorityNode<T> *temp = front;
					while (temp->next != nullptr && temp->next->priority <= pri) { // 寻找插入位置
						temp = temp->next;
					}
					newNode->next = temp->next;
					temp->next = newNode; // 插入新节点
				}
			}

			PushAdjustLastNodeArray(pri, newNode); // 调整最后一个节点数组
		}

		T Pop() { // 弹出优先级最高的节点
			if (front == nullptr) {
				std::cerr << "Queue is empty." << std::endl;
				return T();
			}

			PriorityNode<T> *temp = front;
			front = front->next;
			T poppedData = temp->data;
			delete temp;

			PopAdjustLastNodeArray(front); // 调整最后一个节点数组

			return poppedData;
		}

		T Top() { // 返回优先级最高的节点数据
			if (front == nullptr) {
				std::cerr << "Queue is empty." << std::endl;
				return T();
			}

			return front->data;
		}

		int Size() const { // 返回队列大小
			int size = 0;
			PriorityNode<T> *temp = front;
			while (temp != nullptr) {
				size++;
				temp = temp->next;
			}
			return size;
		}

	private:
		PriorityNode<T> *front; // 队列头指针
		PriorityNode<T> *lastNodeArray[PRIORITY_NUMBER]; // 记录每个优先级的最后一个节点

		void PushAdjustLastNodeArray(short pri, PriorityNode<T> *p) { // 调整最后一个节点数组
			lastNodeArray[pri] = p;
		}

		void PopAdjustLastNodeArray(PriorityNode<T> *p) { // 调整最后一个节点数组
			if (p == nullptr) { // 如果队列为空
				for (int i = 0; i < PRIORITY_NUMBER; ++i) {
					lastNodeArray[i] = nullptr;
				}
			} else {
				while (p != nullptr) { // 遍历队列
					lastNodeArray[p->priority] = p;
					p = p->next;
				}
			}
		}
};

int findKthLargest(std::vector<int> &nums, int k) {
	PriorityQueue<int> pq;

	for (int num : nums) {
		pq.Push(num, num);
		if (pq.Size() > k) {
			pq.Pop();
		}
	}

	return pq.Top();
}

int main() {
	std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
	int k1 = 2;
	std::cout << "输入: [3, 2, 1, 5, 6, 4], k = 2" << std::endl;
	std::cout << "输出: " << findKthLargest(nums1, k1) << std::endl;

	std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
	int k2 = 4;
	std::cout << "输入: [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4" << std::endl;
	std::cout << "输出: " << findKthLargest(nums2, k2) << std::endl;

	return 0;
}
