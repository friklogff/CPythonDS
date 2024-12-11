#include <iostream>  // 包含输入输出流库，用于标准输入输出操作
using namespace std;  // 使用标准命名空间，简化标准库函数和对象的使用

template<class T>  // 模板声明，定义一个通用类型T
struct Node { // 定义一个结构体Node，表示链表的节点
	T data;  // 节点的数据域，类型为T
	struct Node<T> *next;  // 节点的指针域，指向下一个节点
};

template<class T>  // 模板声明，定义一个通用类型T
class LinkList { // 定义一个类LinkList，表示链表
	public:
		LinkList() { // 构造函数：用于初始化对象，在创建对象时自动调用。
			front = new Node<T>;  // 创建一个新的头节点
			front->next = NULL;  // 头节点的next指针指向NULL
		}

		LinkList(T a[], int n);  // 重载构造函数：用于根据不同的参数初始化对象，在创建对象时自动调用。

		~LinkList();  // 析构函数：用于释放对象占用的资源，在对象被销毁时自动调用。

		void PrintList();  // 打印链表中的所有元素

		int GetLength();  // 获取链表的长度

		Node<T> *Get(int i);  // 按位查找，获取第i个节点

		int Locate(T x);  // 按值查找，获取值为x的节点的位置

		void Insert(int i, T x);  // 插入操作，在第i个位置插入值为x的节点

		T Delet(int i);  // 删除操作，删除第i个位置的节点，并返回其值

	private:
		Node<T> *front;  // 链表的头节点指针
};

// 尾插法建立单链表
template<class T>
LinkList<T>::LinkList(T a[], int n) { // 构造函数，通过数组初始化链表
	front = new Node<T>;  // 创建一个新的头节点
	Node<T> *r = front;  // 定义一个尾指针r，初始指向头节点
	for (int i = 0; i < n; i++) { // 遍历数组
		Node<T> *s = new Node<T>;  // 创建一个新的节点s
		s->data = a[i];  // 将数组中的元素赋值给节点的数据域
		r->next = s;  // 将尾指针的next指针指向新节点
		r = s;  // 更新尾指针，指向新节点
	}
	r->next = NULL;  // 尾节点的next指针指向NULL
}

// 析构函数
template<class T>
LinkList<T>::~LinkList() { // 析构函数，释放链表占用的内存
	Node<T> *p = front;  // 定义一个指针p，初始指向头节点
	while (p) { // 遍历链表
		Node<T> *temp = p;  // 定义一个临时指针temp，指向当前节点
		p = p->next;  // 更新指针p，指向下一个节点
		delete temp;  // 释放当前节点的内存
	}
}

// 按位查找
template<class T>
Node<T> *LinkList<T>::Get(int i) { // 按位查找，获取第i个节点
	Node<T> *p = front->next;  // 定义一个指针p，初始指向头节点的下一个节点
	int j = 1;  // 定义一个计数器j，初始值为1
	while (p && j != i) { // 遍历链表，直到找到第i个节点或到达链表末尾
		p = p->next;  // 更新指针p，指向下一个节点
		j++;  // 更新计数器j
	}
	return p;  // 返回第i个节点的指针
}

// 按值查找
template<class T>
int LinkList<T>::Locate(T x) { // 按值查找，获取值为x的节点的位置
	Node<T> *p = front->next;  // 定义一个指针p，初始指向头节点的下一个节点
	int j = 1;  // 定义一个计数器j，初始值为1
	while (p) { // 遍历链表
		if (p->data == x)  // 如果找到值为x的节点
			return j;  // 返回节点的位置
		p = p->next;  // 更新指针p，指向下一个节点
		j++;  // 更新计数器j
	}
	return -1;  // 如果没有找到值为x的节点，返回-1
}

// 插入操作
template<class T>
void LinkList<T>::Insert(int i, T x) { // 插入操作，在第i个位置插入值为x的节点
	Node<T> *p = front;  // 定义一个指针p，初始指向头节点
	if (i != 1)  // 如果插入位置不是第一个位置
		p = Get(i - 1);  // 获取插入位置的前一个节点
	if (p) { // 如果插入位置合法
		Node<T> *s = new Node<T>;  // 创建一个新的节点s
		s->data = x;  // 将值x赋值给节点的数据域
		s->next = p->next;  // 将新节点的next指针指向插入位置的节点
		p->next = s;  // 将插入位置的前一个节点的next指针指向新节点
	} else
		throw "插入位置错误";  // 如果插入位置不合法，抛出异常
}

// 删除操作
template<class T>
T LinkList<T>::Delet(int i) { // 删除操作，删除第i个位置的节点，并返回其值
	Node<T> *p = front;  // 定义一个指针p，初始指向头节点
	if (i != 1)  // 如果删除位置不是第一个位置
		p = Get(i - 1);  // 获取删除位置的前一个节点
	Node<T> *q = p->next;  // 定义一个指针q，指向删除位置的节点
	p->next = q->next;  // 将删除位置的前一个节点的next指针指向删除位置的下一个节点
	T x = q->data;  // 获取删除节点的值
	delete q;  // 释放删除节点的内存
	return x;  // 返回删除节点的值
}

// 打印链表
template<class T>
void LinkList<T>::PrintList() { // 打印链表中的所有元素
	Node<T> *p = front->next;  // 定义一个指针p，初始指向头节点的下一个节点
	while (p != NULL) { // 遍历链表
//		cout << p->data << " ";  // 不能直接打印当前节点的数据域的私有变量
		p->data.print();// 打印当前节点的数据域,使用公有的访问器函数

		p = p->next;  // 更新指针p，指向下一个节点
	}
	cout << endl;  // 换行
}
//#include "LinkList.h"  // 包含自定义的链表头文件
#include <string>  // 包含字符串类的头文件

class PHONEBOOK { // 定义一个类PHONEBOOK，表示通讯录中的一条记录
	private:
		int m_ID;  // 记录的ID
		string m_name;  // 记录的姓名
		string m_phone;  // 记录的电话号码
		string m_group;  // 记录的分组

	public:
		PHONEBOOK() {}  // 默认构造函数：不进行任何初始化

		PHONEBOOK(int id, string name, string phone, string group) {
			// 带参数的构造函数：用于创建一个 PHONEBOOK 对象    PHONEBOOK pbook(20181208, "Mary", "13011221827", "classmates");时
			// 初始化私有成员变量 m_ID、m_name、m_phone 和 m_group
			m_ID = id;
			m_name = name;
			m_phone = phone;
			m_group = group;
		}

		void print() { // 打印记录的信息：将私有成员变量 m_ID、m_name、m_phone 和 m_group 的值输出到标准输出流，使用制表符 \t 分隔。
			cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
		}

		bool operator == (PHONEBOOK &p) { // 重载==运算符，用于比较两个记录的ID是否相同
			if (p.m_ID == m_ID)
				return true;
			return false;
		}
};

int main() { // 主函数
	PHONEBOOK pbook[4] = {  // 初始化一个包含4条记录的通讯录数组
		{20181208, "Mary", "13011221827", "classmates"},
		{20181127, "Tom", "13934621123", "family"},
		{20181156, "John", "1324579880", "classmates"},
		{20181123, "Lisa", "1378001822", "clsaamates"}
	};

	PHONEBOOK record(20181209, "phoneix", "1593020920", "teacher");  // 创建一条新的记录

	LinkList<PHONEBOOK> list(pbook, 4);  // 使用通讯录数组初始化链表

	cout << "通信录内容列表:" << endl;
	list.PrintList();  // 打印链表中的所有记录

	list.Insert(1, record);  // 在链表的第一个位置插入新的记录

	cout << "通信录内容列表:" << endl;
	list.PrintList();  // 打印链表中的所有记录

	PHONEBOOK x = list.Delet(3);  // 删除链表中的第三个记录，并返回删除的记录

	cout << "删除元素:" << endl;
	x.print();  // 打印删除的记录

	cout << "通信录内容列表:" << endl;
	list.PrintList();  // 打印链表中的所有记录

	int p = list.Locate(record);  // 查找新的记录在链表中的位置
	cout << "phoenix的位置是:" << p << endl;  // 打印新的记录的位置

	return 0;  // 返回0，表示程序正常结束
}
/*
`string` 和 `char*` 都是用于处理字符串的数据类型，但它们有显著的区别。下面是对它们的详细解释和比较：

### `string`

`string` 是 C++ 标准库中的一个类，定义在 `<string>` 头文件中。它提供了丰富的字符串操作功能，使得字符串处理更加方便和安全。

**特性和优点：**
1. **动态大小**：`string` 可以动态调整大小，不需要手动管理内存。
2. **丰富的成员函数**：提供了许多成员函数，如 `length()`、`size()`、`substr()`、`find()`、`append()` 等，方便进行各种字符串操作。
3. **安全性**：`string` 自动管理内存，减少了内存泄漏和越界访问的风险。
4. **兼容性**：`string` 可以与 `char*` 互操作，通过 `c_str()` 成员函数可以获取 `const char*`。

**示例：**
```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Substring: " << str.substr(7, 5) << std::endl;
    return 0;
}
```

### `char*`

`char*` 是 C 语言中的字符串表示方式，也可以在 C++ 中使用。它是一个指向字符数组的指针。

**特性和优点：**
1. **灵活性**：`char*` 提供了对底层字符数组的直接访问，可以进行低级别的字符串操作。
2. **兼容性**：`char*` 可以与 C 语言的字符串函数（如 `strlen()`、`strcpy()`、`strcat()` 等）兼容。

**缺点：**
1. **内存管理**：需要手动管理内存，容易出现内存泄漏和越界访问的问题。
2. **不安全**：容易出现缓冲区溢出等安全问题。
3. **操作不便**：需要手动编写许多字符串操作函数，增加了代码的复杂性。

**示例：**
```cpp
#include <iostream>
#include <cstring>

int main() {
    char str[] = "Hello, World!";
    std::cout << "Length: " << std::strlen(str) << std::endl;
    char substr[6];
    std::strncpy(substr, str + 7, 5);
    substr[5] = '\0';
    std::cout << "Substring: " << substr << std::endl;
    return 0;
}
```

### 比较

1. **内存管理**：
   - `string`：自动管理内存，减少内存泄漏和越界访问的风险。
   - `char*`：需要手动管理内存，容易出现内存泄漏和越界访问的问题。

2. **操作便利性**：
   - `string`：提供了丰富的成员函数，方便进行各种字符串操作。
   - `char*`：需要手动编写许多字符串操作函数，增加了代码的复杂性。

3. **安全性**：
   - `string`：更安全，减少了缓冲区溢出等安全问题。
   - `char*`：容易出现缓冲区溢出等安全问题。

4. **兼容性**：
   - `string`：可以与 `char*` 互操作，通过 `c_str()` 成员函数可以获取 `const char*`。
   - `char*`：可以与 C 语言的字符串函数兼容。

### 总结

在 C++ 中，推荐使用 `string` 类来处理字符串，因为它提供了更高的安全性和便利性。只有在需要与 C 语言兼容或进行低级别字符串操作时，才考虑使用 `char*`。
*/