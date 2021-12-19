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
		// 打印个人所有信息
		void print() {
			printf("职工号:%d \t 名字:%s \t 工资:%f \t 津贴：%f\n"
			       , wno, name.c_str(), money, More_money);
		}
		//打印工资表
		void printtot() {
			printf("%d\t %f\t %f\n", wno, tax, tot);
		}
		// 打印工资信息
		void printMoney() {
			printf("%d\t %s\t %f\n"
			       , wno, name.c_str(), tot);
		}
		// 打印职工职称
		void printPosition() {
			printf("职工号:%d \t 名字:%s \t 职位:%s \n"
			       , wno, name.c_str());
		}
};
// 所有职员
vector<Worker> workers;

void printMenu() {
	printf("************职工工资管理系统************\n");
	printf("*1.建立职工工资表                      *\n");
	printf("*2.职工扣税和实发工资                  *\n");
	printf("*3.实发工资从高到低排序                *\n");
	printf("*4.修改职工工资信息                    *\n");
	printf("*5.查询职工工资信息                    *\n");
	printf("*6.职工工资统计分析                    *\n");
	printf("*0.退出程序                            *\n");
	printf("****************************************\n");
	printf("输入您的选择并回车(0-6)\n");
}

int findWorker() {
	int info;
	int i = 0;
	printf("请输入职工号\n");
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
	printf("职工号\t 名字\t 工资\t 津贴 并用空格隔开\n");
	Worker temp;
	cin >> temp.wno >> temp.name >> temp.money >> temp.More_money;
	workers.push_back(temp);
	printf("是否录入下一项[Y/N]");
	cin >> flag;
	if (flag == 'Y')
		goto INPUT;
	printf("添加完成\n");
}

// 输入职工号修改员工信息
void updateWorker() {
	int index = findWorker();
	if (index < 0) {
		printf("未找到该员工\n");
		return;
	}
	printf("找到该员工\n");
	printf("请输入修改 职工号  工资\t 津贴\t 并用空格隔开\n");
	cin >> workers[index].wno >> workers[index].money >> workers[index].More_money;
	printf("修改完成\n");
}

//计算实发工资
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

// 从高到低输出实发工资
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
	printf("职工号\t 名字\t 实发工资\t \n");
	for (int i = 0; i < workers.size(); i++) {
		workers[i].printMoney();
	}
}

// 打印工资表
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
//	printf("职工号\t 扣税\t 实发工资\t \n");
	for (int i = 0; i < size; i++) {
		students[i].printf();
	}
}

// 按条件查询职员信息
void printCondition() {
	int index = findWorker();
	if (index >= 0)
		workers[index].print();
	else
		printf("未找到员工\n");
}

//分析工资信息
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
	printf("实发工资低于3000:%f,占比%.1f\n实发工资低于4000高于3000:%f,占比%.1f\n实发工资高于4000:%f,占比%.1f\n", und3k,
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
				printf("输入错误,请重新输入\n");
				break;
		}
	}

	return 0;
}


