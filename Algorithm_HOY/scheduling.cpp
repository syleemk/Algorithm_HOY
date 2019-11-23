#include <cstdio>
#include <cstdlib>

#define listLEN 100

struct jobNode {
	int start;
	int end;
};

struct processorNode {// 이중연결 리스트 형태로 프로세서 노드 구성
	jobNode job;
	processorNode* befJob;
	processorNode* nextJob;
};

int jobNum = 0;
int processorNum = 0;

jobNode* jobList[listLEN];
processorNode* processorList[listLEN];



void inputJob2JobList(int start, int end);
void sortJobList();
void processJob();
void printProcessor();

int main() {
	int num;
	printf("How many Job? : ");
	scanf("%d", &num);

	int start, end;
	for (int i = 0; i < num; i++) {// job을 입력받고 list에 넣어줌
		printf("Job%d : ", i + 1);
		scanf("%d %d", &start, &end);
		inputJob2JobList(start, end);
	}

	sortJobList();
	processJob();
	printProcessor();

	printf("필요한 프로세서의 개수는 %d 입니다", processorNum);
}

void printProcessor() { // 스케줄링 결과 출력 모듈
	for (int i = 0; i < processorNum; i++) {
		processorNode* ptr = processorList[i];
		printf("processor %d : ", i + 1);
		while (ptr != NULL) {
			printf("( %d, %d ) ", ptr->job.start, ptr->job.end); // (예외)
			ptr = ptr->nextJob;
		}
		puts("");
	}
}

void processJob() { // 입력된 job들을 scheduling하는 모듈
	for (int i = 0; i < jobNum; i++) {
		processorNode* newNode = (processorNode*)malloc(sizeof(processorNode));
		
		if (newNode == NULL) {
			printf("메모리 부족\n");
			exit(1);
		}
		newNode->befJob = NULL;
		newNode->nextJob = NULL;
		newNode->job.start = jobList[i]->start;
		newNode->job.end = jobList[i]->end;
		if (processorNum == 0) { // 처음 실행되는 job인 경우
			processorList[processorNum++] = newNode;
		} 
		else { // 아닌 경우 (한개 이상의 프로세서가 작업중인 경우)
			bool needNewProcessor = true;
			for (int j = 0; j < processorNum; j++) {
				processorNode* ptr = processorList[j];//프로세서가 처리중인 job을 가리킬 포인터
				while (ptr->nextJob != NULL) {// 해당 프로세서의 마지막 job으로 포인터를 옮긴다
					ptr = ptr->nextJob;
				};

				// 해당 프로세서가 처리중인 마지막 job의 끝나는 시간이, 다음으로 처리해야할 job의 시작시간보다 이를 경우, 해당 프로세서에서 job을 처리한다.
				if (ptr->job.end <= newNode->job.start) {
					ptr->nextJob = newNode;
					newNode->befJob = ptr;
					needNewProcessor = false;
					break;
				}
			}
			if (needNewProcessor) { // 새로운 프로세서가 필요한 경우 ( 모든 프로세서가 작업중인 경우 )
				processorList[processorNum++] = newNode;
			}
		}
	}
}

void inputJob2JobList(int start, int end) {
	jobNode* newJob = (jobNode*)malloc(sizeof(jobNode));
	if (newJob == NULL) {
		printf("메모리 부족\n");
		exit(1);
	}
	newJob->start = start;
	newJob->end = end;

	jobList[jobNum++] = newJob;
}

void sortJobList() {//start시간 기준으로 jobList를 정렬한다, 선택정렬 이용
	for (int i = 0; i < jobNum - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < jobNum; j++) {
			if (jobList[idx]->start > jobList[j]->start) {// start 기준 오름차순 정렬
				idx = j;
			}
		}
		jobNode* temp = jobList[i];
		jobList[i] = jobList[idx];
		jobList[idx] = temp;
	}
}