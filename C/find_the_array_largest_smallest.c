#include<stdio.h>

//尋找一陣列的最大值和最小值 


int main(void){
	int arr[10]{20,13,42,53,34,15,68,79,86,9} ;
	int min = arr[0];
	int max = arr[0];	
	for(int i=0; i<10 ; i++){
	if (arr[i] < min) min = arr[i];	
	}
	for(int i=0; i<10 ; i++){
	if (arr[i] > max) max = arr[i];	
	}
	printf("此陣列最小值為%d\n最大值為%d",min,max);
	return 0;
}
