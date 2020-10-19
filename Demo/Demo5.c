#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd = 0,ret = 0;
	char arr[10] = "Marvellous";
	
	fd = open(argv[1],O_WRONLY);
	
	ret = write(fd,arr,strlen(arr));
	
	return 0;
	
}
