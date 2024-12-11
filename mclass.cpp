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
	A objA(42); // 实例化类 A，并传入整数值 42 初始化对象
	objA.printData(); // 调用成员函数以打印对象中存储的数据

	B objB(10); // 实例化类 B，并传入整数值 10 初始化对象
	objB.displayData(); // 调用成员函数以显示对象中存储的数据

	return 0;
}
