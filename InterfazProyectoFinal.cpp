/*
UNIVERSIDAD DISTRITAL FRANCISCO JOS� DE CALDAS
			PROGRAMACI�N B�SICA
			   PROYECTO FINAL 
					2022
					
Titulo: Interfaz
Autoras: 
		-Heylin Daniela Hern�ndez P�rez
		-Laura Daniela Mu�oz Ipus
		-Ana Laura Morcote Chac�n
		
Docente: Fernando Mart�nez Rodriguez
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
    cout<<"\n\n\n\t\t\t\t\t\t\t\tUNIVERSIDAD DISTRITAL FRANCISCO JOS� DE CALDAS \t\t\t\t\t\t\t\t\n";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole,49);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t      PROGRAMACI�N B�SICA \t\t\t\t\t\t\t\t\t\t";
    color(hConsole,60);
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t Proyecto #2: VOTO ELECTR�NICO \t\t\t\t\t\t\t\t\n";
    color(hConsole,63);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Integrantes \t\t\t\t\t\t\t\t\n";
    color(hConsole,61);
    cout<<"\n\t\t\t\t\t\t\t        Heylin Daniela Hern�ndez P�rez   20221020006 \t\t\t\t\t\t\t\t\t\t";
    color(hConsole,61);
    cout<<"\n\t\t\t\t\t\t\t\t    Ana Laura Morcote Chac�n   20221020010\t\t\t\t\t\t\t\t\t\t";
    color(hConsole,61);
    cout<<"\n\t\t\t\t\t\t\t\t    Laura Daniela Mu�oz Ipus   20221020022\t\t\t\t\t\t\t\t\t\t\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t  \t\t\t\t\t\t\t\t\t\t";
    color(hConsole,63);
    cout<<"\t\t\t\t\t\t\t �BIENVENIDOS!  \t\t\t\t\t\t\t\t\n\n\n";
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
   //Incio del Men� que ve el usuario
	menu();

    getchar();
	system("cls");  
}

//desarrollo de las funciones

void menu(){
	int opcion;
	do{
		system("cls");
		cout<<"\n\tMen� de opciones: �A d�nde desea ingresar?"<<endl;
		cout<<"\t1.Formulario de Inscripci�n"<<endl;
		cout<<"\t2.Formulario de Votaci�n"<<endl;
		cout<<"\t3.Muestra de resultados"<<endl;
		cout<<"\t\tElige una opci�n: ";
		cin>>opcion;
		if(cin.fail()){
			cout<<"Ingrese n�meros, por favor.\n"<<endl;
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
	    cout<<"\t\tIngresaste una opci�n no v�lida"<<endl;			    //Aviso de validaci�n
	    system("PAUSE");
		menu();
	    break;
	}
}
