#include<stdio.h>
#include<math.h>

//��J�@����ơA��X�Ҧ��p��ε��󪺽�ơC

int main(void){
	int n;
	printf("�п�J�@�����");
	scanf("%d",&n);
	for(int i = 0 ; i <=n ; i++){
		int sum = 0;
			for(int j=1 ; j <= sqrt(i); j++){
			if(i%j==0){
				sum +=j;
				sum +=i/j; 
				}
			}
		if (sum == i+1)
		printf("%d�O���\n",i);
		}
	
	
	
	
	return 0 ;
}
