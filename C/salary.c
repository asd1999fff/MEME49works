#include <stdio.h>
/*
60小時以內，時薪150元。
61~80小時，以時薪1.25倍計算。
81小時以上，以時薪1.5倍計算。
說明：薪資以累計方式計算。若工時為90小時，則薪資為60*150 + 20*150*1.25 + 10*150*1.5元。
*/
int main(void){
	int hour,salary;
	printf("請輸入時數");
	scanf("%d",&hour);
	if(hour <=60 && hour >=0) salary = 150*hour;
	else if(hour <= 80) salary = 9000 + 1.25*150*(hour-60);
	else if(hour > 80)  salary = 9000 + 3750 + 150*1.5*(hour-80);
	else salary = -1;
	
	if(salary == -1) printf("輸入錯誤");
	else printf("您的薪水為%d",salary); 
	
	return 0;
} 
