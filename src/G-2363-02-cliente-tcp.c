#include <stdio.h>
#include <string.h>
#include "G-2363-02-tcp.h"


int main(int argc, char** argv){

	int sockfd =0;

	sockfd = c_connect(argv[1], 7);

	char buffer [5000];
	char mensaje [5000];

	printf("Socket %d\n", sockfd);

	printf("Enviado: %s\n", argv[2]);


	if(c_send_data(argv[2], strlen(argv[2]), sockfd, 0) <0){
		printf("ERROR al enviar\n");
	}

	if(c_recive_data(buffer, 5000, sockfd) <0){
		printf("ERROR al Recibir\n");
	}else{

		printf("Recibido: %s\n", buffer);
		while(strcmp(mensaje, "salir")!=0){
			

			scanf("%s", mensaje);
			if(c_send_data(mensaje, strlen(mensaje), sockfd, 0) <0){
				printf("ERROR al enviar\n");
			}

			memset(buffer,0,strlen(buffer));
			if(c_recive_data(buffer, 5000, sockfd) <0){
				printf("ERROR al recibir\n");
			}
			printf("Recibido: %s\n", buffer);
		}
	}

	return 0;
}
