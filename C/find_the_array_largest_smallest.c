#include<stdio.h>

//�M��@�}�C���̤j�ȩM�̤p�� 


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
	printf("���}�C�̤p�Ȭ�%d\n�̤j�Ȭ�%d",min,max);
	return 0;
}
