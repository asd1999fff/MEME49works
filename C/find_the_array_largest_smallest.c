#include<stdio.h>

//碝т皚程㎝程 


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
	printf("皚程%d\n程%d",min,max);
	return 0;
}
