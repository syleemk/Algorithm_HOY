#pragma once

// C���� �߰��� �� : ���۽� ������ �޸𸮿� LOAD�ϰ�, ����� �޸��� ������ ���Ͽ� �����ϴ� ���
void loadUserData();
void storeUserData();

void loadGyoList();
void storeGyoList();

void loadJeonList();
void storeJeonList();

void inputProcess();
int deleteClass(char* className);

void printLeftPilClass();
int isGraduate();