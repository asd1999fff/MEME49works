#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv) {

	int userage; //宣告userage 
	while (userage < 18) {
		printf("enter your age\n");
		scanf("%d", &userage);
		int pass = userage >= 18;
		while (!pass) {
			printf("未滿18歲\n");
			break;
		}
		while (pass) {
			printf("已滿18歲\n");
			break;
		}

	}
	printf("END");


	return 0;
}
