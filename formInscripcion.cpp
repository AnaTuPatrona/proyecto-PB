/*
UNIVERSIDAD DISTRITAL FRANCISCO JOSÉ DE CALDAS
			PROGRAMACIÓN BÁSICA
			   PROYECTO FINAL 
					2022
					
Titulo: Formulario de inscripción
Autoras: 
		-Heylin Daniela Hernández Pérez
		-Laura Daniela Muñoz Ipus
		-Ana Laura Morcote Chacón
		
Docente: Fernando Martínez Rodriguez


***ESTRUCTURA DEL TXT***

		DOCUMENTO   <-----  si el documento tiene al lado una arroba (@) significa que dicha persona ha cometido un delito. 
							Si el documento tiene '&' significa que dicha persona es militar activo.
		  - ó --    <-----  un sólo guión (-) significa que la persona no ha votado, dos guiones (--) significan que la persona ya votó
		APELLIDO
		NOMBRE
		 EDAD
	  SEPARADOR (****)

*/

// LIBRERÍAS

#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//PROTOTIPO DE LAS FUNCIONES

void escribir(string a);  //función que se encarga de escribir los datos en el txt
bool buscar(string a);   //función que se encarga de averiguar si un documento está ya inscrito o no
void error(int a);		//función indica las razones por las cuales no se puede realizar la inscripción

// FUNCIÓN PRINCIPAL

main(){
	
	system("color 7D");     //Da color al programa
	//Variables:
	string doc=" ";	//donde se guarda el documento	
	bool docValido=false, docLetras; //variable en la que se guarda si un documento está inscrito (false) o está disponible (true). 
									 //Y variable en la de se detecta si hay caracteres tipo alfa en el documento que ingresó el usuario
	int tamDoc, repetir=0; //variable que almacena la longitud del documento ingresado. Y variable de control para repetir el programa (1=Repetir;2=No repetir)
	
	setlocale(LC_ALL, "spanish"); //Me permite utilizar tildes en mi programa
	
	do{ //Inicio ciclo de repetición del programa
		do{ //ciclo de control de ingreso de un documento válido. (Documento válido: de 8 a 10 caracteres y sin caracteres que NO sean números)
			system("cls");//Limpia la pantalla cada que se ejecute el ciclo
			docLetras=false; //establece a la variable que verifica si una cédula está inscrita o no como 'false'
			cout<<"\t\t\t***FORMULARIO DE INSCRIPCIÓN***\n"<<endl;
			cout<<"En este formulario podrá inscribir su documento para estar habilitado en las votaciones. \n\n";
			cout<<"Ingrese su documento (8-10 números): "; //Se pide si se recolecta el documento.
			cin>>doc;
			cin.ignore();
			tamDoc=doc.size(); //tamDoc guarda la longitud del documento que se acaba de ingresar
				for(int i=0;i<=tamDoc-1;i++){ //recorre cada posición del arreglo
				if(!isdigit(doc[i])){ //si se detecta que algún caracter NO es un número (con !isdigit()), establece a docLetras como 'true'.
					docLetras=true; 
					break; //rompe el ciclo prematuramente si se cumple la condición que se explicó arriba;
				}
			} //fin del ciclo
		
			if(tamDoc>10 || tamDoc<8 || docLetras==true){ //si detecta que la longitud del documento ingresado es menor a 8 o mayor a 10, o se encontraron caracteres que NO son nnúmeros, imprime:
				cout<<"El documento que usted ingresó no es válido por alguna de las siguientes razones:\n1.El documento no consta de 8 a 10 caracteres\n2.Contiene caracteres como: letras, puntos o comas\nPor favor, ingrese nuevamente el documento.\n"<<endl;
				system("PAUSE"); //Se presiona una tecla para continuar
			}
		
		}while(tamDoc>10 || tamDoc<8 || docLetras==true); //si detecta que la longitud del documento ingresado es menor a 8 o mayor a 10, o se encontraron caracteres que NO son nnúmeros, se vuelve a realizar el proceso.
	
	
	
		docValido=buscar(doc); //establece la variable que me indica si un documento puede ser inscrito o no como el valor que retorne 'buscar'
		if(docValido==true){ // si el documento es válido, se procede a llamar a la función 'escribir', mandando cómo parametro al documento ingresado.
				escribir(doc);
		}
		else{ //por el contrario, si el documento ya está inscrito, notifica al usuario.
			cout<<"El documento que intenta registrar ya está inscrito.\n"<<endl;
			system("PAUSE"); //se pide presonar una letra para continuar con el programa
		}
		do{
			cout<<"\n\n¿Le gustaría repetir el programa?\n1.Si\n2.No"<<endl; //pregunta al usuario si le gustaría repetir el programa
				cin>>repetir;
				
			if(repetir<1 || repetir>2 || cin.fail()){ //si no se ingresa un dato que sea 1,2 o un dato que no sea tipo int, pide ingresar una opción válida
				cout<<"Ingrese una opción válida, por favor."<<endl;
				cin.clear();
				cin.ignore();
				repetir=-1;
			}
			
		}while(repetir<1 || repetir>2 || cin.fail()); //pregunta de nuevo en caso de que se ingrese una opción inválida
			
	}while(repetir==1); //Fin de ciclo de repetición del programa
	system("cls"); 
	system("InterfazProyectoFinal.exe"); //se retorna al menú
	
 }
 
 
 //FUNCIONES
 
bool buscar(string doc){ //función que busca el documento dentro del archivo de texto para verificar si este ya está inscrito o no
	string linea;
	int num;
	fstream data;
	
	data.open("datos.txt", ios::in|ios::out); //abre la base de datos (archivo txt) en modo lectura y escritura
	if(data.is_open()){ //hace el ciclo cuando el archivo esté abierto
		while(!data.eof()){ //se recorre el archivo mientras no sea el final de este
			getline(data,linea); //obtiene la linea actual donde está ubicado el cursor en el archivo.
			if((num=linea.find(doc,0))!=string::npos){	//si se detecta que el documento ingresado ya está en el documento:		
				data.close(); //cierra el archivo 
				return false; //y retorna docValido como false
			}
		}
		data.close(); //si el ciclo termina sin encontrar el documento, cierra el archivo
		return true; //y retorna a docValido como true
	}
	
	
}
void escribir(string doc){ //funcion que se encarga de recolectar los datos, y si se cumplen las condiciones de inscripción 
							//(mayor de 18, no ser militar activo y no tener antecedentes penales), inscribe la cédula para votar
	
	string nombre=" ", ape=" "; //string donde se guarda el nombre y el apellido respectivamente
	bool apellidoInv=false, nombreInv=false; //booleanos que verifican si un apellido es válido (false) o inválido (true)
	int edad=0, militar=0, delitos=0; //acá se guarda la edad, si se es militar activo (1. Si; 2. No) o si se tiene antecedentes penales (1. Si; 2. No) respectivamente
	
	ofstream data;	//se hace una variable tipo archivo llamada 'data'
	data.open("datos.txt",ios::app); //con data se abre o crea el archivo 'datos' en modo edición
	if(data.fail()){ //si no se puede abrir muestra:
		cout<<"No pude abrir el archivo"<<endl;
		exit(1);
	}

	//ingreso de apellido
	
	do{	//inicio ciclo para verificar la válidez del apellido	
		apellidoInv=false; //establece a apellidoInv como falso cada vez que se realiza el ciclo
		cout<<"Ingrese sus apellidos (sin tíldes): "; //pide ape (variable donde se guarda el apellido)
		getline(cin, ape); 
		for(int i=0;i<=ape.size()-1;i++){ //verifica que los caracteres que tiene 'ape' no sean invalidos
			if(isdigit(ape[i]) || ape[i]=='.' || ape[i]==',' || ape[i]=='?' || ape[i]=='/' || ape[i]=='(' || ape[i]==')' || ape[i]=='!' || ape[i]=='%'){
				cout<<"Entrada Inválida. Su apellido no puede contener números o carácteres especiales."<<endl;
				apellidoInv=true; //en caso de que lo sean, apellidoInv pasa a ser true, y se repite el ciclo do while
				break; //se sale del ciclo for
			}
		}
	}while(apellidoInv==true); //condición

	//ingreso nombre
	
	do{ //se hace el mismo proceso que con el apellido, solo que está vez con la variable 'nombre'
		nombreInv=false;
		cout<<"Ingrese sus nombres (sin tíldes): ";

		getline(cin, nombre);
		for(int i=0;i<=nombre.size()-1;i++){
			if(isdigit(nombre[i]) || nombre[i]=='.' || nombre[i]==',' || nombre[i]=='?' || nombre[i]=='/' || nombre[i]=='(' || nombre[i]==')' || nombre[i]=='!' || nombre[i]=='%'){
				cout<<"Entrada Inválida. Su nombre no puede contener números o carácteres especiales."<<endl;
				nombreInv=true;
				break;
			}			
		}		
	}while(nombreInv==true);
	
	//ingreso de edad
	
	do{			//inicio del ciclo que válida la edad
		cout<<"Ingrese su edad: "; //pide edad
		cin>>edad;		
		if(edad<0 || cin.fail()){ //si la edad es un número negativo, o hay algún error, pide el dato de nuevo
			cout<<"Por favor, NO ingrese caracteres o números menores a 0.\n"<<endl;
			cin.clear();		
			cin.ignore();
			edad=-1;
		}
		
	}while(edad<0 || cin.fail());
	if(edad<18){ //si la edad es menor de 18, invoca a error con 1 cómo argumento
		error(1);
	}
	else{
		
		//Militar o no:
		
		do{ //verifica que se ingrese una opción válida
			cin.clear();
			cin.ignore();
			cout<<"¿Es usted un militar activo?\n1.Sí\n2.No"<<endl;
			cin>>militar;
			if(militar<1 || militar>2 || cin.fail()){
				cout<<"Por favor, ingrese una opción válida\n"<<endl;
			}
		}while(militar<1 || militar>2 || cin.fail());
				
		if(militar==1){ //si sí se es militar, llama a la función error con 2 cómo argumento
			error(2);
		}
		else{
			
			//antecedentes penales o no
			
			do{	//verifica que se ingrese una opción válida
				cout<<"¿Tiene usted antecedentes penales?\n1.Sí\n2.No"<<endl;
				cin>>delitos;
				if(delitos<1 || delitos>2 || cin.fail()){
					cout<<"Por favor, ingrese una opción válida\n"<<endl;
					cin.clear();		
					cin.ignore();
					edad=-1;					
				}
			}while(delitos<1 || delitos>2 || cin.fail());
			if(delitos==1){ //si sí se tiene antecedentes penales, invoca a error con 3 cómo argumento
				error(3);
			}
			else{ //si todo está en orden:
			
				for(int i=0;i<=ape.size()-1;i++){ //convierte todos los caracteres del apellido a mayúsculas
					ape[i]=toupper(ape[i]);
				}
		
				for(int i=0;i<=nombre.size()-1;i++){ //convierte todos los caracteres del nombre a mayúsculas
					nombre[i]=toupper(nombre[i]);
				}		
		
				data<<doc<<"\n-\n"<<ape<<"\n"<<nombre<<"\n"<<edad<<"\n*****"<<endl; //en el documento se guardan los datos de la siguiente manera:
				/*		documento
						-
						apellido
						nombre
						edad
						*****
				*/
				cout<<"Usted fue inscrito correctamente."<<endl;
				data.close();
		}
	}
	}
}

void error(int nError){ //función error
	cout<<"Usted no puede ser inscrito por:"<<endl;
	
	if(nError==1){ //si el argumento es 1
		cout<<"\tSer menor de edad."<<endl;
	}
	
	if(nError==2){ //si el argumento es 2
		cout<<"\tSer militar activo."<<endl;
	}
	if(nError==3){ //si el argumento es 3
		cout<<"\tTener antecedentes penales"<<endl;
	}
}
