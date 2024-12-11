#include <iostream>
using namespace std;

const int MAXSIZE = 100;

template<class T>
struct StaticNode {
	T data;
	int next;
};

template<class T>
class StaticLinkList {
	public:
		StaticLinkList() {
			for (int i = 0; i < MAXSIZE - 1; i++) {
				SArray[i].next = i + 1;
			}
			SArray[MAXSIZE - 1].next = -1;
//			front = -1;

			tail = 0;
		}

		void Insert(int i, T x) {
			if (i < 0 || i > tail)
				throw "插入位置无效";
			int j = NewNode();
			SArray[j].data = x;
			if (i == 0) {
				SArray[j].next = SArray[0].next;
				SArray[0].next = j;
			} else {
				int k = 0;
				while (k != -1 && i > 0) {
					k = SArray[k].next;
					i--;
				}
				SArray[j].next = SArray[k].next;
				SArray[k].next = j;
			}
			if (SArray[j].next == -1) {
				tail = j;
			}
		}

		T Delete(int i) {
			if (i < 0 || i > tail)
				throw "删除位置无效";
			int k = 0;
			while (k != -1 && i > 0) {
				k = SArray[k].next;
				i--;
			}
			int j = SArray[k].next;
			T x = SArray[j].data;
			SArray[k].next = SArray[j].next;
			DeleteNode(j);
			if (SArray[k].next == -1) {
				tail = k;
			}
			return x;
		}

		T Get(int i) {
			if (i < 0 || i > tail)
				throw "位置无效";
			int k = 0;
			while (k != -1 && i > 0) {
				k = SArray[k].next;
				i--;
			}
			return SArray[SArray[k].next].data;
		}

		int Locate(T x) {
			int k = SArray[0].next;
			int i = 0;
			while (k != -1) {
				if (SArray[k].data == x) {
					return i;
				}
				k = SArray[k].next;
				i++;
			}
			return -1;
		}

	private:
		int tail;
//		int front;
		StaticNode<T> SArray[MAXSIZE];

		int NewNode() {
			if (tail == -1)
				throw "空间不足";
			int pos = tail;
			tail = SArray[tail].next;
			return pos;
		}

		void DeleteNode(int i) {
			if (i < 0 || i >= MAXSIZE || SArray[i].next == -1)
				throw "释放空间错误";
			SArray[i].next = tail;
			tail = i;
		}
};

int main() {
	StaticLinkList<int> list;

	list.Insert(0, 1);
	list.Insert(1, 2);
	list.Insert(2, 3);

	cout << "初始链表：";
	for (int i = 0; i <= list.Locate(3); i++) {
		cout << list.Get(i) << " ";
	}
	cout << endl;

	list.Insert(2, 99);
	cout << "在位置2插入99后：";
	for (int i = 0; i <= list.Locate(3); i++) {
		cout << list.Get(i) << " ";
	}
	cout << endl;

	int deletedValue = list.Delete(2);
	cout << "删除位置2处的值 (" << deletedValue << ") 后：";
	for (int i = 0; i <= list.Locate(3); i++) {
		cout << list.Get(i) << " ";
	}
	cout << endl;

	return 0;
}
