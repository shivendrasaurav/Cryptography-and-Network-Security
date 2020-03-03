#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main() {
   char fname[250] = "";
   char fcontent[1000] = "";
   int fd, fd1, fd2;
   mkfifo("fifo1", 0600);
   mkfifo("fifo2", 0600);
   printf("\nServer Open\n\n");
   fd = open("fifo1", O_RDONLY);
   fd1 = open("fifo2", O_WRONLY);
   read(fd, fname, 25);
   fd2 = open(fname, O_RDONLY);
   while (read(fd2, fcontent, 100) != 0) {
      printf("%s\n", fcontent);
      if (fd < 0)
         write(fd1, "file not exists", 14);
      else
         write(fd1, fcontent, strlen(fcontent));
   }
   close(fd);
   close(fd1);
   close(fd2);
}
