#include <stdio.h>
#include <math.h>

/*
�@�ӼƦr�Y�����Ҧ��]�ƪ��`�M�A�h���Ƭ�perfect number�C
��X100�H���Ҧ��������ơC
*/


int main(void){

for(int i =1 ; i<= 100 ; i++){
	int counter = 0;
	int arr[100]={0};
	int allsum = 0;
		for(int j=1 ; j <= sqrt(i); j++){
			if(i%j==0){
				arr[++counter]=j;
				//printf("arr�O%d\n",arr[counter]);
				if(i/j != i){
				arr[++counter]=i/j; 
				//printf("arr�O%d\n",arr[counter]);
				}
			}
		}
		for(int k = 1 ; k <= counter; k++){
		allsum += arr[k];
		//printf("allsum���ȬO%d\n",allsum);
		}
		if(allsum == i){
			printf("%d�Operfectnumber\n",i);
		}		
	}
	return 0;
}

