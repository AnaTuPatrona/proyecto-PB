/*
UNIVERSIDAD DISTRITAL FRANCISCO JOS� DE CALDAS
			PROGRAMACI�N B�SICA
			   PROYECTO FINAL 
					2022
					
Titulo: Formulario de votaci�n
Autoras: 
		-Heylin Daniela Hern�ndez P�rez
		-Laura Daniela Mu�oz Ipus
		-Ana Laura Morcote Chac�n
		
Docente: Fernando Mart�nez Rodriguez


***ESTRUCTURA DEL TXT***

		DOCUMENTO   <-----  si el documento tiene al lado una arroba (@) significa que dicha persona ha cometido un delito. 
							Si el documento tiene '&' significa que dicha persona es militar activo.
		  - � --    <-----  un s�lo gui�n (-) significa que la persona no ha votado, dos guiones (--) significan que la persona ya vot�
		APELLIDO
		NOMBRE
		 EDAD
	  SEPARADOR (****)

*/

// LIBRER�AS

#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//PROTOTIPO FUNCIONES

bool buscar(string a); //busca el documento
void recogerNombre(string a); //Recolecta nombres y apellidos de una persona
void error(int a); //retorna un mensaje de error dependiendo de ciertas circunstancias
void recogerCandidato(); //recolecta los datos de los candidatos
void menu();//abre el menu
void actualizarDatos(int a); //actualiza la cantidad de votos de los candidatos
void usuarioVoto(string a, int b); //actualiza el estado de votaci�n de una persona
int llenarArreglo(); //recolecta los datos de las personas inscritas

//REGISTROS

struct candidatos{
	char nombre[40];
	char apellido[45];
	int votos;
};

struct persona{
	char documento[13];
	char yaVoto[3];
	char apellidos[40];
	char nombres[40];
	char edad[3];
};

candidatos candidato[5]; //arreglo donde se almacenan las 5 candidatas, es de tipo "candidatos" (estructura)
vector<persona>votante; //vector donde se almacenan las personas inscritas para votar, es de tipo "persona" (estructura)
persona recoleccionVotante; //variable donde se almacena de manera temporal los datos del votante que se est� leyendo, 
							//para posteriormente con la funci�n "push_back" agregarla al vector.

//FUNCI�N PRINCIPAL

main(){
	
	system("color 1F");     //Da color al programa
	setlocale(LC_ALL, "spanish");
		
	int repetir=1, tamDoc=0, indiceVoto=0;
	bool docValido=false, docLetras=false;
	string doc=" ";
	do{	
		votante.clear();//limpia el vector "votante" con cada ejecuci�n
		do{			
			docLetras=false; //establece a la variable que verifica si una c�dula est� inscrita o no como 'false'
			menu();			
			cout<<"Ingrese su documento (8-10 n�meros): "; //Se pide si se recolecta el documento.
			cin>>doc;
			cin.ignore();
			tamDoc=doc.size(); //tamDoc guarda la longitud del documento que se acaba de ingresar
				for(int i=0;i<=tamDoc-1;i++){ //recorre cada posici�n del arreglo
				if(!isdigit(doc[i])){ //si se detecta que alg�n caracter NO es un n�mero (con !isdigit()), establece a docLetras como 'true'.
					docLetras=true; 
					break; //rompe el ciclo prematuramente si se cumple la condici�n que se explic� arriba;
				}
				
			} //fin del ciclo
		
			if(tamDoc>10 || tamDoc<8 || docLetras==true){ //si detecta que la longitud del documento ingresado es menor a 8 o mayor a 10, o se encontraron caracteres que NO son nn�meros, imprime:
				cout<<"El documento que usted ingres� no es v�lido por alguna de las siguientes razones:\n1.El documento no consta de 8 a 10 caracteres\n2.Contiene caracteres como: letras, puntos o comas\nPor favor, ingrese nuevamente el documento.\n"<<endl;
				system("PAUSE"); //Se presiona una tecla para continuar
			}
		
		}while(tamDoc>10 || tamDoc<8 || docLetras==true); //si detecta que la longitud del documento ingresado es menor a 8 o mayor a 10, o se encontraron caracteres que NO son nn�meros, se vuelve a realizar el proceso.			
		docValido=buscar(doc); //establece la variable que me indica si un documento puede ser inscrito o no como el valor que retorne 'buscar'
		if(docValido==true) { // si el documento es v�lido, se procede a:
			do{ //inicio de do while para validar si se ingres� un candidato correcto.
			cout<<"Bienvenido/a se�or(a) ";
			recogerNombre(doc); //llamar la funci�n de recolecci�n de nombre
			cout<<". Ingrese el �ndice del candidato por el que desea votar.\n"<<endl; //pregunta por qui�n se desea votar
			recogerCandidato(); //llamar la funci�n de recolecci�n de candidatos.
			for (int i=0;i<5;i++){
				cout<<"\t"<<i+1<<". "<<candidato[i].apellido<<" "<<candidato[i].nombre<<endl; //imprime el nombre del candidato junto con un �ndice.
			}
			cin>>indiceVoto; //pide el �ndice de la persona por la que se desea votar
			if(indiceVoto<1 || indiceVoto>5 || cin.fail()){ //verifica que se ingrese una opci�n v�lida
				cout<<"Ingrese una opci�n v�lida, por favor.\n"<<endl;
				cin.clear();
				cin.ignore();
				repetir=-1;
				system("PAUSE");
				menu();				
			}
			}while(indiceVoto<1 || indiceVoto>5 || cin.fail()); //fin del do while
			cin.clear(); //limpia la entrada
			actualizarDatos(indiceVoto-1); //actualiza los votos
			usuarioVoto(doc, llenarArreglo()); //llena el vector "votante" y actualiza el estado de votaci�n de la persona de la que se ingres� la c�dula (pasa de "-" a "--")
		}
			
		do{
			cout<<"\n\n�Le gustar�a repetir el programa?\n1.Si\n2.No"<<endl; //pregunta al usuario si le gustar�a repetir el programa
				cin>>repetir;
				
			if(repetir<1 || repetir>2 || cin.fail()){ //si no se ingresa un dato que sea 1,2 o un dato que no sea tipo int, pide ingresar una opci�n v�lida
				cout<<"Ingrese una opci�n v�lida, por favor."<<endl;
				cin.clear();
				cin.ignore();
				repetir=-1;
			}
		
		}while(repetir<1 || repetir>2 || cin.fail()); //pregunta de nuevo en caso de que se ingrese una opci�n inv�lida
		
	}while(repetir==1);
	
	system("cls"); 
	system("InterfazProyectoFinal.exe"); //se retorna al men�
}


//FUNCIONES

void menu(){ //funci�n de men�
	system("cls");		
	cout<<"\t\t\t***FORMULARIO DE VOTACI�N***\n"<<endl;
	cout<<"En este formulario podr� votar. Este proceso es completamente an�nimo.\n\n";	
	return;
}

int llenarArreglo(){ //funci�n que recolecta los datos de las personas inscritas y los guarda en el vector "votante".
	string linea;
	ifstream data;
	int i=-1, len=0; //"i" es el total de personas que hay y "len" es la longitud de la linea que se est� leyendo
	data.open("datos.txt", ios::app); //abre la base de datos (archivo txt) en modo lectura y escritura			
	if(data.is_open()){ //hace el ciclo cuando el archivo est� abierto
		while(!data.eof() && getline(data,linea)!=NULL){ //se recorre el archivo mientras no sea el final de este y la linea actual no est� vac�a
			i=i+1;
		//	getline(data,linea); //obtiene la linea actual donde est� ubicado el cursor en el archivo.
			len=linea.size();
			for(int j=0;j<len;j++){ //guarda temporalmente el documento
				recoleccionVotante.documento[j]=linea[j];
			}
			getline(data,linea);
			len=linea.size();
			for(int j=0;j<len;j++){ //guarda temporalmente el estado de votaci�n
				recoleccionVotante.yaVoto[j]=linea[j];
			}			
			getline(data,linea);
			len=linea.size();
			for(int j=0;j<len;j++){ //guarda temporalmente los apellidos
				recoleccionVotante.apellidos[j]=linea[j];
			}
			getline(data,linea);
			len=linea.size();
			for(int j=0;j<len;j++){ //guarda temporalmente los nombres
				recoleccionVotante.nombres[j]=linea[j];
			}
			getline(data,linea);
			len=linea.size();
			for(int j=0;j<len;j++){ //guarda temporalmente la edad
				recoleccionVotante.edad[j]=linea[j];
			}
			
			
			votante.push_back(recoleccionVotante); //a�ade al vector "votante" todos los datos que se guardaron en la estructura "recoleccionVotante"
			
			//limpia los datos de recoleccionVotante para guardar otros
			for(int j=0;j<13;j++){
				recoleccionVotante.documento[j]=NULL;
			}

			for(int j=0;j<3;j++){
				recoleccionVotante.yaVoto[j]=NULL;
			}			

			for(int j=0;j<40;j++){
				recoleccionVotante.apellidos[j]=NULL;
			}

			for(int j=0;j<40;j++){
				recoleccionVotante.nombres[j]=NULL;
			}

			for(int j=0;j<3;j++){
				recoleccionVotante.edad[j]=NULL;
			}			
			
			getline(data,linea);																				
		}		
		}
		data.close();				
		return i;
}


bool buscar(string doc){ //funci�n que busca el documento dentro del archivo de texto para verificar si este ya est� inscrito o no
	string linea, docMilitar, docDeli;
	int num, edad=0;
	stringstream ss;
	fstream data;
	
	docMilitar=doc+'&';
	docDeli=doc+'@';	
	
	ss.clear();		
	data.open("datos.txt", ios::in|ios::out); //abre la base de datos (archivo txt) en modo lectura y escritura
	if(data.is_open()){ //hace el ciclo cuando el archivo est� abierto
		while(!data.eof()){ //se recorre el archivo mientras no sea el final de este
			getline(data,linea); //obtiene la linea actual donde est� ubicado el cursor en el archivo.			
			if((num=linea.find(docMilitar,0))!=string::npos){ //si se reconoce que el documento ingresado es de un militar:
				error(1); //llama a "error" con 1 como argumento
				data.close();
				return false;
			}
			else if(((num=linea.find(docDeli,0))!=string::npos)){ //si se reconoce que el documento ingresado es de alguien con antecedentes penales:
				error(2); //llama a "error" con 2 como argumento
				data.close();
				return false;
			}

			else if((num=linea.find(doc,0))!=string::npos){
				for(int j=1; getline(data, linea) && j<5;j++){
					if(j==1 && linea=="--"){ //si se reconoce que el usuario ya ejerci� su derecho al voto:
					error(3); //llama a "error" con 3 como argumento
					data.close();
					return false;						
					}
					else if(j==4){
						ss<<linea;
						ss>>num;
						if(num<18){ //si se reconoce que el usuario es menor de edad:
							error(4); //llama a "error" con 4 como argumento
							data.close();
							return false;							
						}
					}
				}
		    	cout<<"\n"<<endl;				
				data.close();
				return true;	//si todo est� en orden, retorna true							
			}			
		}
		cout<<"No se encontr� el documento en la base de datos. Asegurese de que se haya inscrito en el formulario de inscripci�n."<<endl;				
		data.close();
		return false;	//si no se encontr� el documento, retorna al men� principal
	}	
			
}
	

void recogerNombre(string doc){ //recoge el nombre del ususario
	string linea;
	int num;
	fstream data;
	
	data.open("datos.txt", ios::in|ios::out); //abre la base de datos (archivo txt) en modo lectura y escritura
	if(data.is_open()){ //hace el ciclo cuando el archivo est� abierto
		while(!data.eof()){ //se recorre el archivo mientras no sea el final de este
			getline(data,linea); //obtiene la linea actual donde est� ubicado el cursor en el archivo.
			if((num=linea.find(doc,0))!=string::npos){	//si se detecta que el documento ingresado ya est� en el documento:	
			for(int j=1; getline(data, linea) && j<4;j++){ //se encarga de ubicar el apellido y nombre, imprimiendolos
				if(j>1){
					cout<<linea<<" ";
				}
			}	
				data.close(); //cierra el archivo 
				return;
			}
		}
		data.close(); //si el ciclo termina sin encontrar el documento, cierra el archivo
		return;		
}
}

void error(int nError){ //muestra un error dependiendo del paramentro suministrado
	if(nError==1){
		cout<<"Usted no puede votar, debido a que: ES MILITAR ACTIVO.\n"<<endl;
	}
	else if(nError==2){
		cout<<"Usted no puede votar, debido a que: TIENE ANTECEDENTES PENALES.\n"<<endl;
	}
	else if(nError==3){
		cout<<"Usted no puede votar, debido a que: YA VOT�.\n"<<endl;
	}
	else if(nError==4){
		cout<<"Usted no puede votar, debido a que: ES MENOR DE EDAD.\n"<<endl;
	}
	return;
}

void recogerCandidato(){ //recoge los datos de los candidatos y los guarda en el arreglo "candidato"
	stringstream ss; //me permite trasformar texto a n�meros
	fstream cand;
	string linea;
	int len=0;
	
	cand.open("resultados.txt", ios::in|ios::out); //abre el archivo "resultados.txt"
		for(int i=0;i<5;i++){ //realiza este proceso 5 veces. Del 0 al 4
			ss.clear(); //limpia ss
			getline(cand, linea); //Avanza y obtiene la linea actual 
			len=linea.size(); //obtiene la longitud de la linea
			for(int j=0; j<len; j++){ //guarda el nombre del candidato con el indice "i"
				candidato[i].nombre[j]=linea[j];	
			}
			getline(cand, linea);
			len=linea.size();
			for(int j=0; j<len; j++){ //guarda el apellido del candidato con el indice "i"
				candidato[i].apellido[j]=linea[j];
			}
			getline(cand, linea);
			ss<<linea;
			ss>>candidato[i].votos; //guarda los votos del candidato con indice "i"
		}
	cand.close();	
}

void actualizarDatos(int i){ //actualiza los votos
	fstream cand;
	int total=0;
	
	candidato[i].votos=candidato[i].votos+1; //dependiendo del argumento suministrado, le suma a un voto a dicho candidato
	
	for(int j=0; j<5;j++){ //suma todos los votos para sacar el total
		total=total+candidato[j].votos;
	}	
	cand.open("resultados.txt"); //abre "resultados.txt"
	for(int j=0; j<5;j++){
		cand<<candidato[j].nombre<<"\n"<<candidato[j].apellido<<"\n"<<candidato[j].votos<<"\n"; //guarda los datos que est�n en el arreglo en el txt
	}
	cand<<"TOTAL\n"<<total; //luego, guarda el total.
	cand.close();
}

void usuarioVoto(string doc, int total){ //dependiendo del "i" que retorne llenarArreglo, busca i veces entre el vectos ubicando de quien es la c�dula que acaba de votar.
	int n, indice=0;
	fstream data;
	
	for(int i=0; i<=total; i++){ 
		n=0; //cada vez que se haga el ciclo de arriba, n se establecer� como 0
		for(int j=0; j<=doc.size(); j++){  //compara caracteres
			if(votante[i].documento[j]==doc[j]){ //si estos coinciden: n=n+1
				n=n+1;
			}
			if(n==doc.size()){ //si n es igual a el tama�o del documento del usuario, rompe el ciclo
				break;
			}
		}
		if(n==doc.size()){ //si n es igual a el tama�o del documento del usuario, hace que indice sea igual a i
			indice=i;
			break;
		}		
	}
	votante[indice].yaVoto[1]='-'; //a�ade un gui�n al registro con indice "indice" un gui�n. Dejando el campo c�mo "--"
	data.open("datos.txt"); //abre datos.txt
	
	for(int j=0; j<=total;j++){ //actualiza el documento con los datos del vector
		data<<votante[j].documento<<"\n"<<votante[j].yaVoto<<"\n"<<votante[j].apellidos<<"\n"<<votante[j].nombres<<"\n"<<votante[j].edad<<"\n*****\n";
	}	
	cout<<"Su voto fue registrado con �xito."<<endl;
}	
