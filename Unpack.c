/*
Application which is use to combine all files from the directory into one regular file
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

struct FileInfo
{
	char Fname[256];
	int Fsize;
};

//myexe Directory_name File_name
//myexe argv[1]			argv[2]
//argv[1]	:	Name of Directory that we want to open.
//argv[2]	:	Name of File that we want to create.

int main(int argc, char* argv[])
{
	DIR* dir = NULL;

	struct FileInfo fObj;
	char Name[256] = { '\0' };
	char *Buff= NULL;
	int iRet = 0, fdDest = 0, fdSrc = 0, iRead = 0;

	if (argc != 2)
	{
		printf("Error : Invalid arguments\n");
		printf("Usage : File_Name\n");
		printf("File_Name : Name of in which you want to store all combined data\n");
		return -1;
	}

	fdSrc = open(argv[1], O_RDONLY);
	if (fdSrc == -1)
	{
		printf("Error : Unable to open file\n");
		return -1;
	}
	while ((iRead = read(fdSrc, &fObj, sizeof(fObj))) != 0)
	{
		printf("File Name : %s\t File Size : %d\n", fObj.Fname, fObj.Fsize);
		lseek(fdSrc, fObj.Fsize, SEEK_CUR);
		/*fdDest = creat(fObj.Fname, 0777);

		if (fdDest == -1)
		{
			printf("Error : Unable to create file\n");
			return -1;
		}
		Buff = (char*)malloc(fObj.Fsize);

		read(fdSrc, Buff, fObj.Fsize);

		write(fdDest, Buff, fObj.Fsize);

		free(Buff);
		close(fdDest);*/
	}
	close(fdSrc);
	return 0;
}