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
	struct dirent* entry;
	struct stat sFile;
	struct FileInfo fObj;
	char Name[256] = { '\0' };
	char Buff[1024] = { '\0' };
	int iRet = 0, fdDest = 0, fdSrc = 0, iRead = 0;

	if (argc != 3)
	{
		printf("Error : Invalid arguments\n");
		printf("Usage : Directory_Name File_Name\n");
		printf("Directory_Name : Name of directory which contains the files that we want to combine");
		printf("File_Name : Name of in which you want to store all combined data\n");
		return -1;
	}

	dir = opendir(argv[1]);

	fdDest = creat(argv[2], 0777);
	if (fdDest == -1)
	{
		printf("Error : unable to creat file\n");
		return -1;
	}

	if (dir == NULL)
	{
		printf("Unable to open directory ie : %s\n", argv[1]);
		return -1;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		sprintf(Name, "%s/%s", argv[1], entry->d_name);

		iRet = stat(Name, &sFile);

		if (S_ISREG(sFile.st_mode))
		{
			strcpy(fObj.Fname, entry->d_name);	//Store file name
			fObj.Fsize = sFile.st_size;		//Store file size

			printf("%s\t %d\n", fObj.Fname, fObj.Fsize);

			write(fdDest, &fObj, sizeof(fObj));

			fdSrc = open(Name, O_RDONLY);

			while ((iRead = read(fdSrc, Buff, sizeof(Buff))) != 0)
			{
				write(fdDest, Buff, iRead);
			}
			memset(&fObj, 0, sizeof(fObj));
			memset(Buff, 0, sizeof(Buff));
			close(fdSrc);
			/*printf("%s\t %d\n", entry->d_name, sFile.st_size);*/
		}
	}
	close(fdDest);
	closedir(dir);
	return 0;
}