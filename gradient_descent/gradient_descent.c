#include <stdio.h>
#include <math.h>

//Declare variables
double x[] = {1,2,3,4,5,6,7};
double y[] = {-1,-2,-3,-4,-5,-6,-7};
int m,i,l,iterations;
double theta_0 = -5,theta_1 = 12;
double alpha = .001;
double sum_0, sum_1, j;
 
int main(void)
{
	m = sizeof(x)/sizeof(x[0]);
	for(l=0;l<1000000;l++)		
	{
		sum_0 = 0;
		sum_1 = 0;
		j=0;		
		iterations++;		
		for(i=0;i<m;i++)
		{
			sum_0 += ((theta_0 + theta_1 * x[i]) - y[i]);
			sum_1 += ((theta_0 + theta_1 * x[i]) - y[i]) * x[i];
		}
		
		theta_0 = theta_0 - ((alpha*sum_0)/m);	
		theta_1 = theta_1 - ((alpha*sum_1)/m);

		for(i=0;i<m;i++)
		{
			j += pow(((theta_0 + theta_1 * x[i]) - y[i]),2);
		}
		j = j * 1/(2*m);
	}
	printf("theta_0 is %f, theta_1 is %f\n",theta_0,theta_1);
	printf("Algorithm took %d iterations to complete.\n",iterations);
	printf("j = %f\n",j);
}
