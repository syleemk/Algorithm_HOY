#include "data.h"
#include "function.h"

int main() {
	loadUserData();
	loadGyoList();
	loadJeonList();

	while (1) {
		puts("\n==================================================\n");
		if (isGraduate()) break;

		char className[MAX_STRING];

		printLeftPilClass();
		printf("수강한 과목명을 입력하세요 : ");
		gets_s(className, sizeof(char) * MAX_STRING);

		if (!strcmp(className, "status")) continue;
		else if (!deleteClass(className)){
			puts("유효하지 않은 입력입니다.");
			continue;
		}
	}
}