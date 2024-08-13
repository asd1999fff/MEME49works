#include<stdio.h>
#include<math.h>


//计俱计ㄤ计ぇミよ㎝单赣计セō

int main(void){
	for(int i =1 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			for(int k = 0 ; k < 10 ; k++){
				if(i*100+j*10+k == pow(i,3)+pow(j,3)+pow(k,3)){
					printf("%d琌Amstrong计\n",i*100+j*10+k);
				}
			}
		}
	}
	
	return 0;
}
