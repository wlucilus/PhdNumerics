#include <stdio.h>
#include <math.h>
#define N 4

// funcoes
double funcao1(double x, double y, double z, double t){
	return sin(t)+pow(x,2)+2*pow(y,4)+5*z -6;
}
double funcao2(double x, double y, double z, double t){
	return pow(t,5) + 3*x + 3*exp(-y) -2*pow(z,2) - 4;
}
double funcao3(double x, double y, double z, double t){
	return sinh(pow(t,2))+2*pow(x, 3) - cos(y) + pow(z, 2) - 2;
}
double funcao4(double x, double y, double z, double t){
	return pow(t, 3)+ x + 2*y + 3*z - 4;
}

// derivadas da funcao 1
double df1x(double x, double y, double z, double t){	return 2*x;		}
double df1y(double x, double y, double z, double t){	return 8*pow(y, 3);	}
double df1z(double x, double y, double z, double t){	return 5;		}
double df1t(double x, double y, double z, double t){	return cos(t);		}

// derivadas da funcao 2
double df2x(double x, double y, double z, double t){	return 3;		}
double df2y(double x, double y, double z, double t){	return -3*exp(-y);	}
double df2z(double x, double y, double z, double t){	return -4*z;		}
double df2t(double x, double y, double z, double t){	return 5*pow(t,4);		}

// derivadas da funcao 3
double df3x(double x, double y, double z, double t){	return 6*pow(x,2);}
double df3y(double x, double y, double z, double t){	return sin(y);		}
double df3z(double x, double y, double z, double t){	return 2*z;		}
double df3t(double x, double y, double z, double t){	return 2*t*cosh(t*t);		}

// derivadas da funcao 4
double df4x(double x, double y, double z, double t){	return 1;		}
double df4y(double x, double y, double z, double t){	return 2;		}
double df4z(double x, double y, double z, double t){	return 3;		}
double df4t(double x, double y, double z, double t){	return 3*pow(t, 2);	}


double soma(double l[N][N], double u[N][N], int i, int j, int limite){
   int k;
   double s=0;
   for(k=0;k<=limite;k++)
       s+=l[i][k]*u[k][j];
   return s;
}

// imprime uma matriz
void imprime(double vetor[N][N]){
   int i,j;
   for(i=0;i<N;i++){
     for(j=0;j<N;j++){
       printf("\t%lf",vetor[i][j]);
       if(j==N-1) printf("\n");
      }	
   }
}

// imprime um vetor
void imprimeV(double vetor[N]){
   int i;  
   for(i=0;i<N;i++){
       printf("\t%lf",vetor[i]);
   }
   printf("\n");
}

int main()
{
	double x, y, z, t;
	double dx, dy, dz, dt;
	double ep = 1e-7;
	double sum;

	double a[N][N] = {0};
	double l[N][N] = {0}, u[N][N] = {0};
	double mx[N] = {0}, my[N] = {0};
	double gama[N] = {0};

	int i, j, k, passos = 1;

	// ansatz
	x = 2;
	y = 3.14/2;
	z = 2;
	t = 3.14;

	// inicio do metodo de Newton
	while(fabs(funcao1(x, y, z, t)) > ep || fabs(funcao2(x, y, z, t)) > ep || fabs(funcao3(x, y, z, t)) > ep || fabs(funcao4(x, y, z, t)) > ep ){
                          
		// definindo o jacobiano
		a[0][0] = df1x(x, y, z, t);
		a[0][1] = df1y(x, y, z, t);
		a[0][2] = df1z(x, y, z, t);
		a[0][3] = df1t(x, y, z, t);

		a[1][0] = df2x(x, y, z, t);
		a[1][1] = df2y(x, y, z, t);
		a[1][2] = df2z(x, y, z, t);
		a[1][3] = df2t(x, y, z, t);

		a[2][0] = df3x(x, y, z, t);
		a[2][1] = df3y(x, y, z, t);
		a[2][2] = df3z(x, y, z, t);
		a[2][3] = df3t(x, y, z, t);
		
		a[3][0] = df4x(x, y, z, t);
		a[3][1] = df4y(x, y, z, t);
		a[3][2] = df4z(x, y, z, t);
		a[3][3] = df4t(x, y, z, t);

		// definindo a matriz my
		my[0] = -funcao1(x, y, z, t);
		my[1] = -funcao2(x, y, z, t);
		my[2] = -funcao3(x, y, z, t);
		my[3] = -funcao4(x, y, z, t);
		
		// resolvendo o sistema, L*gama = my e U*mx = gama

		// calculando L e U
		//valores iniciais
   		for(i=0;i<N;i++){
        		l[i][0] = a[i][0];
        		u[i][i] = 1;
        		u[0][i] = a[0][i]/l[0][0]; 
   		}

   		//calculo dos lij e uij
   		for(i=1;i<N;i++){//comecam de 1 a frente
   		
      			//calculo dos lij
      			for(j=1;j<=i;j++)
         			l[i][j] = a[i][j] - soma(l,u,i,j,j-1);
      
      			//calculo dos uij
      			for(j=(i+1);j<N;j++)
         			u[i][j] = (a[i][j] - soma(l,u,i,j,i-1))/l[i][i];
   		}

		// agora que temos L e U, calculamos a matriz gama 		 L*gama = my
		for(i=0;i<N;i++){
      			sum = 0;
      			for(j=0;j<i;j++)
          			sum += l[i][j]*gama[j];
      			gama[i] = (1/l[i][i])*(my[i] - sum);
   		}

		// agora, calculamos a matriz mx (solucao do sistema LU*mx = y)  U*mx = gama
		for(i=N-1;i>=0;i--){
      			sum = 0;
      			for(j=i+1;j<N;j++)
          			sum += u[i][j]*mx[j];    
      			mx[i] = (1/u[i][i])*(gama[i] - sum);
   		}

		// solucao do metodo de Newton
		x += mx[0];
		y += mx[1];	
		z += mx[2];
		t += mx[3];
		
		passos++;

     	printf("RESULTADO: \n\n x = %lf, y = %lf, z = %lf, t = %lf. Com %d passos. \n\n", x, y, z, t, passos);
		if(passos > 500) break;
	}

	// resultado

	system("pause");
}


