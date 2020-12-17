//Programa bancario
#include<stdio.h>
//#include<con.h>

int main(){
	float saldo,retiro,deposito, COM;
	saldo=retiro=deposito=0;
	COM=0.01;
	int opc;

	do {
		printf("elige una opcion del cajero: \n1- Depositar \n2- Retirar \n3- Salir");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("Ingresa la cantidad del deposito:");
				scanf("%f", &deposito);
				if (saldo==0){
					printf("dado que estas abriendo la cuenta, el deposito no puede ser menor de 1000 pesos");
					if (deposito>1000 && deposito < 10000)
					saldo=deposito;
					
					else 
					printf("Error: No puede abrir una cuenta con esa cantidad");
					
		}else{ //una vez abierta la cuenta
		printf("tu saldo actual es:%f", saldo);
		if (deposito >=10 && deposito <=1000 && deposito+saldo<=1000000)
		saldo=saldo+deposito; //acumulador
	} 
	     break;
	case 2: //retiro
	printf("ingrese la cantidad a retirar");
	scanf("%f",&retiro);
	 if(retiro>100 && retiro<5000)
	    if(retiro>5000 && retiro<8000)
	       saldo= saldo -retiro - (retiro* COM);
	 
	 }
	
	break;
	
    case 3;
	printf("Adios!! Gracias por usar el programa!!");
	break;
	default:
		printf("Opcion no valida");
		break;
	
	}

}while (opc !=3);
	return 0;

}