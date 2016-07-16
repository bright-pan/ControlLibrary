#include "control.h"

void PI(float K, float K_i, float* u, float* u_i, float err, float h)
{
	u_i[0] = K*u_i[0] + h*K_i*err;
	u[0] = u_i[0] + K*err;
}
