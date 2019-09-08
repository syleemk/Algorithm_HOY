#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>


int main()
{
	clock_t start = clock(); // 시작 시간 


	char * player[50];
	int pNum, endNum;
	scanf("%d %d", &pNum, &endNum);
	getchar(); // 버퍼 비워주기

	for (int i = 1; i <= pNum; i++) { // 플레이어 이름 입력 동적할당하여 받음
		player[i%pNum] = (char*)malloc(sizeof(char) * 20);
		gets_s(player[i%pNum], sizeof(char)*20);
	}

	char str[10]; 
	bool clap;

	for (int i = 1; i <= endNum; i++) {
		sprintf(str, "%d", i); // 숫자를 문자열로 전환	

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
			printf("%s : 짝! \n", player[i%pNum]);
		}
		else {
			printf("%s : %d \n", player[i%pNum], i);
		}
	}

	for (int i = 1; i <= pNum; i++) { // 플레이어 이름 배열 해제
		free(player[i%pNum]);
	}

	clock_t end = clock(); // 코드가 끝난 시간 

						   // 걸린 시간 출력
						   // 단위 : 초(second)
						   // CLOCKS_PER_SEC로 나눠줘야 초단위로 출력
	printf("\nTime : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}

/*

//제출용 코드
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main()
{
clock_t start = clock(); // 시작 시간


char * player[50];
int pNum, endNum;
scanf("%d %d", &pNum, &endNum);
getchar(); // 버퍼 비워주기

for (int i = 1; i <= pNum; i++) { // 플레이어 이름 입력
player[i%pNum] = (char*)malloc(sizeof(char) * 20);
gets(player[i%pNum]);
}

char str[10];
int clap;

for (int i = 1; i <= endNum; i++) {
sprintf(str, "%d", i); // 숫자를 문자열로 전환

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
printf("%s : 짝! \n", player[i%pNum]);
}
else {
printf("%s : %d \n", player[i%pNum], i);
}
}

clock_t end = clock(); // 코드가 끝난 시간

// 걸린 시간 출력
// 단위 : 초(second)
// CLOCKS_PER_SEC로 나눠줘야 초단위로 출력
printf("\nTime : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

return 0;
}


*/