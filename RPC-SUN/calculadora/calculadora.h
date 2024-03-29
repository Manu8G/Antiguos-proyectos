/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALCULADORA_H_RPCGEN
#define _CALCULADORA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct operacion {
	float valor1;
	char operando;
	float valor2;
};
typedef struct operacion operacion;

#define CALCULADORA 0x20000155
#define V2 1

#if defined(__STDC__) || defined(__cplusplus)
#define suma 1
extern  float * suma_1(operacion , CLIENT *);
extern  float * suma_1_svc(operacion , struct svc_req *);
#define resta 2
extern  float * resta_1(operacion , CLIENT *);
extern  float * resta_1_svc(operacion , struct svc_req *);
#define multiplicacion 3
extern  float * multiplicacion_1(operacion , CLIENT *);
extern  float * multiplicacion_1_svc(operacion , struct svc_req *);
#define division 4
extern  float * division_1(operacion , CLIENT *);
extern  float * division_1_svc(operacion , struct svc_req *);
#define raiz 5
extern  float * raiz_1(operacion , CLIENT *);
extern  float * raiz_1_svc(operacion , struct svc_req *);
#define elevar 6
extern  float * elevar_1(operacion , CLIENT *);
extern  float * elevar_1_svc(operacion , struct svc_req *);
extern int calculadora_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define suma 1
extern  float * suma_1();
extern  float * suma_1_svc();
#define resta 2
extern  float * resta_1();
extern  float * resta_1_svc();
#define multiplicacion 3
extern  float * multiplicacion_1();
extern  float * multiplicacion_1_svc();
#define division 4
extern  float * division_1();
extern  float * division_1_svc();
#define raiz 5
extern  float * raiz_1();
extern  float * raiz_1_svc();
#define elevar 6
extern  float * elevar_1();
extern  float * elevar_1_svc();
extern int calculadora_1_freeresult ();
#endif /* K&R C */

#define CALCULADORA2 0x20000156
#define V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define logaritmo_neperiano 1
extern  float * logaritmo_neperiano_1(float , CLIENT *);
extern  float * logaritmo_neperiano_1_svc(float , struct svc_req *);
#define factorial 2
extern  float * factorial_1(float , CLIENT *);
extern  float * factorial_1_svc(float , struct svc_req *);
extern int calculadora2_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define logaritmo_neperiano 1
extern  float * logaritmo_neperiano_1();
extern  float * logaritmo_neperiano_1_svc();
#define factorial 2
extern  float * factorial_1();
extern  float * factorial_1_svc();
extern int calculadora2_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_operacion (XDR *, operacion*);

#else /* K&R C */
extern bool_t xdr_operacion ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALCULADORA_H_RPCGEN */
