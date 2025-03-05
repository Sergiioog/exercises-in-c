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
#include <ctype.h>

typedef struct {
	
	char nombre[11]; //10 char + \0
	char arma[10];
	int fuerza;
	int salud;
	
} Gladiador_t;

typedef enum {
	ESPADA,
	LANZA
} Weapon_e;

int check_is_validName(char * palabra); 

int check_is_validName(char * palabra){
	
	for(int i = 0; i < strlen(palabra); i++){
		if(!isalpha(palabra[i])){
			printf("ERROR: La palabra %s no es valida, cambiela por favor.", palabra); 
			return 1;
		}
	}
	return 0;
}


int main(int argc, char * argv[]){
	
	Gladiador_t gladiador1,gladiador2;
	gladiador1.salud = 100;
	gladiador2.salud = 100;
	
	printf("Introduzca los datos para empezar: gladiador1, fuerza1, arma1, gladiador2, fuerza2, arma2 -> ");
    scanf("%s %d %s %s %d %s", gladiador1.nombre, &gladiador1.fuerza, gladiador1.arma, gladiador2.nombre, &gladiador2.fuerza, gladiador2.arma); 
	
	//--------------NOMBRE GLD1------------------------------
	
	if (strlen(gladiador1.nombre) > 9) {
        printf("ERROR: El nombre del gladiador 1 excede el tamanio permitido\n");
        return 1;
    }
	if(check_is_validName(gladiador1.nombre)){
		return 1;
	}
	
	//--------------ARMA GLD1------------------------------
	
	if (strlen(gladiador1.arma) > 10) {
        printf("ERROR: El arma de %s excede el tamano permitido\n", gladiador1.nombre);
        return 1;
    }
	
	if(check_is_validName(gladiador1.arma)){
		return 1;
	}
	
	//--------------NOMBRE GLD2------------------------------
	
	if (strlen(gladiador2.nombre) > 9) {
        printf("ERROR: El nombre del gladiador 2 excede el tamanio permitido\n");
        return 1;
    }
	
	if(check_is_validName(gladiador2.nombre)){
		return 1;
	}
	
	//--------------ARMA GLD2------------------------------
	
	if (strlen(gladiador2.arma) > 10) {
        printf("ERROR: El arma de %s excede el tamano permitido\n", gladiador2.nombre);
        return 1;
    }
	
	if(check_is_validName(gladiador2.arma)){
		return 1;
	}

	//----------------FUERZA GLD1 GLD2------------------------------
	
	//Mirar como hacer para que no sean palabras
    if (gladiador1.fuerza <= 0 || gladiador2.fuerza <= 0) {
		printf("ERROR: La fuerza introducida no es un numero, introduzca un numero valido\n", gladiador1.nombre, gladiador2.nombre);
		return 1;
	}
	

	
	printf("Los gladiadores elegidos son: %s y %s, utilizan %s y %s como armas, tienen una fuerza de %d y %d y una salud de %d y %d puntos de vida", 
	gladiador1.nombre, gladiador2.nombre, gladiador1.arma, gladiador2.arma, gladiador1.fuerza, gladiador2.fuerza, gladiador1.salud, gladiador2.salud);
	
	return 0;
}