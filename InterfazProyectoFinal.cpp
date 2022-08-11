/*
UNIVERSIDAD DISTRITAL FRANCISCO JOSÉ DE CALDAS
			PROGRAMACIÓN BÁSICA
			   PROYECTO FINAL 
					2022
					
Titulo: Interfaz
Autoras: 
		-Heylin Daniela Hernández Pérez
		-Laura Daniela Muñoz Ipus
		-Ana Laura Morcote Chacón
		
Docente: Fernando Martínez Rodriguez
*/

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include <locale.h>
#include <windows.h>

#define color SetConsoleTextAttribute

//PROTOTIPO FUNCIONES

void menu();
void seleccionar(int a);

using namespace std;

int main(){
	int opcion;
	setlocale(LC_ALL,"spanish");
	system("color 3F");
    cout<<"\n\n\n\t\t\t\t\t\t\t\tUNIVERSIDAD DISTRITAL FRANCISCO JOSÉ DE CALDAS \t\t\t\t\t\t\t\t\n";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole,49);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t      PROGRAMACIÓN BÁSICA \t\t\t\t\t\t\t\t\t\t";
    color(hConsole,60);
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t Proyecto #2: VOTO ELECTRÓNICO \t\t\t\t\t\t\t\t\n";
    color(hConsole,63);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Integrantes \t\t\t\t\t\t\t\t\n";
    color(hConsole,61);
    cout<<"\n\t\t\t\t\t\t\t        Heylin Daniela Hernández Pérez   20221020006 \t\t\t\t\t\t\t\t\t\t";
    color(hConsole,61);
    cout<<"\n\t\t\t\t\t\t\t\t    Ana Laura Morcote Chacón   20221020010\t\t\t\t\t\t\t\t\t\t";
    color(hConsole,61);
    cout<<"\n\t\t\t\t\t\t\t\t    Laura Daniela Muñoz Ipus   20221020022\t\t\t\t\t\t\t\t\t\t\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t  \t\t\t\t\t\t\t\t\t\t";
    color(hConsole,63);
    cout<<"\t\t\t\t\t\t\t ¡BIENVENIDOS!  \t\t\t\t\t\t\t\t\n\n\n";
    color(hConsole,52);
    cout<<"\t\t\t\t\t\t\t\t\t  ****      ****  **********    \n";
    cout<<"\t\t\t\t\t\t\t\t\t  ****      ****  ************    \n";
    cout<<"\t\t\t\t\t\t\t\t\t  ****      ****  ***     *****   \n";
    cout<<"\t\t\t\t\t\t\t\t\t  ****      ****  ***      *****  \n";
	cout<<"\t\t\t\t\t\t\t\t\t  ****      ****  ***      *****  \n";
    cout<<"\t\t\t\t\t\t\t\t\t  ****      ****  ***     *****    \n";
    cout<<"\t\t\t\t\t\t\t\t\t  **************  ***********    \n";
    cout<<"\t\t\t\t\t\t\t\t\t  **************  **********    \n\n";
    color(hConsole,62);
    
    system("PAUSE"); //Se presiona una tecla para continuar
   //Incio del Menú que ve el usuario
	menu();

    getchar();
	system("cls");  
}

//desarrollo de las funciones

void menu(){
	int opcion;
	do{
		system("cls");
		cout<<"\n\tMenú de opciones: ¿A dónde desea ingresar?"<<endl;
		cout<<"\t1.Formulario de Inscripción"<<endl;
		cout<<"\t2.Formulario de Votación"<<endl;
		cout<<"\t3.Muestra de resultados"<<endl;
		cout<<"\t\tElige una opción: ";
		cin>>opcion;
		if(cin.fail()){
			cout<<"Ingrese números, por favor.\n"<<endl;
			cin.clear();
			cin.ignore();
			opcion=-255;
			system("PAUSE"); 
		}
	}while(opcion==-255);
	seleccionar(opcion);
}

void seleccionar(int a){
	switch(a){                                                  //Uso del Switch
	        
		case 1:
		system("formInscripcion.exe");
	    break;
	        
		case 2:
	    system("formVotacion.exe");
	    break;
	       
		case 3:
	    system("muestraResultados.exe");
	    break;
	    
		default:
	    cout<<"\t\tIngresaste una opción no válida"<<endl;			    //Aviso de validación
	    system("PAUSE");
		menu();
	    break;
	}
}
