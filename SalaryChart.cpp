#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100 //一个班最多的人数
#define MAXM 10 //最多课程门数
double Pscore [MAXM];
double Tscore [MAXM];
char subject[MAXM][12]; //保存所有课程名称
char number[MAXN][10]; //保存全班学号
char name[MAXN][20]; //保存全班姓名
float score[MAXN][MAXM]; //保存全班所有课程成绩
float sum[MAXN]; //保存全班总成绩
int n, m; //n,m保存全班实际人数和课程数

void input();
void search();
void change();
void sort();
void save();
void load();
void print();
int main() {
//功能选择界面
	int select;
	while (1) {
		system("cls");
		printf(" 1.学生成绩新建\n");
		printf(" 2.学生成绩修改\n");
		printf(" 3.学生成绩插入\n");
		printf(" 4.学生成绩查询done\n");
		printf(" 5.学生成绩删除\n");
		printf(" 6.学生成绩排名\n");
		printf(" 7.学生成绩保存\n");
		printf(" 8.学生成绩读取\n");
		printf(" 9.学生成绩报表打印\n");
		printf(" 0.退出系统\n");
		printf("请输入您的选择编号,回车键确定：\n");
		scanf("%d", &select);
		switch (select) {
			case 1:
				input();
				break;
			case 2:
				change();
				break;
			case 4:
				search();
				break;
			case 6:
				sort();
				break;
			case 7:
				save();
				break;
			case 8:
				load();
				break;
			case 9:
				print();
				break;
			case 0:
				printf(" 谢谢您的使用。\n");

		}
	}
}

//输入成绩模块
void input() {
	system("cls");
	int i, j;
	printf(" ***********新建学生成绩信息***********\n");
	printf("\n");
	printf("\n");
	printf("\n 请输入全班人数：");
	scanf("%d", &n);
	printf("\n 请输入课程门数：");
	scanf("%d", &m);
	printf("\n 请输入%d门课程名称\n", m);
	for (j = 0; j < m; j++) {
		printf("\n 第%d门课程名称：", j + 1);
		scanf("%s", subject[j]);
	}
	printf("\n 第%d个学生数据\n", n);
	for (i = 0; i < n; i++) {
		printf("\n 请输入第%d个人的数据\n", i + 1);
		printf("\n 学号：");
		scanf("%s", number[i]);
		printf("\n 姓名：");
		scanf("%s", name[i]);
		printf("\n %d门课程的成绩：\n", m);
		sum[i] = 0;
//边输入边统计总成绩
		for (j = 0; j < m; j++) {
			printf(" %s成绩:", subject[j]);
			scanf(" %f成绩", &score[i][j]);
			sum[i] = sum[i] + score[i][j];
		}
		printf("\n 同学互评分：\n", m);
		scanf("%lf", Pscore[i]);
		printf("\n 任课老师评分：\n", m);
		scanf("%lf", Tscore[i]);
	}
}

//修改成绩模块
void change() {
	int i;
	char s_number[10];
	printf(" 请输入要查询的学号：\n");
	scanf("%s", s_number);
	for (i = 0; i < n; i++)
		if (strcmp(number[i], s_number) == 0) {

		}
}

//查询成绩模块
void search() {
	system("cls");
	int j;
	int search1();
	int search2();
	int select, index;
	printf("\n ***********查询学生成绩信息***********\n");
	while (1) {
		printf("\n 1.按学号查询\n");
		printf(" 2.按姓名查询\n");
		printf(" 0.返回\n");
		printf("\n 请输入您的选择编号：");
		printf("\n ---------------------------------------\n");
		scanf("%d", &select);
		switch (select) {
			case 1:
				index = search1();
				break;
			case 2:
				index = search2();
				break;
			case 0:
				return;
		}
		if (index != -1) {
			printf("\n 学号 :%s\n", number[index]);
			printf("\n 姓名 :%s\n", name[index]);
			for (j = 0; j < m; j++) {
				printf("\n %s成绩 :", subject[j]);
				printf("%.2f\n", score[index][j]);
			}
			printf("\n 总成绩 :%.2f\n", sum[index]);
			printf("\n 平均成绩:%.2f\n", sum[index] / m);
			printf("\n 您还可以继续查询其他学生成绩信息:\n");
		} else
			printf("\n 没有这个同学。\n");
	}
}

//按学号查询模块
int search1() {
	system("cls");
	int i;
	char s_number[10];
	printf(" 请输入要查询的学号：\n");
	scanf("%s", s_number);
	printf(" 该同学的信息如下：\n");
	for (i = 0; i < n; i++)
		if (strcmp(number[i], s_number) == 0)
			break;
	if (i < n)
		return i;
	else
		return -1;
}

//按姓名查询模块
int search2() {
	system("cls");
	int i;
	char s_name[10];
	printf(" 请输入要查询的姓名：");
	scanf("%s", s_name);
	for (i = 0; i < n; i++)
		if (strcmp(name[i], s_name) == 0)
			break;
	if (i < n)
		return i;
	else
		return -1;
}

//排名模块
void sort() {
	system("cls");
	void sort1();
	void sort2();
	void sort3();
	int select;
	while (1) {
		printf(" ***********学生成绩排名信息***********\n");
		printf("\n 1.按学号排名\n");
		printf(" 2.按姓名排名\n");
		printf(" 3.按总成绩排名\n");
		printf(" 0.返回\n");
		printf("\n 请输入您的选择编号：\n");
		printf(" --------------------------------------\n");
		scanf("%d", &select);
		switch (select) {
			case 1:
				sort1();
				break;
			case 2:
				sort2();
				break;
			case 3:
				sort();
				break;
			case 0:
				return;
		}
	}
}

//按学号排名模块
void sort1() {
	system("cls");
	int i, j, k;
	char x_number[10];
	char x_name[20];
	float x;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (strcmp(number[i], number[k]) < 0)
				k = j;
		if (k != i) {
			strcpy(x_number, number[i]);
			strcpy(number[i], number[k]);
			strcpy(number[k], x_number);
			strcpy(x_name, name[i]);
			strcpy(name[i], name[k]);
			strcpy(name[k], x_name);
			for (j = 0; j < m; j++) {
				x = score[i][j];
				score[i][j] = score[k][j];
				score[k][j] = x;
			}
			x = sum[i];
			sum[i] = sum[k];
			sum[k] = x;
		}
	}
	printf("排序完毕.\n");
}

//按姓名排名模块
void sort2() {
	system("cls");
	int i, j, k;
	char x_number[10];
	char x_name[20];
	float x;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (strcmp(name[j], name[k]) < 0)
				k = j;
		if (k != i) {
			strcpy(x_number, number[i]);
			strcpy(number[i], number[k]);
			strcpy(number[k], x_number);
			strcpy(name[i], name[k]);
			strcpy(name[k], x_name);
			for (j = 0; j < m; j++) {
				x = score[i][j];
				score[i][j] = score[k][j];
				score[k][j] = x;
			}
			x = sum[i];
			sum[i] = sum[k];
			sum[k] = x;
		}
	}
	printf("排序完毕.\n");
}

//按总成绩排名模块
void sort3() {
	system("cls");
	int i, j, k;
	char x_number[10];
	char x_name[20];
	float x;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (sum[j] < sum[k])
				k = j;
		if (k != i) {
			strcpy(x_number, number[i]);
			strcpy(number[i], number[k]);
			strcpy(number[k], x_number);
			strcpy(x_name, name[i]);
			strcpy(name[i], name[k]);
			strcpy(name[k], x_name);
			for (j = 0; j < m; j++) {
				x = score[i][j];
				score[i][j] = score[k][j];
				score[k][j] = x;
			}
			x = sum[i];
			sum[i] = sum[k];
			sum[k] = x;
		}
	}
	printf("排序完毕.\n");
}

//保存成绩模块
void save() {
	system("cls");
	FILE *fp;
	char filename[20];
	int i, j;
	printf(" 请输入文件名: ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {
		printf(" 打开文件失败.\n");
		return;
	}
	fprintf(fp, "%d %d", n, m);
	for (j = 0; j < m; j++)
		fprintf(fp, "%s", subject[j]);
	for (i = 0; i < n; i++) {
		fprintf(fp, "%s %s", number[i], name[i]);
		for (j = 0; j < m; j++)
			fprintf(fp, "%5.1f", score[i][j]);
	}
	fclose(fp);
	printf(" 保存完毕.\n");
}

// 提取成绩模块
void load( ) {
	system("cls");
	FILE *fp;
	char filename[20];
	int i, j;
	printf (" 请输入文件名：");
	scanf("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL) {
		printf(" 文件不存在.\n");
		return;
	}
	fscanf(fp, "%d%d", &n, &m);
	for (j = 0; j < m; j++)
		fscanf(fp, "%s", subject[j]);
	for (i = 0; i < n; i++) {
		fscanf(fp, "%s%s", number[i], name[i]);
		sum[i] = 0;
		for (j = 0; j < m; j++) {
			fscanf(fp, "%f", &score[i][j]);
			sum[i] = sum[i] + score[i][j];
		}
	}
	fclose(fp);
	printf(" 提取完毕.\n");
}

//打印成绩报表模块
void print() {
	system("cls");
	void print1();
	void print2();
	int select;
	printf(" ***********打印学生成绩信息***********\n");
	printf("\n");
	printf("\n");
	printf(" 1.屏幕显示报表\n");
	printf(" 2.打印机打印报表\n");
	printf(" 0.返回\n");
	printf("\n 请输入您的选择编号：");
	printf("\n --------------------------------------\n");
	scanf("%d", &select);
	switch (select) {
		case 1:
			print1();
			break;
		case 2:
			print2();
			break;
		case 0:
			return;
	}
}

// 屏幕显示报表模块
void print1() {
	system("cls");
	int i, j;
	printf(" 成绩总表\n");
	printf(" 学号姓名:");
	for (j = 0; j < m; j++)
		printf("%10s", subject[j]);
	printf(" 总成绩平均成绩\n");
	for (i = 0; i < n; i++) {
		printf("%8s %8s", number[i], name[i]);
		for (j = 0; j < m; j++)
			printf("%6.1f", score[i][j]);
		printf("%6.1f %6.2f\n", sum[i], sum[i] / m);
	}
	printf(" 显示完毕.\n");
}

// 打印机打印报表模块
void print2( ) {
	system("cls");
	FILE *fp;
	int i, j;
	printf(" 请准备好打印机，按任意键继续…\n");
	scanf("% * c");
	if ((fp = fopen("prn", "w")) == NULL) {
		printf(" 打印机没有准备好.\n");
		return;
	}
	fprintf(fp, " 成绩总表\n");
	fprintf(fp, " 学号姓名\n");
	for (j = 0; j < m; j++ )
		fprintf(fp, "%10s", subject[j]);
	fprintf(fp, " 总成绩平均成绩\n");
	for (i = 0; i < n; i++) {
		fprintf(fp, "%6.1f", score[i][j]);
		fprintf(fp, "%8s %8s", number[i], name[i]);

		for (j = 0; j < m; j++)
			fprintf(fp, "%6.1f %6.2f\n", sum[i], sum[i] / m);
	}
	fclose(fp);
	printf(" 打印完毕.\n");
}