#include <stdio.h>
#include <math.h>

//Declare variables
int x[] = {1, 2, 3};
int y[] = {1, 2, 3};
int m,i;
double theta_1 = 1;
double temp, j;

int main(void)
{
	m = sizeof(x)/sizeof(x[0]);
	for(i=0;i<m;i++)
	{
		temp = pow(((theta_1 * x[i]) - y[i]),2);
		j = j + temp;
	}
	j = j * 1/(2*m);
	printf("j = %f\n",j);
}
