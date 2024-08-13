#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
char String_id[100];
char countryEnglsih[]={'A','B','C','D','E','F','G','H','I','J','K','M','N','O','P','Q','T','U','V','W','X','Z'};
int countryNumber[]={10,11,12,13,14,15,16,17,34,18,19,21,22,35,23,24,27,28,29,32,30,33};
char *countryName[]={"臺北市","臺中市","基隆市","臺南市","高雄市","新北市","宜蘭縣","桃園市","嘉義市","新竹縣","苗栗縣","南投縣","彰化縣","新竹市","雲林縣","嘉義縣","屏東縣","花蓮縣","臺東縣","金門縣","澎湖縣","連江縣"};
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


int boolean_isID(char *str){
	if(strlen(str) != 10) return 0;
	if(str[0] < 'A' || str[0] > 'Z') return 0;
	if(str[1] !='1' && str[1] != '2') return 0; 
	for(int i = 2; i < 9 ; i++){
		if(str[i] < '0' || str[i] > '9'){ 
		return 0;
		} 
	}
	if((int)(str[9]-'0')!=Checksum(str)) return 0;
	return 1;
}


int main(void){
	printf("請輸入身分證號碼\n");
	scanf("%s",String_id);
	if (boolean_isID(String_id))printf("輸入正確");
	else printf("輸入錯誤");
	
	return 0;
}
