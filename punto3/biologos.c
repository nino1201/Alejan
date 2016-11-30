#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n=96;
	
	double x_0[n];
	double y_0[n];
	double t_0[n];
	
	srand48(1.0);	

	int N =1000000;

	double *alph=malloc(N*sizeof(double));
	double *beta=malloc(N*sizeof(double));
	double *gamma=malloc(N*sizeof(double));
	double *delta=malloc(N*sizeof(double));

	alph[0]=drand48();
	beta[0]=drand48();
	gamma[0]=drand48();
	delta[0]=drand48();

	int i;
	int j;

	double an;
	double bn;
	double gn;
	double dn;

	double pnew;
	double pold;

	double pnew2;
	double pold2;

	double xn;
	double yn;

	double *xold=malloc(n*sizeof(double));
	double *yold=malloc(n*sizeof(double));

	double da=0.1;
	double db=0.12;
	double dg=0.13;
	double dd=0.14;

	double dt;
	double dx;
	double dy;

	double random;
	double random2;

	double alpha;
	double alpha2;
	

	for(i=1;i<N;i++)
	{
		an=alph[i-1]+da*(drand48()-0.5)*2.;
		bn=beta[i-1]+db*(drand48()-0.5)*2.;
		gn=gamma[i-1]+dg*(drand48()-0.5)*2.;
		dn=delta[i-1]+dd*(drand48()-0.5)*2.;

		pnew=0;
		pold=0;

		for(j=0;j<n-1;j++)
		{	dt=t_0[j+1]-t_0[j];
			dx=x_0[j+1]-x_0[j];
			dy=y_0[j+1]-y_0[j];

			yn=(dt*x_0[j]*an-dx)/(dt*x_0[j]*bn);		
			xn=(dt*y_0[j]*gn+dy)/(dt*y_0[j]*dn);

			yold[j]=(dt*x_0[j]*alph[i-1]-dx)/(dt*x_0[j]*beta[i-1]);
			xold[j]=(dt*x_0[j]*gamma[i-1]-dx)/(dt*x_0[j]*delta[i-1]);

			pnew=pnew+pow(x_0[j]-xn,2.)/0.02;
			pold=pold+pow(x_0[j]-xold[j],2.)/0.02;

			pnew2=pnew2+pow(y_0[j]-yn,2.)/0.02;
			pold2=pold2+pow(y_0[j]-yold[j],2.)/0.02;
			
		} 
		
		pnew=exp(-pnew);
		pold=exp(-pold);
		
		if(pnew/pold<1.0)
		{
			alpha=pnew/pold;
		}

		else
		{
			alpha=1.0;
		}
		
		random=	drand48();	

		if(random<alpha)
		{
			gamma[i]=gn;
			delta[i]=dn;
		}
		
		else
		{
			gamma[i]=gamma[i-1];
			delta[i]=delta[i-1];

		}

		pnew2=exp(-pnew2);
		pold2=exp(-pold2);
		
		if(pnew2/pold2<1.0)
		{
			alpha2=pnew2/pold2;
		}

		else
		{
			alpha2=1.0;
		}
		
		random2=drand48();	

		if(random2<alpha2)
		{
			alph[i]=an;
			beta[i]=bn;
		}
		
		else
		{
			alph[i]=alph[i-1];
			beta[i]=beta[i-1];

		}
		
		printf("%f %f %f %f \n",alph[i],beta[i],gamma[i],delta[i]);
	}
}
