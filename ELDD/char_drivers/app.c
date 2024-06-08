#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include "ioctlh.h"

#define handle_error(msg) do{perror(msg);exit(EXIT_FAILURE);}while(0);
char *devfile = "/dev/chardrivclass";
char rd_buff[100],wr_buff[100];
int main() {
	int fd;
	int ch,cx;
	int x = 7;
	fd = open(devfile,O_RDWR);
	if(fd == -1)
		handle_error("Error opening file\n");
	while(1) {
		printf("Enter your choice\n\t 1.Read\n\t 2.Write\n\t 3.IOCTL\n 4.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:if(read(fd,rd_buff,sizeof(rd_buff))<=0)
					handle_error("error in read operation user\n");
				printf("Data read: %s",rd_buff);
			break;
			case 2:printf("Enter the data to write to kernel\n");
			       scanf("%s",wr_buff);
				if(write(fd,wr_buff,strlen(wr_buff))<=0)
					handle_error("error in write operation\n");
				printf("Write operation complete\n");
			break;
			case 3:printf("Enter choice\n 1.SET\n 2.CLEAR\n 3.GET\n");
				scanf("%d",&cx);
				switch(cx){
				case 1:printf("Enter the value to set\n");
				scanf("%d",&x);
				ioctl(fd,CMD_3,&x);
				break;
				case 2:ioctl(fd,CMD_1);
				break;
				case 3:ioctl(fd,CMD_2,&x);
				printf("Value recieved %d\n",x);
				break;
				default:break;
				}

			break;
			case 4:close(fd);
			exit(1);
		default:printf("Not a valid choice\n");
			break;
			}
		}
	close(fd);
	return 0;
	}
