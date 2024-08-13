#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv)
{
	
	int levelnumber = 0; // 決定重複執行幾次
	int leafnumber = 0; // 決定葉子打印次數
	int space = 0; // 決定打印空白次數
	int counter = 1; // 普通的計數器
	
	while (levelnumber <= 2 || levelnumber > 8) {
		printf("輸入層數,此數需大於2不能超過9\n");
		scanf("%d", &levelnumber);
		if (levelnumber <= 2 || levelnumber > 8) {
			printf("數值錯誤，請重新輸入\n");
		}
		if (levelnumber > 2 && levelnumber <= 8) {
			printf("數值正確\n");
		}
	}	
	/*
	用for產生 
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
