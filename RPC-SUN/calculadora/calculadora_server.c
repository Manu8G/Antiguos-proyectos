/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calculadora.h"

float * suma_1_svc(operacion arg1,  struct svc_req *rqstp){
	static float  result;
	result=arg1.valor1 + arg1.valor2;

	return &result;
}

float * resta_1_svc(operacion arg1,  struct svc_req *rqstp){
	static float  result;
	result=arg1.valor1 - arg1.valor2;

	return &result;
}

float * multiplicacion_1_svc(operacion arg1,  struct svc_req *rqstp){
	static float  result;
	result=arg1.valor1 * arg1.valor2;
	
	return &result;
}

float * division_1_svc(operacion arg1,  struct svc_req *rqstp){
	static float  result;
	result=arg1.valor1 / arg1.valor2;

	return &result;
}

float * raiz_1_svc(operacion arg1,  struct svc_req *rqstp){
	static float  result;

	result=pow(arg1.valor1, 1/arg1.valor2);

	return &result;
}

float * elevar_1_svc(operacion arg1,  struct svc_req *rqstp){
	static float  result;

	result=pow(arg1.valor1, arg1.valor2);

	return &result;
}

float * logaritmo_neperiano_1_svc(float num,  struct svc_req *rqstp){
	static float  result;

	result=log(num);

	return &result;
}

float * factorial_1_svc(float num,  struct svc_req *rqstp){
	static float  result;
	float valor=1;
	//int repeticiones=(int)num;

	for(int i=1; i<=num; i++){
		valor=valor*i;
	}

	result=valor;

	return &result;
}

