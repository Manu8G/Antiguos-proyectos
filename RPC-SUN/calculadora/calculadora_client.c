/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"
#include <stdio.h>

float calculadora_1(char *host, float n1, float n2, char operando){
	CLIENT *clnt;
	float * result;
	operacion op;
	
	#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, V2, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	#endif	/* DEBUG */

	op.valor1=n1;
	op.valor2=n2;
	op.operando=operando;

	if(operando == '+'){
		result = suma_1(op, clnt);
	}else if(operando == '-'){
		result = resta_1(op, clnt);
	}else if(operando == '*'){
		result = multiplicacion_1(op, clnt);
	}else if(operando == '/'){
		if(n1 != 0 && n2 != 0){
			result = division_1(op, clnt);
		}else{
			printf("No se puede dividir 0\n");
			clnt_destroy (clnt);
			exit(0);
		}
	}else if(operando == 'S'){
		result = raiz_1(op, clnt);		
	}else if(operando == '^'){
		result = elevar_1(op, clnt);
	}else{
		clnt_destroy (clnt);
		exit(0);
	}

	if (result == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 /* DEBUG */

	return *result;
}


float calculadora2_1(char *host, float num, char oper){
	CLIENT *clnt;
	float *result;
	float valor=num;
	char operando=oper;

	#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA2, V1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	#endif	/* DEBUG */

	if(operando == 'L'){
		result = logaritmo_neperiano_1(valor, clnt);
	}else if(operando == 'F'){
		result = factorial_1(valor, clnt);
	}else{
		clnt_destroy (clnt);
		exit(0);
	}
	
	if (result == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 /* DEBUG */

	return *result;
}


int main (int argc, char *argv[]){
	char *host;
	char tipo;
	char value[100];

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];

// %f para float %c para chars
	printf("¿Que tipo de operacion quieres realizar?(con numero = A, logaritmo_neperiano/factorial == B)\n");
	gets(value);
	tipo=value[0];

	while(tipo != 'A' && tipo != 'B'){
			printf("Las opciones validas son A y B, se lo vuelvo a repetir:\n");
			printf("¿Que tipo de operacion quieres realizar?(con numeros = A, logaritmo_neperiano/factorial == B)\n");
			gets(value);
			tipo=value[0];
	}

	if(tipo == 'A'){
		float n1, n2, resultado=0;
		char operando;
		printf("Las operaciones disponibles son: Suma == +, Resta == -, Multiplicacion == *, Division == / y Raiz == S\n");
		printf("La sintaxis permitida es: numero ENTER operacion ENTER numero ENTER. Para el caso de la raiz y el elevado el segundo numero es el exponente de dicha raiz o el numero al que se eleva el primero\n");
	
		gets(value);
		n1=atof(value);
		gets(value);
		operando=value[0];
		gets(value);
		n2=atof(value);

		while(operando != '+' && operando != '-' && operando != '*' && operando != '/' && operando != 'S'){
			printf("Las opciones validas son +, -, '*', / y S se lo vuelvo a repetir:\n");
			printf("Las operaciones disponibles son: Suma == +, Resta == -, Multiplicacion == '*', Division == / , Raiz == S\n");
			printf("La sintaxis permitida es: numero operacion numero. Para el caso de la raiz el primer numero es el exponente de dicha raiz\n");
			gets(value);
			n1=atof(value);
			gets(value);
			operando=value[0];
			gets(value);
			n2=atof(value);
		}	

		resultado=calculadora_1(host, n1, n2, operando);
		printf("%f %c %f = %f\n", n1, operando, n2, resultado);

	}else if(tipo == 'B'){
		float n1, resultado;
		char operando;

		printf("Las operaciones disponibles son: logaritmo_neperiano == L y factorial == F\n");
		printf("La sintaxis es: numero ENTER operacion\n");
		gets(value);
		n1=atof(value);
		gets(value);
		operando=value[0];

		while(operando != 'L' && operando != 'F'){
			printf("Las opciones validas son F y L, se lo vuelvo a repetir:\n");
			printf("Las operaciones disponibles son: logaritmo_neperiano == L y factorial == F\n");
			printf("La sintaxis es: numero operacion\n");
			gets(value);
			n1=atof(value);
			gets(value);
			operando=value[0];
		}

		resultado=calculadora2_1 (host, n1, operando);
		printf("%f\n",resultado);

	}
		
	exit (0);
}
