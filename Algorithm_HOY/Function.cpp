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
	if (fp == NULL) { // 파일이 존재하지 않는 경우 (처음 입력받는 경우)
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
		printf("학번을 입력하세요 : ");
		scanf("%d", &studentN);
		getchar(); // enter입력 제거
		if (studentN < 13) puts("유효하지 않은 입력입니다.");
		else break;
	}

	while (1) {
		char yn;
		printf("복수전공을 하고있습니까? (y/n) : ");
		scanf("%c", &yn); 
		getchar(); // enter입력 제거
		if (yn == 'Y' || yn == 'y') isMulti = 'y';
		else if (yn == 'N' || yn == 'n') isMulti = 'n';
		else {
			puts("y / n 중에서 선택해주세요");
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

	//교직 일반 검색
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

	//교직 필수 검색
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

	//전공 일반 검색
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

		if (!strcmp(className, "Social Learning과 인터넷")) leftMajorIlCredit -= 2;
		else leftMajorIlCredit -= 3;

		if (leftMajorIlCredit < 0) leftMajorIlCredit = 0;

		storeJeonList();
		storeUserData();
		return 1;
	}

	//전공 필수 검색
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
	puts("남은 학점");
	printf(" 전공 %d/%d\n", leftMajorPilCredit + leftMajorIlCredit, totalMajorCredit);
	printf(" 교직 %d/%d\n", leftTeachingIlCredit + leftTeachingPilCredit, totalTeachingCredit);

	puts("\n남은 전공 필수 과목");
	for (int i = 0; i < numOfjeonpil; i++) {
		printf(" %s\n", jeonpil[i]->name);
	}

	puts("\n남은 교직 필수 과목");
	for (int i = 0; i < numOfgyopil; i++) {
		printf(" %s\n", gyopil[i]->name);
	}
	puts("");
}

int isGraduate() {
	if (leftMajorIlCredit <= 0 && leftMajorPilCredit <= 0 && leftTeachingIlCredit <= 0 && leftTeachingPilCredit <= 0) {
		puts("졸업!");
		return 1;
	}
	else return 0;
}