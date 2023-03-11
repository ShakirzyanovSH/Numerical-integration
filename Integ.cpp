#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

const
	double a = 0;
	double b = 1;
	int MaxIter = 15;
    float x;
double f(double x)
{
	return x;
}

double Rectang(long int n)
{
	double S=0;
	int i;
	double h;
	h = (b-a)/double(n);
	for(i=0;i<n;i++)
	{
		S += (h*f(a+i*h));
	}
	return S;
}


int main()
{
	double S1,S2;
	double dS;
	long int n=4;
	int k=0;
	double e;

	printf(" Numerical integration. Left Rectangle Method \n");
	do 
	{
		printf(" Specify the accuracy of the integral calculation e>0: ");
		scanf("%lf",&e);
	} while(e<=0);
	printf("\n The program starts the calculation with the number of intervals of the partition n=4 \n");
	printf(" If the accuracy is not achieved, the number of intervals is increased by 2 times. \n");


	S1 = Rectang(n);
	do
	{
		printf(" S1(n=%ld) = %lf",n,S1);
		n *= 2;
		S2 = Rectang(n);
		dS = (S2-S1);
		if(S2!=0) dS /= S2;
		printf(" S2(n=%ld)=%lf  |S2-S1|/S2=%-6.2e \n",n,S2,dS);
		S1 = S2;
		k++;
		if(k>MaxIter) break;
	} while(dS>e);
	
	if(k>MaxIter) 
	{
		printf("\n The specified accuracy is not the value for the maximum number of iterations 15. \n");
		printf(" Integral value = %lf \n",S2);
	}
	else
	{
		printf("\n Integral value = %lf \n",S2);
	}

	getch();
	return 0;
}

