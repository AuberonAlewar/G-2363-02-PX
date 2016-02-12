#include <stdio.h>

void c_conectar(char* ip_address, int port){
	printf("conectando el server\n");
}

void c_leer_datos(char* buffer, int longitud){
	printf("aceptando datos\n");
}

void c_escribir_datos(char* buffer, int longitud){
	printf("escribiendo datos\n");
}

void c_desconectar(int id){
	printf("desconectando del server\n");
}

void s_aceptar_conexion(char* ip_address, int port){
	printf("conectando a un cliente\n");
}

void s_leer_datos(char* buffer, int longitud){
	printf("aceptando datos de cliente\n");
}

void s_escribir_datos(char* buffer, int longitud){
	printf("escribiendo datos en cliente\n");
}

void s_desconectar(int id){
	printf("desconectando del cliente\n");
}