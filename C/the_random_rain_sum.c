#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
輸入一字串，字串為"all" 表示計算60個月的總平均降雨量，
"year"、"season"和"month"分別表示計算某年、某季或某月的平均降雨量。
若為後三者，再輸入一個正整數表示那一年、那一季或那一月。
*/

int main(void){
	double rain[5][4][3];
	char func[10];
	char flag;
	int year ;
	int season ;
	int month ;
	
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			for(int k = 0; k < 3 ; k++){
			rain[i][j][k]=(rand()*0.1);
			}
		}
	}
	
	printf("請輸入all、year、season和month\n");
	scanf("%s",func);
	if(strcmp(func, "all") == 0) flag = 'a';
	else if(strcmp(func, "year") == 0) flag = 'y';
	else if(strcmp(func, "season") == 0) flag = 's';
	else if(strcmp(func, "month") == 0) flag = 'm';
	else flag = 'x';
	
	switch(flag){
	double sum ;
		case 'a':
			sum = 0;
			for(int i = 0 ; i < 5 ; i++){
				for(int j = 0 ; j < 4 ; j++){
					for(int k = 0; k < 3 ; k++){
					sum += rain[i][j][k];
						}
					}
				}
			printf("總雨量為%f\n",sum);
			break;
		case 'y':
			sum = 0;
			while(year < 1 || year > 5){
			printf("請輸入欲查詢之年分");
			scanf("%d",&year);
			if(year < 1 || year > 5)printf("輸入錯誤，請重新輸入\n");
			}
			for(int j = 0 ; j < 4 ; j++){
					for(int k = 0; k < 3 ; k++){
					sum += rain[year-1][j][k];
						}
					}
			printf("該年的總雨量為%f\n",sum);
			break;
		case 's':
			sum = 0;
			while(season < 1 || season > 4){
			printf("請輸入欲查詢之季節");
			scanf("%d",&season);
			if(season < 1 || season > 4)printf("輸入錯誤，請重新輸入\n");
			}
			for(int i = 0 ; i < 5 ; i++){
					for(int k = 0; k < 3 ; k++){
					sum += rain[i][season-1][k];
						}
					}
			printf("該季的總雨量為%f\n",sum);
			break;
		case 'm':
			sum = 0;
			while(month < 1 || month > 12){
			printf("請輸入欲查詢之月份");
			scanf("%d",&month);
			if(month < 1 || month > 12)printf("輸入錯誤，請重新輸入\n");
			}
			for(int i = 0 ; i < 5 ; i++){
					sum += rain[i][month/4][month%3];
					}
			printf("該月的總雨量為%f\n",sum);
			break;
		default:
		printf("輸入錯誤");
		break;
	}
	
	return 0;
}
