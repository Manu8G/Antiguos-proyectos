/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_operacion (XDR *xdrs, operacion *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->valor1))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->operando))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->valor2))
		 return FALSE;
	return TRUE;
}