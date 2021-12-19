#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100 //һ������������
#define MAXM 10 //���γ�����
double Pscore [MAXM];
double Tscore [MAXM];
char subject[MAXM][12]; //�������пγ�����
char number[MAXN][10]; //����ȫ��ѧ��
char name[MAXN][20]; //����ȫ������
float score[MAXN][MAXM]; //����ȫ�����пγ̳ɼ�
float sum[MAXN]; //����ȫ���ܳɼ�
int n, m; //n,m����ȫ��ʵ�������Ϳγ���

void input();
void search();
void change();
void sort();
void save();
void load();
void print();
int main() {
//����ѡ�����
	int select;
	while (1) {
		system("cls");
		printf(" 1.ѧ���ɼ��½�\n");
		printf(" 2.ѧ���ɼ��޸�\n");
		printf(" 3.ѧ���ɼ�����\n");
		printf(" 4.ѧ���ɼ���ѯdone\n");
		printf(" 5.ѧ���ɼ�ɾ��\n");
		printf(" 6.ѧ���ɼ�����\n");
		printf(" 7.ѧ���ɼ�����\n");
		printf(" 8.ѧ���ɼ���ȡ\n");
		printf(" 9.ѧ���ɼ������ӡ\n");
		printf(" 0.�˳�ϵͳ\n");
		printf("����������ѡ����,�س���ȷ����\n");
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
				printf(" лл����ʹ�á�\n");

		}
	}
}

//����ɼ�ģ��
void input() {
	system("cls");
	int i, j;
	printf(" ***********�½�ѧ���ɼ���Ϣ***********\n");
	printf("\n");
	printf("\n");
	printf("\n ������ȫ��������");
	scanf("%d", &n);
	printf("\n ������γ�������");
	scanf("%d", &m);
	printf("\n ������%d�ſγ�����\n", m);
	for (j = 0; j < m; j++) {
		printf("\n ��%d�ſγ����ƣ�", j + 1);
		scanf("%s", subject[j]);
	}
	printf("\n ��%d��ѧ������\n", n);
	for (i = 0; i < n; i++) {
		printf("\n �������%d���˵�����\n", i + 1);
		printf("\n ѧ�ţ�");
		scanf("%s", number[i]);
		printf("\n ������");
		scanf("%s", name[i]);
		printf("\n %d�ſγ̵ĳɼ���\n", m);
		sum[i] = 0;
//�������ͳ���ܳɼ�
		for (j = 0; j < m; j++) {
			printf(" %s�ɼ�:", subject[j]);
			scanf(" %f�ɼ�", &score[i][j]);
			sum[i] = sum[i] + score[i][j];
		}
		printf("\n ͬѧ�����֣�\n", m);
		scanf("%lf", Pscore[i]);
		printf("\n �ο���ʦ���֣�\n", m);
		scanf("%lf", Tscore[i]);
	}
}

//�޸ĳɼ�ģ��
void change() {
	int i;
	char s_number[10];
	printf(" ������Ҫ��ѯ��ѧ�ţ�\n");
	scanf("%s", s_number);
	for (i = 0; i < n; i++)
		if (strcmp(number[i], s_number) == 0) {

		}
}

//��ѯ�ɼ�ģ��
void search() {
	system("cls");
	int j;
	int search1();
	int search2();
	int select, index;
	printf("\n ***********��ѯѧ���ɼ���Ϣ***********\n");
	while (1) {
		printf("\n 1.��ѧ�Ų�ѯ\n");
		printf(" 2.��������ѯ\n");
		printf(" 0.����\n");
		printf("\n ����������ѡ���ţ�");
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
			printf("\n ѧ�� :%s\n", number[index]);
			printf("\n ���� :%s\n", name[index]);
			for (j = 0; j < m; j++) {
				printf("\n %s�ɼ� :", subject[j]);
				printf("%.2f\n", score[index][j]);
			}
			printf("\n �ܳɼ� :%.2f\n", sum[index]);
			printf("\n ƽ���ɼ�:%.2f\n", sum[index] / m);
			printf("\n �������Լ�����ѯ����ѧ���ɼ���Ϣ:\n");
		} else
			printf("\n û�����ͬѧ��\n");
	}
}

//��ѧ�Ų�ѯģ��
int search1() {
	system("cls");
	int i;
	char s_number[10];
	printf(" ������Ҫ��ѯ��ѧ�ţ�\n");
	scanf("%s", s_number);
	printf(" ��ͬѧ����Ϣ���£�\n");
	for (i = 0; i < n; i++)
		if (strcmp(number[i], s_number) == 0)
			break;
	if (i < n)
		return i;
	else
		return -1;
}

//��������ѯģ��
int search2() {
	system("cls");
	int i;
	char s_name[10];
	printf(" ������Ҫ��ѯ��������");
	scanf("%s", s_name);
	for (i = 0; i < n; i++)
		if (strcmp(name[i], s_name) == 0)
			break;
	if (i < n)
		return i;
	else
		return -1;
}

//����ģ��
void sort() {
	system("cls");
	void sort1();
	void sort2();
	void sort3();
	int select;
	while (1) {
		printf(" ***********ѧ���ɼ�������Ϣ***********\n");
		printf("\n 1.��ѧ������\n");
		printf(" 2.����������\n");
		printf(" 3.���ܳɼ�����\n");
		printf(" 0.����\n");
		printf("\n ����������ѡ���ţ�\n");
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

//��ѧ������ģ��
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
	printf("�������.\n");
}

//����������ģ��
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
	printf("�������.\n");
}

//���ܳɼ�����ģ��
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
	printf("�������.\n");
}

//����ɼ�ģ��
void save() {
	system("cls");
	FILE *fp;
	char filename[20];
	int i, j;
	printf(" �������ļ���: ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) {
		printf(" ���ļ�ʧ��.\n");
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
	printf(" �������.\n");
}

// ��ȡ�ɼ�ģ��
void load( ) {
	system("cls");
	FILE *fp;
	char filename[20];
	int i, j;
	printf (" �������ļ�����");
	scanf("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL) {
		printf(" �ļ�������.\n");
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
	printf(" ��ȡ���.\n");
}

//��ӡ�ɼ�����ģ��
void print() {
	system("cls");
	void print1();
	void print2();
	int select;
	printf(" ***********��ӡѧ���ɼ���Ϣ***********\n");
	printf("\n");
	printf("\n");
	printf(" 1.��Ļ��ʾ����\n");
	printf(" 2.��ӡ����ӡ����\n");
	printf(" 0.����\n");
	printf("\n ����������ѡ���ţ�");
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

// ��Ļ��ʾ����ģ��
void print1() {
	system("cls");
	int i, j;
	printf(" �ɼ��ܱ�\n");
	printf(" ѧ������:");
	for (j = 0; j < m; j++)
		printf("%10s", subject[j]);
	printf(" �ܳɼ�ƽ���ɼ�\n");
	for (i = 0; i < n; i++) {
		printf("%8s %8s", number[i], name[i]);
		for (j = 0; j < m; j++)
			printf("%6.1f", score[i][j]);
		printf("%6.1f %6.2f\n", sum[i], sum[i] / m);
	}
	printf(" ��ʾ���.\n");
}

// ��ӡ����ӡ����ģ��
void print2( ) {
	system("cls");
	FILE *fp;
	int i, j;
	printf(" ��׼���ô�ӡ�����������������\n");
	scanf("% * c");
	if ((fp = fopen("prn", "w")) == NULL) {
		printf(" ��ӡ��û��׼����.\n");
		return;
	}
	fprintf(fp, " �ɼ��ܱ�\n");
	fprintf(fp, " ѧ������\n");
	for (j = 0; j < m; j++ )
		fprintf(fp, "%10s", subject[j]);
	fprintf(fp, " �ܳɼ�ƽ���ɼ�\n");
	for (i = 0; i < n; i++) {
		fprintf(fp, "%6.1f", score[i][j]);
		fprintf(fp, "%8s %8s", number[i], name[i]);

		for (j = 0; j < m; j++)
			fprintf(fp, "%6.1f %6.2f\n", sum[i], sum[i] / m);
	}
	fclose(fp);
	printf(" ��ӡ���.\n");
}