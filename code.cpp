#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Worker {
	public:
		int wno;
		string name;
		double money;
		double More_money;
		double tax;
		double tot;
		// ��ӡ����������Ϣ
		void print() {
			printf("ְ����:%d \t ����:%s \t ����:%f \t ������%f\n"
			       , wno, name.c_str(), money, More_money);
		}
		//��ӡ���ʱ�
		void printtot() {
			printf("%d\t %f\t %f\n", wno, tax, tot);
		}
		// ��ӡ������Ϣ
		void printMoney() {
			printf("%d\t %s\t %f\n"
			       , wno, name.c_str(), tot);
		}
		// ��ӡְ��ְ��
		void printPosition() {
			printf("ְ����:%d \t ����:%s \t ְλ:%s \n"
			       , wno, name.c_str());
		}
};
// ����ְԱ
vector<Worker> workers;

void printMenu() {
	printf("************ְ�����ʹ���ϵͳ************\n");
	printf("*1.����ְ�����ʱ�                      *\n");
	printf("*2.ְ����˰��ʵ������                  *\n");
	printf("*3.ʵ�����ʴӸߵ�������                *\n");
	printf("*4.�޸�ְ��������Ϣ                    *\n");
	printf("*5.��ѯְ��������Ϣ                    *\n");
	printf("*6.ְ������ͳ�Ʒ���                    *\n");
	printf("*0.�˳�����                            *\n");
	printf("****************************************\n");
	printf("��������ѡ�񲢻س�(0-6)\n");
}

int findWorker() {
	int info;
	int i = 0;
	printf("������ְ����\n");
	cin >> info;
	for ( i = 0; i < workers.size(); i++) {
		if (info == (workers[i].wno))
			return i;
	}
	return -1;
}

void insertWorkers() {
	int num = 0;
	char flag;
INPUT:
	printf("ְ����\t ����\t ����\t ���� ���ÿո����\n");
	Worker temp;
	cin >> temp.wno >> temp.name >> temp.money >> temp.More_money;
	workers.push_back(temp);
	printf("�Ƿ�¼����һ��[Y/N]");
	cin >> flag;
	if (flag == 'Y')
		goto INPUT;
	printf("������\n");
}

// ����ְ�����޸�Ա����Ϣ
void updateWorker() {
	int index = findWorker();
	if (index < 0) {
		printf("δ�ҵ���Ա��\n");
		return;
	}
	printf("�ҵ���Ա��\n");
	printf("�������޸� ְ����  ����\t ����\t ���ÿո����\n");
	cin >> workers[index].wno >> workers[index].money >> workers[index].More_money;
	printf("�޸����\n");
}

//����ʵ������
void calW() {
	int size = workers.size() ;
	int tmp;
	for (int i = 0; i < size; i++) {
		workers[i].tax = 0;
		workers[i].tot = workers[i].money + workers[i].More_money;
		if (workers[i].tot >= 3000 && workers[i].tot < 4000) {
			workers[i].tax = (workers[i].tot - 3000) * 0.05;
			workers[i].tot = workers[i].tot - workers[i].tax;
		} else if (workers[i].tot > 4000) {
			workers[i].tax = (workers[i].tot - 3000) * 0.05 + (workers[i].tot - 4000) * 0.1;
			workers[i].tot = workers[i].tot - workers[i].tax;
		}
	}
}

// �Ӹߵ������ʵ������
void sortWorker() {
	calW();
	int tmp;
	for (int i = 0; i <  workers.size(); i++) {
		for (int j = 0; j <  workers.size() - 1 - i; j++) {
			if (workers[j].tot < workers[j + 1].tot) {
				tmp = workers[j].tot;
				workers[j].tot = workers[j + 1].tot;
				workers[j + 1].tot = tmp;
			}
		}
	}
	printf("ְ����\t ����\t ʵ������\t \n");
	for (int i = 0; i < workers.size(); i++) {
		workers[i].printMoney();
	}
}

// ��ӡ���ʱ�
void printALL() {
	int size = students.size() ;
	int tmp;
//	calW();
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size - 1 - i; j++) {
//			if (workers[j].wno > workers[j + 1].wno) {
//				tmp = workers[j].wno;
//				workers[j].wno = workers[j + 1].wno;
//				workers[j + 1].wno = tmp;
//			}
//		}
//	}
//	printf("ְ����\t ��˰\t ʵ������\t \n");
	for (int i = 0; i < size; i++) {
		students[i].printf();
	}
}

// ��������ѯְԱ��Ϣ
void printCondition() {
	int index = findWorker();
	if (index >= 0)
		workers[index].print();
	else
		printf("δ�ҵ�Ա��\n");
}

//����������Ϣ
void Analyze() {
	calW();
	double totN = workers.size(), und3k = 0;
	double und4k = 0, rest = 0;
	for (int i = 0; i < totN; i++) {
		double tot = workers[i].tot;
		if (tot < 3000) {
			und3k++;
			printf("%f", und3k);
		} else if (tot < 4000) {
			und4k++;
			printf("%f", und4k);
		} else {
			rest++;
			printf("%f", rest);
		}
	}
	printf("ʵ�����ʵ���3000:%f,ռ��%.1f\nʵ�����ʵ���4000����3000:%f,ռ��%.1f\nʵ�����ʸ���4000:%f,ռ��%.1f\n", und3k,
	       (und3k / totN), und4k, (und4k / totN), rest, (rest / totN));
}

int main() {
	int select = 0;
	while (1) {
		printMenu();
		cin >> select;
		switch (select) {
			case 1:
				insertWorkers();
				break;
			case 2:
				printALL();
				break;
//			case 3:
//				sortWorker();
//				break;
//			case 4:
//				updateWorker();
//				break;
//			case 5:
//				printCondition();
//				break;
//			case 6:
//				Analyze();
//				break;
//			case 0:
//				exit(0);
//				break;
			default:
				printf("�������,����������\n");
				break;
		}
	}

	return 0;
}


