/*
- Escribe un programa que actúe como un conversor de pulgadas a centímetros y viceversa desde la línea de
comandos. 
- El programa permitirá al usuario ingresar un valor junto con la unidad de origen y la unidad de
destino, y luego realizará la conversión correspondiente.

El programa deberá aceptar tres argumentos de línea de comandos:
- Valor númérico que se quiere convertir en formato coma flotante.
- Una palabra que representa la unidad de origen: puede ser “inch” ó “cm”
- Una palabra que representa la unidad de destino: puede ser “inch” ó “cm”

Se pide implementar una función que convierta los datos de entrada a las unidades pedidas:
- double convertir_longitud(ConversionInfo_t conversion);

La función recibirá una estructura que contenga información de los datos, el tipo de datos de entrada
(cm ó pulgadas) y tipo de datos de salida (cm ó pulgadas) pedidos.

Se valorará la calidad de la implementación en base a las siguientes pautas:
- Se debe guardar en una estructura tanto el tipo de unidad como el valor de origen y destino.
- Se valorará el uso correcto de enumerados para esta implementación.
- Se valorará el control de errores. Si el número introducido o si las unidades especificadas no son
válidas o no se reconocen, el programa deberá mostrar un mensaje de error apropiado y terminar la
ejecución.
- Se valorará el uso de funciones para pasar valores “cadena” a valores “enumerado” para realizar las
operaciones pedidas.

IMPORTANTE: Una pulgada equivale a 2.54 centímetros.

*/

#include <stdio.h>
#include <string.h>



typedef struct {
	
	float cantidad;
	char palabraOrigen[100];
	char palabraDestino[100];

} ConversionInfo_t;


double convertir_longitud(ConversionInfo_t conversion){
	
	float inch = 2.54;
	float cm;
	float resultadoFinal = 0;
	
	if(strcmp(conversion.palabraOrigen,"inch") == 0){
		
		resultadoFinal = conversion.cantidad * inch;
		printf("%.2f inches son %.2f cm", conversion.cantidad, resultadoFinal);
	
	}else{
	
		resultadoFinal = conversion.cantidad / inch;
		printf("%.2f cm son %.2f inches", conversion.cantidad, resultadoFinal);
	
	}
	
	return resultadoFinal;
}



int main(int argc, char * argv[]){
	
	ConversionInfo_t conversion;
		
	printf("Por favor, introduzca el valor numerico a convertir, palabra de origen y palabra de destino: \n");
	scanf("%f %s %s", &conversion.cantidad, conversion.palabraOrigen, conversion.palabraDestino);
	

	if (getchar() != '\n') { //Si hay salto de linea (3 valores) no entra
        
		printf("ERROR: Introduzca un numero valido de entidades\n");
		return 1;
	}
	
	//Ver posibilidad de implementar ENUM
	if ((strcmp(conversion.palabraOrigen, "inch") == 0 && strcmp(conversion.palabraDestino, "cm") == 0) ||
        (strcmp(conversion.palabraOrigen, "cm") == 0 && strcmp(conversion.palabraDestino, "inch") == 0)) {
			
		convertir_longitud(conversion);
		
	}else{
		//Ver posibilidad de funcion de error
		printf("ERROR: segunda o tercera palabra erronea\n");
		return 1;
	}

	
	return 0;
}















