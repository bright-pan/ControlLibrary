#include "control.h"
#include <stdio.h>

/*
*	Proportional and Integrator Controller:
*		k: Proportional constant
*		k_i: Integrator constant
*		u: Full output of Controller. Must be defined as zero in the main 		funcion
*		u_i: Partial output, only relative to the integrator. Same constriction the variable above
*		err: Error funcion
*		h: Sample time in seconds
*/

void PI(float k_p, float k_i, float* u, float* u_i, float err, float h)
{
	// Auxiliary state
	*u_i = k_p*(*u_i) + h*k_i*err;

	*u = *u_i + k_p*err;
}

/*
*	Proportional, Integrator and Differential Controller:
*		k_d: Differential constant
*		err0: Error at n
*		err1: Error at n-1
*		err2: Error at n-2
*/

void PID(float k_p, float k_i, float k_d, float* u, float err0, float err1, float err2, float h)
{
	float k0, k1, k2, delta_u;

	// auxiliary constants
	k0 = k_p + k_i + k_d;
	k1 = -k_p - 2*k_d;
	k2 = k_d;

	delta_u = k0*err0 + k1*err1 + k2*err2;
 	*u = *u + delta_u;
}

/*
*	Ziegler-Nichols:
*		to be added later
*/


/*
*	Optimum control:
*		to be added later
*/
