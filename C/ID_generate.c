#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef char* String; 
char String_id[100];
char countryEnglsih[]={'A','B','C','D','E','F','G','H','I','J','K','M','N','O','P','Q','T','U','V','W','X','Z'};
int countryNumber[]={10,11,12,13,14,15,16,17,34,18,19,21,22,35,23,24,27,28,29,32,30,33};
String countryName[]={"�O�_��","�O����","�򶩥�","�O�n��","������","�s�_��","�y����","��饫","�Ÿq��","�s�˿�","�]�߿�","�n�뿤","���ƿ�","�s�˥�",
"���L��","�Ÿq��","�̪F��","�Ὤ��","�O�F��","������","���","�s����"};
char cityName[50];
char sexual[50];
char id[50];

int numbercount(char *str){
	int sum=0;
	for(int i=1;i<9;i++){
		sum += (int)(str[i]-'0')*(9-i);
	}
	return sum;
}


int Checksum(char *str){
	int temp ;
	for(int i = 0; i<22 ;i++){
		if (countryEnglsih[i]==str[0]){
			temp = countryNumber[i];
		}
	}
	temp = temp/10+temp%10*9;
	temp = temp+numbercount(str);
	temp = 10-(temp%10);
	return temp;
}


void makeId(char *Name,char *sexual){
	int sex =0;
	char x;
	int y;
	char sexualM[]={"�k"};
	char sexualF[]={"�k"};
	for(int i = 0;i < 22;i++){
		if(strncmp(countryName[i],Name,4) ==0){
		x=countryEnglsih[i];
		//printf("%c",x);
		break;
		}
	}
	if(strncmp(sexual,sexualM,3)==0)sex=1;
	else  if(strncmp(sexual,sexualF,3)==0)sex=2;
	//printf("%d",sex); 
	
	srand(time(NULL));
	y = rand()*78000%9999999;
	//printf("%d\n",y);
	sprintf(id,"%c%d%d",x,sex,y);
	printf("���ͪ������Ҧr����%s",id);
	printf("%d",Checksum(id));
}


int main(void){
	printf("�п�J�a��\n");
	scanf("%s",cityName);
	while (getchar() != '\n');
	printf("�п�J�ʧO(�k�Τk)\n");
	scanf("%s",sexual);
	//printf("%s�M%s",cityName,sexual);
	makeId(cityName,sexual);
	//printf("���ͪ������Ҧr����%s",id);
	
	return 0;
}


