#include "user.h"

#define MAX_MESSAGE_SIZE 256
#define CLIENT_KEY 10

int main(int argc, char** argv)
{
	user_t* host =  user(SERVER,SERVER_NAME);
	
    while(1)
    {		
            if(host->status == READY)
            {	
            	printf("Message Recieved\n");
            	printf("%s\n",host->buffer);

				host->status = NOT_READY;
            }
            sleep(1);
    }
	return 0;	
}
