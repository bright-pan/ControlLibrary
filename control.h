#ifndef CONTROL_H_
#define CONTROL_H_

void PI(float K, float K_i, float* u, float* u_i, float err, float h);
void PID(float k_p, float k_i, float k_d, float* u, float err0, float err1, float err2, float h);

#endif
