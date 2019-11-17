#pragma once

// C에서 추가된 것 : 시작시 파일을 메모리에 LOAD하고, 종료시 메모리의 내용을 파일에 저장하는 모듈
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