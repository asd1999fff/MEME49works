#include<stdio.h>
#include<stdlib.h>
int main(void){
	int arr[52];
	//int arr1[]={'A','1','2','3','4','5','6','7','8','9','10','J','Q','K'};
	for(int i=0;i<52;i++){
		arr[i]=i;
	}
	int x = 0;
	int y = 52;
	int j = 51;
	for(int k = 0; k < 4;k++){
		printf("玩家%d\n\n\n",k+1);
		for(int i=0;i<13;i++){
		x = rand()%y;
		switch(arr[x]/13){
				case 0:{
				printf("黑桃");
				break;
			}
				case 1:{
				printf("紅心");
				break;
			}
				case 2:{
				printf("方塊");
				break;
			}
				case 3:{
				printf("梅花");
				break;
			}
		}
		switch(arr[x]%13){
			case 0:{
				printf("A\n");
				break;
			}case 1:{
				printf("2\n");
				break;
			}case 2:{
				printf("3\n");
				break;
			}
			case 3:{
				printf("4\n");
				break;
			}
			case 4:{
				printf("5\n");
				break;
			}
			case 5:{
				printf("6\n");
				break;
			}
			case 6:{
				printf("7\n");
				break;
			}
			case 7:{
				printf("8\n");
				break;
			}
			case 8:{
				printf("9\n");
				break;
			}
			case 9:{
				printf("10\n");
				break;
			}
			case 10:{
				printf("J\n");
				break;
			}
			case 11:{
				printf("Q\n");
				break;
			}
			case 12:{
				printf("K\n");
				break;
			}
		}
		//printf("%d\n",rand()%y);
		int temp = arr[j];
		arr[j]=arr[x];
		arr[x]=temp;
		j--;
		y--;
		}
	printf("\n\n");
	printf("================================");
	printf("\n\n");
}
	return 0;
} 
