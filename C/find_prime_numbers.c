#include<stdio.h>
#include<math.h>

//輸入一正整數，找出所有小於或等於的質數。

int main(void){
	int n;
	printf("請輸入一正整數");
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
		printf("%d是質數\n",i);
		}
	
	
	
	
	return 0 ;
}
