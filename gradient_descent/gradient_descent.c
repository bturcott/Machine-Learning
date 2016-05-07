#include <stdio.h>
#include <math.h>

//Declare variables
double x[] = {0,1,3,4};
double y[] = {1,2,2,3};
int m,i,k,l,iterations;
double theta_0 = 1,theta_1 = 3;
double alpha = .001;
double sum_0_temp, sum_1_temp, sum_0, sum_1, temp, j, j_prev=55;

int main(void)
{
	m = sizeof(x)/sizeof(x[0]);
	while(j != j_prev)		
	{
		sum_0 = 0;
		sum_1 = 0;
		j_prev = j;
		j=0;		
		iterations++;		
		for(i=0;i<m;i++)
		{
			sum_0_temp = ((theta_0 + theta_1 * x[i]) - y[i]);
			sum_1_temp = ((theta_0 + theta_1 * x[i]) - y[i]) * x[i];
			sum_0 = sum_0 + sum_0_temp;
			sum_1 = sum_1 + sum_1_temp;
		}
		
		theta_0 = theta_0 - ((alpha*sum_0)/m);	
		theta_1 = theta_1 - ((alpha*sum_1)/m);

		for(l=0;l<m;l++)
		{
			temp = pow(((theta_0 + theta_1 * x[i]) - y[i]),2);
			j = j + temp;
		}
		j = j * 1/(2*m);
		printf("j = %f\n",j);
	}
	printf("theta_0 is %f, theta_1 is %f\n",theta_0,theta_1);
	printf("Algorithm took %d iterations to complete.\n",iterations);
	printf("j = %f\n",j);
}
