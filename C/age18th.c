#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv) {

	int userage; //�ŧiuserage 
	while (userage < 18) {
		printf("enter your age\n");
		scanf("%d", &userage);
		int pass = userage >= 18;
		while (!pass) {
			printf("����18��\n");
			break;
		}
		while (pass) {
			printf("�w��18��\n");
			break;
		}

	}
	printf("END");


	return 0;
}
