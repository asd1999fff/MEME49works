#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv)
{
	
	int levelnumber = 0; // �M�w���ư���X��
	int leafnumber = 0; // �M�w���l���L����
	int space = 0; // �M�w���L�ťզ���
	int counter = 1; // ���q���p�ƾ�
	
	while (levelnumber <= 2 || levelnumber > 8) {
		printf("��J�h��,���ƻݤj��2����W�L9\n");
		scanf("%d", &levelnumber);
		if (levelnumber <= 2 || levelnumber > 8) {
			printf("�ƭȿ��~�A�Э��s��J\n");
		}
		if (levelnumber > 2 && levelnumber <= 8) {
			printf("�ƭȥ��T\n");
		}
	}	
	/*
	��for���� 
	for (counter = 1; counter < levelnumber + 1; counter++) {
		for(space = levelnumber - counter; space >= 0 ; space--){
					printf(" ");
		}
		for (leafnumber = 1 ; leafnumber < counter * 2; leafnumber++) {
					printf("*");
		}
		printf("\n");
	}*/


	counter = 1;
	while (counter < levelnumber+1) {
		
		space = levelnumber - counter;
		while (space >= 0) {
			printf(" ");
			space--;
		}

		leafnumber = 1;
		while (leafnumber < counter * 2) {
			printf("*");
			leafnumber++;
		}

		counter++;
		printf("\n");
	}













	printf("THE END");
	









	return 0;


}
