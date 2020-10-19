----------------------------------------------------------

Types of files
    Regular file
    Directory file
    Symbolic link
    Hard link
    FIFO (Pipe)

----------------------------------------------------------

List of ssystem calls of file subsystem

unlink      Delete existing regular file

open        Open exisiting regular file

close       Close the opened regulra file

read        Read the data from the regular file

write       WRite the data into the regular file

lseek       Perform random access in the regular file

----------------------------------------------------------


Name : create
Description : Cretate new regular file
Prototype :
Parameters :
Return value:
Internal algorithms flow:

----------------------------------------------------------

Name : open
Description : open existing regular file
Prototype : int open(file path, mode)
Parameters :
        file path : Either absolute or relative path of the file that we want to open
        mode :
                    O_RDONLY
                    O_WRONLY
                    O_RDWR
                    O_CREAT
                    O_TRUNC
                    O_APPEND

Return value:   integer which is considered as a file descripter
    
Error code :    It returns -1 if unable to open file

Internal algorithms flow:


                        fopen()
                        
                        open()

                        namei()

                        iget()
        
                        entery into IIT

                        entry into FT

                        entry into UFDT

                        return index of UFDT

----------------------------------------------------------

name : write

Description : It is used to write data into the regular file

Prototype : int write(fd,data,size);

Parameters :
first paratemet is the file descripter
second parameter is the array  which contains the data that we want to write
third paramener is the size of data that we want to write.

Return value:
It reyurns the number of succesfull bytes writen in the file.

----------------------------------------------------------

name : read

Description : It is used to read data into the regular file

Prototype : int read(data,size);

Parameters :
first paratemet is the file descripter
second parameter is the array  whichis empty
third paramener is the size of data that we want to read.

Return value:
It reyurns the number of succesfull bytes readf from the file.

----------------------------------------------------------

Algorithm : namei
Description : Accept path and return inode number of target file

Exmaple :   /Demo/Hello/Marvellous.c

----------------------------------------------------------

Algoithm : iget

Description : USed to get the inode of existing file

----------------------------------------------------------




































