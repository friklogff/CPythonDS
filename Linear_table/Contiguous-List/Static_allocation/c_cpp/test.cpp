#include <stdio.h>
#include <string.h>

// ����ṹ�� Person
struct Person {
	char name[50];
	int age;
	float height;


} ;

// ����Ƕ�׽ṹ�� Address
struct Address {
	char street[100];
	char city[50];
	int zip;
};

// �������Ƕ�׽ṹ�� Address �Ľṹ�� PersonWithAddress
struct PersonWithAddress {
	char name[50];
	int age;
	struct Address address;

} person3 = {"����3˿3", 30, {"123 ��Ҫ�ֵ�", "�󶼻�", 54321}};

// ʹ�� typedef ����ṹ��
typedef struct {
	char brand[50];
	int model_year;
} Car;

// ��������
void printPerson(struct Person p);
void modifyPerson(struct Person *p);

int main() {
	// �����ͳ�ʼ���ṹ�����
	struct Person person1 = {"����˿", 30, 5.7f};
	struct Person person2;

	// �޸ĳ�Ա
	strcpy(person2.name, "����");
	person2.age = 25;
	person2.height = 5.9f;

	// ��ӡ�ṹ�����
	printPerson(person1);
	printPerson(person2);

	// �����ṹ������
	struct Person people[3] = {
		{"����", 22, 6.0f},
		{"����", 27, 5.5f},
		{"��ܽ", 29, 5.6f}
	};

	// ��ӡ�ṹ������
	for (int i = 0; i < 3; i++) {
		printPerson(people[i]);
	}

	// ָ��ṹ���ָ��
	struct Person *ptr = &person1;
	ptr->age = 31;  // ʹ�ü�ͷ���������ʳ�Ա

	// ��ӡ�޸ĺ�� person1
	printPerson(person1);

	// ����Ƕ�׽ṹ�����
//	struct PersonWithAddress person3 = {"������", 35, {"123 ��Ҫ�ֵ�", "�󶼻�", 54321}};
	printf("����: %s, ����: %d, �ֵ�: %s, ����: %s, �ʱ�: %d\n",
	       person3.name, person3.age, person3.address.street, person3.address.city, person3.address.zip);

	// ���� typedef ����Ľṹ�����
	Car car1 = {"����", 2021};
	printf("����Ʒ��: %s, �������: %d\n", car1.brand, car1.model_year);

	// ͨ��ָ���޸Ľṹ��
	modifyPerson(&person2);
	printPerson(person2);

	return 0;
}

// �������壺ͨ��ֵ���ݴ�ӡ�ṹ��
void printPerson(struct Person p) {
	printf("����: %s, ����: %d, ���: %.2f\n", p.name, p.age, p.height);
}

// �������壺ͨ��ָ���޸Ľṹ���Ա
void modifyPerson(struct Person *p) {
	p->age = 30;
	strcpy(p->name, "���µ�����");
}
