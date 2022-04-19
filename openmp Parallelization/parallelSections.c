 #include <omp.h>
 #include <stdio.h>
 #define N 2000

int main(int argc, char *argv[]) {

 int i,j,k;
 float a[N], b[N], c[N], d[N];

 /* Some initializations */
 for (i=0; i < N; i++) {
   a[i] = i * 1.5;
   b[i] = i + 22.35;
   }


	//shared(a,b,c,d)
   #pragma omp parallel 
   {

   #pragma omp sections  private(i,j,k)  nowait
     {

     #pragma omp section
     {
      for (i=0; i < N; i++){
    	 for (j=0; j < N; j++){
	    	 for (k=0; k < N; k++){
		       c[k] = a[i] + b[j];
     		}
     	}
     }
     }	//end first section

     #pragma omp section
     {
     for (i=0; i < N; i++){
    	 for (j=0; j < N; j++){
	    	 for (k=0; k < N; k++){
		       d[i] = a[i] * b[i];
     		}
     	}
     }	
     }

     }  /* end of sections */

   }  /* end of parallel region */

   for(i=1990;i<2000; i++)
	printf("c:%lf   d:%lf \n",c[i],d[i]);



 }
