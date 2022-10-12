#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
// Creado Por Maikol Alexander Vergara Torres y Sebastian Guarnizo Campos
using namespace std;

	struct RegUsuario{
		char nombre[100];
		char Identificacion[30];
		char email[250];
		char Fecha [15];
	};

	struct mensajesForos{
		char NombreUsuario[100];
		char fecha[25];
		int NoVeces;
	};

	struct listaprivada{
		char Identificacion[30];
		char Tema[100];
	};
	
	struct mesajeCita{
		char ContenidoCita[200];
		char NombreUsuario[100];
		char FechaConHora[30];
		char Identificacion[30];
	};

	struct mensajes{
		char contenidoC[200];
		char NombreUsuario[100];
		char FechaConHora[30];
		struct mesajeCita Cita;
		char Identificacion[30];
	};

	struct RegForos{
		char Tema[100];
		char FechaConHora [30];
		struct mensajes Contenido;
	};
	
/* 	Nombre: 	ConsultarUsuarioPrivacidad
	Objetivo:	Verificar que el usuario este o no este en el archivo de privacidad.dat 
	Entradas:	2 Cadenas de caracteres que son la identifiacion y el nomnbre
	Salidas: 	True o false
*/	
bool ConsultarUsuarioPrivacidad(char IdentificaP[], char NombreF[]);

/* 	Nombre: 	ConsultarUsuario
	Objetivo:	Verificar que el usuario este o no este en el archivo de usuarios.dat
	Entradas:	Una cadenas de caracteres que es la identifiacion del usuario
	Salidas: 	True o false
*/
bool ConsultarUsuario(char IdentificaP[]);	

/* 	Nombre: 	InsertarUsuario
	Objetivo:	Insertar usuario al archivo usuarios.dat
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/	
void InsertarUsuario();

/* 	Nombre: 	ListarUsuario
	Objetivo:	Mostrar los usuarios que estan en el archivo usuarios.dat
	Entradas:	Ninguna
	Salidas: 	Muestra en una tabla los datos de cada uno de los usuarios que estan en el archivo usuarios.dat
*/	
void ListarUsuario();

/* 	Nombre: 	ConsultarUsuario
	Objetivo:	Buscar en el archivo usuarios.dat el usuario con la identifacion digitada
	Entradas:	Ninguna
	Salidas: 	Muestra en una tabla los datos del usuario encontrado que esta en el archivo usuarios.dat
*/	
void ConsultarUsuario();

/* 	Nombre: 	ModificarUsuario 
	Objetivo:	Modificar el nombre, fecha o el correo de un usuario
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/	
void ModificarUsuario ();

/* 	Nombre: 	BorrarUsuario 
	Objetivo:	Borrar un usuario en especifico digitando un numero de identicacion
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void BorrarUsuario ();

/* 	Nombre: 	InsertarForo
	Objetivo:	Menu donde estan todas las opciones de los foros
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void InsertarForo();

/* 	Nombre: 	CrearForo
	Objetivo:	Crea un foro
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void CrearForo();

/* 	Nombre: 	RegForosleer
	Objetivo:	Muestra todos los mensajes de un foro en especifico ordenandolos de menos a mayor por fecha
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void RegForosleer();

/* 	Nombre: 	EscribirMensajesEnElForo
	Objetivo:	Escribir el primer mensaje un foro
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void EscribirMensajesEnElForo();

/* 	Nombre: 	EscribirCitaDeLosMensajesEnElForo
	Objetivo:	Citar un mensaje de un foro filtrandolo por el nombre de quien digito el mensaje y la fecha en la que lo digito
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void EscribirCitaDeLosMensajesEnElForo();

/* 	Nombre: 	EscribirMensajesMasEnElForo
	Objetivo:	Escribir mensajes a un foro
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void EscribirMensajesMasEnElForo();

/* 	Nombre: 	ReporteMensajes
	Objetivo:	Mostrar los 5 usuarios que mas han participado
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void ReporteMensajes();

/* 	Nombre: 	PrivacidadForo
	Objetivo:	Insertar usuario restringido al archivo privacidad.dat
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
void PrivacidadForo();

/* 	Nombre: 	contar
	Objetivo:	Recorre el archivo del foro y cuenta los mensajes que estan ah� para lograr asignar memoria dinamica 
	Entradas:	Ninguna
	Salidas: 	Ninguna
*/
int contar(char cadena[]);


int main(int argc, char** argv) {
	int opcion;
	do{
		system("cls");
		cout << " ================= ADMINISTRACION DE USUARIOS DEL FORO ================="<< endl;
		cout << "	1. Ingresar usuario nuevo" << endl;
		cout << "	2. Listar usuarios"<<endl;
		cout << "	3. Consultar usuario"<<endl;
		cout << "	4. Modificar usuario"<<endl;
		cout<<	"	5. Borrar usuario"<<endl;
		cout<<	"	6. Crear o ingresar a los foros"<<endl;
		cout<<	"	7. ReporteMensajes"<<endl;
		cout<<	"	8. PrivacidadForo"<<endl;
		cout<<	"	9. Salir"<<endl;
		cout  << " Digite opcion: ";
			cin >> opcion;

		switch(opcion){

			case 1 : InsertarUsuario();
			break;

			case 2 : ListarUsuario();
			break;

			case 3 : ConsultarUsuario();
			break;

			case 4 : ModificarUsuario();
			break;

			case 5 : BorrarUsuario ();
			break;

			case 6 : InsertarForo ();
			break;

			case 7 : ReporteMensajes ();
			break;

			case 8 : PrivacidadForo ();
			break;

			case 9 : exit(1);
			break;

			default :
					system("cls");
					cout  << "----------------------ERROR Digite una opcion valida--------------------"<<endl<<endl;
				break;
			}
		}while(opcion!=7);

	return 0;
}

bool ConsultarUsuarioPrivacidad(char IdentificaP[], char NombreF[]){
	struct listaprivada regP;
	bool Encontro=false;

	ifstream archi("Privacidad.dat", ios::binary);
	if(archi){				
		while(!archi.eof() && !Encontro){
		if(archi.read((char*)&regP, sizeof(regP)))
		{
			if(strcmp(IdentificaP, regP.Identificacion)==0 && strcmp(NombreF, regP.Tema)==0)
			{
				Encontro=true;
			}
		}
	}
		if (Encontro){
			return true;
			}else
			return false; 
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios restringidos" << endl;
		system("pause");		
}

bool ConsultarUsuario(char IdentificaP[]){	
	struct RegUsuario regU;
	bool Encontro=false;

	ifstream archi("usuarios.dat", ios::binary);
	if(archi){				
		while(!archi.eof() && !Encontro){
		if(archi.read((char*)&regU , sizeof(regU)))
		{
			if(strcmp(IdentificaP, regU.Identificacion)==0)
			{
				Encontro=true;
			}
		}
	}
		if (Encontro){
			return true;
			}else
			return false; 
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
		system("pause");
		
}

void InsertarUsuario(){
	struct RegUsuario regU;
	system("cls");
	cout <<" ==== INGRESAR USUSARIO NUEVO AL FORO ====" <<endl;
	cout << " Digite el nombre: ";
	cin.ignore(); //Borrar el buffer del teclado
	cin.getline(regU.nombre, sizeof(regU.nombre));
	cout << " Digite el numero de identificacion: ";
	cin >> regU.Identificacion;
	cout << " Digite correo electronico: ";
	cin >> regU.email;
	cout << " Digite la fecha actual con el formato dd/mm/yyyy: ";
	cin.ignore(); //Borrar el buffer del teclado
	cin.getline(regU.Fecha, sizeof(regU.Fecha));

	ofstream archi("usuarios.dat", ios::binary|ios::app);

	if (archi)
	{
		archi.write((char*)&regU, sizeof(regU));
		archi.close();
		cout << " Usuario grabado correctamente!" <<endl;
	}else
		cout << " No se pudo abrir el archivo!"<< endl;

	system("pause");
}

void ListarUsuario(){
	struct RegUsuario regU;
	system("cls");
	cout << " ====================================== LISTA USUARIOS DEL FORO ======================================" << endl << endl;
	ifstream archi("usuarios.dat", ios::binary);
	if(archi){
		cout <<setw(12)<<" Identificacion"<<setw(35)<<"Nombre"<<setw(40)<<"Correo"<<setw(35)<<"Fecha" << endl;
		while(!archi.eof())
		{
			if(archi.read((char*)&regU, sizeof(regU)))
			{
				cout <<setw(12)<<regU.Identificacion <<setw(45) <<regU.nombre <<setw(45) <<regU.email <<setw(30)<< regU.Fecha << endl;
			}
		}
		
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
		system("pause");
}

void ConsultarUsuario(){
	struct RegUsuario regU;
	char Identifica[50];
	bool Encontro=false;

	system("cls");
	cout << " ===== CONSULTAR USARIO DEL FORO =====" << endl << endl;
	cout << " Digite el No. identificacion a buscar: ";
	cin >> Identifica;

	ifstream archi("usuarios.dat", ios::binary);
	if(archi){
				cout <<setw(12)<<" Identificacion"<<setw(35)<<"Nombre"<<setw(40)<<"Correo"<<endl;
		while(!archi.eof() && !Encontro){
		if(archi.read((char*)&regU, sizeof(regU)))
		{
			if(strcmp(Identifica, regU.Identificacion)==0)
			{
				Encontro=true;
			}
		}
	}
		if (Encontro){
			cout <<setw(12)<<regU.Identificacion <<setw(45) <<regU.nombre <<setw(45) <<regU.email<<endl;
			}else
			cout << " No hay un usuario en el foro con esa identificacion" << endl;
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
		system("pause");
}

void ModificarUsuario(){
	struct RegUsuario regU;
	char Identifica[50];
	bool Encontro=false;

	system("cls");
	cout << " ===== MODIFICAR USARIO DEL FORO=====" << endl << endl;
	cout << " Digite el No. identificacion a modificar: ";
	cin >> Identifica;

	fstream archi("usuarios.dat", ios::binary|ios::in|ios::out);
	if(archi){
		cout <<setw(12)<<" Identificacion"<<setw(35)<<"Nombre"<<setw(40)<<"Correo"<<endl;
		while(!archi.eof() && !Encontro)
		{
			if (archi.read((char*)&regU, sizeof(regU))){
			if(strcmp(Identifica, regU.Identificacion)==0)

			{

				Encontro=true;
			}
		}
		}
		if (Encontro){
			cout <<setw(12)<<regU.Identificacion <<setw(45) <<regU.nombre <<setw(45) <<regU.email<<endl;
			cout<<endl<<endl;
			int op;
			cout <<" 1. Para cambiar el nombre" <<endl;
			cout <<" 2. Para cambiar el correo" <<endl;
			cout <<" 3. Para cambiar la fecha" <<endl;
			cout <<"Digite la opcion: ";
				cin>> op; 
			if(op==1){
				cout << "Digite nuevo nombre: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regU.nombre, sizeof(regU.nombre));			
				archi.seekg((int)((-1)*sizeof(regU)),ios::cur);
				archi.write((char *)&regU, sizeof(regU));
				cout << " Usuario modificado correctamente!" << endl;
			}
			if(op==2){
				cout << "Digite nuevo correo: ";
				cin >> regU.email;
				archi.seekg((int)((-1)*sizeof(regU)),ios::cur);
				archi.write((char *)&regU, sizeof(regU));
				cout << " Usuario modificado correctamente!" << endl;
			}
			if(op==3){
				cout << "Digite la nuevo fecha: ";
				cin >> regU.Fecha;
				archi.seekg((int)((-1)*sizeof(regU)),ios::cur);
				archi.write((char *)&regU, sizeof(regU));
				cout << " Usuario modificado correctamente!" << endl;
			}		
			
		}else
			cout << " No hay un usuario en el foro con esa identificacion" << endl;
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
		system("pause");
}

void BorrarUsuario (){
    struct RegUsuario regU;
    char identifica [50];
    bool Encontro = false;

    system("cls");
    cout <<endl;
    cout << "====================== BORRAR USUARIO DEL FORO ========================"<<endl<<endl;
    cout << " Digite el numero de identificacion :";
    cin>> identifica;
    ifstream archivo ( "usuarios.dat", ios::binary | ios::in |ios::out);

    if ( archivo)
    {

        ofstream archivotemp ("usuariostemp.dat", ios::binary);
        while ( !archivo.eof())
        {
            if ( archivo.read ((char *)&regU,sizeof (regU)))
            {
                if ( strcmp (regU.Identificacion, identifica )!=0)
                {
                    archivotemp.write((char *)&regU,sizeof (regU));
                }
            }


        }

        archivo.close ();
        archivotemp.close ();

        remove ("usuarios.dat");
        rename ( "usuariostemp.dat", "usuarios.dat" );
        cout << "ususario borrado exitosamente"<<endl;

    }
    else
    {
        cout << " no se pudo abrir el archivo" <<endl;
        system("pause");
    }
}

void InsertarForo(){
	int op;
	system("cls");

		do{
		system("cls");
		cout <<endl; 
		cout <<" ========================== Desea crear un nuevo foro o continuar con uno ya hecho? ==========================" <<endl<<endl;
	
		cout <<" 1. Para crearlo" <<endl;
		cout <<" 2. Para ver un foro en especifico" <<endl;
		cout <<" 3. Ingresar el primer mensaje a un foro" <<endl;
		cout <<" 4. Ingresar cita a un mensaje" <<endl;
		cout <<" 5. Ingresar mensajes a un foro" <<endl;
		cout << " Digite la opcion: ";
			cin >> op;

		switch(op){

			case 1 : CrearForo();
			break;

			case 2 : RegForosleer();
			break;

			case 3 : EscribirMensajesEnElForo();
			break;

			case 4 : EscribirCitaDeLosMensajesEnElForo();
			break;

			case 5 : EscribirMensajesMasEnElForo();
			break;		

			}
		}while(op!=5);
	system("pause");
}

void CrearForo(){
	struct RegForos regF;
	struct RegUsuario regU;
	char op, op2;
	bool Encontro=false;
	system("cls");

	cout <<"========================================= CREAR FORO =========================================" <<endl;
	cout << " Digite el tema del Foro: ";
	cin.ignore(); //Borrar el buffer del teclado
	cin.getline(regF.Tema, sizeof(regF.Tema));

	cout << " Digite la fecha actual y la hora con el formato dd/mm/yyyy hh/mm/ss: ";
	cin.ignore(); //Borrar el buffer del teclado
	cin.getline(regF.FechaConHora, sizeof(regF.FechaConHora));
	cout<<endl;
	
	for(int i=0; i< sizeof(regF.Contenido.Cita.ContenidoCita); i++  ){
		regF.Contenido.Cita.ContenidoCita[i]= ' ';
	}
	for(int i=0; i< sizeof(regF.Contenido.Cita.NombreUsuario); i++  ){
		regF.Contenido.Cita.NombreUsuario [i]= ' ';
	}
	for(int i=0; i<sizeof(regF.Contenido.Cita.FechaConHora); i++  ){
		regF.Contenido.Cita.FechaConHora[i]= ' ';
	}
	char cadena[100];
	strcpy(cadena, regF.Tema);
	strcat(cadena, ".dat");

	ofstream archi(cadena, ios::binary|ios::app);
	if (archi)
	{
		archi.write((char*)&regF, sizeof(regF));
		archi.close();
		cout << " Foro grabado correctamente!" <<endl;

	}else
		cout << " No se pudo abrir el archivo!"<< endl;

	system("pause");
}
int contar(char cadena[]){
    int cont = 0;
    struct RegForos s;
    ifstream archi (cadena, ios::binary);
    if (archi)
    {
        while (!archi.eof())
        {
            if (archi.read((char *)&s, sizeof (s)))
            {
                cont++;
            }
        }
        archi.close();
    }
    else
    {
        cout <<"No se pudo abrir el archivo" <<endl;
    }
    return cont;
}

void RegForosleer(){
	int num, cont;
    char cadena[100];
    char cadena2[100];
    char Identifica[30];
   
    system("cls");
    
    struct RegForos s;
 	cout << " ========================================= Acceso en el foro " <<" ========================================="<<endl<<endl;

    cout << " Digite el tema del foro: ";
		cin >> cadena;
			strcpy(cadena2,cadena);
			strcat(cadena, ".dat");
			num = contar(cadena);
			mensajes *registros = new mensajes [num];
	cout << " Digite la identificacion: ";
		cin >> Identifica;		
	
	// Verifica que la identifiacion este en el archivo de usuarios
	if( ConsultarUsuario(Identifica) == true ){
	// Verifica que la identicacion y el nombre del foro no esten en el archivo de privacidad		
	if( ConsultarUsuarioPrivacidad(Identifica, cadena2) == false ){	

    ifstream archi (cadena, ios::binary);
    cont = 0;
     if (archi){
        while (!archi.eof())
        {
            if (archi.read((char *)&s, sizeof (s)))
            {
            	strcpy(registros[cont].contenidoC,s.Contenido.contenidoC);                
                strcpy(registros[cont].NombreUsuario, s.Contenido.NombreUsuario);
                strcpy(registros[cont].FechaConHora, s.Contenido.FechaConHora);
              
                strcpy(registros[cont].Cita.ContenidoCita , s.Contenido.Cita.ContenidoCita);
                strcpy(registros[cont].Cita.NombreUsuario , s.Contenido.Cita.NombreUsuario);
                strcpy(registros[cont].Cita.FechaConHora , s.Contenido.Cita.FechaConHora);
                cont++;
            }
        }
        struct mensajes temporal;
    	for (int i = 1; i < cont; i++) {
        	for (int j = 0; j< cont-1; j++) {
            	if ( strcmp(registros[j].FechaConHora, registros[j+1].FechaConHora) > 0)
            	{
                	temporal = registros[j];
                	registros[j] = registros[j+1];
                	registros[j+1] = temporal;
            	}
        	}
    	}
	cout <<endl; 

    cout << " ====================================== Los mensajes en el foro " << cadena <<" son"<<" ======================================"<<endl<<endl;
    cout<<setw(40)<<"Mensajes"<<setw(35)<<"Nombre usuario"<<setw(35)<<"Fecha en la que fue escrito"<<endl;
    for( int i=0; i<cont; i++){
        cout<<setw(40)<<registros[i].contenidoC	<<setw(35)<<registros[i].NombreUsuario<<setw(35)<<registros[i].FechaConHora<<endl;
		cout<<" Cita:"<<setw(40)<<registros[i].Cita.ContenidoCita<<setw(35)<<registros[i].Cita.NombreUsuario<<setw(35)<<registros[i].Cita.FechaConHora;
    	cout<<endl;    
			 	
	}
	system("pause");	
        archi.close();
    }
    else{
        cout <<" No se pudo abrir el archivo" <<endl;
    } 	
		
	}
	else{
		cout<<" No tiene acceso a este foro"<<endl;
		system("pause");
	}
	}
	else{
		cout<<" Este usuario no esta registrado"<<endl;
		system("pause");
	}
}

void EscribirMensajesEnElForo(){
	struct RegForos regF;
	struct RegUsuario regU;
	struct mensajesForos mensa;
	char cadena[100];
	char cadena2[100];
	char Identifica[30];
	bool Encontro=false;
	system("cls");
	
	cout << " ===== Escribir mensaje de foro =====" << endl << endl;
	cout << " Digite el tema del foro: ";
		cin >> cadena;
			strcpy(cadena2, cadena); // cadeba=
			strcat(cadena, ".dat");
	cout << " Digite la identificacion: ";
		cin >> Identifica;
	
	if( ConsultarUsuario(Identifica) == true ){
		if(  ConsultarUsuarioPrivacidad(Identifica, cadena2) == false    ){
				fstream archi(cadena, ios::binary|ios::in|ios::out);
	if(archi){

		while(!archi.eof() && !Encontro)
		{
			if (archi.read((char*)&regF, sizeof(regF))){
				if(strcmp(cadena2, regF.Tema)==0)
				{

				Encontro=true;
				}
			}
		}

		if (Encontro){
			cout<<endl;
			cout << " Digite el mensaje: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regF.Contenido.contenidoC, sizeof(regF.Contenido.contenidoC));
			cout << " Digite el nombre: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regF.Contenido.NombreUsuario, sizeof(regF.Contenido.NombreUsuario));
					strcpy(mensa.NombreUsuario,regF.Contenido.NombreUsuario )  ;
			cout << " Digite la fecha: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regF.Contenido.FechaConHora, sizeof(regF.Contenido.FechaConHora));
					strcpy(mensa.fecha,regF.Contenido.FechaConHora )  ;

			archi.seekg((int)((-1)*sizeof(regF)),ios::cur);
			archi.write((char *)&regF, sizeof(regF));
			cout << " Mensaje escrito correctamente!" << endl;

			ofstream archivo;
			archivo.open("Mensajes.txt", ios::app| ios::out);
				if(archivo.fail() ){
					cout<<" No se puedo abrir el archivo";
				}else{
				archivo<<mensa.NombreUsuario<<",";
				}

		}else
			cout << " No hay foro con ese tema" << endl;
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
		system("pause");			
	}
	else{
		cout<<" No tiene acceso a este foro"<<endl;
		system(" pause");
	}
		
	}
	else{
		cout<<" El usuario no esta registrado"<<endl;
		system("pause");
	}
}

void EscribirCitaDeLosMensajesEnElForo(){
	struct RegForos regF;
	struct RegUsuario regU;
	struct mensajesForos mensa;
	char cadena[100], op;
	char cadena2[100];
	char Nombre[100];
	char FechaConHora[30];
	char Identifica[30];
	bool Encontro=false;
	
	system("cls");
	cout << " ===== Escribir mensaje de foro =====" << endl << endl;
	cout << " Digite el tema del foro: ";
		cin >> cadena;
			strcpy(cadena2, cadena);
			strcat(cadena, ".dat");
	cout << " Digite la identificacion: ";
		cin >> Identifica;
	// Verifica que el usuario este en el archivo usuarios.dat
	if( ConsultarUsuario(Identifica) == true ){
		// Verifica que el usuario no este en el archivo privacidad.dat
		if(   ConsultarUsuarioPrivacidad(Identifica, cadena2) == false    ){
				cout<<" Digite el nombre del usuario a citar: ";
	 		cin.ignore(); //Borrar el buffer del teclado
				cin.getline(Nombre, sizeof(Nombre));
	 	cout<<" Digite la fecha a citar: ";
	 		cin.ignore(); //Borrar el buffer del teclado
				cin.getline(FechaConHora, sizeof(FechaConHora));

		fstream archi(cadena, ios::binary|ios::in|ios::out);
	if(archi){

		while(!archi.eof() && !Encontro)
		{
			if (archi.read((char*)&regF, sizeof(regF))){
				if( strcmp    (cadena2, regF.Tema) ==0){
					if( strcmp    (Nombre, regF.Contenido.NombreUsuario) ==0){
						if( strcmp    (FechaConHora, regF.Contenido.FechaConHora) ==0){
							Encontro=true;
						}
					}
				}
			}
		}
		if (Encontro){
		cout<<endl;
		cout<<" En verdad desea citar este mensaje? s para si, de lo contrario n: ";
			cin>> op;
			if( op == 's'){
				cout << " Digite la cita: ";
					cin.ignore(); //Borrar el buffer del teclado
						cin.getline(regF.Contenido.Cita.ContenidoCita, sizeof(regF.Contenido.Cita.ContenidoCita));
				cout << " Digite el nombre: ";
					cin.ignore(); //Borrar el buffer del teclado
						cin.getline(regF.Contenido.Cita.NombreUsuario, sizeof(regF.Contenido.Cita.NombreUsuario));
						strcpy(mensa.NombreUsuario,regF.Contenido.Cita.NombreUsuario)  ;
				cout << " Digite la fecha: ";
					cin.ignore(); //Borrar el buffer del teclado
						cin.getline(regF.Contenido.Cita.FechaConHora, sizeof(regF.Contenido.Cita.FechaConHora));						

			archi.seekg((int)((-1)*sizeof(regF)),ios::cur);
			archi.write((char *)&regF, sizeof(regF));
			cout << " Mensaje citado correctamente!" << endl;

			ofstream archivo;
			archivo.open("Mensajes.txt", ios::app|ios::out);
				if(archivo.fail() ){
					cout<<"No se puedo abrir el archivo";
				}else{
					archivo<<mensa.NombreUsuario<<",";
				}

			}
			else{
				return;
			}

		}else
			cout << " No hay mensajes con esas caracteristicas" << endl;
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
		system("pause");
			
		}
	else{
		cout<<" No tiene acceso a este foro"<<endl;
		system(" pause");
	}
	}	
	else{
		cout<<" El usuario no esta registrado"<<endl;
		system("pause");
	}
		
}

void EscribirMensajesMasEnElForo(){
	struct RegForos regF;
	struct RegUsuario regU;
	struct mensajesForos mensa;
	char cadena[100];
	char cadena2[100];
	char Identifica[30];
	bool Encontro=false;

	system("cls");
	cout << " ===== Escribir mensaje de foro =====" << endl << endl;
	cout << " Digite el tema del foro: ";
		cin >> cadena;
			strcpy(cadena2, cadena);
			strcat(cadena, ".dat");
	cout << " Digite la identificacion: ";
		cin >> Identifica;	
	// Verifica que la identifiacion este en el archivo de usuarios
	if( ConsultarUsuario(Identifica) == true ){
	// Verifica que la identicacion y el nombre del foro no esten en el archivo de privacidad	
	if(  ConsultarUsuarioPrivacidad(Identifica, cadena2) == false    ){
			
	fstream archi(cadena, ios::binary|ios::app|ios::in|ios::out);
	if(archi){

		while(!archi.eof() && !Encontro)
		{
			if (archi.read((char*)&regF, sizeof(regF))){
				if(strcmp(cadena2, regF.Tema)==0)
				{

				Encontro=true;
				}
			}
		}

		if (Encontro){
			cout<<endl;
			cout << " Digite el mensaje: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regF.Contenido.contenidoC, sizeof(regF.Contenido.contenidoC));
			cout << " Digite el nombre: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regF.Contenido.NombreUsuario, sizeof(regF.Contenido.NombreUsuario));
					strcpy(mensa.NombreUsuario,regF.Contenido.NombreUsuario )  ;
			cout << " Digite la fecha: ";
				cin.ignore(); //Borrar el buffer del teclado
				cin.getline(regF.Contenido.FechaConHora, sizeof(regF.Contenido.FechaConHora));
					strcpy(mensa.fecha,regF.Contenido.FechaConHora )  ;

			for(int i=0; i< sizeof(regF.Contenido.Cita.ContenidoCita); i++  ){
				regF.Contenido.Cita.ContenidoCita[i]= ' ';
			}

			for(int i=0; i< sizeof(regF.Contenido.Cita.NombreUsuario); i++  ){
				regF.Contenido.Cita.NombreUsuario [i]= ' ';
			}

			for(int i=0; i<sizeof(regF.Contenido.Cita.FechaConHora); i++  ){
				regF.Contenido.Cita.FechaConHora[i]= ' ';
			}

			archi.seekg((int)((-1)*sizeof(regF)),ios::cur);
			archi.write((char *)&regF, sizeof(regF));
			cout << " Mensaje escrito correctamente!" << endl;

			ofstream archivo;
			archivo.open("Mensajes.txt",ios::app| ios::out);
			if(archivo.fail() ){
				cout<<" No se puedo abrir el archivo";
			}else{
				archivo<<mensa.NombreUsuario<<",";
			}


		}else
			cout << " No hay foro con ese tema" << endl;
		archi.close();
	}else
		cout << " No se pudo abrir el archivo usuarios" << endl;
				
	}
	else{
		cout<<" No tiene acceso a este foro"<<endl;
		system(" pause");
	}
	}
	else{
		cout<<" El usuario no esta registrado"<<endl;
		system("pause");
	}
	
}

void ReporteMensajes(){   
   mensajesForos *Mensaje = new mensajesForos [5];   
   int ContPalabra=0,Temp=0;
   char Linea[500];
   char *p;
   bool Existe;
   int i,j;

   system("cls");
   ifstream archi("Mensajes.txt");
   if (archi)
   {
   	  while (!archi.eof())
   	  {
   	  	archi.getline(Linea, sizeof(Linea));
   	  	p=strtok(Linea," ,");
   	  	while (p!=NULL)
   	  	{
   	  	  Existe=false;
   	  	  for (i=0; i<ContPalabra; i++)
   	  	  {
   	  	  	if (strcmp(Mensaje[i].NombreUsuario,p)==0)
   	  	  	{
   	  	  	  Existe=true;
   	  	  	  Mensaje[i].NoVeces++;
 		    }
		  }
		  if (!Existe)
		  {
		    strcpy(Mensaje[ContPalabra].NombreUsuario, p);
		    Mensaje[ContPalabra].NoVeces=1;
		    ContPalabra++;
		  }
   	  	  p=strtok(NULL," ,");
		}
	  }
	  archi.close();
	  for (i=0;i<ContPalabra;i++)
	  {
	    for (j=i+1;j<ContPalabra;j++)
	    {
	    	if (Mensaje[i].NoVeces < Mensaje[j].NoVeces)
	    	{
	    	  struct mensajesForos Temp=Mensaje[i];
	    	  Mensaje[i]=Mensaje[j];
	    	  Mensaje[j]=Temp;
			}
	    }
	  }
	  

	  cout << " =============== REPORTE DE USARIOS CANTIDAD MENSAJES EN FOROS ===============" << endl << endl;
	  for (i=0;i<5;i++)
	    cout <<" El usuario : "<< Mensaje[i].NombreUsuario <<" a escrito: "<<Mensaje[i].NoVeces<< " en el todos los foros." << endl;
   }else{
        cout << " No se pudo abrir el archivo!" << endl;
   }
   archi.close();

     system("pause");
}

void PrivacidadForo(){
	struct listaprivada regP;
	system("cls");
	cout <<" ==== Ingresar Privacidad AL FORO ====" <<endl;
	cout << "Digite el numero de identificacion del usuario que se le va a restringir el acceso: ";
		cin >> regP.Identificacion;
	cout << "Digite el tema del foro: ";
		cin >> regP.Tema;

	fstream archi("Privacidad.dat", ios::binary|ios::app);
	if (archi)
	{		
		archi.write((char*)&regP, sizeof(regP));
		archi.close();
		cout << " Usuario restringido correctamente!" <<endl;
	}else
		cout << " No se pudo abrir el archivo!"<< endl;

	system("pause");
}
