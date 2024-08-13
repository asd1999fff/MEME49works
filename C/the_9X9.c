#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char** argv) {
	int number = 1;
	int multiplier = 1;
	while (number <= 9) {
		while (multiplier <= 9) {
			printf("(%dx%d=%s%d)", number, multiplier, number * multiplier < 10 ? "0" : "", number * multiplier);
			multiplier++;
		}
		multiplier = 1;
		number++;
		printf("\n");
	}
	return 0;
}
