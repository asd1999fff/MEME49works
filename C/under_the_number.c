#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv) {
	
	int Max = 1;
	int d = 3;
	int num = 1;
	while (Max <= 4 || Max > 9 || Max % 2 == 0) {
		printf("請輸入一個大於4但不超過9的奇數\n");
		scanf("%d", &Max);
	}
	while (d != 1 && d != 2 ) {
		printf("請輸入1或2\n");
		scanf("%d", &d);
	}
	for (num = 1; num <= Max; num +=d ) {
			printf("(%d)", num);
	}
	
	
	
	
	printf("\nEND");
	return 0;
}
