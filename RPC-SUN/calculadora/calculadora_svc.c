/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static float *
_suma_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (suma_1_svc(*argp, rqstp));
}

static float *
_resta_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (resta_1_svc(*argp, rqstp));
}

static float *
_multiplicacion_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (multiplicacion_1_svc(*argp, rqstp));
}

static float *
_division_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (division_1_svc(*argp, rqstp));
}

static float *
_raiz_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (raiz_1_svc(*argp, rqstp));
}

static float *
_elevar_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (elevar_1_svc(*argp, rqstp));
}

static float *
_logaritmo_neperiano_1 (float  *argp, struct svc_req *rqstp)
{
	return (logaritmo_neperiano_1_svc(*argp, rqstp));
}

static float *
_factorial_1 (float  *argp, struct svc_req *rqstp)
{
	return (factorial_1_svc(*argp, rqstp));
}

static void
calculadora_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		operacion suma_1_arg;
		operacion resta_1_arg;
		operacion multiplicacion_1_arg;
		operacion division_1_arg;
		operacion raiz_1_arg;
		operacion elevar_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case suma:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _suma_1;
		break;

	case resta:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _resta_1;
		break;

	case multiplicacion:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _multiplicacion_1;
		break;

	case division:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _division_1;
		break;

	case raiz:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _raiz_1;
		break;

	case elevar:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _elevar_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
calculadora2_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		float logaritmo_neperiano_1_arg;
		float factorial_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case logaritmo_neperiano:
		_xdr_argument = (xdrproc_t) xdr_float;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _logaritmo_neperiano_1;
		break;

	case factorial:
		_xdr_argument = (xdrproc_t) xdr_float;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _factorial_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CALCULADORA, V2);
	pmap_unset (CALCULADORA2, V1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, V2, calculadora_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, V2, udp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA2, V1, calculadora2_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA2, V1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, V2, calculadora_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, V2, tcp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA2, V1, calculadora2_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA2, V1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
