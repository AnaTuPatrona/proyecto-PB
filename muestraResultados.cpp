/*
UNIVERSIDAD DISTRITAL FRANCISCO JOSÉ DE CALDAS
			PROGRAMACIÓN BÁSICA
			   PROYECTO FINAL 
					2022
					
Titulo: Muestra de resultados elecciones
Autoras: 
		-Heylin Daniela Hernández Pérez
		-Laura Daniela Muñoz Ipus
		-Ana Laura Morcote Chacón
		
Docente: Fernando Martínez Rodriguez


***ESTRUCTURA DEL TXT (candidatos)***

		NOMBRE 
		APELLIDO
		CANTIDAD DE VOTOS
		(se repiten los campos de arriba hasta que las 5 candidatas estén)
		"TOTAL"
		TOTAL DE VOTOS

*/

// LIBRERÍAS

#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

//PROTOTIPO FUNCIONES
void recogerCandidato();
void votos();

//REGISTROS

struct candidatos{
	char nombre[40];
	char apellido[45];
	int votos;
};

candidatos candidato[5]; //guarda los candidatos
char barra[10]; //muestra barras

main(){
	system("color 0B");     //Da color al programa
	recogerCandidato();
	setlocale(LC_ALL, "spanish");
	system("cls");		
	cout<<"\t\t\t***MUESTRA DE RESULTADOS***\n"<<endl;
	cout<<"En este espacio se puede ver cómo va la resolución de las elecciones hasta el momento.\n\n";
	votos();
	system("PAUSE");
	system("cls"); 
	system("InterfazProyectoFinal.exe"); //retorna a la interfaz inicial
}

void recogerCandidato(){ //recoge los datos de los candidatos (explicación en la misma función de "formVotación". Es exactamente la misma)
	stringstream ss;
	fstream cand;
	string linea;
	int len=0;
	
	cand.open("resultados.txt", ios::in|ios::out);
		for(int i=0;i<5;i++){
			ss.clear();
			getline(cand, linea);
			len=linea.size();
			for(int j=0; j<len; j++){
				candidato[i].nombre[j]=linea[j];	
			}
			getline(cand, linea);
			len=linea.size();
			for(int j=0; j<len; j++){
				candidato[i].apellido[j]=linea[j];
			}
			getline(cand, linea);
			ss<<linea;
			ss>>candidato[i].votos;
		}
	cand.close();	
}
void votos(){ //calcula cómo se mostrarán las barras y las muestra
	float total=0, res=0;
	float porcentaje[5], posBarras[5];
	for(int i=0;i<5;i++){
		total=candidato[i].votos+total; //calcula el total de votos
	}
	for(int i=0; i<5; i++){
		porcentaje[i]=candidato[i].votos*10/total; //guarda el porcentaje de votos de cada candidato
		posBarras[i]=trunc(porcentaje[i]); //genera hasta que poscición del arreglo "barra" se mostrará
	}	
	for(int i=0; i<10;i++){ //llena el arreglo "barra" con "/"
		barra[i]='/';
	}

	//Votos candidatas:
	
	for(int x=0; x<5; x++){ //se hace 5 veces. Del 0 al 4 (indices de las candidatas)
		
		cout<<"\n"<<candidato[x].apellido<<" "<<candidato[x].nombre<<":\n|"; //muestra apellidos y nombres de las candidatas
		
		if(posBarras[x]<1){ //si la posición es menor a 1, no muestra nada:
			cout<<"          |  "<<porcentaje[x]*10<<"% con "<<candidato[x].votos<<" votos."<<endl;
		}
		else{//de otro modo
			res=0; //res se establece como 0
			for(int i=0; i<=posBarras[x]-1;i++){//muestra las barras dependiendo de la posición de barras indicada
				cout<<barra[i];
				res=res+1; //se le suma a res 1
			}
			for(int j=res; j<10;j++){//a partir de res, y mientras j sea menor que 10, se rellena con espacios
				cout<<" ";
			}
			cout<<"|  "<<porcentaje[x]*10<<"% con "<<candidato[x].votos<<" votos."<<endl; //finalmente, muestra el porcentaje en números y cuantos votos tiene aquella candidata
		}
	}
	cout<<"\n\n\t\t\tTOTAL VOTOS: "<<total<<"\n"<<endl; //muestra el total de votos
	return;
}

