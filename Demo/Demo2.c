#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd = 0,ret = 0;
	char arr[11];
	char brr[5];
	char crr[5];
	
	fd = open(argv[1],O_RDONLY);
	
	ret = read(fd,arr,10);
	//printf("Data aftre first read is %s\n",arr);
	write(1,arr,ret);
	printf("\n");
	
	ret = read(fd,brr,4);
	//printf("Data aftre second read is %s\n",brr);
	write(1,brr,ret);
	printf("\n");
	
	ret = read(fd,crr,4);
	//printf("Data aftre third read is %s\n",crr);
	write(1,crr,ret);
	printf("\n");
	return 0;
	
}
