 #include <omp.h>
 #include <stdio.h>
 #define N 2000

 int main(int argc, char *argv[]) {

 int i,j,k,aa;
 float a[N], b[N], c[N], d[N];

 /* Difine 2 vectors */
 for (i=0; i < N; i++) {
   a[i] = i * 1.5;
   b[i] = i + 22.35;
 }


    //repeat for 4 times (just to increase computation time)
    for(aa=0; aa<4; aa++){
	    
    	//"randomily" compose a 4 vector there will be the sum
    	for (i=0; i < N; i++){
    		for (j=0; j < N; j++){
	    	   for (k=0; k < N; k++){
		       c[k] = a[i] + b[j];
     		   }
     	        }
       }	
	    
    }
	 
     //"randomily" compose a 4 vector there will be the sum
     for(aa=0; aa<4; aa++){
     for (i=0; i < N; i++){
    	 for (j=0; j < N; j++){
	    	 for (k=0; k < N; k++){
		       d[i] = a[i] * b[i];
    		 }
     	}
     }}

     //print a part of the final vectors (not parallizable) 
     for(i=1990;i<2000; i++)
	printf("c:%lf   d:%lf\n",c[i],d[i]);


 }
