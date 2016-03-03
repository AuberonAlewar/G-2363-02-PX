#include <stdio.h>
#include <string.h>
#include "G-2363-02-tcp.h"


int main(int argc, char** argv){

	int sockfd =0;

	sockfd = s_accept_connection(argv[1], 7, 10);

	char buffer [5000];
	char mensaje [5000];

	printf("Socket %d\n", sockfd);


	if(s_recive_data(buffer, 5000, sockfd) <0){
		printf("ERROR al Recibir\n");
	}else{

		printf("Recibido: %s\n", buffer);
		while(1){
			

			/*memset(buffer,0,strlen(buffer));*/
			if(s_send_data(buffer, strlen(buffer), sockfd, 0) <0){
				printf("ERROR al enviar\n");
			}
			if(s_recive_data(buffer, 5000, sockfd) <0){
				printf("ERROR al recibir\n");
			}
			printf("Recibido: %s\n", buffer);
		}
	}

	return 0;
}