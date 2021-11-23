#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#define N 50

pid_t pid;
int i;
int f = fork();


void manejador(int signum){
	if(f)
		printf("\nDetencion no permitida\n");
	sleep(1);
}

int main(){
	pid = getpid();
	srand(pid);

	signal(SIGINT, manejador); 
	signal(SIGTSTP, manejador); 
	signal(SIGQUIT, manejador); 
	
	///variables para llevar el calculo de la serie Fibonacci
	long long fibo_aux1 = 0, fibo_aux2 = 1, fib_n_value;
	
	//contador para impares
	int count_imp = 1;

	for( i = 1; i <= N; i++ ){
		if(f == 0){
			//Proceso hijo
			printf("Valor Impar: %d - PID = %d\n", count_imp, pid);
			count_imp += 2;
		}
		else {
			// Proceso padre
			fib_n_value=fibo_aux1+fibo_aux2;
			printf("Valor Fibonacci: %lld - PIDE = %d\n",fib_n_value, pid);
			fibo_aux1 = fibo_aux2;
			fibo_aux2 = fib_n_value;
		}
		// Esperar [x] segundos.
		unsigned int wait_sg = 1;
		sleep(wait_sg);
	}
	
	return 0;
}
