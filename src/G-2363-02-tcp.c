#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#include "G-2363-02-tcp.h"

/*Funciones Cliente*/
int c_connect(char* ip_address, int port){

	struct sockaddr_in serv_addr;
	int sockfd = 0;
	struct hostent* address_struct;


	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(!sockfd){
		return ERROR;
	}

	memset(&serv_addr, '0', sizeof(serv_addr)); 

	serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0){
    	
    	address_struct = gethostbyname(ip_address);

    	if(address_struct != NULL){
    		serv_addr.sin_addr = *((struct in_addr *)address_struct->h_addr);
    	}else{
    		return ERROR;
    	}
    }
 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       return ERROR;
    } 
    return sockfd;
}

int c_recive_data(char* buffer, int length, int sockfd){
	return read(sockfd, buffer, length);
}

int c_send_data(char* buffer, int length, int sockfd, int flags){
	return send(sockfd, buffer, length, flags);
}

int c_disconnect(int sockfd){
	return close(sockfd);
}


/*Fnciones Server*/
int s_accept_connection(char* ip_address, int port, int queue){

	struct sockaddr_in serv_addr;
	int sockfd = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, '0', sizeof(serv_addr));

	//INADDR_ANY ??
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port); 

    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) <0){
    	return ERROR;
    } 
    if(listen(sockfd, queue) <0){
    	return ERROR;
    } 

    return sockfd;
}

int s_recive_data(char* buffer, int length, int sockfd){
	return read(sockfd, buffer, length);
}

int s_send_data(char* buffer, int length, int sockfd, int flags){
	return send(sockfd, buffer, length, flags);
}

int s_disconnect(int sockfd){
	return close(sockfd);
}
