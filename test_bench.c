#include <stdio.h>
#include <unistd.h>
#include "control.h"

void process(float in, float* out)
{

	out[0] = out[0] + 0.9*in;

}


int main(void)
{
	float ref, err, in, out;
	int end = 0;
	float h = 1; // sample period = 1 [s]
	//float int_state = 0; //auxiliary state for the integrator
	float k_p = 1;
	float k_i = 0.5;
	float k_d = 0.2;
	float err1 = 0; // error at n-1
	float err2 = 0; // error at n-2

	/* Initial conditions - a disturbance out = 200 */
	out = 200;
	in = 0;
    ref = 0;
	err1 = 0;
	err2 = 0;

	printf("Please specify a reference: ");
	scanf("%f", &ref);

	while(end == 0)
	{
	   	err = ref - out;
		// PI(k_p, k_i, &in, &int_state, err, h);
		PID(k_p, k_i, k_d, &in, err, err1, err2, h);
		process(in, &out);

		// Update errors
		err2 = err1;
		err1 = err;

		printf("Output value: %.1f \n", out);

		sleep(h);

		if (err < 0.01 && err > -0.01)
			end = 1;
	}


	return 0;
}
