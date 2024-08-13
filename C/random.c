#include<stdio.h>
#include<stdlib.h>
int main(void){
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	int x = 0;
	int y = 10;
	int j = 9;
	for(int i=0;i<4;i++){
	x = rand()%y;
	printf("%d\n",arr[x]);
	int temp = arr[j];
	arr[j]=arr[x];
	arr[x]=temp;
	j--;
	y--;
	}
	
	return 0;
} 
