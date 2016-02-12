#ifndef TCP_H_
#define TCP_H_ 

#define ERROR -1
#define OK 0

int c_conectar(char* ip_address, int port);

void c_leer_datos(char* buffer, int longitud);

void c_escribir_datos(char* buffer, int longitud);

void c_desconectar(int id);

void s_aceptar_conexion(char* ip_address, int port);

void s_leer_datos(char* buffer, int longitud);

void s_escribir_datos(char* buffer, int longitud);

void s_desconectar(int id);

#endif