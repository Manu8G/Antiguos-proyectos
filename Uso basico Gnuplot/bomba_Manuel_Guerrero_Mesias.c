// gcc -Og bomba_Manuel_Guerrero_Mesias.c -o bomba_Manuel_Guerrero_Mesias -no-pie -fno-guess-branch-probability

#include <stdio.h>	// para printf(), fgets(), scanf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define SIZE 100
#define TLIM 5

char password[]="locopizzas\n";	// contraseña
int  passcode  = 8888;			// pin
int variable_para_nada_sospechosa=69;
void boom(void){
	printf(	"\n"
		"***************\n"
		"*** BOOM!!! ***\n"
		"***************\n"
		"\n");
	exit(-1);
}

void defused(void){
	printf(	"\n"
		"·························\n"
		"··· bomba desactivada ···\n"
		"·························\n"
		"\n");
	exit(0);
}

void funcion_masageador(char contrasena[]){
	int solucion=4;
	for(int i=0; i<4; i++){
		solucion+=i;
	}
	contrasena[9]+=32;
	if(solucion==variable_para_nada_sospechosa){
		boom();
	}else if(solucion==5){
		boom();
	}else{

	}

}

int funcion_para_nada_sospechosa(int codigo){
	codigo+=codigo;
	return codigo;
}

int main(){
	char pw[SIZE];
	int  pc, n;

	struct timeval tv1,tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1,NULL);

	do	printf("\nIntroduce la contraseña: ");
	while (	fgets(pw, SIZE, stdin) == NULL );
	funcion_masageador(pw);	
	if(pw[4]=='w'){
		boom();
	}else{
		if    (	strncmp(pw,password,sizeof(password)) )
		    boom();
	}
	gettimeofday(&tv2,NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM )
	    boom();

	do  {	printf("\nIntroduce el pin: ");
	 if ((n=scanf("%i",&pc))==0)
		scanf("%*s")    ==1;         }
	while (	n!=1 );
	pc=funcion_para_nada_sospechosa(pc);
	if    (	pc != passcode )
	    boom();

	gettimeofday(&tv1,NULL);
	if    ( tv1.tv_sec - tv2.tv_sec > TLIM )
	    boom();

	defused();
}
