#include <iostream>
#include <queue>

using namespace std;

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 队列结构体
struct QueueNode {
	BiTree data;
	QueueNode *next;
};

class Queue {
	private:
		QueueNode *front, *rear;

	public:
		Queue() {
			front = rear = NULL;
		}

		void EnQueue(BiTree x) {
			QueueNode *newNode = new QueueNode;
			newNode->data = x;
			newNode->next = NULL;

			if (rear == NULL) {
				front = rear = newNode;
			} else {
				rear->next = newNode;
				rear = newNode;
			}
		}

		void DeQueue() {
			if (front == NULL) {
				return;
			}

			QueueNode *temp = front;
			front = front->next;

			if (front == NULL) {
				rear = NULL;
			}

			delete temp;
		}

		bool isEmpty() {
			return front == NULL;
		}

		BiTree getFront() {
			if (front != NULL) {
				return front->data;
			}
			return NULL;
		}
};

void LevelOrder(BiTree T) {
	Queue Q;
	Q.EnQueue(T);

	while (!Q.isEmpty()) {
		BiTree p = Q.getFront();
		Q.DeQueue();

		cout << p->data << " ";

		if (p->lchild != NULL) {
			Q.EnQueue(p->lchild);
		}
		if (p->rchild != NULL) {
			Q.EnQueue(p->rchild);
		}
	}
}

int main() {
	BiTNode n1, n2, n3, n4, n5;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;
	n1.lchild = &n2;
	n1.rchild = &n3;
	n2.lchild = &n4;
	n2.rchild = &n5;
	n3.lchild = n3.rchild = n4.lchild = n4.rchild = n5.lchild = n5.rchild = NULL;

	BiTree T = &n1;

	cout << "Level Order Traversal: ";
	LevelOrder(T);

	return 0;
}
