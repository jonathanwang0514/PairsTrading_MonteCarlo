/**************** G_dev.c *********************************/
#include <math.h>

double G_dev(long *idum)
{
/*******************************************************************
Returns a normally distributed deviate with zero mean and unit variance, 
using ran1(idum) as the source of uniform deviates.
********************************************************************/

double ran_G(long *idum);
static int iset=0;
static double gset;
double fac,rsq,v1,v2;

if (iset == 0) {	
	do {
		v1 = 2.0*ran_G(idum)-1.0;
		v2 = 2.0*ran_G(idum)-1.0;
		rsq = v1*v1 + v2*v2;
/* We don't have an extra deviate handy, so pick two uniform numbers in
   the square extending from -1 to +1 in each direction, see if they are 
   in the unit circle, and if they are not, try again.              */

		} while (rsq >= 1.0 || rsq == 0.0);
	fac = sqrt(-2.0*log(rsq)/rsq);
/* Now make the Box-Muller transfermation to get two normal deviates. 
   Return one and save the other for next time.*/
	gset = v1*fac;
	iset = 1;		/* Set the flag; */
	return v2*fac;
	}
else {				/* We have an extra deviate handy */
	iset = 0; 		/* so unset the flag	     */
	return gset;
	}
}

