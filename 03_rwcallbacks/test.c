#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char setbuffer[100];
    char getbuffer[100];
    ssize_t ret;

    fd = open("/dev/dummydriver", O_RDWR);
    if(fd == -1) {
        perror("Failed to open dummydriver");
        return -1;
    }
    printf("Dummy Driver Opening was successfull!\n");

    /* get string */
    printf("Write to the device : ");
    if(fgets(setbuffer, sizeof(setbuffer), stdin) == NULL) {
        printf("fgets Errr!\n");
        return 0;
    }
    setbuffer[strlen(setbuffer)-1] = '\0';

    /* write */
    ret = write(fd, setbuffer, strlen(setbuffer));
    if(ret < 0) {
        perror("Failed to write the message to the device");
        return -1;
    }

    /* read */
    memset(getbuffer, 0, sizeof(getbuffer));
    ret = read(fd, getbuffer, sizeof(getbuffer));
    if(ret < 0) {
        perror("Failed to read the message from the device");
        return -1;
    }

    printf("Read from the device : %s\n", getbuffer);

    close(fd);
    return 0;
}