/*
Brian DeJesus
File copy program
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  
  char data[200] = {0}; //Buffer
  int fd1, fd2; //File descriptors
  ssize_t rd; //Bytes read variable
  
  if(argc != 3) {
    fprintf(stderr, "Usage: %s <sourcefile> <destinationfile>\n", argv[0]);
    return -1;
  }

  char *source_file = argv[1];
  char *destination_file = argv[2];

  printf("Source file: %s \nDestination file: %s \n", source_file, destination_file);

  fd1 = open(source_file, O_RDONLY); // Open source file
  if(fd1 < 0) {
    fprintf(stderr, "Error opening the source file");
    return -1;
  }

  fd2 = open(destination_file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR); // Open destination file. Create one if it doesn't exist
  if(fd2 < 0) { 
    fprintf(stderr, "Error creating or writing to destination file");
    return -1;
  }
  printf("Successfully copied file!! \n");

  while(rd = read(fd1, data, sizeof(data))) { // Read data byte by byte from source then write byte by byte into destination
    write(fd2, data, rd);
  }

  close(fd1); // Close file descriptors
  close(fd2);

  return 0;
}
