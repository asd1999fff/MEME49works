#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv) {

	int Max = 1;
	int d = 3;
	int num = 1;
	int mount = 0;
	while (Max <= 4 || Max > 9 || Max % 2 == 0) {
		printf("請輸入一個大於4但不超過9的奇數\n");
		scanf("%d", &Max);
	}
	while (d != 1 && d != 2) {
		printf("請輸入1或2\n");
		scanf("%d", &d);
	}
	for (num = 1; num <= Max; num += d) {
		mount += num;
	}
	printf("Max 的值為%d\n", mount);

	/*
	用while產生
	 
	num = 1;
	mount = 0;
	while (num <= Max) {
		mount += num;
		num += d;
	}



	printf("Max 的值為%d", mount);*/



	printf("\nEND");
	return 0;
}
