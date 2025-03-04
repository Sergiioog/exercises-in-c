/*
Simular una batalla entre dos gladiadores, uno será el usuario y el otro la máquina.

Cada gladiador tiene un nombre (hasta 10 caracteres), un tipo de arma, una fuerza y una salud.

Los ataques dependerán de la fuerza del gladiador y del tipo de arma, restarán salud a su contrincante.

Deberá haber dos tipos de arma:
	• Espada: el ataque será la fuerza del gladiador.
	• Lanza: en este caso será el doble de la fuerza del gladiador.
	
El programa deberá permitir al usuario ingresar los nombres de los dos gladiadores y datos de juego desde
la terminal. 

Al ejecutar el programa se le pasarán los datos de dos gladiadores (usuario y cpu en ese orden).

Deberá pasarle los siguientes parámetros (Espartaco será el usuario, Marcus la máquina):
./gladiadores.exe Espartaco,20,espada Marcus,10,lanza

Al inicio del programa, ambos jugadores tienen una salud de 100 unidades. 

Durante la batalla, el usuario tendrá la oportunidad de atacar o defenderse en cada turno mediante un menú. 

En el caso de la máquina atacará con una probabilidad del 50% aleatorio.

La batalla se desarrollará por turnos hasta que uno de los gladiadores quede sin salud.

Al finalizar la batalla, el programa deberá mostrar el resultado y mostrar los datos del ganador de la batalla

*/

#include <stdio.h>
#include <string.h>

typedef struct {
	
	char nombre[10];
	char arma[20];
	int fuerza;
	int salud;
	
} Gladiador1_t;

typedef struct {
	
	char nombre[10];
	char arma[20];
	int fuerza;
	int salud;
	
} Gladiador2_t;

int main(int argc, char * argv[]){
	
	
	Gladiador1_t gladiador1;
	Gladiador2_t gladiador2;
	
    printf("Introduzca el nombre del primer gladiador (10char): \n");
    scanf("%s", gladiador1.nombre);  

    printf("Introduzca el nombre del segundo gladiador (10char): ");
    scanf("%s", gladiador2.nombre);  
	

    if (strlen(gladiador1.nombre) > 9) {
        printf("ERROR: El nombre del gladiador 1 excede el tamaño permitido\n");
        return 1;
    } else if (strlen(gladiador2.nombre) > 9) {
        printf("ERROR: El nombre del gladiador 2 excede el tamaño permitido\n");
        return 1;
    } else {
        printf("Los gladiadores elegidos son: %s y %s\n", gladiador1.nombre, gladiador2.nombre);
    }
	

	
	return 0;
}