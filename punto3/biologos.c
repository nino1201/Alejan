#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n=96;
	double x_0[96]={15,11,13,16,16,22,46,49,64,67,58,49,37,17,13,13,11,13,12,13,16,17,20,26,29,41,53,49,59,60,62,66,63,65,58,12,9,8,14,10,13,18,13,15,20,20,38,34,42,50,52,56,59,63,64,62,16,12,10,14,15,15,19,24,25,35,35,41,53,57,58,63,61,64,65,62,58,53,55,52,34,32,26,24,26,20,18,13,12,12,9,15,15,18,21,24};
	double y_0[96]={13,9,7,3,1,1,1,2,4,6,10,13,15,13,9,7,5,4,4,4,4,2,1,2,2,2,2,2,3,3,6,7,8,9,9,11,9,9,8,6,5,3,3,2,2,2,2,0,0,2,1,3,3,7,7,9,13,9,7,7,4,2,2,2,1,1,1,2,3,3,3,5,7,7,8,9,10,12,12,12,16,17,16,15,16,14,14,11,9,6,4,3,3,1,2,1};
	double t_0[96]={0.006,0.018,0.03,0.058,0.078,0.08,0.109,0.117,0.133,0.141,0.147,0.157,0.164,0.181,0.197,0.209,0.214,0.225,0.226,0.227,0.231,0.251,0.263,0.268,0.27,0.293,0.296,0.297,0.307,0.309,0.319,0.321,0.323,0.327,0.328,0.371,0.379,0.380,0.382,0.389,0.4,0.417,0.417,0.424,0.434,0.435,0.46,0.464,0.465,0.477,0.479,0.484,0.489,0.501,0.502,0.506,0.542,0.554,0.562,0.566,0.577,0.605,0.613,0.621,0.623,0.642,0.643,0.650,0.664,0.666,0.669,0.678,0.679,0.682,0.683,0.684,0.69,0.691,0.692,0.694,0.705,0.706,0.71,0.711,0.712,0.718,0.72,0.731,0.739,0.748,0.761,0.772,0.774,0.791,0.794,0.799};
	
	srand48(1.0);	

	int N =10000;

	double *alph=malloc(N*sizeof(double));
	double *beta=malloc(N*sizeof(double));
	double *gamma=malloc(N*sizeof(double));
	double *delta=malloc(N*sizeof(double));

	alph[0]=drand48()*20;
	beta[0]=drand48()*20;
	gamma[0]=drand48()*20;
	delta[0]=drand48()*20;

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
