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
		// 打印学生所有信息
		void print() {
			printf("学号:%d \t 名字:%s \t 综合测评总分：%.2f \t\n"
			       , wno, name.c_str(), tot);
		}
		//打印分数
		void printtot() {
			printf("%d \t %s \t %.2f \t\n", wno, name.c_str(), tot);
		}
};
// 所有学生
vector<Student> Students;

void printMenu() {
	printf("************职工工资管理系统************\n");
	printf("*1.录入学生信息               (done)   *\n");
	printf("*2.添加学生测评信息           (done)   *\n");
	printf("*3.综合测评分从高到低排序     (done)   *\n");
	printf("*4.查询学生测评信息           (done)   *\n");
	printf("*5.修改学生测评信息           (done)   *\n");
	printf("*6.删除学生测评信息           (done)   *\n");
	printf("*7.浏览学生测评信息                    *\n");
	printf("*0.退出程序                            *\n");
	printf("****************************************\n");
	printf("输入您的选择并回车(0-7)\n");
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
		printf("请输入学生名字\n");
		string info;
		cin >> info;
		for ( i = 0; i < Students.size(); i++) {
			if (!info.compare(Students[i].name))
				return i;
		}

	} else {
		printf("请输入学生号\n");
		int info;
		cin >> info;
		for ( i = 0; i < Students.size(); i++) {
			if (info == (Students[i].wno))
				return i;
		}
	}

	return -1;
}

//插入学生
void insertStudents() {
	int num = 0;
	char flag;
INPUT:
	printf("学号\t 名字\t 分数\t 同学互评分\t 任课老师评分 并用空格隔开\n");
	Student temp;
	cin >> temp.wno >> temp.name >> temp.avr >> temp.classmate >> temp.teacher;
	temp.tot = temp.avr * 0.6 + temp.classmate * 0.2 + temp.teacher * 0.2;
	Students.push_back(temp);
	printf("是否录入下一项[Y/N]");
	cin >> flag;
	if (flag == 'Y')
		goto INPUT;
	sort();
	printf("添加完成\n");
}

// 输入学生号修改学生信息
void updateStudent() {
	int index = findStudent(2);
	if (index < 0) {
		printf("未找到该学生\n");
		Student temp;
		printf("输入 名字\t 分数\t 同学互评分\t 任课老师评分 并用空格隔开\n");
		temp.wno = info;
		cin  >> temp.name >> temp.avr >> temp.classmate >> temp.teacher;
		temp.tot = temp.avr * 0.6 + temp.classmate * 0.2 + temp.teacher * 0.2;
		Students.push_back(temp);
		sort();
		return;
	}
	printf("找到该学生\n");
	printf("请输入修改 学号\t 名字\t 分数\t 同学互评分\t 任课老师评分\t 并用空格隔开\n");
	cin >> Students[index].wno >> Students[index].name >> Students[index].avr;
	cin >> Students[index].classmate >> Students[index].teacher;
	sort();
	printf("修改完成\n");
}

// 删除学生
void deleteStudent() {

	int index = findStudent(2);
	if (index < 0) {
		printf("未找到该学生\n");
		return;
	}
	printf("找到该学生\n");
	Students.erase(Students.begin() + index);
	printf("删除完成\n");
}


// 从高到低输出综合测评分数
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
	printf("学号 \t 名字 \t 综合测评分数 \t \n");

	for (int i = 0; i < Students.size(); i++) {
		Students[i].print();
	}
}

// 打印测评信息表
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

//查询学生
void printCondition() {
	int flag = 0;
	printf("1.姓名查询 \n2.学号查询\n");
	printf("请输入[1-2]\n");
	cin >> flag;

	if (flag <= 2) {
		int index = findStudent(flag);
		if (index >= 0)
			Students[index].print();
		else
			printf("未找到学生\n");
	}
}

//读取并显示学生测评信息
void OutputStudent() {
	sort();
	FILE *fp;
	fp = fopen("data.txt", "a+");
	if ((fp = fopen("data.txt", "a+")) == NULL) {
		printf("文件打开失败！\n");
		exit(0);
	}
	fprintf(fp, "学号 \t 名字 \t 综合测评总分 \t 综合测评排名 \t \n");

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
				printf("输入错误,请重新输入\n");
				break;
		}
	}

	return 0;
}


