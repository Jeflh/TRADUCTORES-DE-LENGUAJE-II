/* 
	Análisis l�xico
	
		~=~ DESARROLLADORES ~=~
	# Juan José Salazar Villegas
	# Juan Emmanuel Fernández de Lara Hernández
	# Paola Vanessa Del Rio Gomóz
	# Mally Samira Hernández Martinez
	
	Versi�n 1.3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool esDelimitador(char caracter) { 
 	// Evalúa el caráter de entrada para saber si es un delimitador
 	// devuelve True en caso de pertener al grupo, o en caso contrario
 	// nos regresa False.
	switch(caracter){
		case ' ':
		case '+':
		case '-':
		case '*':
		case '/':
		case '>':
		case '<':
		case '=':
		case '(':
		case ')':
		case '[':
		case ']':
		case '{': 
		case '}':
		case ';':
		case ':':
		case ',':
		case '.':
		case '"':
		case '&':
		case '|':
			return (true);
			break;
		default: return (false);	
	}
}


bool esOperador(char caracter) {
	switch (caracter){
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '>':
		case '<':
		case '=':
		case ':':
		case '.':
			return (true);
			break;
		default: return (false);
	}
}


bool esLogico(char caracter) {
	switch (caracter){
		case '&':
		case '|':
			return (true);
			break;
		default: return (false);
	}
}

bool identificadorValido(char *cadena) {
	
	if(esDelimitador(cadena[0]) == true) {
		return (false);
	}
	switch (cadena[0]){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return (false);
			break;
		default: return (true);	
	}
}


bool esReservada(char *str) {
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
        !strcmp(str, "continue") ||
        !strcmp(str, "int") ||
        !strcmp(str, "double") ||
        !strcmp(str, "float") ||
        !strcmp(str, "return") ||
        !strcmp(str, "char") ||
        !strcmp(str, "case") ||
        !strcmp(str, "char") ||
        !strcmp(str, "sizeof") ||
        !strcmp(str, "long") ||
        !strcmp(str, "short") ||
        !strcmp(str, "typedef") ||
        !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}


bool esEntero(char *cadena) {
	int i, len = strlen(cadena);
	
	if (len == 0) return (false);
	
	for(i = 0; i < len; i++) {
		if (cadena[i] != '0' && cadena[i] != '1' && cadena[i] != '2' && 
			cadena[i] != '3' && cadena[i] != '4' && cadena[i] != '5' && 
			cadena[i] != '6' && cadena[i] != '7' && cadena[i] != '8' && 
			cadena[i] != '9' || (cadena[i] == '-' && i > 0)) return (false);
	}
	return (true);
}


bool esNumeroReal(char *cadena) {
	int i, len = strlen(cadena);
	bool tieneDecimal = false;
	
	if (len == 0) {
		return (false);	
	}
	
	for (i = 0; i < len; i++) {
		if (cadena[i] != '0' && cadena[i] != '1' && cadena[i] != '2' && 
			cadena[i] != '3' && cadena[i] != '4' && cadena[i] != '5' &&
			cadena[i] != '6' && cadena[i] != '7' && cadena[i] != '8' &&
			cadena[i] != '9' && cadena[i] != '.' 
			|| (cadena[i] == '-' && i > 0)) return (false);
		if (cadena[i] == '.') tieneDecimal = true; 
	}
	return (tieneDecimal);
}


char *subCadena(char *cadena, int left, int right) {
	
	char *subStr = (char *)malloc(sizeof(char) * (right - left + 2)); 
	
	for (int i = left; i <= right; i++){
		subStr[i - left] = cadena[i];
	}
	
	subStr[right - left + 1] = '\0';
	
	return (subStr);
}


void frase (char *cadena) {
	int left = 0, right = 0;
	int len = strlen(cadena);
	
	while (right <= len && left <= right) {
		if (esDelimitador(cadena[right]) == false) {
			right++;
		}
		if (esDelimitador(cadena[left]) == true && left == right){
			if (esOperador(cadena[right]) == true) {
				printf("'%c' es un OPERADOR\n", cadena[right]);
			} 
			if(esLogico(cadena[right]) == true) {
				printf("'%c' es un OPERADOR LOGICO\n", cadena[right]);	
			}
			else {
				printf("'%c' es un DELIMITADOR\n", cadena[right]);
			}
			
			right++;
			left = right;
		}
		else if (esDelimitador(cadena[right]) == true && left != right || (right == len && left != right)) {
			char *subStr = subCadena(cadena, left, right -1);
			
			if (esReservada(subStr) == true) {
				printf("'%s' es una PALABRA RESERVADA\n", subStr);
			}
			else if (esEntero(subStr) == true){	
				printf("'%s' es un ENTERO\n", subStr);
			}
			else if (esNumeroReal(subStr) == true) {
				printf("'%s' es un numero REAL\n", subStr);
			}
			else if (identificadorValido(subStr) == true && esDelimitador(cadena[right - 1]) == false){
				printf("'%s' es un IDENTIFICADOR VALIDO\n", subStr);
			}
			else if (identificadorValido(subStr) == false && esDelimitador(cadena[right - 1]) == false){
				printf("'%s' NO es un IDENTIFICADOR VALIDO\n", subStr);
			}
			
			left = right;
		}
	}
}


int main() {
	while (true) {
		char cadena[101];
		printf("Ingresa una cadena: ");
		scanf("%s", cadena);
		getchar();
		frase(cadena);
		printf("\n");
	}
	
	return (0);
}

