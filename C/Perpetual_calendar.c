#include<stdio.h>

int main(void){
	int monthR[]={31,29,31,30,31,30,31,31,30,31,30,31};
	int monthN[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year;
	int month;
	int day;
	int flag;
	printf("請輸入年份");
	scanf("%d",&year);
	printf("請輸入月份");
	scanf("%d",&month);
	printf(" 日 一 二 三 四 五 六\n");
	printf("=====================\n");
	if(year%4==0&&year%100!=0||year%400==0){
		flag=0;
	}else{
		flag=1;
	}
	int orginalyear = year;
	year-=1990;
	month-=1;
		switch(year){
			case 0:{
				break;
			}
			case 1:{
				day +=365;
				break;
			}
			case 2:{
				day +=730;
				break;
			}
			case 3:{
				day +=1096;
				break;
			}
			default:{
				day += 1096;
				year-= 3;
				day +=(year-year/4)*365+year/4*366;
				break;
			}
		}
	//	printf("%d\n",day);		
	for(int i = 0; i < month ;i++){
		if(orginalyear%4 == 0)day+=monthR[i];
		if(orginalyear%4 != 0)day+=monthN[i];
	}
	//printf("距離1990一月過了%d天\n",day); 
	if(flag == 0){
			int i =1;
			int space = day%7;
			//printf("%d",space);
			while(i<=monthR[month]){
			for(int j = 0;j<7;j++){ 
			if(space>=0 && space<6){
				printf("   ");
				space --;
			}else{
				//printf("%d",monthR[month]);
				printf("%3d",i);	
				i++;
				if(i>monthR[month])break;
				} 			
			}
			printf("\n");
			}
		}else if(flag == 1){
			int i =1;
			int space = day%7;
			//space ++;
			//printf("%d",space);
			while(i<=monthN[month]){
			for(int j = 0;j<7;j++){ 
			if(space>=0 && space<6){
				printf("   ");
				space --;
			}else{
				//printf("%d",monthR[month]);
				printf("%3d",i);	
				i++;
				if(i>monthN[month])break;
				} 			
			}
		printf("\n");
		}
	}
	printf("=====================\n");
		return 0;
}
