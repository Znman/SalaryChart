#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int info;

class Student {
	public:
		int wno;
		string name;
		double avr;
		double classmate;
		double teacher;
		double tot;
		// ��ӡѧ��������Ϣ
		void print() {
			printf("ѧ��:%d \t ����:%s \t �ۺϲ����ܷ֣�%.2f \t\n"
			       , wno, name.c_str(), tot);
		}
		//��ӡ����
		void printtot() {
			printf("%d \t %s \t %.2f \t\n", wno, name.c_str(), tot);
		}
};
// ����ѧ��
vector<Student> Students;

void printMenu() {
	printf("************ְ�����ʹ���ϵͳ************\n");
	printf("*1.¼��ѧ����Ϣ               (done)   *\n");
	printf("*2.���ѧ��������Ϣ           (done)   *\n");
	printf("*3.�ۺϲ����ִӸߵ�������     (done)   *\n");
	printf("*4.��ѯѧ��������Ϣ           (done)   *\n");
	printf("*5.�޸�ѧ��������Ϣ           (done)   *\n");
	printf("*6.ɾ��ѧ��������Ϣ           (done)   *\n");
	printf("*7.���ѧ��������Ϣ                    *\n");
	printf("*0.�˳�����                            *\n");
	printf("****************************************\n");
	printf("��������ѡ�񲢻س�(0-7)\n");
}

void sort() {
	int size = Students.size() ;
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (Students[j].wno > Students[j + 1].wno) {
				tmp = Students[j].wno;
				Students[j].wno = Students[j + 1].wno;
				Students[j + 1].wno = tmp;
			}
		}
	}
}


int findStudent(int F) {
	int i = 0;
	if (F == 1) {
		printf("������ѧ������\n");
		string info;
		cin >> info;
		for ( i = 0; i < Students.size(); i++) {
			if (!info.compare(Students[i].name))
				return i;
		}

	} else {
		printf("������ѧ����\n");
		int info;
		cin >> info;
		for ( i = 0; i < Students.size(); i++) {
			if (info == (Students[i].wno))
				return i;
		}
	}

	return -1;
}

//����ѧ��
void insertStudents() {
	int num = 0;
	char flag;
INPUT:
	printf("ѧ��\t ����\t ����\t ͬѧ������\t �ο���ʦ���� ���ÿո����\n");
	Student temp;
	cin >> temp.wno >> temp.name >> temp.avr >> temp.classmate >> temp.teacher;
	temp.tot = temp.avr * 0.6 + temp.classmate * 0.2 + temp.teacher * 0.2;
	Students.push_back(temp);
	printf("�Ƿ�¼����һ��[Y/N]");
	cin >> flag;
	if (flag == 'Y')
		goto INPUT;
	sort();
	printf("������\n");
}

// ����ѧ�����޸�ѧ����Ϣ
void updateStudent() {
	int index = findStudent(2);
	if (index < 0) {
		printf("δ�ҵ���ѧ��\n");
		Student temp;
		printf("���� ����\t ����\t ͬѧ������\t �ο���ʦ���� ���ÿո����\n");
		temp.wno = info;
		cin  >> temp.name >> temp.avr >> temp.classmate >> temp.teacher;
		temp.tot = temp.avr * 0.6 + temp.classmate * 0.2 + temp.teacher * 0.2;
		Students.push_back(temp);
		sort();
		return;
	}
	printf("�ҵ���ѧ��\n");
	printf("�������޸� ѧ��\t ����\t ����\t ͬѧ������\t �ο���ʦ����\t ���ÿո����\n");
	cin >> Students[index].wno >> Students[index].name >> Students[index].avr;
	cin >> Students[index].classmate >> Students[index].teacher;
	sort();
	printf("�޸����\n");
}

// ɾ��ѧ��
void deleteStudent() {

	int index = findStudent(2);
	if (index < 0) {
		printf("δ�ҵ���ѧ��\n");
		return;
	}
	printf("�ҵ���ѧ��\n");
	Students.erase(Students.begin() + index);
	printf("ɾ�����\n");
}


// �Ӹߵ�������ۺϲ�������
void sortStudent() {
	int tmp;
	for (int i = 0; i <  Students.size(); i++) {
		for (int j = 0; j <  Students.size() - 1 - i; j++) {
			if (Students[j].tot < Students[j + 1].tot) {
				tmp = Students[j].tot;
				Students[j].tot = Students[j + 1].tot;
				Students[j + 1].tot = tmp;
			}
		}
	}
	printf("ѧ�� \t ���� \t �ۺϲ������� \t \n");

	for (int i = 0; i < Students.size(); i++) {
		Students[i].print();
	}
}

// ��ӡ������Ϣ��
void printALL() {
	int size = Students.size() ;
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (Students[j].wno > Students[j + 1].wno) {
				tmp = Students[j].wno;
				Students[j].wno = Students[j + 1].wno;
				Students[j + 1].wno = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		Students[i].print();
	}
}

//��ѯѧ��
void printCondition() {
	int flag = 0;
	printf("1.������ѯ \n2.ѧ�Ų�ѯ\n");
	printf("������[1-2]\n");
	cin >> flag;

	if (flag <= 2) {
		int index = findStudent(flag);
		if (index >= 0)
			Students[index].print();
		else
			printf("δ�ҵ�ѧ��\n");
	}
}

//��ȡ����ʾѧ��������Ϣ
void OutputStudent() {
	sort();
	FILE *fp;
	fp = fopen("data.txt", "a+");
	if ((fp = fopen("data.txt", "a+")) == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
	fprintf(fp, "ѧ�� \t ���� \t �ۺϲ����ܷ� \t �ۺϲ������� \t \n");

	for (int i = 1; i <= Students.size(); i++) {
		fprintf(fp, "%d \t %s \t %.2f \t %d \n", Students[i].wno, Students[i].name, Students[i].tot, i);
	}
	fclose(fp);
}

int main() {
	int select = 0;
	while (1) {
		printMenu();
		cin >> select;
		switch (select) {
			case 1:
				insertStudents();
				break;
			case 4:
				printCondition();
				break;
			case 3:
				sortStudent();
				break;
			case 2:
				updateStudent();
				break;
			case 5:
				updateStudent();
				break;
			case 6:
				deleteStudent();
				break;
			case 7:
				OutputStudent();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("�������,����������\n");
				break;
		}
	}

	return 0;
}


