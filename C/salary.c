#include <stdio.h>
/*
60�p�ɥH���A���~150���C
61~80�p�ɡA�H���~1.25���p��C
81�p�ɥH�W�A�H���~1.5���p��C
�����G�~��H�֭p�覡�p��C�Y�u�ɬ�90�p�ɡA�h�~�ꬰ60*150 + 20*150*1.25 + 10*150*1.5���C
*/
int main(void){
	int hour,salary;
	printf("�п�J�ɼ�");
	scanf("%d",&hour);
	if(hour <=60 && hour >=0) salary = 150*hour;
	else if(hour <= 80) salary = 9000 + 1.25*150*(hour-60);
	else if(hour > 80)  salary = 9000 + 3750 + 150*1.5*(hour-80);
	else salary = -1;
	
	if(salary == -1) printf("��J���~");
	else printf("�z���~����%d",salary); 
	
	return 0;
} 
