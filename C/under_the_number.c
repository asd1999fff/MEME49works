#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv) {
	
	int Max = 1;
	int d = 3;
	int num = 1;
	while (Max <= 4 || Max > 9 || Max % 2 == 0) {
		printf("�п�J�@�Ӥj��4�����W�L9���_��\n");
		scanf("%d", &Max);
	}
	while (d != 1 && d != 2 ) {
		printf("�п�J1��2\n");
		scanf("%d", &d);
	}
	for (num = 1; num <= Max; num +=d ) {
			printf("(%d)", num);
	}
	
	
	
	
	printf("\nEND");
	return 0;
}
