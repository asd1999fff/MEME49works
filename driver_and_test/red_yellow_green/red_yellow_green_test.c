#include <stdio.h>
#include <stdlib.h>	//system
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define DEVICE_BLTEST "/dev/light"
int main(void)
{
	int testfd;
	int ret = 0;
	unsigned char buf[2];
	int i = 0;
		
	testfd = open(DEVICE_BLTEST, O_RDONLY);
	if(testfd < 0)
	{
		perror("can not open device");
		exit(1);
	}

	
	while(1)
	{
		ret = read(testfd,buf,sizeof(buf));
    	if(ret < 0)
    	{
    		printf("read err!\n");
		}
        else
		{
		printf("running %d\n",i);
		i++;
		}
	sleep(1);
	}
	
	if (testfd >= 0)	 //close humidityfd if open
	{
		close(testfd);
	}
	
	return 0;
}
