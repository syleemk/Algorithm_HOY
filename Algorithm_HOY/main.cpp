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
		printf("������ ������� �Է��ϼ��� : ");
		gets_s(className, sizeof(char) * MAX_STRING);

		if (!strcmp(className, "status")) continue;
		else if (!deleteClass(className)){
			puts("��ȿ���� ���� �Է��Դϴ�.");
			continue;
		}
	}
}