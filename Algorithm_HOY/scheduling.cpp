#include <cstdio>
#include <cstdlib>

#define listLEN 100

struct jobNode {
	int start;
	int end;
};

struct processorNode {// ���߿��� ����Ʈ ���·� ���μ��� ��� ����
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
	for (int i = 0; i < num; i++) {// job�� �Է¹ް� list�� �־���
		printf("Job%d : ", i + 1);
		scanf("%d %d", &start, &end);
		inputJob2JobList(start, end);
	}

	sortJobList();
	processJob();
	printProcessor();

	printf("�ʿ��� ���μ����� ������ %d �Դϴ�", processorNum);
}

void printProcessor() { // �����ٸ� ��� ��� ���
	for (int i = 0; i < processorNum; i++) {
		processorNode* ptr = processorList[i];
		printf("processor %d : ", i + 1);
		while (ptr != NULL) {
			printf("( %d, %d ) ", ptr->job.start, ptr->job.end); // (����)
			ptr = ptr->nextJob;
		}
		puts("");
	}
}

void processJob() { // �Էµ� job���� scheduling�ϴ� ���
	for (int i = 0; i < jobNum; i++) {
		processorNode* newNode = (processorNode*)malloc(sizeof(processorNode));
		
		if (newNode == NULL) {
			printf("�޸� ����\n");
			exit(1);
		}
		newNode->befJob = NULL;
		newNode->nextJob = NULL;
		newNode->job.start = jobList[i]->start;
		newNode->job.end = jobList[i]->end;
		if (processorNum == 0) { // ó�� ����Ǵ� job�� ���
			processorList[processorNum++] = newNode;
		} 
		else { // �ƴ� ��� (�Ѱ� �̻��� ���μ����� �۾����� ���)
			bool needNewProcessor = true;
			for (int j = 0; j < processorNum; j++) {
				processorNode* ptr = processorList[j];//���μ����� ó������ job�� ����ų ������
				while (ptr->nextJob != NULL) {// �ش� ���μ����� ������ job���� �����͸� �ű��
					ptr = ptr->nextJob;
				};

				// �ش� ���μ����� ó������ ������ job�� ������ �ð���, �������� ó���ؾ��� job�� ���۽ð����� �̸� ���, �ش� ���μ������� job�� ó���Ѵ�.
				if (ptr->job.end <= newNode->job.start) {
					ptr->nextJob = newNode;
					newNode->befJob = ptr;
					needNewProcessor = false;
					break;
				}
			}
			if (needNewProcessor) { // ���ο� ���μ����� �ʿ��� ��� ( ��� ���μ����� �۾����� ��� )
				processorList[processorNum++] = newNode;
			}
		}
	}
}

void inputJob2JobList(int start, int end) {
	jobNode* newJob = (jobNode*)malloc(sizeof(jobNode));
	if (newJob == NULL) {
		printf("�޸� ����\n");
		exit(1);
	}
	newJob->start = start;
	newJob->end = end;

	jobList[jobNum++] = newJob;
}

void sortJobList() {//start�ð� �������� jobList�� �����Ѵ�, �������� �̿�
	for (int i = 0; i < jobNum - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < jobNum; j++) {
			if (jobList[idx]->start > jobList[j]->start) {// start ���� �������� ����
				idx = j;
			}
		}
		jobNode* temp = jobList[i];
		jobList[i] = jobList[idx];
		jobList[idx] = temp;
	}
}