#include <iostream>
#include <string>

using namespace std;

int MONtime[12][12];
int TUEtime[12][12];
int WEDtime[12][12];
int THUtime[12][12];
int FRItime[12][12];

void checkTime(int daytime[][12], string time); // ���� �� array�� ���� �ð��� �Է¹޾� ǥ���ϴ� ���
void inputClassTime(string day, string time); // �Էµ� ������ ��������, checkTime�Լ��� �ش��ϴ� ���� �迭�� ����
void printAvailTime(string day, int daytime[][12]); // ���Ϻ� �迭�� �˻��ؼ�, check���� ���� �ð� �� 30�� �̻��� �ð� ����ϴ� �Լ�


int main() {
// �ð�ǥ �Է� ���μ���
	printf("input >>");
	int peopleNum;
	scanf("%d", &peopleNum);

	int i = 0;
	while (i < peopleNum) {
		string day;
		cin >> day;
		getchar();
		
		if (day == ".") i++;
		else {
			while (1) {
				string time;
				char blank;
				cin >> time;
				blank = getchar();

				inputClassTime(day, time);
				if (blank == '\n') break;		
			}
		}
	}

// �ð�ǥ ��� ���μ���
	printf("OUTPUT >>");
	printAvailTime("MON", MONtime);
	printAvailTime("TUE", TUEtime);
	printAvailTime("WED", WEDtime);
	printAvailTime("THU", THUtime);
	printAvailTime("FRI", FRItime);
}

void checkTime(int daytime[][12], string time) {//time�� ���� 10000-1200
	int starthour = stoi(time.substr(0, 2)) - 9;
	int startmin = stoi(time.substr(2, 2)) / 5;
	int endhour = stoi(time.substr(5, 2)) - 9;
	int endmin = stoi(time.substr(7, 2)) / 5;

	for (int hour = starthour;  hour <= endhour; hour++) {
		int min = 0;
		if (hour != endhour) {
			if (hour == starthour) {
				for (min = startmin; min < 12; min++) {
					daytime[hour][min] += 1;
				}
			}
			else {
				for (min = 0; min < 12; min++) {
					daytime[hour][min] += 1;
				}
			}
		}
		else { 
			if (hour == starthour) { // ���� �ð��� ������ �ð��� ���� ��� ( ����, �� �ð� �̸� ���� �ִٸ� )	
				for (min = 0; min < endmin; min++) {
					daytime[hour][min] += 1;
				}
			}
			else if (endmin == 0) break; // ������ ������ ��ġ�� ��� ǥ������ �ʰ� for���� Ż��
			else {
				for (min = 0; min < endmin ; min++) {
					daytime[hour][min] += 1;
				}
			}
		}
	}
}

void inputClassTime(string day, string time) {
	if (day == "MON") {
		checkTime(MONtime, time);
	}
	else if (day == "TUE") {
		checkTime(TUEtime, time);
	}
	else if (day == "WED") {
		checkTime(WEDtime, time);
	}
	else if (day == "THU") {
		checkTime(THUtime, time);
	}
	else if (day == "FRI") {
		checkTime(FRItime, time);
	}
}

void printAvailTime(string day, int daytime[][12]) {
	int hour = 0, min = 0;
	int count = 0; // �������� 0�� �������� Ȯ�� ���� ����
	bool beforeZero = false; // �������� 0�� ������ �Ǻ����� ����
	int starthour = 0, startmin = 0;// ���� �ð� ������� ����
	bool firstprint = false; // ���� ��� ���� ����

	for (hour = 0; hour < 12; hour++) {
		for (min = 0; min < 12; min++) {
			if (daytime[hour][min] == 0) {
				if (beforeZero == false) { // üũ���� ���� �ð� ���۵Ǵ� ����
					starthour = hour;
					startmin = min;
				}
				count++;
				beforeZero = true;
				
				if (hour == 11 && min == 11 && count >= 6) {// 2100�� ������ ����
					if (firstprint == false) {
						cout << day << ' ';
						firstprint = true;
					}
					printf("%02d%02d-%02d%02d ", starthour + 9, startmin * 5, 21, 00);
				}
			}
			else {
				if (beforeZero == true) { // ���ӵ� üũ���� ���� �ð��� ������ ����
					if (count >= 6) { // 30�� �̻� ��� ����
						if (firstprint == false) {
							cout << day << ' ';
							firstprint = true;
						}
						printf("%02d%02d-%02d%02d ", starthour + 9, startmin * 5, hour + 9, min * 5);
					}
					count = 0;
				}
				beforeZero = false;
			}
		}
	}

	printf("\n");
}
