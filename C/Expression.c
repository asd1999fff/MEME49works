#include <stdio.h>;
#include <math.h>;

//利用for迴圈計算1平方-2平方+3平方-4平方+…+49平方-50平方的值
int main(void){
int sum1,sum2;
for(int i = 1 ; i <=50 ; i+=2){
	sum1+=pow(i,2);
	}
for(int i = 2 ; i <=50 ; i+=2){
	sum2+=pow(i,2);
	}
printf("數字是%d\n",sum1-sum2);

return 0;
}
