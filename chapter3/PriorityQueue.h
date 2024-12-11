#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>

#define PRIORITY_NUMBER 100 // �������ȼ�����Ϊ100
//ģ����һ��ͨ�ñ�̼�������������д�����Ĵ��룬�ܹ�������ֲ�ͬ���͵����ݡ�ͨ��ģ�壬������ʵ�����ݽṹ���㷨�ȿ�������֧�ֲ�ͬ�������͵Ĺ��ܡ�
//template <class T>
//T add(T a, T b) {
//    return a + b;
//}
//
//int result1 = add(5, 3); // ʹ��ģ�庯���������
//double result2 = add(2.5, 3.7); // ʹ��ģ�庯����Ӹ�����

template <class T>
struct PriorityNode { // ����洢���ݺ����ȼ��Ľڵ�ṹ��
	short priority; // ���ȼ�
	T data; // ����
	struct PriorityNode<T> *next; // ָ����һ���ڵ��ָ��
};

template <class T>
class PriorityQueue { // �������ȶ�����
	public:
		PriorityQueue() { // ���캯��
			front = nullptr; // ����ͷָ��Ϊ��
			for (int i = 0; i < PRIORITY_NUMBER; ++i) { // ��ʼ�����һ���ڵ����飬���ڼ�¼ÿ�����ȼ������һ���ڵ�
				lastNodeArray[i] = nullptr;
			}
		}

		~PriorityQueue() { // ��������
			while (front != nullptr) { // �ͷŶ��������нڵ�ռ�õ��ڴ�
				PriorityNode<T> *temp = front;
				front = front->next;
				delete temp;
			}
		}

		void Push(T x, short pri) { // ����ڵ㵽���ȶ��У����
			PriorityNode<T> *newNode = new PriorityNode<T>; // �����½ڵ�
			newNode->priority = pri; // �������ȼ�
			newNode->data = x; // ��������
			newNode->next = nullptr; // �½ڵ�ָ���

			if (front == nullptr) { // �������Ϊ��
				front = newNode; // �½ڵ��Ϊ��һ���ڵ�
			} else {
				if (pri < front->priority) { // ����½ڵ����ȼ��ȵ�һ���ڵ��
					newNode->next = front;
					front = newNode; // �½ڵ��Ϊ��һ���ڵ�
				} else {
					PriorityNode<T> *temp = front;
					while (temp->next != nullptr && temp->next->priority <= pri) { // Ѱ�Ҳ���λ��
						temp = temp->next;
					}
					newNode->next = temp->next;
					temp->next = newNode; // �����½ڵ�
				}
			}

			PushAdjustLastNodeArray(pri, newNode); // �������һ���ڵ�����
		}

		T Pop() { // �������ȼ���ߵĽڵ㣻����
			if (front == nullptr) {
				std::cerr << "Queue is empty." << std::endl;
				return T();
			}

			PriorityNode<T> *temp = front;
			front = front->next;
			T poppedData = temp->data;
			delete temp;

			PopAdjustLastNodeArray(front); // �������һ���ڵ�����

			return poppedData;
		}
/////////////////////////////////////////////////////////////
		T Top() { // �������ȼ���ߵĽڵ�����
			if (front == nullptr) {
				std::cerr << "Queue is empty." << std::endl;
				return T();
			}

			return front->data;
		}

		int Size() const { // ���ض��д�С
			int size = 0;
			PriorityNode<T> *temp = front;
			while (temp != nullptr) {
				size++;
				temp = temp->next;
			}
			return size;
		}

	private://���º���������Ҫ�����е������������ã��ⲿ�����޷�ֱ�ӵ�����Щ�������Ӷ�ȷ��������һ���Ժ���ȷ��
		PriorityNode<T> *front; // ����ͷָ�룻ͷ���
		PriorityNode<T> *lastNodeArray[PRIORITY_NUMBER]; // ��¼ÿ�����ȼ������һ���ڵ㣻�����ָ������

		void PushAdjustLastNodeArray(short pri, PriorityNode<T> *p) { // �������һ���ڵ����飻���ʱ��������
			lastNodeArray[pri] = p;
		}

		void PopAdjustLastNodeArray(PriorityNode<T> *p) { // �������һ���ڵ����飻����ʱ��������
			if (p == nullptr) { // �������Ϊ��
				for (int i = 0; i < PRIORITY_NUMBER; ++i) {
					lastNodeArray[i] = nullptr;
				}
			} else {
				while (p != nullptr) { // ��������
					lastNodeArray[p->priority] = p;
					p = p->next;
				}
			}
		}
		//ͨ��������װ���������������ڲ����ݽṹ�ľ���ʵ��ϸ�ڣ�ͬʱ�ṩ���ܿصķ��ʻ��ơ����ַ�װʹ���������ʹ�á�ά������չ��ͬʱ�����˴���İ�ȫ�ԺͿɿ��ԡ�

};


#endif
