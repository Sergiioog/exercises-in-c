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
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>  

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



int cpu_attack(Gladiador_t * gladiador1, Gladiador_t * gladiador2);
int cpu_attack(Gladiador_t * gladiador1, Gladiador_t * gladiador2){
	srand(time(NULL)); //Genera nums aleatorios
	int random_value = rand() % 2 + 1;
	
	if(random_value == 1){
		gladiador1->salud = gladiador1->salud - gladiador2->fuerza;
		printf("--------------------------------------------------------------------\n");
		printf("%s le quita %d puntos de vida a %s, vida restante %d \n", gladiador2->nombre, gladiador2->fuerza, gladiador1->nombre, gladiador1->salud);	
	}else{
		printf("%s ha decidido no atacar \n", gladiador2->nombre);	
	}
	
	return 0;
}

int attack(Gladiador_t * gladiador1, Gladiador_t * gladiador2); 
int attack(Gladiador_t * gladiador1, Gladiador_t * gladiador2){
	
	gladiador2->salud = gladiador2->salud - gladiador1->fuerza;
	printf("%s le quita %d puntos de vida a %s, vida restante %d \n", gladiador1->nombre, gladiador1->fuerza, gladiador2->nombre, gladiador2->salud, gladiador2->salud);	
	
	cpu_attack(gladiador1, gladiador2);
	return 0;
}


int main(int argc, char * argv[]){
	
	Gladiador_t gladiador1,gladiador2;
	gladiador1.salud = 100;
	gladiador2.salud = 100;
	int opcionUsuario = 0;
	bool programFinal = false;
	
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
	
	
	/*

	Deberá haber dos tipos de arma:
	• Espada: el ataque será la fuerza del gladiador.
	• Lanza: en este caso será el doble de la fuerza del gladiador.
	*/
	
	printf("--------Comienza la batalla--------\n");
	
	while(!programFinal){
		
		printf("--------Turno de %s--------\n", gladiador1.nombre);
		printf("1. Atacar\n");
		printf("2. Defender\n");
		printf("Selecciona una opcion: ");
		
		if(scanf("%d", &opcionUsuario) == 1){ //entrada del usuario (solo 1 num)
			
			if(opcionUsuario == 1 || opcionUsuario == 2){
				
				if(opcionUsuario == 1){
					attack(&gladiador1, &gladiador2);
				}else {
					printf("%s se defiende y no le afecta el golpe de %s!\n", gladiador1.nombre, gladiador2.nombre);
				}
				
				if (gladiador2.salud == 0) { 
					printf("La salud de %s es %d, %s gana la batalla!!!!\n", gladiador2.nombre, gladiador2.salud, gladiador1.nombre);
					programFinal = true;  // El juego ha terminado
				} else if (gladiador1.salud == 0 && gladiador2.salud == 0) {
					printf("La salud de %s es %d y la de %s es %d, empate!!!!\n", gladiador1.nombre, gladiador1.salud, gladiador2.nombre, gladiador2.salud);
					programFinal = true;  // El juego ha terminado
				} else if (gladiador1.salud == 0) {
					printf("La salud de %s es %d, %s gana la batalla!!!!\n", gladiador1.nombre, gladiador1.salud, gladiador2.nombre);
					programFinal = true;  // El juego ha terminado
				}
			}
				
		}else{
			printf("Por favor, introduzca un numero valido (1 o 2): \n");
			while (getchar() != '\n'); //Limpia el buffer 
		}
	}
	
	printf("Fin de la batalla, gracias por acudir al coliseo \n");
	
	return 0;
}