#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double x_0[8] ={0.324190175,-0.701534590,-0.982564148,1.104185888,3.266443877,-9.218802228,19.930781147,24.323085642};
	double y_0[8] ={0.090955208,-0.168809218,-0.191145980,-0.826097003,-3.888055863,1.788299816,-2.555241579,-17.606227355};
	double z_0[8] ={-0.022920510,0.037947785,-0.000014724,-0.04459599,-0.057015321,0.335737817,-0.267710968,-0.197974999};

	double vx_0[8] ={-4.627851589,1.725066954,1.126784520,3.260215854,2.076140727,-0.496457364,0.172224285,0.664855006};
	double vy_0[8] ={10.390063716,-7.205747212,-6.187988860,4.524583075,1.904040630,-2.005021061,1.357933443,0.935497207};
	double vz_0[8] ={1.273504997,-0.1198268558,0.000330572,0.014760239,-0.054374153,0.054667082,0.002836325,-0.034716967};

	srand48(1.0);	

	int N =400000;

	double *n=malloc(N*sizeof(double));
	n[0]=10*drand48();

	double *Msol=malloc(N*sizeof(double));	
	Msol[0]=10*drand48()+100;

	double *r= malloc(8*sizeof(double));
	double *vr= malloc(8*sizeof(double));
	double *vn= malloc(8*sizeof(double));
	double *vold=malloc(8*sizeof(double));

	double n_n;
	double M_n;

	int i;
	int j;

	double alpha;

	double p_new;
	double p_old;

	double random;

	double d_n=0.01;
	double d_M=0.01;
	
	double G=log10(pow(1.19112883711,-27));

	for (i=1;i<N;i++)
	{
		n_n=n[i-1]+d_n*(drand48()-0.5)*2.;
		M_n=Msol[i-1]+d_M*(drand48()-0.5)*2.;

		p_new=0;
		p_old=0;

		for(j=0;j<8;j++)
		{	
			r[j]=log10(pow(x_0[j],2.)+pow(y_0[j],2.)+pow(z_0[j],2.));
			vr[j]=log10(pow(vx_0[j],2.)+pow(vy_0[j],2.)+pow(vz_0[j],2.));

			vn[j]=G+M_n-n_n*r[j];
			vold[j]=G+Msol[i-1]-n[i-1]*r[j];

			p_new=p_new+pow(vr[j]-vn[j],2.)/0.02;			
			p_old=p_old+pow(vr[j]-vold[j],2.)/0.02;
		}
		p_new=exp(-p_new);
		p_old=exp(-p_old);
		
		if(p_new/p_old<1.0)
		{
			alpha=p_new/p_old;
		}

		else
		{
			alpha=1.0;
		}
		
		random=	drand48();	

		if(random<alpha)
		{
			n[i]=n_n;
			Msol[i]=M_n;
		}
		
		else
		{
			n[i]=n[i-1];
			Msol[i]=Msol[i-1];

		}
		
		printf("%e %e\n",n[i],Msol[i]);
	}

	return 0;
}
