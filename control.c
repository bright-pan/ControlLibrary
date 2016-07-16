#include "control.h"

/*
*	Proportional and Integrator Controller:
*		K: Proportional constant
*		K_i: Integrator constant
*		u:
*/

void PI(float K, float K_i, float* u, float* u_i, float err, float h)
{
	*u_i = K*(*u_i) + h*K_i*err;
	*u = *u_i + K*err;
}
