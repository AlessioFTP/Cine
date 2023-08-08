#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct datos {
    string usuario;
    string contra;
};

struct tarjetas{
	string cedula;
	string tarjeta;
	string credito;
};

struct Reserva{
	string Usuario;
	string Sillas;
	string Estado;
};

string SillasT[11][20];

string SillasR[11][20];

string SillasP[11][20];

vector <datos> Cuentas;

vector <tarjetas> Tarjetas;

void Importar(vector <datos> &Cuentas, vector <tarjetas> &Tarjetas);
	
void Login(bool &A, vector <datos> Cuentas, string &Nombre);

void AgregarCuentas(bool A, vector <datos> &Cuentas);

void CrearTarjeta(vector <tarjetas> &Tarjetas);

void Guardar_Tarjetas (vector <tarjetas> Tarjetas);

void AgregarCredito(vector <tarjetas> &Tarjetas);

void Guardar_Cuentas (vector <datos> Cuentas);

void Mostrar_Sala(string Pelicula, int op, string Usuario);

void menu();

void Menu2(string Nombre);

void Importar_Sillas(string (&Sillas)[11][20], string Pelicula);

void Reservas(string Usuario);

void Comprar_Sillas(string (&Sillas)[11][20], string Pelicula, string Usuario);

void Texto_Ascii (string Texto);

void Facturar_Silla(vector <tarjetas> Tarjetas, int ValorT, int ValorN, bool &B, string Pelicula, string Usuario);

void Guardar_Sillas(string Sillas[11][20], string Pelicula);

void Guardar_Reservas(string Usuario, bool A, string Pelicula, string Silla);

int main() {
	setlocale(LC_ALL, "spanish");
    Importar(Cuentas, Tarjetas);
    Importar_Sillas(SillasT, "Thor");
	Importar_Sillas(SillasR, "Rapidos_Y_Furiosos");
	Importar_Sillas(SillasP, "Pequeño_Pero_Peligroso");
    srand(time(NULL));
	menu();
    return 0;
}

void menu(){
	
	int op;
	do {
		system ("cls");
		bool A = false;
		cout << "\n\n\n\n\n\t\t\t##  ### ### ### # # ### ### ### ##   #      #      ##  ### ### ### # #  #   ##\n\t\t\t# #  #  #   # # # # #   # #  #  # # # #    # #    #     #  # # #   ### # # #   \n\t\t\t##   #  ### # # # # ### # #  #  # # # #    ###    #     #  # # ##  ### ###  #  \n\t\t\t# #  #  #   # # # # #   # #  #  # # # #    # #    #     #  # # #   # # # #   # \n\t\t\t##  ### ### # #  #  ### # # ### ##   #     # #     ##  ### # # ### # # # # ##  \n" << endl;
		cout << "\t\t\t\t\t-----------------MENÚ-----------------" << endl;
		cout << "\t\t\t\t\t\tDigite una opción" << endl;
		cout << "\t\t\t\t\t\t0. Salir del programa.\n\t\t\t\t\t\t1. Ingresar cuenta.\n\t\t\t\t\t\t2. Crear cuenta." << endl;		
		cout << "\t\t\t\t\t\tIngrese la opción: ";		
		cin >> op;
		switch (op){	
			case 0:{
				cout << "\n\t\t\t\t\t\t\tAdios" << endl;
				break;
			}
			case 1:{
				string Nombre;
				Login(A, Cuentas, Nombre);
				if(A)
				Menu2(Nombre);
				break;
			}
			case 2:{
				AgregarCuentas(A, Cuentas);
				break;
			}
			default :{
				cout << "\n\t\t\t\t\t\t  Opción no valida\n" << endl;
				system ("pause");
				break;
			}
		}
	}while(op != 0);
}

void Login(bool &A, vector <datos> Cuentas, string &Nombre){
	system("cls");
	string ID, Contrase;
	cout << "\n\n\n\n\n";
	Texto_Ascii("Iniciar sesion");
	cout << "\n\t\t\t\t   ----------------------Cuenta----------------------" << endl;
	cout << "\t\t\t\t\t\t     Usuario: ";
	cin >> ID;
	cout << "\t\t\t\t\t\t     Contraseña: ";
	cin >> Contrase;
	for (int i = 0; i < Cuentas.size(); i++){
		if (ID == Cuentas[i].usuario && Contrase == Cuentas[i].contra){
			A = true;
			Nombre = ID;
			break;
		}
	}
	if (!A){
		cout << "\n\t\t\t\t   Usuario o Contraseña incorrecta, intentelo de nuevo.\n" << endl;
		system("pause");
		system("cls");
	}
}

void Importar(vector <datos> &Cuentas, vector <tarjetas> &Tarjetas){	

    ifstream Cuenta, Contra, Cedulas, Tarjets, Creditos;
    Cuenta.open("Cuentas//Usuarios.txt");
    Contra.open("Cuentas//Contraseñas.txt");
    Cedulas.open("Tarjetas//Cedulas.txt");
    Tarjets.open("Tarjetas//Tarjetas.txt");
    Creditos.open("Tarjetas//Credito.txt");
    string U, C, T, CD, CR;
	while (!Cuenta.eof()){
        getline(Cuenta, U);
        getline(Contra, C);
        Cuentas.push_back(datos{U,C});
    }
    while (!Cedulas.eof()){
    	getline(Cedulas, CD);
    	getline(Tarjets, T);
    	getline(Creditos, CR);
    	Tarjetas.push_back(tarjetas{CD,T,CR});
	}
	Cuenta.close();
	Contra.close();
	Cedulas.close();
	Tarjets.close();
	Creditos.close();
	}
	
void AgregarCuentas(bool A, vector <datos> &Cuentas){
	system("cls");
	string ID, Contrase;
	cout << "\n\n\n\n\n\t\t\t\t\t##  ###  ## ###  ## ### ##   #  ## \n\t\t\t\t\t# # #   #    #  #    #  # # # # # #\n\t\t\t\t\t##  ##  # #  #   #   #  ##  ### ##\n\t\t\t\t\t# # #   # #  #    #  #  # # # # # #\n\t\t\t\t\t# # ###  ## ### ##   #  # # # # # #\n" << endl;
	cout << "\n\t\t\t\t----------------------Cuenta----------------------" << endl;
	cout << "\t\t\t\t\t\tUsuario: ";
	cin >> ID;
	cout << "\t\t\t\t\t\tContraseña: ";
	cin >> Contrase;
	for (int i = 0; i < Cuentas.size(); i++){
		if (ID == Cuentas[i].usuario){
			A = true;
			break;
		}
	}
	if (!A){
		Cuentas.push_back(datos{ID, Contrase});
		cout << "\t\t\t\t\t   Cuenta creada exitosamente\n";
		Guardar_Cuentas (Cuentas);
		system("pause");
		system("cls");
	}
	else{
		cout << "\t\t\t\t\tUsuario en uso, intentelo de nuevo\n";
		system("pause");
		system("cls");
	}
}
	
void Menu2(string Nombre){
	int op;
	string Texto = "Hola ";	
	Texto += Nombre;
	do{
		system("cls");
		cout << "\n\n\n\n\n";
		Texto_Ascii (Texto);
		cout << "\n\t\t\t\t\t-----------------MENÚ-----------------" << endl;
		cout << "\t\t\t\t\t\tDigita una opción:" << endl;		
		cout << "\t\t\t\t\t\t0. Ir al menú principal.\n\t\t\t\t\t\t1. Crear una nueva tarjeta.\n\t\t\t\t\t\t2. Recargar una tarjeta.\n\t\t\t\t\t\t3. Crear una reserva." << endl;
		cout << "\t\t\t\t\t\tIngrese la opción: ";	
		cin >> op;		
		switch(op){			
			case 0:{				
				system("cls");				
				break;
			}			
			case 1:{			
				CrearTarjeta(Tarjetas);				
				break;
			}
			case 2:{				
				AgregarCredito(Tarjetas);
				break;
			}
			case 3:{
				Reservas(Nombre);
				break;
			}
			default:{
				cout << "\n\t\t\t\t\t\t  Opción no valida\n";
				system ("pause");
				break;
			}
		}		
	}while(op != 0);
}

void CrearTarjeta(vector <tarjetas> &Tarjetas){
	system("cls");
	cout << "\n\n\n\n\n\t\t\t       ###  #  ##   ## ### ###  #       ## ### ### ### # #  #   ##\n\t\t\t        #  # # # #   # #    #  # #     #    #  # # #   ### # # #\n\t\t\t        #  ### ##    # ##   #  ###     #    #  # # ##  ### ###  #\n\t\t\t        #  # # # # # # #    #  # #     #    #  # # #   # # # #   #\n\t\t\t        #  # # # #  #  ###  #  # #      ## ### # # ### # # # # ##" << endl;
	bool A = true;
	string Cedula, Tarjeta(10, ' ');
	cout << "\n\t\t\t\t    --------------------Tarjetas--------------------" << endl;
	cout << "\t\t\t\t\t Ingrese su numero de cedula: ";
	cin >> Cedula;
	if (Cedula.size() > 6 && Cedula.size() < 11 ){
	for (int i = 0; i < Tarjetas.size(); i++){ 
		if(Cedula == Tarjetas[i].cedula){
		A = false;
		break;
		}
	}
	if (A){
		for (int i = 0; i < 10; i++){
			char Alazar;
			Alazar = rand() % (10);
			Tarjeta[i]= Alazar + '0';
		}
		Tarjetas.push_back(tarjetas{Cedula, Tarjeta, "70000"});
		cout << "\n\t\t\t\t\t\tTarjeta creada con exito\n\t\t\t\tSu numero de tarjeta es: " << Tarjeta  << " con saldo de 70000$\n"<< endl;
		Guardar_Tarjetas (Tarjetas);
	}
	else 
		cout << "\n\t\t\t\t\t\tNumero de cedula en uso\n" << endl;
	system("pause");
	}
	else {
	cout << "\n\t\t\t\t\t\t\tERROR\n\t\t\t\t\t      Numero de cedula no valido.\n" << endl;
	system("pause");
	}

}

void AgregarCredito(vector <tarjetas> &Tarjetas){
    system("cls");
    int i = 0, Credito, Saldo;
    string Tarjeta, Nuevo_Credito;
    bool A = false;
    	cout << "\n\n\n\n\n\t\t\t       ###  #  ##   ## ### ###  #       ## ### ### ### # #  #   ##\n\t\t\t        #  # # # #   # #    #  # #     #    #  # # #   ### # # #\n\t\t\t        #  ### ##    # ##   #  ###     #    #  # # ##  ### ###  #\n\t\t\t        #  # # # # # # #    #  # #     #    #  # # #   # # # #   #\n\t\t\t        #  # # # #  #  ###  #  # #      ## ### # # ### # # # # ##" << endl;
    	cout << "\n\t\t\t\t -----------------------Credito------------------------" << endl;
    cout << "\t\t\t         Ingrese el numero de la tarjeta a recargar: ";
    cin >> Tarjeta;
    for (i; i < Tarjetas.size(); i++){
        if (Tarjeta == Tarjetas[i].tarjeta){
            A = true;
            break;
        }
    }
    if (A){
        cout << "\n\t\t\t\t\t     Su saldo actual es de: " << Tarjetas[i].credito << "$\n" <<endl;
        cout << "\t\t\t\t Ingrese el valor que desea recargar, recuerde que el \n\t\t\t\t valor de recarga minima es de 50000$: ";
        cin >> Credito;
        if (Credito > 49999){
            istringstream(Tarjetas[i].credito) >> Saldo;
            Credito += Saldo;
            Nuevo_Credito = to_string(Credito);
            Tarjetas[i].credito = Nuevo_Credito;
            cout << "\n\t\t\t\t\t      Su nuevo saldo es de: " << Nuevo_Credito << "$\n"<< endl;
		    remove("Tarjetas//Creditos.txt");
		    ofstream Credito;
		    Credito.open("Tarjetas//Credito.txt");
		    for (int i = 0 ; i < Tarjetas.size(); i++){
				if (i == Tarjetas.size() - 1){
					Credito << Tarjetas[i].credito;
				}
				else{
					Credito << Tarjetas[i].credito << endl;
				}
			}
		    Credito.close();
        }
        else
            cout << "\n\t\t\t\t\tEl valor ingresado es menor al permitido.\n" << endl;
    }
    else
        cout << "\n\t\t\t\t\t\t  Tarjeta no encontrada\n" << endl;
    system("pause");
}

void Guardar_Tarjetas (vector <tarjetas> Tarjetas){
	remove("Tarjetas//Cedulas.txt");
    remove("Tarjteas//Tarjetas.txt");
    remove("Tarjetas//Creditos.txt");
    ofstream Cedulas, Tarjets, Credito;
    Cedulas.open("Tarjetas//Cedulas.txt");
    Tarjets.open("Tarjetas//Tarjetas.txt");
    Credito.open("Tarjetas//Credito.txt");
    for (int i = 0 ; i < Tarjetas.size(); i++){
		if (i == Tarjetas.size() - 1){
			Cedulas << Tarjetas[i].cedula;
			Tarjets << Tarjetas[i].tarjeta;
			Credito << Tarjetas[i].credito;
		}
		else{
			Cedulas << Tarjetas[i].cedula << endl;
			Tarjets << Tarjetas[i].tarjeta << endl;
			Credito << Tarjetas[i].credito << endl;
		}
	}
	Cedulas.close();
    Tarjets.close();
    Credito.close();
    
}

void Guardar_Cuentas (vector <datos> Cuentas){
	remove("Cuentas//Usuarios.txt");
    remove("Cuentas//Contraseñas.txt");
    ofstream Cuenta, Contra;
    Cuenta.open("Cuentas//Usuarios.txt");
    Contra.open("Cuentas//Contraseñas.txt");
    
	for (int i = 0 ; i < Cuentas.size(); i++){
		if (i == Cuentas.size() - 1){
			Cuenta << Cuentas[i].usuario;
			Contra << Cuentas[i].contra;
		}
		else{
			Cuenta << Cuentas[i].usuario << endl;
			Contra << Cuentas[i].contra << endl;
		}
	}
	Cuenta.close();
    Contra.close();
}

void Importar_Sillas(string (&Sillas)[11][20], string Pelicula){
	
ifstream Fila_A, Fila_B, Fila_C, Fila_D, Fila_E, Fila_F, Fila_G, Fila_H, Fila_I, Fila_J, Fila_K;
string FilaA, FilaB, FilaC, FilaD, FilaE, FilaF, FilaG, FilaH, FilaI, FilaJ, FilaK;
FilaA = "Reservas//" + Pelicula + "//Fila_A.txt";
FilaB = "Reservas//" + Pelicula + "//Fila_B.txt";
FilaC = "Reservas//" + Pelicula + "//Fila_C.txt";
FilaD = "Reservas//" + Pelicula + "//Fila_D.txt";
FilaE = "Reservas//" + Pelicula + "//Fila_E.txt";
FilaF = "Reservas//" + Pelicula + "//Fila_F.txt";
FilaG = "Reservas//" + Pelicula + "//Fila_G.txt";
FilaH = "Reservas//" + Pelicula + "//Fila_H.txt";
FilaI = "Reservas//" + Pelicula + "//Fila_I.txt";
FilaJ = "Reservas//" + Pelicula + "//Fila_J.txt";
FilaK = "Reservas//" + Pelicula + "//Fila_K.txt";

Fila_A.open(FilaA);
Fila_B.open(FilaB);
Fila_C.open(FilaC);
Fila_D.open(FilaD);
Fila_E.open(FilaE);
Fila_F.open(FilaF);
Fila_G.open(FilaG);
Fila_H.open(FilaH);
Fila_I.open(FilaI);
Fila_J.open(FilaJ);
Fila_K.open(FilaK);

for (int i = 0; i < 20; i++){
getline(Fila_A, Sillas[0][i]);
getline(Fila_B, Sillas[1][i]);
getline(Fila_C, Sillas[2][i]);
getline(Fila_D, Sillas[3][i]);
getline(Fila_E, Sillas[4][i]);
getline(Fila_F, Sillas[5][i]);
getline(Fila_G, Sillas[6][i]);
getline(Fila_H, Sillas[7][i]);
getline(Fila_I, Sillas[8][i]);
getline(Fila_J, Sillas[9][i]);
getline(Fila_K, Sillas[10][i]);
}

Fila_A.close();
Fila_B.close();
Fila_C.close();
Fila_D.close();
Fila_E.close();
Fila_F.close();
Fila_G.close();
Fila_H.close();
Fila_I.close();
Fila_J.close();
Fila_K.close();
}

void Reservas(string Usuario){
	system("cls");
	int op;
	cout << "\n\n\n\n\n";
	Texto_Ascii("Reservas");
	cout << "\n\t\t\t\t\t --------------Películas--------------" << endl;
	cout << "\t\t\t\t\t       ¿Qué película deseas ver?\n\t\t\t\t\t     1. Pequeño pero Peligroso 2.\n\t\t\t\t\t     2. Thor vs Superman.\n\t\t\t\t\t     3. Rapidos y Furiosos 27 \n\t\t\t\t\t        el contraataque.\n\t\t\t\t\t     Ingrese la película(número): ";
	cin >> op;
	switch (op){
		case 1:{
			system("cls");
			Mostrar_Sala("Pequeño pero Peligroso 2", 1, Usuario);
			break;
		}
		case 2:{
			system("cls");
			Mostrar_Sala("Thor vs Superman", 2, Usuario);
			break;
		}
		case 3:{
			system("cls");
			Mostrar_Sala("Rapidos y furiosos 27", 3, Usuario);
			break;
		}
		default:{
			cout << "\n\t\t\t\t\t\t  Opción no valida\n" << endl;
			break;
		}
	}
	system("pause");
}

void Mostrar_Sala(string Pelicula, int op, string Usuario){

	cout << "\n";
	Texto_Ascii(Pelicula);
	cout << "\n\n\t\t\t\t   *************************************************\n\t\t\t\t   *    A B C D E F G H I J K L M N O P Q R S T    *\n";
	
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 20; j++){
			if (j == 0){
				if ( i < 9)
				cout << "\t\t\t\t   * 0" << i + 1 << " ";
				else  
				cout << "\t\t\t\t   * " << i + 1 << " ";
			}
			if (op == 1)
				cout << SillasP[i][j] << " ";
			else if (op == 2)
				cout << SillasT[i][j] << " ";
			else if (op == 3)
				cout << SillasR[i][j] << " ";
			if (j == 19)
				cout << "   *";
		}
		if (i == 7)
			cout << "\n\t\t\t\t   *    ---------------------------------------    *";
		cout << "\n";
	}
	
	cout << "\t\t\t\t   *\t\t\t\t\t\t   *\n\t\t\t\t   *\t\t\t\t\t\t   *\n\t\t\t\t   *       #################################       *\n\t\t\t\t   *       #################################       *\n\t\t\t\t   *       #################################       *\n\t\t\t\t   *************************************************\n";
	
			if (op == 1)
				Comprar_Sillas(SillasP, Pelicula, Usuario);
			else if (op == 2)
				Comprar_Sillas(SillasT, Pelicula, Usuario);
			else if (op == 3)
				Comprar_Sillas(SillasR, Pelicula, Usuario);
}

void Comprar_Sillas(string (&Sillas)[11][20], string Pelicula, string Usuario){
	cout << "\t\t\t\t   Ingrese la cantidad de sillas que desea comprar: ";
	int Cantidad;
	cin >> Cantidad;
	if (Cantidad < 8 && Cantidad > 0){
		int Sillas_Reserva_Numero[Cantidad];
		int Sillas_Reserva_Letra[Cantidad];
		char Silla_Reserva_Letra[Cantidad];
		for (int i = 0; i < Cantidad; i++){
			bool A = false;
			do{
				do{
					cout << "\n\t\t\t\t    Ingrese el numero de la silla: ";
					cin >> Sillas_Reserva_Numero[i];
					Sillas_Reserva_Numero[i] -= 1;
					if(Sillas_Reserva_Numero[i] < 0 || Sillas_Reserva_Numero[i] > 10){
						cout << "\n\t\t\t\t    Numero de silla no valido.";
					}
					if(Sillas_Reserva_Numero[i] >= 0 && Sillas_Reserva_Numero[i] < 10){
						break;
					}
				}while(Sillas_Reserva_Numero[i] < 0 || Sillas_Reserva_Numero[i] > 10);
				do{
					cout << "\n\t\t\t\t    Ingrese la letra de la silla: ";
					cin >> Silla_Reserva_Letra[i];
					switch (Silla_Reserva_Letra[i]){
					case 'A':{
						Sillas_Reserva_Letra[i] = 0;
						break;
					}
					case 'a':{
						Sillas_Reserva_Letra[i] = 0;
						break;
					}
					case 'B':{
						Sillas_Reserva_Letra[i] = 1;
						break;
					}
					case 'b':{
						Sillas_Reserva_Letra[i] = 1;
						break;
					}
					case 'C':{
						Sillas_Reserva_Letra[i] = 2;
						break;
					}
					case 'c':{
						Sillas_Reserva_Letra[i] = 2;
						break;
					}
					case 'D':{
						Sillas_Reserva_Letra[i] = 3;
						break;
					}
					case 'd':{
						Sillas_Reserva_Letra[i] = 3;
						break;
					}
					case 'E':{
						Sillas_Reserva_Letra[i] = 4;
						break;
					}
					case 'e':{
						Sillas_Reserva_Letra[i] = 4;
						break;
					}
					case 'F':{
						Sillas_Reserva_Letra[i] = 5;
						break;
					}
					case 'f':{
						Sillas_Reserva_Letra[i] = 5;
						break;
					}
					case 'G':{
						Sillas_Reserva_Letra[i] = 6;
						break;
					}
					case 'g':{
						Sillas_Reserva_Letra[i] = 6;
						break;
					}
					case 'H':{
						Sillas_Reserva_Letra[i] = 7;
						break;
					}
					case 'h':{
						Sillas_Reserva_Letra[i] = 7;
						break;
					}
					case 'I':{
						Sillas_Reserva_Letra[i] = 8;
						break;
					}
					case 'i':{
						Sillas_Reserva_Letra[i] = 8;
						break;
					}
					case 'J':{
						Sillas_Reserva_Letra[i] = 9;
						break;
					}
					case 'j':{
						Sillas_Reserva_Letra[i] = 9;
						break;
					}
					case 'K':{
						Sillas_Reserva_Letra[i] = 10;
						break;
					}
					case 'k':{
						Sillas_Reserva_Letra[i] = 10;
						break;
					}
					case 'L':{
						Sillas_Reserva_Letra[i] = 11;
						break;
					}
					case 'l':{
						Sillas_Reserva_Letra[i] = 11;
						break;
					}
					case 'M':{
						Sillas_Reserva_Letra[i] = 12;
						break;
					}
					case 'm':{
						Sillas_Reserva_Letra[i] = 12;
						break;
					}
					case 'N':{
						Sillas_Reserva_Letra[i] = 13;
						break;
					}
					case 'n':{
						Sillas_Reserva_Letra[i] = 13;
						break;
					}
					case 'O':{
						Sillas_Reserva_Letra[i] = 14;
						break;
					}
					case 'o':{
						Sillas_Reserva_Letra[i] = 14;
						break;
					}
					case 'P':{
						Sillas_Reserva_Letra[i] = 15;
						break;
					}
					case 'p':{
						Sillas_Reserva_Letra[i] = 15;
						break;
					}
					case 'Q':{
						Sillas_Reserva_Letra[i] = 16;
						break;
					}
					case 'q':{
						Sillas_Reserva_Letra[i] = 16;
						break;
					}
					case 'R':{
						Sillas_Reserva_Letra[i] = 17;
						break;
					}
					case 'r':{
						Sillas_Reserva_Letra[i] = 17;
						break;
					}
					case 'S':{
						Sillas_Reserva_Letra[i] = 18;
						break;
					}
					case 's':{
						Sillas_Reserva_Letra[i] = 18;
						break;
					}
					case 'T':{
						Sillas_Reserva_Letra[i] = 19;
						break;
					}
					case 't':{
						Sillas_Reserva_Letra[i] = 19;
						break;
					}
				}
					if(Sillas_Reserva_Letra[i] < 0 || Sillas_Reserva_Letra[i] > 19){
						cout << "\n\t\t\t\t    Letra de silla no valido.";
					}
					if(Sillas_Reserva_Letra[i] >= 0 && Sillas_Reserva_Letra[i] < 19){
						break;
					}
				}while (Sillas_Reserva_Letra[i] < 0 || Sillas_Reserva_Letra[i] > 19);
				if (Sillas[Sillas_Reserva_Numero[i]][Sillas_Reserva_Letra[i]] != "X" && Sillas[Sillas_Reserva_Numero[i]][Sillas_Reserva_Letra[i]] != "P"){
					A = true;
				}
				if (!A){
					cout << "\n\t\t\t\t    Silla ya reservada, ingresela nuevamente\n";
				}
			}while(!A);
		}
		int Valor;
		string SillaReservada = "";
		for (int i = 0; i < Cantidad; i++){
			string Numero;
			Numero = to_string(Sillas_Reserva_Numero[i] + 1) ;
			if (Sillas_Reserva_Numero[i] + 1 < 10)
			SillaReservada = SillaReservada + Silla_Reserva_Letra[i] + "0" + Numero + " ";
			else
			SillaReservada = SillaReservada + Silla_Reserva_Letra[i] + Numero + " ";
		}
		system("cls");
		cout << "\n\n\n\n\n";
		Texto_Ascii(Pelicula);
		cout << "\n\t\t\t\t     --------------Reserva realizada--------------\n";
		cout << "\t\t\t\t\t ¿Desea pagar la reserva ahora mismo?\n\t\t\t\t\t\t\t1. Si\n\t\t\t\t\t\t\t2. No\n\t\t\t\t\t\tIngrese la opción: ";
		int op;
		cin >> op;
		switch (op){
			case 1:{
				bool B = false;
				int ValorT = 0, ValorN = 0;
				for (int i = 0; i < Cantidad; i++){
					if (Sillas_Reserva_Numero[i] > 7)
					ValorT += 9900;
					else ValorT += 7200;
				}
				for (int i = 0; i < Cantidad; i++){
					if (Sillas_Reserva_Numero[i] > 7)
					ValorN += 11000;
					else ValorN += 8000;
				}
				Facturar_Silla(Tarjetas, ValorT, ValorN, B, Pelicula, Usuario);
				if (B){
					for (int i = 0; i < Cantidad; i++){
						Sillas[Sillas_Reserva_Numero[i]][Sillas_Reserva_Letra[i]] = "X";
					}
					if (Pelicula == "Thor vs Superman"){
					    	Guardar_Sillas(SillasT, Pelicula);
						}
						else if (Pelicula == "Pequeño pero Peligroso 2"){
					    	Guardar_Sillas(SillasP, Pelicula);
						}
						else if (Pelicula == "Rapidos y furiosos 27"){
					    	Guardar_Sillas(SillasR, Pelicula);
						}
					bool C = true;
					Guardar_Reservas(Usuario, C, Pelicula, SillaReservada);
				}
				break;
			}
			case 2:{
				cout << "\n\t\t\tLa reserva quedo registrada en la cuenta '" << Usuario << "', recuerde realizar el pago.\n";
				for (int i = 0; i < Cantidad; i++){
					Sillas[Sillas_Reserva_Numero[i]][Sillas_Reserva_Letra[i]] = "P";
				}
				if (Pelicula == "Thor vs Superman"){
					    	Guardar_Sillas(SillasT, Pelicula);
						}
						else if (Pelicula == "Pequeño pero Peligroso 2"){
					    	Guardar_Sillas(SillasP, Pelicula);
						}
						else if (Pelicula == "Rapidos y furiosos 27"){
					    	Guardar_Sillas(SillasR, Pelicula);
						}
						bool C = false;
					Guardar_Reservas(Usuario, C, Pelicula, SillaReservada); 
				break;
			}
		}
	}
	else{
		cout << "\n\t\t\t\t     La cantidad que se puede reservar es de 1 a 7 asientos.\n";
	}
}

void Facturar_Silla(vector <tarjetas> Tarjetas, int ValorT, int ValorN, bool &B, string Pelicula, string Usuario){
	int op;
	do{
		system("cls");
		cout << "\n\n\n\n\n";
		Texto_Ascii(Pelicula);
		cout << "\n\t\t\t\t     --------------Reserva realizada--------------\n";
		cout << "\n\t\t\t\t\t    ¿Desea pagar con o sin tarjeta?\n\t\t\t\t\t\t1. Con tarjeta\n\t\t\t\t\t\t2. Sin tarjeta\n\t\t\t\t\t\t3. Cancelar reserva\n\t\t\t\t\t\tIngrese la opción: ";
		cin >> op;
		switch (op){
			case 1:{
				bool A = false;
				int i = 0;	
				string Tarjeta;
				cout << "\n\t\t\t\t\tEl valor de las entradas es de: " << ValorT <<"$\n\t\t\t\t\tIngrese el numero de la tarjeta: ";
				cin >> Tarjeta;
				for (i; i < Tarjetas.size(); i++){
			        if (Tarjeta == Tarjetas[i].tarjeta){
			            A = true;
			            break;
			        }
		    	}
		    	if (A){
		    		int Saldo;
		    		string Nuevo_Credito;
		    		istringstream(Tarjetas[i].credito) >> Saldo;
		    		if ( Saldo - ValorT >= 0){
			    		cout << "\n\t\t\t\t\t\t\tREALIZADO!\n\t\t\t\t\t     Su nuevo saldo es de: " << Saldo - ValorT << "$\n";
			    		B = true;
			    		Saldo -= ValorT;
			    		Tarjetas[i].credito = to_string(Saldo);
			    		remove("Tarjetas//Creditos.txt");
					    ofstream Credito;
					    Credito.open("Tarjetas//Credito.txt");
					    for (int i = 0 ; i < Tarjetas.size(); i++){
							if (i == Tarjetas.size() - 1){
								Credito << Tarjetas[i].credito;
							}
							else{
								Credito << Tarjetas[i].credito << endl;
							}
						}
						B = true;
					    Credito.close();
					    return;
					    break;
			    		}
			    	else{
			    		cout << "\n\t\t\t\t\tNo se pudo realizar la compra, saldo insuficiente\n";
			    		system ("pause");
			    		break;
					}
				}
				else{
				cout << "\n\t\t\t\t\t\tTarjeta no encontrada\n";
				system ("pause");
				break;
				}
			}
			case 2:{
				int Dinero;
				cout << "\n\t\t\t\t\tEl valor de las entradas es de: " << ValorN << "$\n\t\t\t\t\t¿Con cuanto va a pagar?: ";
				cin >> Dinero;
				if (Dinero - ValorN > 0){
					cout << "\n\t\t\t\t\t\tPago realizado con exito.\n\t\t\t\t\t\tSu cambio es de: " << Dinero - ValorN << "$\n\n";
					B = true;
					return;
				}
				else if (Dinero - ValorN == 0){
					cout << "\n\t\t\t\t\t\tPago realizado con exito.\n";
					B = true;
					return;
				}
				else 
					cout << "\n\t\t\t\t\tDinero no suficiente para pagar las entradas.\n";
					system ("pause");
				break;
			}
			case 3:{
				cout << "\n\t\t\t\t\t\tReserva cancelada con exito\n";
				break;
			}
			default :{
				cout << "\n\t\t\t\t\t\t  Opción no valida\n";
				system ("pause");
				break;
			}
		}
	}while (op != 3 );
	
}

void Guardar_Sillas(string Sillas[11][20], string Pelicula){
	ofstream Fila_A, Fila_B, Fila_C, Fila_D, Fila_E, Fila_F, Fila_G, Fila_H, Fila_I, Fila_J, Fila_K;
	if (Pelicula == "Thor vs Superman"){
		remove("Reservas//Thor//Fila_A.txt");
		remove("Reservas//Thor//Fila_B.txt");
		remove("Reservas//Thor//Fila_C.txt");
		remove("Reservas//Thor//Fila_D.txt");
		remove("Reservas//Thor//Fila_E.txt");
		remove("Reservas//Thor//Fila_F.txt");
		remove("Reservas//Thor//Fila_G.txt");
		remove("Reservas//Thor//Fila_H.txt");
		remove("Reservas//Thor//Fila_I.txt");
		remove("Reservas//Thor//Fila_J.txt");
		remove("Reservas//Thor//Fila_K.txt");
		Fila_A.open("Reservas//Thor//Fila_A.txt");
		Fila_B.open("Reservas//Thor//Fila_B.txt");
		Fila_C.open("Reservas//Thor//Fila_C.txt");
		Fila_D.open("Reservas//Thor//Fila_D.txt");
		Fila_E.open("Reservas//Thor//Fila_E.txt");
		Fila_F.open("Reservas//Thor//Fila_F.txt");
		Fila_G.open("Reservas//Thor//Fila_G.txt");
		Fila_H.open("Reservas//Thor//Fila_H.txt");
		Fila_I.open("Reservas//Thor//Fila_I.txt");
		Fila_J.open("Reservas//Thor//Fila_J.txt");
		Fila_K.open("Reservas//Thor//Fila_K.txt");
		
	}
	else if (Pelicula == "Pequeño pero Peligroso 2"){
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_A.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_B.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_C.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_D.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_E.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_F.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_G.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_H.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_I.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_J.txt");
		remove("Reservas//Pequeño_Pero_Peligroso//Fila_K.txt");
		Fila_A.open("Reservas//Pequeño_Pero_Peligroso//Fila_A.txt");
		Fila_B.open("Reservas//Pequeño_Pero_Peligroso//Fila_B.txt");
		Fila_C.open("Reservas//Pequeño_Pero_Peligroso//Fila_C.txt");
		Fila_D.open("Reservas//Pequeño_Pero_Peligroso//Fila_D.txt");
		Fila_E.open("Reservas//Pequeño_Pero_Peligroso//Fila_E.txt");
		Fila_F.open("Reservas//Pequeño_Pero_Peligroso//Fila_F.txt");
		Fila_G.open("Reservas//Pequeño_Pero_Peligroso//Fila_G.txt");
		Fila_H.open("Reservas//Pequeño_Pero_Peligroso//Fila_H.txt");
		Fila_I.open("Reservas//Pequeño_Pero_Peligroso//Fila_I.txt");
		Fila_J.open("Reservas//Pequeño_Pero_Peligroso//Fila_J.txt");
		Fila_K.open("Reservas//Pequeño_Pero_Peligroso//Fila_K.txt");
	}
	else if (Pelicula == "Pequeño pero Peligroso 2"){
		remove("Reservas//Rapidos_Y_Furiosos//Fila_A.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_B.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_C.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_D.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_E.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_F.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_G.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_H.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_I.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_J.txt");
		remove("Reservas//Rapidos_Y_Furiosos//Fila_K.txt");
		Fila_A.open("Reservas//Rapidos_Y_Furiosos//Fila_A.txt");
		Fila_B.open("Reservas//Rapidos_Y_Furiosos//Fila_B.txt");
		Fila_C.open("Reservas//Rapidos_Y_Furiosos//Fila_C.txt");
		Fila_D.open("Reservas//Rapidos_Y_Furiosos//Fila_D.txt");
		Fila_E.open("Reservas//Rapidos_Y_Furiosos//Fila_E.txt");
		Fila_F.open("Reservas//Rapidos_Y_Furiosos//Fila_F.txt");
		Fila_G.open("Reservas//Rapidos_Y_Furiosos//Fila_G.txt");
		Fila_H.open("Reservas//Rapidos_Y_Furiosos//Fila_H.txt");
		Fila_I.open("Reservas//Rapidos_Y_Furiosos//Fila_I.txt");
		Fila_J.open("Reservas//Rapidos_Y_Furiosos//Fila_J.txt");
		Fila_K.open("Reservas//Rapidos_Y_Furiosos//Fila_K.txt");
	}
	for (int i = 0; i < 20; i++){
		if ( i == 19){
			Fila_A << Sillas[0][i];
			Fila_B << Sillas[1][i];
			Fila_C << Sillas[2][i];
			Fila_D << Sillas[3][i];
			Fila_E << Sillas[4][i];
			Fila_F << Sillas[5][i];
			Fila_G << Sillas[6][i];
			Fila_H << Sillas[7][i];
			Fila_I << Sillas[8][i];
			Fila_J << Sillas[9][i];
			Fila_K << Sillas[10][i];
		}
		else{
			Fila_A << Sillas[0][i] << endl;
			Fila_B << Sillas[1][i] << endl;
			Fila_C << Sillas[2][i] << endl;
			Fila_D << Sillas[3][i] << endl;
			Fila_E << Sillas[4][i] << endl;
			Fila_F << Sillas[5][i] << endl;
			Fila_G << Sillas[6][i] << endl;
			Fila_H << Sillas[7][i] << endl;
			Fila_I << Sillas[8][i] << endl;
			Fila_J << Sillas[9][i] << endl;
			Fila_K << Sillas[10][i] << endl;
		}
	}
	
	Fila_A.close();
	Fila_B.close();
	Fila_C.close();
	Fila_D.close();
	Fila_E.close();
	Fila_F.close();
	Fila_G.close();
	Fila_H.close();
	Fila_I.close();
	Fila_J.close();
	Fila_K.close();
	}

void Guardar_Reservas(string Usuario, bool A, string Pelicula, string Silla){
	if (A){
		ofstream Estado, Sillas, Usuarios;
		if (Pelicula == "Thor vs Superman"){
			ifstream estado, sillas, usuarios;
			estado.open("Reservas//Thor//Reservas//Estado.txt");
			sillas.open("Reservas//Thor//Reservas//Sillas.txt");
			usuarios.open("Reservas//Thor//Reservas//Usuario.txt");
			vector <Reserva> Reservas;
			string e, s, u;
			while(!estado.eof()){
				getline (estado, e);
				getline (sillas, s);
				getline (usuarios, u);
				Reservas.push_back(Reserva{u,s,e});
			}
			Reservas.push_back(Reserva{Usuario, Silla, "Pagada"});
			remove("Reservas//Thor//Reservas//Estado.txt");
			remove("Reservas//Thor//Reservas//Sillas.txt");
			remove("Reservas//Thor//Reservas//Usuario.txt");
			Estado.open("Reservas//Thor//Reservas//Estado.txt");
			Sillas.open("Reservas//Thor//Reservas//Sillas.txt");
			Usuarios.open("Reservas//Thor//Reservas//Usuario.txt");
			
			for (int i = 0; i < Reservas.size(); i++){
				if ( i == Reservas.size() -1){
					Estado << Reservas[i].Estado;
					Usuarios << Reservas[i].Usuario;
					Sillas << Reservas[i].Sillas;
				}
				else{
					Estado << Reservas[i].Estado << endl;
					Usuarios << Reservas[i].Usuario << endl;
					Sillas << Reservas[i].Sillas << endl;
				}
			}
			Estado.close();
			Sillas.close();
			Usuarios.close();
			estado.close();
			sillas.close();
			usuarios.close();
		}
		else if (Pelicula == "Pequeño pero Peligroso 2"){
			ifstream estado, sillas, usuarios;
			estado.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Estado.txt");
			sillas.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Sillas.txt");
			usuarios.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Usuario.txt");
			vector <Reserva> Reservas;
			string e, s, u;
			while(!estado.eof()){
				getline (estado, e);
				getline (sillas, s);
				getline (usuarios, u);
				Reservas.push_back(Reserva{u,s,e});
			}
			Reservas.push_back(Reserva{Usuario, Silla, "Pagada"});
			remove("Reservas//Pequeño_Pero_Peligroso//Reservas//Estado.txt");
			remove("Reservas//Pequeño_Pero_Peligroso//Reservas//Sillas.txt");
			remove("Reservas//Pequeño_Pero_Peligroso//Reservas//Usuario.txt");
			Estado.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Estado.txt");
			Sillas.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Sillas.txt");
			Usuarios.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Usuario.txt");
			
			for (int i = 0; i < Reservas.size(); i++){
				if ( i == Reservas.size() -1){
					Estado << Reservas[i].Estado;
					Usuarios << Reservas[i].Usuario;
					Sillas << Reservas[i].Sillas;
				}
				else{
					Estado << Reservas[i].Estado << endl;
					Usuarios << Reservas[i].Usuario << endl;
					Sillas << Reservas[i].Sillas << endl;
				}
			}
			Estado.close();
			Sillas.close();
			Usuarios.close();
			estado.close();
			sillas.close();
			usuarios.close();
		}
		else if (Pelicula == "Rapidos y furiosos 27"){
			ifstream estado, sillas, usuarios;
			estado.open("Reservas//Rapidos_Y_Furiosos//Reservas//Estado.txt");
			sillas.open("Reservas//Rapidos_Y_Furiosos//Reservas//Sillas.txt");
			usuarios.open("Reservas//Rapidos_Y_Furiosos//Reservas//Usuario.txt");
			vector <Reserva> Reservas;
			string e, s, u;
			while(!estado.eof()){
				getline (estado, e);
				getline (sillas, s);
				getline (usuarios, u);
				Reservas.push_back(Reserva{u,s,e});
			}
			Reservas.push_back(Reserva{Usuario, Silla, "Pagada"});
			remove("Reservas//Rapidos_Y_Furiosos//Reservas//Estado.txt");
			remove("Reservas//Rapidos_Y_Furiosos//Reservas//Sillas.txt");
			remove("Reservas//Rapidos_Y_Furiosos//Reservas//Usuario.txt");
			Estado.open("Reservas//Rapidos_Y_Furiosos//Reservas//Estado.txt");
			Sillas.open("Reservas//Rapidos_Y_Furiosos//Reservas//Sillas.txt");
			Usuarios.open("Reservas//Rapidos_Y_Furiosos//Reservas//Usuario.txt");
			
			for (int i = 0; i < Reservas.size(); i++){
				if ( i == Reservas.size() -1){
					Estado << Reservas[i].Estado;
					Usuarios << Reservas[i].Usuario;
					Sillas << Reservas[i].Sillas;
				}
				else{
					Estado << Reservas[i].Estado << endl;
					Usuarios << Reservas[i].Usuario << endl;
					Sillas << Reservas[i].Sillas << endl;
				}
			}
			Estado.close();
			Sillas.close();
			Usuarios.close();
			estado.close();
			sillas.close();
			usuarios.close();
		}
	}
	else if (!A){
		ofstream Estado, Sillas, Usuarios;
		if (Pelicula == "Thor vs Superman"){ifstream estado, sillas, usuarios;
			estado.open("Reservas//Thor//Reservas//Estado.txt");
			sillas.open("Reservas//Thor//Reservas//Sillas.txt");
			usuarios.open("Reservas//Thor//Reservas//Usuario.txt");
			vector <Reserva> Reservas;
			string e, s, u;
			while(!estado.eof()){
				getline (estado, e);
				getline (sillas, s);
				getline (usuarios, u);
				Reservas.push_back(Reserva{u,s,e});
			}
			Reservas.push_back(Reserva{Usuario, Silla, "Pendiente"});
			remove("Reservas//Thor//Reservas//Estado.txt");
			remove("Reservas//Thor//Reservas//Sillas.txt");
			remove("Reservas//Thor//Reservas//Usuario.txt");
			Estado.open("Reservas//Thor//Reservas//Estado.txt");
			Sillas.open("Reservas//Thor//Reservas//Sillas.txt");
			Usuarios.open("Reservas//Thor//Reservas//Usuario.txt");
			
			for (int i = 0; i < Reservas.size(); i++){
				if ( i == Reservas.size() -1){
					Estado << Reservas[i].Estado;
					Usuarios << Reservas[i].Usuario;
					Sillas << Reservas[i].Sillas;
				}
				else{
					Estado << Reservas[i].Estado << endl;
					Usuarios << Reservas[i].Usuario << endl;
					Sillas << Reservas[i].Sillas << endl;
				}
			}
			Estado.close();
			Sillas.close();
			Usuarios.close();
			estado.close();
			sillas.close();
			usuarios.close();
		}else if (Pelicula == "Pequeño pero Peligroso 2"){
			ifstream estado, sillas, usuarios;
			estado.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Estado.txt");
			sillas.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Sillas.txt");
			usuarios.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Usuario.txt");
			vector <Reserva> Reservas;
			string e, s, u;
			while(!estado.eof()){
				getline (estado, e);
				getline (sillas, s);
				getline (usuarios, u);
				Reservas.push_back(Reserva{u,s,e});
			}
			Reservas.push_back(Reserva{Usuario, Silla, "Pendiente"});
			remove("Reservas//Pequeño_Pero_Peligroso//Reservas//Estado.txt");
			remove("Reservas//Pequeño_Pero_Peligroso//Reservas//Sillas.txt");
			remove("Reservas//Pequeño_Pero_Peligroso//Reservas//Usuario.txt");
			Estado.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Estado.txt");
			Sillas.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Sillas.txt");
			Usuarios.open("Reservas//Pequeño_Pero_Peligroso//Reservas//Usuario.txt");
			
			for (int i = 0; i < Reservas.size(); i++){
				if ( i == Reservas.size() -1){
					Estado << Reservas[i].Estado;
					Usuarios << Reservas[i].Usuario;
					Sillas << Reservas[i].Sillas;
				}
				else{
					Estado << Reservas[i].Estado << endl;
					Usuarios << Reservas[i].Usuario << endl;
					Sillas << Reservas[i].Sillas << endl;
				}
			}
			Estado.close();
			Sillas.close();
			Usuarios.close();
			estado.close();
			sillas.close();
			usuarios.close();	
		}else if (Pelicula == "Rapidos y furiosos 27"){
			ifstream estado, sillas, usuarios;
			estado.open("Reservas//Rapidos_Y_Furiosos//Reservas//Estado.txt");
			sillas.open("Reservas//Rapidos_Y_Furiosos//Reservas//Sillas.txt");
			usuarios.open("Reservas//Rapidos_Y_Furiosos//Reservas//Usuario.txt");
			vector <Reserva> Reservas;
			string e, s, u;
			while(!estado.eof()){
				getline (estado, e);
				getline (sillas, s);
				getline (usuarios, u);
				Reservas.push_back(Reserva{u,s,e});
			}
			Reservas.push_back(Reserva{Usuario, Silla, "Pendiente"});
			remove("Reservas//Rapidos_Y_Furiosos//Reservas//Estado.txt");
			remove("Reservas//Rapidos_Y_Furiosos//Reservas//Sillas.txt");
			remove("Reservas//Rapidos_Y_Furiosos//Reservas//Usuario.txt");
			Estado.open("Reservas//Rapidos_Y_Furiosos//Reservas//Estado.txt");
			Sillas.open("Reservas//Rapidos_Y_Furiosos//Reservas//Sillas.txt");
			Usuarios.open("Reservas//Rapidos_Y_Furiosos//Reservas//Usuario.txt");
			
			for (int i = 0; i < Reservas.size(); i++){
				if ( i == Reservas.size() -1){
					Estado << Reservas[i].Estado;
					Usuarios << Reservas[i].Usuario;
					Sillas << Reservas[i].Sillas;
				}
				else{
					Estado << Reservas[i].Estado << endl;
					Usuarios << Reservas[i].Usuario << endl;
					Sillas << Reservas[i].Sillas << endl;
				}
			}
			Estado.close();
			Sillas.close();
			Usuarios.close();
			estado.close();
			sillas.close();
			usuarios.close();
		}	
		}
		}

void Texto_Ascii (string Texto){
	int x = Texto.size();
	x *= 4;
	x = (120 - x)/2;
	for (int i = 0; i < Texto.size(); i++){
		if (i == 0){
			for (int j = 0; j < x; j++){
				cout << " ";
			}
		}
		if (Texto[i] == '1')
			cout << " ## ";
		if (Texto[i] == '2')
			cout << "### ";
		if (Texto[i] == '3')
			cout << "### ";
		if (Texto[i] == '4')
			cout << "# # ";
		if (Texto[i] == '5')
			cout << "### ";
		if (Texto[i] == '6')
			cout << "### ";
		if (Texto[i] == '7')
			cout << "### ";
		if (Texto[i] == '8')
			cout << "### ";
		if (Texto[i] == '9')
			cout << "### ";
		if (Texto[i] == '0')
			cout << "### ";
		if (Texto[i] == 'A' || Texto[i] == 'a')
			cout << " #  ";
		if (Texto[i] == 'B' || Texto[i] == 'b')
			cout << "##  ";
		if (Texto[i] == 'C' || Texto[i] == 'c')
			cout << " ## ";
		if (Texto[i] == 'D' || Texto[i] == 'd')
			cout << "##  ";
		if (Texto[i] == 'E' || Texto[i] == 'e')
			cout << "### ";
		if (Texto[i] == 'F' || Texto[i] == 'f')
			cout << "### ";
		if (Texto[i] == 'G' || Texto[i] == 'g')
			cout << " ## ";
		if (Texto[i] == 'H' || Texto[i] == 'h')
			cout << "# # ";
		if (Texto[i] == 'I' || Texto[i] == 'i')
			cout << "### ";
		if (Texto[i] == 'J' || Texto[i] == 'j')
			cout << " ## ";
		if (Texto[i] == 'K' || Texto[i] == 'k')
			cout << "# # ";
		if (Texto[i] == 'L' || Texto[i] == 'l')
			cout << "#   ";
		if (Texto[i] == 'M' || Texto[i] == 'm')
			cout << "# # ";
		if (Texto[i] == 'N' || Texto[i] == 'n')
			cout << "### ";
		if (Texto[i] == 'Ñ' || Texto[i] == 'ñ')
			cout << "*** ";
		if (Texto[i] == 'O' || Texto[i] == 'o')
			cout << " #  ";
		if (Texto[i] == 'P' || Texto[i] == 'p')
			cout << "##  ";
		if (Texto[i] == 'Q' || Texto[i] == 'q')
			cout << " #  ";
		if (Texto[i] == 'R' || Texto[i] == 'r')
			cout << "##  ";
		if (Texto[i] == 'S' || Texto[i] == 's')
			cout << " ## ";
		if (Texto[i] == 'T' || Texto[i] == 't')
			cout << "### ";
		if (Texto[i] == 'U' || Texto[i] == 'u')
			cout << "# # ";
		if (Texto[i] == 'V' || Texto[i] == 'v')
			cout << "# # ";
		if (Texto[i] == 'W' || Texto[i] == 'w')
			cout << "# # ";
		if (Texto[i] == 'X' || Texto[i] == 'x')
			cout << "# # ";
		if (Texto[i] == 'Y' || Texto[i] == 'y')
			cout << "# # ";
		if (Texto[i] == 'Z' || Texto[i] == 'z')
			cout << "### ";
		if (Texto[i] == ' ')
			cout << "    ";
	} cout << endl;
	for (int i = 0; i < Texto.size(); i++){
		if (i == 0){
			for (int j = 0; j < x; j++){
				cout << " ";
			}
		}
		if (Texto[i] == '1')
			cout << "# # ";
		if (Texto[i] == '2')
			cout << "  # ";
		if (Texto[i] == '3')
			cout << "  # ";
		if (Texto[i] == '4')
			cout << "# # ";
		if (Texto[i] == '5')
			cout << "#   ";
		if (Texto[i] == '6')
			cout << "#   ";
		if (Texto[i] == '7')
			cout << "  # ";
		if (Texto[i] == '8')
			cout << "# # ";
		if (Texto[i] == '9')
			cout << "# # ";
		if (Texto[i] == '0')
			cout << "# # ";
		if (Texto[i] == 'A' || Texto[i] == 'a')
			cout << "# # ";
		if (Texto[i] == 'B' || Texto[i] == 'b')
			cout << "# # ";
		if (Texto[i] == 'C' || Texto[i] == 'c')
			cout << "#   ";
		if (Texto[i] == 'D' || Texto[i] == 'd')
			cout << "# # ";
		if (Texto[i] == 'E' || Texto[i] == 'e')
			cout << "#   ";
		if (Texto[i] == 'F' || Texto[i] == 'f')
			cout << "#   ";
		if (Texto[i] == 'G' || Texto[i] == 'g')
			cout << "#   ";
		if (Texto[i] == 'H' || Texto[i] == 'h')
			cout << "# # ";
		if (Texto[i] == 'I' || Texto[i] == 'i')
			cout << " #  ";
		if (Texto[i] == 'J' || Texto[i] == 'j')
			cout << "  # ";
		if (Texto[i] == 'K' || Texto[i] == 'k')
			cout << "# # ";
		if (Texto[i] == 'L' || Texto[i] == 'l')
			cout << "#   ";
		if (Texto[i] == 'M' || Texto[i] == 'm')
			cout << "### ";
		if (Texto[i] == 'N' || Texto[i] == 'n')
			cout << "# # ";
		if (Texto[i] == 'Ñ' || Texto[i] == 'ñ')
			cout << "### ";
		if (Texto[i] == 'O' || Texto[i] == 'o')
			cout << "# # ";
		if (Texto[i] == 'P' || Texto[i] == 'p')
			cout << "# # ";
		if (Texto[i] == 'Q' || Texto[i] == 'q')
			cout << "# # ";
		if (Texto[i] == 'R' || Texto[i] == 'r')
			cout << "# # ";
		if (Texto[i] == 'S' || Texto[i] == 's')
			cout << "#   ";
		if (Texto[i] == 'T' || Texto[i] == 't')
			cout << " #  ";
		if (Texto[i] == 'U' || Texto[i] == 'u')
			cout << "# # ";
		if (Texto[i] == 'V' || Texto[i] == 'v')
			cout << "# # ";
		if (Texto[i] == 'W' || Texto[i] == 'w')
			cout << "# # ";
		if (Texto[i] == 'X' || Texto[i] == 'x')
			cout << "# # ";
		if (Texto[i] == 'Y' || Texto[i] == 'y')
			cout << "# # ";
		if (Texto[i] == 'Z' || Texto[i] == 'z')
			cout << "  # ";
		if (Texto[i] == ' ')
			cout << "    ";
	} cout << endl;
	for (int i = 0; i < Texto.size(); i++){
		if (i == 0){
			for (int j = 0; j < x; j++){
				cout << " ";
			}
		}
		if (Texto[i] == '1')
			cout << "  # ";
		if (Texto[i] == '2')
			cout << "  # ";
		if (Texto[i] == '3')
			cout << " ## ";
		if (Texto[i] == '4')
			cout << "### ";
		if (Texto[i] == '5')
			cout << "### ";
		if (Texto[i] == '6')
			cout << "### ";
		if (Texto[i] == '7')
			cout << " ## ";
		if (Texto[i] == '8')
			cout << "### ";
		if (Texto[i] == '9')
			cout << "### ";
		if (Texto[i] == '0')
			cout << "# # ";
		if (Texto[i] == 'A' || Texto[i] == 'a')
			cout << "### ";
		if (Texto[i] == 'B' || Texto[i] == 'b')
			cout << "##  ";
		if (Texto[i] == 'C' || Texto[i] == 'c')
			cout << "#   ";
		if (Texto[i] == 'D' || Texto[i] == 'd')
			cout << "# # ";
		if (Texto[i] == 'E' || Texto[i] == 'e')
			cout << "##  ";
		if (Texto[i] == 'F' || Texto[i] == 'f')
			cout << "##  ";
		if (Texto[i] == 'G' || Texto[i] == 'g')
			cout << "# # ";
		if (Texto[i] == 'H' || Texto[i] == 'h')
			cout << "### ";
		if (Texto[i] == 'I' || Texto[i] == 'i')
			cout << " #  ";
		if (Texto[i] == 'J' || Texto[i] == 'j')
			cout << "  # ";
		if (Texto[i] == 'K' || Texto[i] == 'k')
			cout << "# # ";
		if (Texto[i] == 'L' || Texto[i] == 'l')
			cout << "#   ";
		if (Texto[i] == 'M' || Texto[i] == 'm')
			cout << "### ";
		if (Texto[i] == 'N' || Texto[i] == 'n')
			cout << "# # ";
		if (Texto[i] == 'Ñ' || Texto[i] == 'ñ')
			cout << "# # ";
		if (Texto[i] == 'O' || Texto[i] == 'o')
			cout << "# # ";
		if (Texto[i] == 'P' || Texto[i] == 'p')
			cout << "##  ";
		if (Texto[i] == 'Q' || Texto[i] == 'q')
			cout << "# # ";
		if (Texto[i] == 'R' || Texto[i] == 'r')
			cout << "##  ";
		if (Texto[i] == 'S' || Texto[i] == 's')
			cout << " #  ";
		if (Texto[i] == 'T' || Texto[i] == 't')
			cout << " #  ";
		if (Texto[i] == 'U' || Texto[i] == 'u')
			cout << "# # ";
		if (Texto[i] == 'V' || Texto[i] == 'v')
			cout << "# # ";
		if (Texto[i] == 'W' || Texto[i] == 'w')
			cout << "### ";
		if (Texto[i] == 'X' || Texto[i] == 'x')
			cout << " #  ";
		if (Texto[i] == 'Y' || Texto[i] == 'y')
			cout << " #  ";
		if (Texto[i] == 'Z' || Texto[i] == 'z')
			cout << " #  ";
		if (Texto[i] == ' ')
			cout << "    ";
	} cout << endl;
	for (int i = 0; i < Texto.size(); i++){
		if (i == 0){
			for (int j = 0; j < x; j++){
				cout << " ";
			}
		}
		if (Texto[i] == '1')
			cout << "  # ";
		if (Texto[i] == '2')
			cout << " #  ";
		if (Texto[i] == '3')
			cout << "  # ";
		if (Texto[i] == '4')
			cout << "  # ";
		if (Texto[i] == '5')
			cout << "  # ";
		if (Texto[i] == '6')
			cout << "# # ";
		if (Texto[i] == '7')
			cout << "  # ";
		if (Texto[i] == '8')
			cout << "# # ";
		if (Texto[i] == '9')
			cout << "  # ";
		if (Texto[i] == '0')
			cout << "# # ";
		if (Texto[i] == 'A' || Texto[i] == 'a')
			cout << "# # ";
		if (Texto[i] == 'B' || Texto[i] == 'b')
			cout << "# # ";
		if (Texto[i] == 'C' || Texto[i] == 'c')
			cout << "#   ";
		if (Texto[i] == 'D' || Texto[i] == 'd')
			cout << "# # ";
		if (Texto[i] == 'E' || Texto[i] == 'e')
			cout << "#   ";
		if (Texto[i] == 'F' || Texto[i] == 'f')
			cout << "#   ";
		if (Texto[i] == 'G' || Texto[i] == 'g')
			cout << "# # ";
		if (Texto[i] == 'H' || Texto[i] == 'h')
			cout << "# # ";
		if (Texto[i] == 'I' || Texto[i] == 'i')
			cout << " #  ";
		if (Texto[i] == 'J' || Texto[i] == 'j')
			cout << "# # ";
		if (Texto[i] == 'K' || Texto[i] == 'k')
			cout << "# # ";
		if (Texto[i] == 'L' || Texto[i] == 'l')
			cout << "#   ";
		if (Texto[i] == 'M' || Texto[i] == 'm')
			cout << "# # ";
		if (Texto[i] == 'N' || Texto[i] == 'n')
			cout << "# # ";
		if (Texto[i] == 'Ñ' || Texto[i] == 'ñ')
			cout << "# # ";
		if (Texto[i] == 'O' || Texto[i] == 'o')
			cout << "# # ";
		if (Texto[i] == 'P' || Texto[i] == 'p')
			cout << "#   ";
		if (Texto[i] == 'Q' || Texto[i] == 'q')
			cout << " ## ";
		if (Texto[i] == 'R' || Texto[i] == 'r')
			cout << "# # ";
		if (Texto[i] == 'S' || Texto[i] == 's')
			cout << "  # ";
		if (Texto[i] == 'T' || Texto[i] == 't')
			cout << " #  ";
		if (Texto[i] == 'U' || Texto[i] == 'u')
			cout << "# # ";
		if (Texto[i] == 'V' || Texto[i] == 'v')
			cout << "# # ";
		if (Texto[i] == 'W' || Texto[i] == 'w')
			cout << "### ";
		if (Texto[i] == 'X' || Texto[i] == 'x')
			cout << "# # ";
		if (Texto[i] == 'Y' || Texto[i] == 'y')
			cout << " #  ";
		if (Texto[i] == 'Z' || Texto[i] == 'z')
			cout << "#   ";
		if (Texto[i] == ' ')
			cout << "    ";
	} cout << endl;
		for (int i = 0; i < Texto.size(); i++){
			if (i == 0){
			for (int j = 0; j < x; j++){
				cout << " ";
			}
		}
		if (Texto[i] == '1')
			cout << "  # ";
		if (Texto[i] == '2')
			cout << "### ";
		if (Texto[i] == '3')
			cout << "### ";
		if (Texto[i] == '4')
			cout << "  # ";
		if (Texto[i] == '5')
			cout << "### ";
		if (Texto[i] == '6')
			cout << "### ";
		if (Texto[i] == '7')
			cout << "  # ";
		if (Texto[i] == '8')
			cout << "### ";
		if (Texto[i] == '9')
			cout << "### ";
		if (Texto[i] == '0')
			cout << "### ";
		if (Texto[i] == 'A' || Texto[i] == 'a')
			cout << "# # ";
		if (Texto[i] == 'B' || Texto[i] == 'b')
			cout << "##  ";
		if (Texto[i] == 'C' || Texto[i] == 'c')
			cout << " ## ";
		if (Texto[i] == 'D' || Texto[i] == 'd')
			cout << "##  ";
		if (Texto[i] == 'E' || Texto[i] == 'e')
			cout << "### ";
		if (Texto[i] == 'F' || Texto[i] == 'f')
			cout << "#   ";
		if (Texto[i] == 'G' || Texto[i] == 'g')
			cout << " ## ";
		if (Texto[i] == 'H' || Texto[i] == 'h')
			cout << "# # ";
		if (Texto[i] == 'I' || Texto[i] == 'i')
			cout << "### ";
		if (Texto[i] == 'J' || Texto[i] == 'j')
			cout << " #  ";
		if (Texto[i] == 'K' || Texto[i] == 'k')
			cout << "# # ";
		if (Texto[i] == 'L' || Texto[i] == 'l')
			cout << "### ";
		if (Texto[i] == 'M' || Texto[i] == 'm')
			cout << "# # ";
		if (Texto[i] == 'N' || Texto[i] == 'n')
			cout << "# # ";
		if (Texto[i] == 'Ñ' || Texto[i] == 'ñ')
			cout << "# # ";
		if (Texto[i] == 'O' || Texto[i] == 'o')
			cout << " #  ";
		if (Texto[i] == 'P' || Texto[i] == 'p')
			cout << "#   ";
		if (Texto[i] == 'Q' || Texto[i] == 'q')
			cout << "  # ";
		if (Texto[i] == 'R' || Texto[i] == 'r')
			cout << "# # ";
		if (Texto[i] == 'S' || Texto[i] == 's')
			cout << "##  ";
		if (Texto[i] == 'T' || Texto[i] == 't')
			cout << " #  ";
		if (Texto[i] == 'U' || Texto[i] == 'u')
			cout << "### ";
		if (Texto[i] == 'V' || Texto[i] == 'v')
			cout << " #  ";
		if (Texto[i] == 'W' || Texto[i] == 'w')
			cout << "# # ";
		if (Texto[i] == 'X' || Texto[i] == 'x')
			cout << "# # ";
		if (Texto[i] == 'Y' || Texto[i] == 'y')
			cout << " #  ";
		if (Texto[i] == 'Z' || Texto[i] == 'z')
			cout << "### ";
		if (Texto[i] == ' ')
			cout << "    ";
	} cout << endl;
}





	
	
	
	
