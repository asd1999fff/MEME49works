#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
��J�@�r��A�r�ꬰ"all" ��ܭp��60�Ӥ몺�`�������B�q�A
"year"�B"season"�M"month"���O��ܭp��Y�~�B�Y�u�άY�몺�������B�q�C
�Y����T�̡A�A��J�@�ӥ���ƪ�ܨ��@�~�B���@�u�Ψ��@��C
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
	
	printf("�п�Jall�Byear�Bseason�Mmonth\n");
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
			printf("�`�B�q��%f\n",sum);
			break;
		case 'y':
			sum = 0;
			while(year < 1 || year > 5){
			printf("�п�J���d�ߤ��~��");
			scanf("%d",&year);
			if(year < 1 || year > 5)printf("��J���~�A�Э��s��J\n");
			}
			for(int j = 0 ; j < 4 ; j++){
					for(int k = 0; k < 3 ; k++){
					sum += rain[year-1][j][k];
						}
					}
			printf("�Ӧ~���`�B�q��%f\n",sum);
			break;
		case 's':
			sum = 0;
			while(season < 1 || season > 4){
			printf("�п�J���d�ߤ��u�`");
			scanf("%d",&season);
			if(season < 1 || season > 4)printf("��J���~�A�Э��s��J\n");
			}
			for(int i = 0 ; i < 5 ; i++){
					for(int k = 0; k < 3 ; k++){
					sum += rain[i][season-1][k];
						}
					}
			printf("�өu���`�B�q��%f\n",sum);
			break;
		case 'm':
			sum = 0;
			while(month < 1 || month > 12){
			printf("�п�J���d�ߤ����");
			scanf("%d",&month);
			if(month < 1 || month > 12)printf("��J���~�A�Э��s��J\n");
			}
			for(int i = 0 ; i < 5 ; i++){
					sum += rain[i][month/4][month%3];
					}
			printf("�Ӥ몺�`�B�q��%f\n",sum);
			break;
		default:
		printf("��J���~");
		break;
	}
	
	return 0;
}
