struct operacion{
	float valor1;
	char operando;
	float valor2;
};

program CALCULADORA{
	version V2{
		float suma(operacion)=1;
		float resta(operacion)=2;
		float multiplicacion(operacion)=3;
		float division(operacion)=4;
		float raiz(operacion)=5;
		float elevar(operacion)=6;
	} =1;							
} = 0x20000155;

program CALCULADORA2{
	version V1{
		float logaritmo_neperiano(float num)=1;
		float factorial(float num)=2;
	} =1;						
} = 0x20000156;
