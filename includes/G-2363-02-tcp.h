/** ===================================================================
	@file       G-2363-NN-tcp.h
    @version    1.0
    @date       13 Feb 2016
    @author     Alvaro Cortés and Eduardo Rodríguez

    @brief High level functions for connection by TCP

    Revision history:
        13 Feb 2016 Version 1.0 (initial release).

    =================================================================== */

#ifndef TCP_H_
#define TCP_H_ 

#define ERROR -1
#define OK 0


/**
    @brief           c_connect
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Creates a socket with TCP in the IP address and port specified.

	@param ip_address IP address you want to connect with, (you can use a name, ej: google.com)

	@param port specified port to connect

    @return int: returns the id of the socket.
*/
int c_connect(char* ip_address, int port);

/**
    @brief           c_recive_data
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Catches data from a specific port.

    @param buffer the messagge

    @param lenght size of the message

    @param sockfd socket you are going to use


    @return int: returns result of the function read().
*/
int c_recive_data(char* buffer, int length, int sockfd);

/**
    @brief           c_send_data
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Sends data through a socket specifying FLAGS.

	@param buffer the messagge

	@param lenght size of the message

	@param sockfd socket you are going to use

	@param flags specific flags

    @return int: returns result of the function send().
*/
int c_send_data(char* buffer, int length, int sockfd, int flags);

/**
    @brief           c_disconnect
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Closes a socket.

	@param sockfd socket you are going to close

    @return int: returns the result of the function disconnect().
*/
int c_disconnect(int sockfd);


/**
    @brief           s_accept_connection
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Creates a socket with TCP in the IP address and port specified
            and stays listening

    @param ip_address IP address you want to ONLY connect with, if NULL = INADDR_ANY

    @param port specified port to connect

    @return int: returns the id of the socket.
*/
int s_accept_connection(char* ip_address, int port, int queue);


/**
    @brief           s_recive_data
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Catches data from a specific port.

    @param buffer the messagge

    @param lenght size of the message

    @param sockfd socket you are going to use


    @return int: returns result of the function read().
*/
int s_recive_data(char* buffer, int length, int sockfd);

/**
    @brief           s_send_data
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Sends data through a socket specifying FLAGS.

    @param buffer the messagge

    @param lenght size of the message

    @param sockfd socket you are going to use

    @param flags specific flags

    @return int: returns result of the function send().
*/
int s_send_data(char* buffer, int length, int sockfd, int flags);

/**
    @brief           s_disconnect
    @date            13 Feb 2016
    @author          Alvaro Cortés and Eduardo Rodríguez

    @brief Closes a socket.

    @param sockfd socket you are going to close

    @return int: returns the result of the function disconnect().
*/
int s_disconnect(int sockfd);

#endif