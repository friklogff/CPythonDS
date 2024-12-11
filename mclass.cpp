#include <iostream>

class A {
	public:
		A(int i) : data(i) {}

		void printData() {
			std::cout << "Data: " << data << std::endl;
		}

	private:
		int data;
};

class B {
	public:
		B(int value) : data(value) {
			std::cout << "Constructing object with value: " << value << std::endl;
		}

		void displayData() {
			std::cout << "Data value: " << data << std::endl;
		}

	private:
		int data;
};

int main() {
	A objA(42); // ʵ������ A������������ֵ 42 ��ʼ������
	objA.printData(); // ���ó�Ա�����Դ�ӡ�����д洢������

	B objB(10); // ʵ������ B������������ֵ 10 ��ʼ������
	objB.displayData(); // ���ó�Ա��������ʾ�����д洢������

	return 0;
}
