#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double x_0[6] = {3.,4.,5.,3.,4.,5.};
	double y_0[6] = {15.,15.,15.,16.,16.,16.};
	double t[6] = {3.12,3.26,2.98,3.12,2.82,2.98};
	
	int N = 500000;
	
	srand48(1.0);


	double x_n;
	double y_n;
	
	double *x=malloc(N*sizeof(double));
	double *y=malloc(N*sizeof(double));
	
	int i;
	int j;

	double alpha;

	double prob1;
	double prob2;

	double *tm=malloc(6*sizeof(double));
	double *tm2=malloc(6*sizeof(double));

	double delta_x=0.03;
	double delta_y=0.02;
	
	double random;
	
	x[0]=1+drand48()*3;
	y[0]=5+drand48()*10;

	for(i=1;i<N;i++)
	{	x_n=x[i-1]+delta_x*(drand48()-0.5)*2.;
		y_n=y[i-1]+delta_y*(drand48()-0.5)*2.;
		
		prob1=0;
		prob2=0;

		for(j=0;j<6;j++)
		{	
			tm[j]=pow(pow(x_0[j]-x_n,2.)+pow(y_0[j]-y_n,2.),0.5)/5.;
			tm2[j]=pow(pow(x_0[j]-x[i-1],2.)+pow(y_0[j]-y[i-1],2.),0.5)/5.;
			
			prob1=prob1+pow(t[j]-tm[j],2.)/0.02;
			prob2=prob2+pow(t[j]-tm2[j],2.)/0.02;
			
				
		}
		
		prob1=exp(-prob1);
		prob2=exp(-prob2);
		
		if(prob1/prob2<1.0)
		{
			alpha=prob1/prob2;
		}

		else
		{
			alpha=1.0;
		}
		
		random=	drand48();	

		if(random<alpha)
		{
			x[i]=x_n;
			y[i]=y_n;
		}
		
		else
		{
			x[i]=x[i-1];
			y[i]=y[i-1];

		}
		
		printf("%e %e\n",x[i],y[i]);
	}
	
	return 0;
}
