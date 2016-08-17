#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

#include "user.h"

char* message;
char* address;
#define MAX_MESSAGE_SIZE 50
#define CLIENT_KEY 10


int connect_to_host(user_t* host,user_t* client)
{
	fflush( stdout );
	printf("c\n");
	int i;
	int status = -1;

	printf("c\n");
	for(i = 0; i < 10; i++)
	{
		printf("b\n");
		if(host->users[i] == NULL)
		{
			printf("asd\n");
			host->users[i] =  client;
			queue_element_t* message;
			message  = (queue_element_t*)malloc(sizeof(queue_element_t));
			 if(message == NULL){
					 perror("malloc");
					 exit(EXIT_FAILURE);
		  	}
			printf("A\n");
			
			strcpy(host->buffer,client->name);
			printf("%s\n",host->buffer);
			host->status = READY;
			status = 1;
			break;

		}
	}

	return status;

}

int main(int argc, char** argv)
{
	printf("Creating Host\n");
	user_t* host =  user(SERVER,SERVER_NAME);	
	printf("Creating Client\n");
	user_t* client = user(CLIENT,"rmc343");

	printf("Connecting Client\n");	
	//fflush()

	int status = connect_to_host(host,client);

	if(status == 1){
		printf("Client Connected...\n");
        while(1)
        {
        	/*
            if(host->status == READY)
            {   
               	fgets(host->buffer,BUFF_SIZE,stdin);
                host->status = NOT_READY;
                
        	}
        	*/
        }
	}
	
	return 0;

}
