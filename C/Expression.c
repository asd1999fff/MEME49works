#include <stdio.h>;
#include <math.h>;

//�Q��for�j��p��1����-2����+3����-4����+�K+49����-50���誺��
int main(void){
int sum1,sum2;
for(int i = 1 ; i <=50 ; i+=2){
	sum1+=pow(i,2);
	}
for(int i = 2 ; i <=50 ; i+=2){
	sum2+=pow(i,2);
	}
printf("�Ʀr�O%d\n",sum1-sum2);

return 0;
}
