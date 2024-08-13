#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef char* String; 
char String_id[100];
char countryEnglsih[]={'A','B','C','D','E','F','G','H','I','J','K','M','N','O','P','Q','T','U','V','W','X','Z'};
int countryNumber[]={10,11,12,13,14,15,16,17,34,18,19,21,22,35,23,24,27,28,29,32,30,33};
String countryName[]={"臺北市","臺中市","基隆市","臺南市","高雄市","新北市","宜蘭縣","桃園市","嘉義市","新竹縣","苗栗縣","南投縣","彰化縣","新竹市",
"雲林縣","嘉義縣","屏東縣","花蓮縣","臺東縣","金門縣","澎湖縣","連江縣"};
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
	char sexualM[]={"男"};
	char sexualF[]={"女"};
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
	printf("產生的身分證字號為%s",id);
	printf("%d",Checksum(id));
}


int main(void){
	printf("請輸入地區\n");
	scanf("%s",cityName);
	while (getchar() != '\n');
	printf("請輸入性別(男或女)\n");
	scanf("%s",sexual);
	//printf("%s和%s",cityName,sexual);
	makeId(cityName,sexual);
	//printf("產生的身分證字號為%s",id);
	
	return 0;
}


