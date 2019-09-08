#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>


int main()
{
	clock_t start = clock(); // ���� �ð� 


	char * player[50];
	int pNum, endNum;
	scanf("%d %d", &pNum, &endNum);
	getchar(); // ���� ����ֱ�

	for (int i = 1; i <= pNum; i++) { // �÷��̾� �̸� �Է� �����Ҵ��Ͽ� ����
		player[i%pNum] = (char*)malloc(sizeof(char) * 20);
		gets_s(player[i%pNum], sizeof(char)*20);
	}

	char str[10]; 
	bool clap;

	for (int i = 1; i <= endNum; i++) {
		sprintf(str, "%d", i); // ���ڸ� ���ڿ��� ��ȯ	

		int k = 0;
		while (str[k] != '\0') {
			clap = false;
			if (str[k] == '3' || str[k] == '6' || str[k] == '9') {
				clap = true;
				break;
			}
			k++;
		}
		if (clap == true) {
			printf("%s : ¦! \n", player[i%pNum]);
		}
		else {
			printf("%s : %d \n", player[i%pNum], i);
		}
	}

	for (int i = 1; i <= pNum; i++) { // �÷��̾� �̸� �迭 ����
		free(player[i%pNum]);
	}

	clock_t end = clock(); // �ڵ尡 ���� �ð� 

						   // �ɸ� �ð� ���
						   // ���� : ��(second)
						   // CLOCKS_PER_SEC�� ������� �ʴ����� ���
	printf("\nTime : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

/*

//����� �ڵ�
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main()
{
clock_t start = clock(); // ���� �ð�


char * player[50];
int pNum, endNum;
scanf("%d %d", &pNum, &endNum);
getchar(); // ���� ����ֱ�

for (int i = 1; i <= pNum; i++) { // �÷��̾� �̸� �Է�
player[i%pNum] = (char*)malloc(sizeof(char) * 20);
gets(player[i%pNum]);
}

char str[10];
int clap;

for (int i = 1; i <= endNum; i++) {
sprintf(str, "%d", i); // ���ڸ� ���ڿ��� ��ȯ

int k = 0;
while (str[k] != '\0') {
clap = 0;
if (str[k] == '3' || str[k] == '6' || str[k] == '9') {
clap = 1;
break;
}
k++;
}
if (clap == 1) {
printf("%s : ¦! \n", player[i%pNum]);
}
else {
printf("%s : %d \n", player[i%pNum], i);
}
}

clock_t end = clock(); // �ڵ尡 ���� �ð�

// �ɸ� �ð� ���
// ���� : ��(second)
// CLOCKS_PER_SEC�� ������� �ʴ����� ���
printf("\nTime : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

return 0;
}


*/