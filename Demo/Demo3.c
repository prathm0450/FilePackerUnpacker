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
	
	ret = lseek(fd,10,SEEK_SET);
	// SEEK_SET	From starting position
	// SEEK_CUR	From current position
	// SEEK_END	From end of the file
	printf("Return value of lseek is %d\n",ret);
	
	ret = read(fd,arr,10);
	
	write(1,arr,ret);
	
	printf("\n");
	
	ret = lseek(fd,-4,SEEK_END);

	printf("Return value of lseek is %d\n",ret);
	
	ret = read(fd,arr,4);
	
	write(1,arr,ret);
	
	return 0;
	
}
