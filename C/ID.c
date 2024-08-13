#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
char String_id[100];
char countryEnglsih[]={'A','B','C','D','E','F','G','H','I','J','K','M','N','O','P','Q','T','U','V','W','X','Z'};
int countryNumber[]={10,11,12,13,14,15,16,17,34,18,19,21,22,35,23,24,27,28,29,32,30,33};
char *countryName[]={"�O�_��","�O����","�򶩥�","�O�n��","������","�s�_��","�y����","��饫","�Ÿq��","�s�˿�","�]�߿�","�n�뿤","���ƿ�","�s�˥�","���L��","�Ÿq��","�̪F��","�Ὤ��","�O�F��","������","���","�s����"};
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
	printf("�п�J�����Ҹ��X\n");
	scanf("%s",String_id);
	if (boolean_isID(String_id))printf("��J���T");
	else printf("��J���~");
	
	return 0;
}
