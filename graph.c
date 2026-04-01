/****************************** graph.c ************************/
#include "heading.h"

void graph(void) { 
int n;

FILE *fp1,*fp2,*fp_plot;

fp1 = fopen("myfile1","w+"); fp2 = fopen("myfile2","w+");
fp_plot = fopen("myfile_plot","w+");

fprintf(fp1,"%s","x=[");
for (n=0; n < N_total; ++n ) {
    if (n < N_total-1)  {
       fprintf(fp1,"%f,\n",eta*n);
     }
      else    {
       fprintf(fp1,"%f];\n",eta*n);
   }
  }

fprintf(fp1,"%s","xi=[");
for (n=0; n < N_total; ++n ) {
    if (n < N_total-1)  {
        fprintf(fp1,"%f,\n",xi[n]);
}
       else  {           
	    fprintf(fp1,"%f];\n",xi[n]);
}}

fprintf(fp1,"%s","S=[");
for (n=0; n < N_total; ++n ) {
    if (n < N_total-1)  {
        fprintf(fp1,"%f,\n",exp(xi[n]));
}
       else  {           
	    fprintf(fp1,"%f];\n",exp(xi[n]));
}}

fprintf(fp_plot,"\nsubplot(2,1,1); plot(x,xi,'b-'); grid, hold on; xlabel('t'); ylabel('X_t'); title(' ');hold on\n");

/*
fprintf(fp_plot,"\nsubplot(2,1,2); 

plot(x,S,'g-'); grid, hold on; 

xlabel('t'); 
ylabel('S_t'); 
title(' ');hold on\n");
*/

fprintf(fp_plot,"%s","\norient tall;\n");
fprintf(fp_plot,"\nprint -dpsc sample.ps;\n");

fclose(fp1); fclose(fp2); fclose(fp_plot);

system("rm f.m");
system("cat myfile1 myfile2 myfile_plot >> f.m");
system("rm myfile*"); 

}

 
 

