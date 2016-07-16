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
	float u_i = 0;
	float k_p = 0.5;
	float k_i = 0.1;

	/* Initial conditions - a disturbance out = 200 */
	out = 200;
	in = 0;

    ref = 0;

	printf("Please specify a reference: ");
	scanf("%f", &ref);

	while(end == 0)
	{
	   	err = ref - out;
		PI(k_p, k_i, &in, &u_i, err, h);
		process(in, &out);

		printf("Output value: %.1f \n", out);

		sleep(h);

		if (err < 0.01 && err > -0.01)
			end = 1;
	}


	return 0;
}
