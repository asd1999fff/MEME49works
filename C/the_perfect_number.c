#include <stdio.h>
#include <math.h>

/*
计璝单ㄤ┮Τ计羆㎝玥计perfect number
т100ず┮ΤЧ计
*/


int main(void){

for(int i =1 ; i<= 100 ; i++){
	int counter = 0;
	int arr[100]={0};
	int allsum = 0;
		for(int j=1 ; j <= sqrt(i); j++){
			if(i%j==0){
				arr[++counter]=j;
				//printf("arr琌%d\n",arr[counter]);
				if(i/j != i){
				arr[++counter]=i/j; 
				//printf("arr琌%d\n",arr[counter]);
				}
			}
		}
		for(int k = 1 ; k <= counter; k++){
		allsum += arr[k];
		//printf("allsum琌%d\n",allsum);
		}
		if(allsum == i){
			printf("%d琌perfectnumber\n",i);
		}		
	}
	return 0;
}

