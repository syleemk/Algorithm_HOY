#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "data.h"
#include "function.h"

#define LIST_NUM 100

dataNode * jeonpil[LIST_NUM];
dataNode * jeonil[LIST_NUM];
dataNode * gyopil[LIST_NUM];
dataNode * gyoil[LIST_NUM];

int numOfjeonpil;
int numOfjeonil;
int numOfgyopil;
int numOfgyoil;

int studentN;
char isMulti;
int totalMajorCredit;
int totalTeachingCredit = 22;

int leftMajorPilCredit;
int leftMajorIlCredit;
int leftTeachingPilCredit;
int leftTeachingIlCredit;

void loadUserData() {
	FILE * fp = fopen("user.dat", "r");
	if (fp == NULL) { // ������ �������� �ʴ� ��� (ó�� �Է¹޴� ���)
		inputProcess();
		return;
	}

	fread(&studentN, sizeof(int), 1, fp);
	fread(&isMulti, sizeof(char), 1, fp);
	fread(&numOfgyoil, sizeof(int), 1, fp);
	fread(&numOfgyopil, sizeof(int), 1, fp);
	fread(&numOfjeonil, sizeof(int), 1, fp);
	fread(&numOfjeonpil, sizeof(int), 1, fp);
	fread(&leftMajorIlCredit, sizeof(int), 1, fp);
	fread(&leftMajorPilCredit, sizeof(int), 1, fp);
	fread(&leftTeachingIlCredit, sizeof(int), 1, fp);
	fread(&leftTeachingPilCredit, sizeof(int), 1, fp);

	if (isMulti == 'y') totalMajorCredit = 50;
	else totalMajorCredit = 66;

	fclose(fp);
}

void storeUserData() {
	FILE * fp = fopen("user.dat", "w");

	fwrite(&studentN, sizeof(int), 1, fp);
	fwrite(&isMulti, sizeof(char), 1, fp);
	fwrite(&numOfgyoil, sizeof(int), 1, fp);
	fwrite(&numOfgyopil, sizeof(int), 1, fp);
	fwrite(&numOfjeonil, sizeof(int), 1, fp);
	fwrite(&numOfjeonpil, sizeof(int), 1, fp);
	fwrite(&leftMajorIlCredit, sizeof(int), 1, fp);
	fwrite(&leftMajorPilCredit, sizeof(int), 1, fp);
	fwrite(&leftTeachingIlCredit, sizeof(int), 1, fp);
	fwrite(&leftTeachingPilCredit, sizeof(int), 1, fp);
	
	fclose(fp);
}

void inputProcess() {
	while (1) {
		printf("�й��� �Է��ϼ��� : ");
		scanf("%d", &studentN);
		getchar(); // enter�Է� ����
		if (studentN < 13) puts("��ȿ���� ���� �Է��Դϴ�.");
		else break;
	}

	while (1) {
		char yn;
		printf("���������� �ϰ��ֽ��ϱ�? (y/n) : ");
		scanf("%c", &yn); 
		getchar(); // enter�Է� ����
		if (yn == 'Y' || yn == 'y') isMulti = 'y';
		else if (yn == 'N' || yn == 'n') isMulti = 'n';
		else {
			puts("y / n �߿��� �������ּ���");
			continue;
		}
		break;
	}

	numOfgyopil = 5;
	numOfgyoil = 8;

	if (studentN >= 13 && studentN <= 16) {
		numOfjeonpil = 11;
		numOfjeonil = 21;
	}
	else {
		numOfjeonpil = 12;
		numOfjeonil = 20;
	}

	if (isMulti == 'y') totalMajorCredit = 50;
	else totalMajorCredit = 66;

	leftTeachingPilCredit = 2 * numOfgyopil;
	leftTeachingIlCredit = totalTeachingCredit - leftTeachingPilCredit;
	
	leftMajorPilCredit = 3 * numOfjeonpil;
	leftMajorIlCredit = totalMajorCredit - leftMajorPilCredit;

}

void loadGyoList() {
	FILE * il = fopen("gyoil.txt", "r");
	FILE * pil = fopen("gyopil.txt", "r");

	for (int i = 0; i < numOfgyoil; i++) {
		gyoil[i] = (dataNode*)malloc(sizeof(dataNode));
		fgets(gyoil[i]->name, MAX_STRING, il);

		int sLen = strlen(gyoil[i]->name);
		gyoil[i]->name[sLen - 1] = 0;
	}

	for (int i = 0; i < numOfgyopil; i++) {
		gyopil[i] = (dataNode*)malloc(sizeof(dataNode));
		fgets(gyopil[i]->name, MAX_STRING, pil);

		int sLen = strlen(gyopil[i]->name);
		gyopil[i]->name[sLen - 1] = 0;
	}

	fclose(il);
	fclose(pil);
}

void storeGyoList() {
	FILE * il = fopen("gyoil.txt", "w");
	FILE * pil = fopen("gyopil.txt", "w");

	for (int i = 0; i < numOfgyoil; i++) {
		fprintf(il, "%s\n", gyoil[i]->name);
	}

	for (int i = 0; i < numOfgyopil; i++) {
		fprintf(pil, "%s\n", gyopil[i]->name);
	}

	fclose(il);
	fclose(pil);
}

void loadJeonList() {
	FILE *il, *pil;

	if (studentN >= 13 && studentN <= 16) {
		il = fopen("jeonil_old.txt", "r");
		pil = fopen("jeonpil_old.txt", "r");
	}
	else {
		il = fopen("jeonil_new.txt", "r");
		pil = fopen("jeonpil_new.txt", "r");
	}

	for (int i = 0; i < numOfjeonil; i++) {
		jeonil[i] = (dataNode*)malloc(sizeof(dataNode));
		fgets(jeonil[i]->name, MAX_STRING, il);

		int sLen = strlen(jeonil[i]->name);
		jeonil[i]->name[sLen - 1] = 0;

	}

	for (int i = 0; i < numOfjeonpil; i++) {
		jeonpil[i] = (dataNode*)malloc(sizeof(dataNode));
		fgets(jeonpil[i]->name, MAX_STRING, pil);

		int sLen = strlen(jeonpil[i]->name);
		jeonpil[i]->name[sLen - 1] = 0;
	}

	fclose(il);
	fclose(pil);
}

void storeJeonList() {
	FILE *il, *pil;

	if (studentN >= 13 && studentN <= 16) {
		il = fopen("jeonil_old.txt", "w");
		pil = fopen("jeonpil_old.txt", "w");
	}
	else {
		il = fopen("jeonil_new.txt", "w");
		pil = fopen("jeonpil_new.txt", "w");
	}

	for (int i = 0; i < numOfjeonil; i++) {
		fprintf(il, "%s\n", jeonil[i]->name);
	}

	for (int i = 0; i < numOfjeonpil; i++) {
		fprintf(pil, "%s\n", jeonpil[i]->name);
	}

	fclose(il);
	fclose(pil);
}

int deleteClass(char * className) {
	int delIdx = 0; 
	int matchedCount = 0;

	//���� �Ϲ� �˻�
	for (int i = 0; i < numOfgyoil; i++) {
		if (!strcmp(gyoil[i]->name, className)) {
			delIdx = i;
			matchedCount++;
			break;
		}
	}

	if (matchedCount != 0) {
		free(gyoil[delIdx]);
		for (int i = delIdx; i < numOfgyoil - 1; i++) {
			gyoil[i] = gyoil[i + 1];
		}
		numOfgyoil--;
		if(leftTeachingIlCredit > 0) leftTeachingIlCredit -= 2;

		storeGyoList();
		storeUserData();
		return 1;
	}

	//���� �ʼ� �˻�
	for (int i = 0; i < numOfgyopil; i++) {
		if (!strcmp(gyopil[i]->name, className)) {
			delIdx = i;
			matchedCount++;
			break;
		}
	}

	if (matchedCount != 0) {
		free(gyopil[delIdx]);
		for (int i = delIdx; i < numOfgyopil - 1; i++) {
			gyopil[i] = gyopil[i + 1];
		}
		numOfgyopil--;
		leftTeachingPilCredit -= 2;

		storeGyoList();
		storeUserData();
		return 1;
	}

	//���� �Ϲ� �˻�
	for (int i = 0; i < numOfjeonil; i++) {
		if (!strcmp(jeonil[i]->name, className)) {
			delIdx = i;
			matchedCount++;
			break;
		}
	}

	if (matchedCount != 0) {
		free(jeonil[delIdx]);
		for (int i = delIdx; i < numOfjeonil - 1; i++) {
			jeonil[i] = jeonil[i + 1];
		}
		numOfjeonil--;

		if (!strcmp(className, "Social Learning�� ���ͳ�")) leftMajorIlCredit -= 2;
		else leftMajorIlCredit -= 3;

		if (leftMajorIlCredit < 0) leftMajorIlCredit = 0;

		storeJeonList();
		storeUserData();
		return 1;
	}

	//���� �ʼ� �˻�
	for (int i = 0; i < numOfjeonpil; i++) {
		if (!strcmp(jeonpil[i]->name, className)) {
			delIdx = i;
			matchedCount++;
			break;
		}
	}

	if (matchedCount != 0) {
		free(jeonpil[delIdx]);
		for (int i = delIdx; i < numOfjeonpil - 1; i++) {
			jeonpil[i] = jeonpil[i + 1];
		}
		numOfjeonpil--;
		leftMajorPilCredit -= 3;

		storeJeonList();
		storeUserData();
		return 1;
	}

	return 0;
}

void printLeftPilClass() {
	puts("���� ����");
	printf(" ���� %d/%d\n", leftMajorPilCredit + leftMajorIlCredit, totalMajorCredit);
	printf(" ���� %d/%d\n", leftTeachingIlCredit + leftTeachingPilCredit, totalTeachingCredit);

	puts("\n���� ���� �ʼ� ����");
	for (int i = 0; i < numOfjeonpil; i++) {
		printf(" %s\n", jeonpil[i]->name);
	}

	puts("\n���� ���� �ʼ� ����");
	for (int i = 0; i < numOfgyopil; i++) {
		printf(" %s\n", gyopil[i]->name);
	}
	puts("");
}

int isGraduate() {
	if (leftMajorIlCredit <= 0 && leftMajorPilCredit <= 0 && leftTeachingIlCredit <= 0 && leftTeachingPilCredit <= 0) {
		puts("����!");
		return 1;
	}
	else return 0;
}