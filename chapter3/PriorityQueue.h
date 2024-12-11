#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>

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

		void Push(T x, short pri) { // 插入节点到优先队列；入队
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

		T Pop() { // 弹出优先级最高的节点；出队
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
/////////////////////////////////////////////////////////////
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

	private://以下函数仅仅需要被类中的其他函数调用；外部代码无法直接调用这些方法，从而确保了数据一致性和正确性
		PriorityNode<T> *front; // 队列头指针；头结点
		PriorityNode<T> *lastNodeArray[PRIORITY_NUMBER]; // 记录每个优先级的最后一个节点；最后结点指针数组

		void PushAdjustLastNodeArray(short pri, PriorityNode<T> *p) { // 调整最后一个节点数组；入队时调整数组
			lastNodeArray[pri] = p;
		}

		void PopAdjustLastNodeArray(PriorityNode<T> *p) { // 调整最后一个节点数组；出队时调整数组
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
		//通过上述封装，类对外界隐藏了内部数据结构的具体实现细节，同时提供了受控的访问机制。这种封装使得类更易于使用、维护和扩展，同时增加了代码的安全性和可靠性。

};


#endif
