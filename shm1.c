#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY 0x101252
#define SIZE 1024
main(){
	int shmid;
	char *shmaddr;

	if((shmid = shmget(KEY, SIZE, IPC_CREAT|0666)) == -1){
		perror("shmid failed");
		exit(1);
	}
	if((shmaddr = shmat(shmid, NULL, 0)) == (void *)-1){
		perror("shmat failed");
		exit(1);
	}
 	strcpy((char *)shmaddr, "Hello World LYC!!");
	if(shmdt(shmaddr) == -1){
		perror("shmdt failed");
		exit(1);
	}
}
