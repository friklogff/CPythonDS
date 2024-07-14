#include <stdio.h>
#include <string.h>

// 定义结构体 Person
struct Person {
	char name[50];
	int age;
	float height;


} ;

// 定义嵌套结构体 Address
struct Address {
	char street[100];
	char city[50];
	int zip;
};

// 定义包含嵌套结构体 Address 的结构体 PersonWithAddress
struct PersonWithAddress {
	char name[50];
	int age;
	struct Address address;

} person3 = {"爱丽3丝3", 30, {"123 主要街道", "大都会", 54321}};

// 使用 typedef 定义结构体
typedef struct {
	char brand[50];
	int model_year;
} Car;

// 函数声明
void printPerson(struct Person p);
void modifyPerson(struct Person *p);

int main() {
	// 创建和初始化结构体变量
	struct Person person1 = {"爱丽丝", 30, 5.7f};
	struct Person person2;

	// 修改成员
	strcpy(person2.name, "鲍勃");
	person2.age = 25;
	person2.height = 5.9f;

	// 打印结构体变量
	printPerson(person1);
	printPerson(person2);

	// 创建结构体数组
	struct Person people[3] = {
		{"查理", 22, 6.0f},
		{"丹娜", 27, 5.5f},
		{"伊芙", 29, 5.6f}
	};

	// 打印结构体数组
	for (int i = 0; i < 3; i++) {
		printPerson(people[i]);
	}

	// 指向结构体的指针
	struct Person *ptr = &person1;
	ptr->age = 31;  // 使用箭头操作符访问成员

	// 打印修改后的 person1
	printPerson(person1);

	// 创建嵌套结构体变量
//	struct PersonWithAddress person3 = {"弗兰克", 35, {"123 主要街道", "大都会", 54321}};
	printf("名字: %s, 年龄: %d, 街道: %s, 城市: %s, 邮编: %d\n",
	       person3.name, person3.age, person3.address.street, person3.address.city, person3.address.zip);

	// 创建 typedef 定义的结构体变量
	Car car1 = {"丰田", 2021};
	printf("汽车品牌: %s, 车型年份: %d\n", car1.brand, car1.model_year);

	// 通过指针修改结构体
	modifyPerson(&person2);
	printPerson(person2);

	return 0;
}

// 函数定义：通过值传递打印结构体
void printPerson(struct Person p) {
	printf("名字: %s, 年龄: %d, 身高: %.2f\n", p.name, p.age, p.height);
}

// 函数定义：通过指针修改结构体成员
void modifyPerson(struct Person *p) {
	p->age = 30;
	strcpy(p->name, "更新的名字");
}
