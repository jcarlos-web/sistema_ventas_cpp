/*
* @Autor: <jCarlos:Mendoza/>
* 
* Proyecto: sistema_ventas_c
* Código: sistema_sentas_c.cpp
* Fecha: 22/04/2017
*/

/*Directivas de preprocesador*/
#include<iostream> // Entrada y Salida de C++ 
#include<stdlib.h> // funciones del sistema



/*Declaración de la estructura cliente*/
struct cliente{
	int numCli;
	char nomCli[30];
	char apPat[30];
	char apMat[30];

} usu;

/* Declaración de funciones */
float cobrarCliente (float val1, float val2);
float cambioCliente(float a, float b);
float descuentos(float suma);
int sugerenciaCambio(int cambio);


// namespaces para c++
using namespace std;

/*funcion principal main*/
int main(void){

/*Declaración de variables locales de main*/
	int opc,a=1;
	float nCom,suma=0,descuento, cobrar, pago, cambio;
	int cantidad ;
	double sugerencia;


/* arreglo de tienda*/
	char supNom[30]="King's  Market";
	char supLem[30]="Donde el cliente manda";
	char supDir[200]="\n\t\t\t* Sucursal 2144:\n\t\t\t*Insurgentes Sur 3579, DF Tel:5878414* *";
	char supVen[50]="\n\t\t\t* Le atendio 1454 Carlos Fuentes *\n\n\n";

/*arreglo de cajero*/
	int numCaj=1454;
	char nomCaj[20]="Carlos";
	char apCaj[30]="Fuentes Fuentes";
	char mensaje[50]="\n\n\t\t***Gracias por su preferencia***";
/*-------------------------------------------------------------------------------------------------------------*/



system("cls"); /* limpiador de pantalla*/
/* Datos de super mercado*/
	cout<<"\n\t\t\t\t\t%s\n\n"<<supNom;
	cout<<"\t\t\t\t``"<<supLem<<"``\n\n";
	cout<<"\t\t\t\t\tHola Usuario...\n\n";


/*Menu del programa*/
	cout<<"Menu\n1-Caja\n2-Salir\n\n\tElige una opcion: ";
	cin>>opc;
	switch(opc) /* seleccion multimple */
	{
		case 1:
					system("cls");
					cout<<"Captura de datos del cliente...\n\nId: ";
					cin>>usu.numCli;
					cout<<"\nIngresa nombre: ";
					cin>>usu.nomCli;
					cout<<"\nIngresa Apellido paterno: ";
					cin>>usu.apPat;
					cout<<"\nIngresa Apellido materno: ";
					cin>>usu.apMat;
					cout<<endl;
					system("pause>null");
					system("cls");
		
					do{ /*ciclo hacer mientras*/
		
						cout<<"Captura de compras...";
						cout<<"\n\n\t\tSuma de compras es: $"<<suma<<" pesos/centavos\n\n";
						cout<<"\n\nIngrese 00 para terminar\n\n\tIngrese $compra numero: "<<a++<<": ";
						cin>>nCom;
						cout<<"\n\n\t\tSuma de compras es: $"<<suma<<" pesos/centavos";
						suma=suma+nCom; /* Acomulador de compras*/
						system("cls");
					}
					
		while(nCom != 00);
		cout<<"\n\n\t\tSuma de compras es: $"<<suma<<" pesos/centavos\n\n";
		
		
		/*Toma de decición sobre descuento invocando al modulo descuentos*/
		descuento=descuentos(suma);
		
		/* Calculo de cobro invocando al módulo cobrarCliente*/
		cobrar=cobrarCliente(suma, descuento);
					/* Mensaje de cobro*/
					cout<<"\n\n\t\tCobrar $"<<cobrar;
					/* Mensaje para ingresar pago*/
					cout<<"\n\nIngrese pago: ";
					cin>>pago;
		
		/* calculo de cambio invocando al modulo cambioCliente*/
		cambio=cambioCliente(pago, cobrar);
				cout<<"\n\n El monto de su cambio es: "<<cambio;
		/*sugerencia de cambio con rendondeo invocando al módulo sugerenciaCambio*/
		sugerencia=sugerenciaCambio(cambio);
				system("pause>nul");
		
		
		
		/* Ticket*/
				system("cls");
				cout<<"\t*****************************************************************";
				cout<<"\n\n\t\t\t***** "<<supNom<<" *****\n\n";
			    cout<<"\n\n\t\t* Cliente:\n\t\t"<<usu.numCli<<"  "<<usu.nomCli<<"  "<<usu.apPat<<"  "<<usu.apMat<<" *";
				cout<<"\n\n\t\t* Suma de compras es: $"<<suma<<" *";
				cout<<"\n\t\t* Descuento aplicado es: $"<<descuento<<" *";
				cout<<"\n\t\t* Se le cobro: $"<<cobrar<<" *";
				cout<<"\n\t\t* Efectivo: $"<<pago<<" *";
				cout<<"\n\t\t* Su cambio es: $"<<cambio<<" *";
				//puts(mensaje);/* impresion de cadena puts*/
				cout<<"%s",supDir;
				cout<<"\n\t\t\t* Le atendio "<<numCaj<<" "<<nomCaj<<" "<<apCaj<<" *\n\n\n";
				cout<<"\t*****************************************************************\n\n";
				system("pause>null"); /* hace una pausa */
				return(main()); /* regresa al Menu*/
		break;
		
		case 2:
					system("cls"); /* Limpia pantalla*/
					/* Mensaje de salida*/
					cout<<"\n\n\n\t\t*****************************************";
					cout<<"\n\n\n\t\t*   Un placer servirle...Hasta Pronto    *\n";
					cout<<"\n\n\n\t\t*****************************************\n\n\n";
					return(0); /* cierra programa*/
		break;
		
		default:
					system("cls"); /* Limpia pantalla*/
					/* Mensaje de erro*/
					cout<<"\n\n\n\t\t******************************************";
					cout<<"\n\n\n\t\t* Opcion invalida...Intentelo nuevamente *\n";
					cout<<"\n\n\n\t\t******************************************\n\n\n";
					system("pause>null"); /* hace una pausa*/
					return (main());/* regresa al Menu*/
		
			}/* fin switch*/
		
		}/* fin main*/
		
		/* Implementación de funciones */
		
		float cobrarCliente (float val1, float val2){	/* parametros val1 y val2 de tipo float*/
			return val1-val2;	/* regresa operacion de cobrar*/
		}/* fin cobrarCliente*/
		
		/*---------------------------------------------------------*/
		float cambioCliente(float a, float b){
			return a-b;		/* regresa operacion de cambio*/
		}/* fin CambioCliente*/
		
		/*----------------------------------------------------------*/
		float descuentos(float suma)
		{ /*parametro suma de tipo float*/
			float descuento; /* variable local descuento*/
			/* decicion de descuento*/
			if(suma<= 499)
			{
					descuento=suma*.5;
					cout<<"\n\n\t\tTu descuento de 5% es $"<<descuento<<" pesos/centavos"; 
			}
			if(suma>= 500 && suma<= 999)
			{
				
					descuento=suma*.10;
					cout<<"\n\n\t\tTu descuento de 10% es $"<<descuento<<" pesos/centavos"; 
			}
			if(suma>=1000)	
			{
					descuento=suma*.15;
					cout<<"\n\n\t\tTu descuento de 15% es $"<<descuento<<" pesos/centavos";
			}
			return descuento; /* regresa a descuento*/
		}/* fin descuentos*/
		
		int sugerenciaCambio(int cambio){ /* parametro cambio de tipo int*/
		/*Calculamos el cambio y lo devolvemos*/
		cout<<"\n\n Sugerencia de cambio con redondeo "<<cambio;
		cout<<endl;
		cout<<"\n\t"<<cambio/200<<" billetes de $200";
		cambio = cambio%200;
		cout<<"\n\t"<<cambio/100<<" billetes de $100";
		cambio = cambio%100;
		cout<<"\n\t"<<cambio/50<<" billetes de $50";
		cambio = cambio%50;
		cout<<"\n\t"<<cambio/20<<" billetes de $20";
		cambio = cambio%20;
		cout<<"\n\t"<<cambio/10<<" monedas de $10";
		cambio = cambio%10;
		cout<<"\n\t"<<cambio/5<<" monedas de $5";
		cambio = cambio%5;
		cout<<"\n\t"<<cambio/2<<" monedas de $2";
		cambio = cambio%2;
		cout<<"\n\t"<<cambio<<" monedas de $1";
		cout<<endl;
			return cambio; /* regresa a cambio*/
}/* Fin sugerenciaCambio*/


