/*****************************sample.c**********************/
#include "heading.h"
double G_dev(long *);

void sample() {
int k;
long s_xi;

s_xi=-1000;

xi[0]=x; S[0]=exp(xi[0]);
for (k=0; k<N_total; ++k) {
  xi[k+1]=xi[k]+eta*a*(b-xi[k])+sqrt(eta)*sigma*G_dev(&s_xi);
  S[k+1]=exp(xi[k+1]);
  }

}


