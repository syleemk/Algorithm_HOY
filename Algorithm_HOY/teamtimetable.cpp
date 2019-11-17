#include <iostream>
#include <string>

using namespace std;

int MONtime[12][12];
int TUEtime[12][12];
int WEDtime[12][12];
int THUtime[12][12];
int FRItime[12][12];

void checkTime(int daytime[][12], string time); // 요일 별 array에 수업 시간을 입력받아 표시하는 모듈
void inputClassTime(string day, string time); // 입력된 요일을 바탕으로, checkTime함수에 해당하는 요일 배열을 전달
void printAvailTime(string day, int daytime[][12]); // 요일별 배열을 검사해서, check되지 않은 시간 중 30분 이상의 시간 출력하는 함수


int main() {
// 시간표 입력 프로세스
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

// 시간표 출력 프로세스
	printf("OUTPUT >>");
	printAvailTime("MON", MONtime);
	printAvailTime("TUE", TUEtime);
	printAvailTime("WED", WEDtime);
	printAvailTime("THU", THUtime);
	printAvailTime("FRI", FRItime);
}

void checkTime(int daytime[][12], string time) {//time의 형식 10000-1200
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
			if (hour == starthour) { // 시작 시간과 끝나는 시간이 같은 경우 ( 만약, 한 시간 미만 수업 있다면 )	
				for (min = 0; min < endmin; min++) {
					daytime[hour][min] += 1;
				}
			}
			else if (endmin == 0) break; // 수업이 정각에 마치는 경우 표시하지 않고 for루프 탈출
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
	int count = 0; // 연속으로 0이 나오는지 확인 위한 변수
	bool beforeZero = false; // 연속으로 0이 나온지 판별위한 변수
	int starthour = 0, startmin = 0;// 시작 시간 기억위한 변수
	bool firstprint = false; // 요일 출력 위한 변수

	for (hour = 0; hour < 12; hour++) {
		for (min = 0; min < 12; min++) {
			if (daytime[hour][min] == 0) {
				if (beforeZero == false) { // 체크되지 않은 시간 시작되는 지점
					starthour = hour;
					startmin = min;
				}
				count++;
				beforeZero = true;
				
				if (hour == 11 && min == 11 && count >= 6) {// 2100에 끝나는 수업
					if (firstprint == false) {
						cout << day << ' ';
						firstprint = true;
					}
					printf("%02d%02d-%02d%02d ", starthour + 9, startmin * 5, 21, 00);
				}
			}
			else {
				if (beforeZero == true) { // 연속된 체크되지 않은 시간이 끝나는 지점
					if (count >= 6) { // 30분 이상 출력 가능
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
