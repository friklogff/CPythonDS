#include <iostream>
#include <iostream>
#include <vector>


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

		void Push(T x, short pri) { // ����ڵ㵽���ȶ���
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

		T Pop() { // �������ȼ���ߵĽڵ�
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

	private:
		PriorityNode<T> *front; // ����ͷָ��
		PriorityNode<T> *lastNodeArray[PRIORITY_NUMBER]; // ��¼ÿ�����ȼ������һ���ڵ�

		void PushAdjustLastNodeArray(short pri, PriorityNode<T> *p) { // �������һ���ڵ�����
			lastNodeArray[pri] = p;
		}

		void PopAdjustLastNodeArray(PriorityNode<T> *p) { // �������һ���ڵ�����
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
	std::cout << "����: [3, 2, 1, 5, 6, 4], k = 2" << std::endl;
	std::cout << "���: " << findKthLargest(nums1, k1) << std::endl;

	std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
	int k2 = 4;
	std::cout << "����: [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4" << std::endl;
	std::cout << "���: " << findKthLargest(nums2, k2) << std::endl;

	return 0;
}
