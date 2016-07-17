#include "control.h"

/*
*	Proportional and Integrator Controller:
*		K: Proportional constant
*		K_i: Integrator constant
*		u: Full output of Controller. Must be defined as zero in the main 		funcion
*		u_i: Partial output, only relative to the integrator. Same constriction the variable above
*		err: Error funcion
*		h: Sample time in seconds
*/

void PI(float K, float K_i, float* u, float* u_i, float err, float h)
{
	*u_i = K*(*u_i) + h*K_i*err;
	*u = *u_i + K*err;
}
