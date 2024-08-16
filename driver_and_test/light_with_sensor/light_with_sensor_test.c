#include <stdio.h>
#include <stdlib.h>	//system
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define DEVICE_SR04 "/dev/HC-SR04"
#define DEVICE_LIGHT "/dev/light"
int main(void)
{
	int SR04_fd;
    int light_fd;
	int ret = 0;
	unsigned char buf[2];
		
	SR04_fd = open(DEVICE_SR04, O_RDONLY);
	if(SR04_fd < 0)
	{
		perror("can not open device");
		exit(1);
	}
	while(1)
	{
		ret = read(SR04_fd,buf,sizeof(buf));
    	if(ret < 0)
    	{
    		printf("read err!\n");
		}
        else
		{
			printf("mile = %d\n", buf[0]);
		}
		sleep(1);
	}
	
	if (SR04_fd >= 0)	 //close SR04 if open
	{
		close(SR04_fd);
	}
	
	return 0;
}