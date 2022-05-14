#include "Cinema.h"
Cinema::Cinema()
{
	miLista = new Lista;
	miListMovies = new ListMovies;
	miListFunct = new ListFunct;
	miAsientos = new Asientos;
	miListArch = new ListArch;
	miListUsuario = new ListUsuario;
	miArbolMovies = new ArbolMovies;
	miArbolHorario = new ArbolHorario;
	miBoletos = new ListBoletos;
	setlocale(LC_ALL, "");
}
Cinema::~Cinema() {}
void Cinema::Imprimir(vector<string>&str, int num) 
{
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "\t" << str[i] << "\n" << endl;
	}
	cout << "________________________________" << endl;
}
void Cinema::Menu() 
{
	int opc,val = 0;
	do
	{
		cout << "____________Cinema____________" << endl;
		Imprimir(Menu_1, Menu_1.size());
		cout << "Digite la opión deseada (1/2/3) : ";
		cin >> opc;
		system("cls");
		if (opc > 0 && opc < 4)
			val = 1;
	} while (val == 0);
		switch (opc)
		{
		case 1:
			Menu_Usuario();
			break;
		case 2:
			Validar_Admin();
			break;
		default:
			exit(0);
			break;
		}
	
}
void Cinema::Validar_Admin() 
{
	string usuario, contra;
	bool val = false;
	int fail = 0;
	do
	{
		cout << "\n_______Validación_______" << endl<<endl;
		cout << "  Administrador : ";
		cin.ignore();
		getline(cin, usuario);
		cout << "  Contraseña : ";
		getline(cin, contra);
		system("cls");
		val = miLista->Buscar_Val_Admin(usuario, contra);
		if (val == true)
		{
			Menu_Admin();
		}
		if (val == false)
		{
			fail += 1;
		}
		if (fail == 3)
		{
			cout << "Por motivos de seguridad seras regresado al menu." << endl;
			Menu();
		}
	} while (val == false);
}
void Cinema::Menu_Admin() 
{
	Boletos Encont;
	int opc, val = 0,codi;
	do
	{
		cout << "____________Menu de Administrador____________" << endl;
		Imprimir(Menu_Adm, Menu_Adm.size());
		cout << "Digite la opión deseada (1/2/3/4/5/6/7) : ";
		cin >> opc;
		system("cls");
		if (opc > 0 && opc < 8)
			val = 1;
	} while (val == 0);
	switch (opc)
	{
	case 1:
		miLista->Mostrar_Admin();
		system("pause()");
		system("cls");
		Menu_Admin();
		break;
	case 2:
	    Agregar_Admin();
		Menu_Admin();
		break;
	case 3:
		Eliminar_Admin();
		Menu_Admin();
		break;
	case 4:
		cout << "Digite el codigo del boleto que quiere validar : ";
		cin >> codi;
		Encont = miBoletos->Buscar_Codi(codi);
		cout << "Información del Boleto : "<<endl;
		cout << "Codigo : " << Encont.codi << endl;
		cout << "Correo : " << Encont.correo << endl;
		cout << "Nombre : " << Encont.nom << endl;
		cout << "Película : " << Encont.peli << endl;
		cout << "Hora : " << Encont.hrs << endl;
		cout << "Sala : " << Encont.sala << endl;
		cout << "Asiento : " << Encont.sala << endl;
		system("pause()");
		system("cls");
		Menu_Admin();
		break;
	case 5:
		Edit_Movie();
		Menu_Admin();
		break;
	case 6:
		miListUsuario->Mostrar_Usuarios();
		system("pause()");
		system("cls");
		Menu_Admin();
		break;
	default:
		Menu();
		break;
	}
	
}
void Cinema::LeeryCopiarAdmin() 
{
	string usuario="", contra ="";
	ifstream file;
	file.open("Administrador.csv");
	string line;
	int i = 0;
	while (file.good())
	{

		getline(file, line);//2
		if (!(i == 0))
		{
			for (int n = 0; n < line.length(); n++)
			{
				contra.push_back(line[n]);

			}
			
		}
		if (contra != "" && usuario != "")
		{
			miLista->Insertar_Fin(usuario, contra);
			usuario = ""; contra = "";
		}
		getline(file, line, ';');//1
		
		for (int n = 0; n < line.length(); n++)
			{
				usuario.push_back(line[n]);
			}
		i++;
	}
	/*numAdmin = i-1;*/
}
void Cinema::Agregar_Admin()
{
	string usuario, contra, subcontra;
	bool val = false;
	int cont = 0;
	do
	{
		cout << "___________Agregar_Adminstrador__________" << endl << endl << endl;
		cout << " Digite el nombre del administrador : ";
		cin.ignore();
		getline(cin, usuario);
		cout << " Digite la contraseña : ";
		getline(cin, contra);
		cout << " Digite de nuevo la contraseña : ";
		getline(cin, subcontra);
		system("cls");
		if (contra == subcontra)
		{
			val = true;
		}
		cont++;
		if (cont == 3)
			Menu_Admin();

	} while (val == false);
	fstream file("Administrador.csv", ios::out | ios::app);
	if (file.is_open())
	{
		file << usuario << ";" << contra << endl; 
	}
	miLista->Insertar_Fin(usuario, contra);
}
void Cinema::Eliminar_Admin()
{
	string usuario;
	bool val = false;
	int cont = 0;
	do
	{
		cout << "___________Eliminar_Adminstrador__________" << endl << endl << endl;
		cout << " Nombre del administrador que quieres eliminar: ";
		cin.ignore();
		getline(cin, usuario);
		val = miLista->Buscar_Admin(usuario);
		system("cls");
		cont++;
		if (cont == 3)
			Menu_Admin();
	} while (val == false);
	miLista->Extrae_Inter(usuario);
	miLista->Reiniciar_BD();
}
void Cinema::LeeryCopiarMovie()
{
	Califica* principio;
	bool ok = false,val = false;
	string peli = "", gene = "",calif = "";
	float cal = 0.0,fnum;
	int tnum;
	string caux,temp;
	int m = 0,num,pos = 0;
	ifstream file;
	file.open("List_Movies.csv");
	string line;
	int i = 0;
	while (file.good())
	{

		getline(file, line);//3 calif
		if (!(i == 0))
		{
			ID = i;
			ok = false;
			for (int n = 0; n < line.length(); n++)
			{
				
				calif.push_back(line[n]);
				if (line[n] == '.')
				{
					pos = n + 1;
					
				}
	
				if (pos == n)
				{
					ok = true;
				}
					
			}
			if (ok == true)
			{
				for (int u = 0; u < calif.length(); u++)
				{
					if (u == pos)
					{
						caux.push_back(calif[u]);
					}
					if (u < pos - 1)
					{
						temp.push_back(calif[u]);
					}
				}
			}
			tnum = stoi(calif);
			
			/*string::size_type sz;
			cal = stof(calif, &sz);*/
			if (ok == true)
			{
				num = stoi(caux);
				fnum = (float)num / 10;
				cal = (float)tnum + fnum;
			}

		}
		if (peli != "" && gene != "" && calif != "")
		{
			
			
			miListMovies->Insertar_Movie(peli,gene,cal,ID);
			miListMovies->Insertar_Alfa(peli, gene, cal, ID);
			miArbolMovies->Crear_Nodo(peli, gene, cal, ID);
			principio = miArbolMovies->Consultar_Raiz();
			miArbolMovies->Insertar(principio);
			peli = ""; gene = ""; calif = ""; caux = "";
			cal = 0.0;
		}
		getline(file, line, ';');//1 peli

		for (int n = 0; n < line.length(); n++)
		{
			peli.push_back(line[n]);
		}
		getline(file, line, ';');//2 gene

		for (int n = 0; n < line.length(); n++)
		{
			gene.push_back(line[n]);
		}
		i++;
	
	}
}
void Cinema::Edit_Movie() 
{
	int opc, val = 0;
	string buscar;
	do
	{
		cout << "____________Editar Películas____________" << endl;
		Imprimir(Menu_Edit, Menu_Edit.size());
		cout << "Digite la opión deseada (1/2/3/4/5/6/7) : ";
		cin >> opc;
		system("cls");
		if (opc > 0 && opc < 8)
			val = 1;
	} while (val == 0);
	switch (opc)
	{
	case 1:
		miListMovies->Mostrar_Movie();
		system("pause()");
		system("cls");
		Edit_Movie();
		break;
	case 2:
		Agregar_Movie();
		Edit_Movie();
		break;
	case 3:
		Eliminar_Movie();
		Edit_Movie();
		break;
	case 4: //Mostrar Funciones
		miListFunct->Mostrar_Sala_Hora();
		system("pause()");
		system("cls");
		Edit_Movie();
		break;
	case 5: //Agregar Funciones
		Agregar_Sala_Hora();
		Edit_Movie();
		break;
	case 6: //Eliminar Funciones
		Eliminar_Sala_Hora();
		Edit_Movie();
		break;
	default:
		Menu_Admin();
		break;
	}
}
void Cinema::Agregar_Movie() 
{
	Califica* principio;
	string Peli, Gene;
	float Cali;
	
	cout << "___________Agregar_Película__________" << endl << endl << endl;
	cout << " Digite el nombre de la película : ";
	cin.ignore();
	getline(cin, Peli);
	cout << " Digite el genero de la película : ";
	getline(cin, Gene);
	cout << " Digite la calificación de la película : ";
	cin >> Cali;
	ID++;

	system("cls");
		

	fstream file("List_Movies.csv", ios::out | ios::app);
	if (file.is_open())
	{
		file << Peli << ";" << Gene <<";" <<  to_string(Cali) << ";" << to_string(ID) << endl;
	}
	miListMovies->Insertar_Movie(Peli, Gene,Cali,ID);
	miListMovies->Insertar_Alfa(Peli, Gene, Cali, ID);
	miArbolMovies->Crear_Nodo(Peli, Gene, Cali, ID);
	principio = miArbolMovies->Consultar_Raiz();
	miArbolMovies->Insertar(principio);
}
void Cinema::Eliminar_Movie()
{
	string val;
	int extpeli;
	Califica* principio;
	
	cout << "___________Eliminar_Película__________" << endl << endl << endl;
	miListMovies->Mostrar_Movie_y_Seleccionar();
	cout << "\n ____________________________________" << endl;
	cout << " Digite el número asignado a la película que quieres eliminar: ";
	cin >> extpeli;
	miListMovies->Extrae_Inter_Alfa(extpeli);
	
	principio = miArbolMovies->Consultar_Raiz();
	if (!principio)
		cout << "" ;
	else
		miArbolMovies->Extraer(NULL, principio, extpeli, "");
		

	val = miListMovies->Extrae_Inter_Movie(extpeli);
	system("cls");
	if (val != "")
	{
		cout << "Se elimino la película con el nombre de " << val << endl;
		miListFunct->Extrae_Peli(val);
		miListFunct->Reiniciar_BD();
		miListMovies->Reiniciar_BD_Movie();
	}
	system("pause()");
	system("cls");
	

}
void Cinema::LeeryCopiarSalaHora()
{
	Hora* prin;
	string peli = "", sal = "", hrs = "", nomfun = "", ShrsI = "", ShrsF = "";
	int HrsI = 0, HrsF = 0,Sal = 0;
	bool ok = false, ok2 = false,ok3 = false;
	ifstream file;
	file.open("Funciones_Movies.csv");
	string line;
	int i = 0;
	while (file.good())
	{

		getline(file, line);//6 NumFin
		if (!(i == 0))
		{
			ID2 = i;
			for (int n = 0; n < line.length(); n++)
			{
				ShrsF.push_back(line[n]);
				ok2 = true;
			}
			if (ok2 == true)
			{
				HrsF = stoi(ShrsF);
				ok2 = false;
			}
			
		}

		if (peli != "" && sal != "" && hrs != "" && nomfun != "" && ShrsI != "" && ShrsF != "")
		{

			
			miListFunct->Insertar_Sala_Hora(nomfun, Sal, hrs, peli, HrsI, HrsF,ID2);
			miArbolHorario->Crear_Nodo(nomfun, Sal, hrs, peli, HrsI, HrsF);
			prin = miArbolHorario->Consultar_Raiz();
			miArbolHorario->Insertar(prin);
			
			peli = ""; sal = ""; hrs = ""; nomfun = ""; ShrsI = ""; ShrsF = "";

		}
		getline(file, line, ';');//1 Funciones

		for (int n = 0; n < line.length(); n++)
		{
			nomfun.push_back(line[n]);
		}
		getline(file, line, ';');//2 Sala

		for (int n = 0; n < line.length(); n++)
		{
			sal.push_back(line[n]);
			ok3 = true;
		}
		if (ok3 == true)
		{
			Sal = stoi(sal);
			ok3 = false;
			
		}
		
		getline(file, line, ';');//3 Hora

		for (int n = 0; n < line.length(); n++)
		{
			hrs.push_back(line[n]);
		}
		getline(file, line, ';');//4 Peli

		for (int n = 0; n < line.length(); n++)
		{
			peli.push_back(line[n]);
		}
		getline(file, line, ';');//5 NumHrsIni

		for (int n = 0; n < line.length(); n++)
		{
			ShrsI.push_back(line[n]);
			ok = true;
		}
		if (ok == true) 
		{
			HrsI = stoi(ShrsI);
			ok = false;
		}
		
		i++;

	}
}
void Cinema::Agregar_Sala_Hora()
{
	Hora* prin;
	string peli , hrs , nomfun,aux ;
	int HrsI, HrsF,sala,fun;

	cout << "___________Agregar_Sala_y_Hora__________" << endl << endl << endl;
	cout << " Digite el nombre de la película : ";
	cin.ignore();
	getline(cin, peli);
	cout << " Digite el número de sala : ";
	cin >> sala;
	cout << " Digite la hora de inicio con (:) : ";
	getline(cin, hrs);
	cout << " Digite la hora de inicio número : ";//1800
	cin >> HrsI;
	cout << " Digite la hora de fin número : ";//1900
	cin >> HrsF;
	nomfun.push_back('f');
	fun = ID + rand() %1000;
	ID2++;
	aux =to_string(fun);
	for (int n = 0; n < aux.length(); n++)
	{
		nomfun.push_back(aux[n]);
	}
	system("cls");

	fstream file("Funciones_Movies.csv", ios::out | ios::app);
	if (file.is_open())
	{
		file << nomfun << ";" << to_string(sala) << ";" << hrs<< ";" << peli << ";" << to_string(HrsI) << ";" << to_string(HrsF) << endl;
	}
	miListFunct->Insertar_Sala_Hora(nomfun, sala, hrs, peli, HrsI, HrsF,ID2);
	miArbolHorario->Crear_Nodo(nomfun, sala, hrs, peli, HrsI, HrsF);
	prin = miArbolHorario->Consultar_Raiz();
	miArbolHorario->Insertar(prin);
}
void Cinema::Eliminar_Sala_Hora()
{
	Hora* prin;
	string hrs,val ;
	int sala;
	
	cout << "___________Eliminar_Sala_Hora_________" << endl << endl << endl;
	cout << " Número de la sala que se quiere eliminar : ";
	cin >> sala;
	cout << " Hora que se quiere eliminar con (:) : ";
	cin.ignore();
	getline(cin, hrs);
	/*prin = miArbolHorario->Consultar_Raiz();
	if (!prin)
		cout << "";
	else
		miArbolHorario->Extraer(NULL, prin, extpeli, "");*/
		


	val = miListFunct->Extrae_Inter(hrs, sala);
	system("cls");
	if (val != "")
	{
		cout << "Se elimino la película con el nombre de " << val << endl;
		miListFunct->Reiniciar_BD();
	}
	system("pause()");
	system("cls");
	
}
void Cinema::LeeryCopiarUsu()
{
	bool ok = false;
	string correo = "", usuario = "", contra = "",dinero = "";
	int cash;
	ifstream file;
	file.open("Usuario_Cinema.csv");
	string line;
	int i = 0;
	while (file.good())
	{

		getline(file, line);//4 Dinero
		if (!(i == 0))
		{
			for (int n = 0; n < line.length(); n++)
			{
				dinero.push_back(line[n]);
				
				ok = true;
			}
			if (ok == true)
			{
				cash = stoi(dinero);
				ok = false;
			}
		}
		if (correo != "" && usuario != ""&& contra != ""&& dinero != "")
		{
			miListUsuario->Insertar_Fin(correo, usuario, contra, cash);
			
			usuario = ""; contra = ""; correo = ""; dinero = "";
		}
		getline(file, line, ';');//1 Correo

		for (int n = 0; n < line.length(); n++)
		{
			correo.push_back(line[n]);
		}
		getline(file, line, ';');//2  Nombre

		for (int n = 0; n < line.length(); n++)
		{
			usuario.push_back(line[n]);
		}
		getline(file, line, ';');//3 Contra

		for (int n = 0; n < line.length(); n++)
		{
			contra.push_back(line[n]);
		}
		
		i++;
	}
}
void Cinema::Menu_Usuario()
{
	int opc, val = 0;
	do
	{
		cout << "____________Menu del Usuario____________" << endl;
		Imprimir(Menu_Usu, Menu_Usu.size());
		cout << "Digite la opión deseada (1/2/3) : ";
		cin >> opc;
		system("cls");
		if (opc > 0 && opc < 4)
			val = 1;
	} while (val == 0);
	switch (opc)
	{
	case 1:
		
		Iniciar_Sesion();
		break;
	case 2:
		Crear_Cuenta();
		system("cls");
		Menu_Usuario();
		break;
	default:
		Menu();
		break;
	}
}
void Cinema::Iniciar_Sesion()
{
	string usuario, contra;
	bool val = false;
	int fail = 0;
	do
	{
		cout << "\n_______Iniciar_Sesion_______" << endl << endl;
		cout << "  Nombre de Usuario o Correo : ";
		cin.ignore();
		getline(cin, usuario);
		cout << "  Contraseña : ";
		getline(cin, contra);
		system("cls");
		val = miListUsuario->Buscar_Val_Usuario(usuario, contra);
		if (val == true)
		{
			Menu_Prin(usuario);
		}
		if (val == false)
		{
			fail += 1;
		}
		if (fail == 3)
		{
			cout << "Por motivos de seguridad seras regresado al menu." << endl;
			Menu();
		}
	} while (val == false);
}
void Cinema::Crear_Cuenta()
{
	string usuario, contra, subcontra,correo;
	bool val = false;
	int cont = 0,cash = 0;
	do
	{
		cout << "___________Crear_Cuenta__________" << endl << endl << endl;
		cout << " Digite su nombre de Usuario: ";
		cin.ignore();
		getline(cin, usuario);
		cout << " Digite su contraseña : ";
		getline(cin, contra);
		cout << " Digite de nuevo su contraseña : ";
		getline(cin, subcontra);

		if (contra == subcontra)
		{
			val = true;
		}
		if (val == false)
			system("cls");
		cont++;
		if (cont == 3)
			Menu_Usuario();
		

	} while (val == false);
	cout << "\nDigite su correo electronico : ";
	getline(cin, correo);
	cout << "Digite la cantidad de dinero que quiere ingresar : $";
	cin >> cash;

	fstream file("Usuario_Cinema.csv", ios::out | ios::app);
	if (file.is_open())
	{
		file << correo << ";" << usuario << ";" << contra << ";" << to_string(cash) << endl;
	}
	miListUsuario->Insertar_Fin(correo, usuario, contra, cash);
	
}
void Cinema::LeeryCopiarArch() 
{
	string nomfun = "";
	ifstream file;
	file.open("Archivo_Funcion.csv");
	string line;
	int i = 0;
	while (file.good())
	{

		getline(file, line);//2
		if (!(i == 0))
		{
			for (int n = 0; n < line.length(); n++)
			{
				nomfun.push_back(line[n]);

			}

		}
		if (nomfun != "")
		{
			
			miListArch->Insertar_Fin(nomfun);
			nomfun = ""; 
		}
		
		i++;
	}
}
void Cinema::Menu_Prin(string nomUsu) 
{
	Califica* principio;
	Hora* prin;
	Usuario NUsu;
	int opc, val = 0,sum =0;
	do
	{
		cout << "____________Menu Principal____________" << endl;
		Imprimir(Menu_Pin, Menu_Pin.size());
		cout << "Digite la opión deseada (1/2/3/4/5/6/7/8) : ";
		cin >> opc;
		system("cls");
		if (opc > 0 && opc < 9)
			val = 1;
	} while (val == 0);
	switch (opc)
	{
	case 1:  // Calif
		cout << "\n_________Películas_Ordenadas_por_Calificación__________" << endl;
		principio = miArbolMovies->Consultar_Raiz();
		if (!principio)
			cout << "";
		else
		    miArbolMovies->Recorrer_In_Orden(principio);
		
		system("pause()");
		system("cls");
		Menu_Prin(nomUsu);
		break;
	case 2: //Horario
		cout << "\n_________Películas_Ordenadas_por_Horario__________" << endl;
		prin = miArbolHorario->Consultar_Raiz();
		if (!prin)
			cout << "";
		else
			miArbolHorario->Recorrer_In_Orden(prin);
		system("pause()");
		system("cls");
		Menu_Prin(nomUsu);
		break;
	case 3: //Alfa
		miListMovies->Mostrar_Alfa();
		system("pause()");
		system("cls");
		Menu_Prin(nomUsu);
		break;
	case 4: //Comprar Boleto
		Comprar_Boletos(nomUsu);
		Menu_Prin(nomUsu);
		break;
	case 5: //Ingresa Money
		cout << "Digite la cantidad de dinero que quiere añadir a su cuenta : $";
		cin >> sum;
		miListUsuario->Sumar_Cash(nomUsu, sum);
		miListUsuario->Reiniciar_BD();
		system("cls");
		Menu_Prin(nomUsu);
		break;
	case 6: //Estado de Cuenta
		
		NUsu = miListUsuario->Buscar_Info_Usuario(nomUsu);
		cout << "Su estado de cuenta actual es de : $" << NUsu.cash << endl;
		system("pause()");
		system("cls");
		Menu_Prin(nomUsu);
		break;
	case 7: //Menu Usuario
		
		system("cls");
		Menu_Usuario();

		break;
	default: //Salir
		exit(0);
		break;
	}
}
void Cinema::CrearyCopiarFun(string nomfun)
{
	string A1 = "", A2 = "", A3 = "", A4 = "", A5 = "", A6 ="", A7 ="", A8 = "";
	string file;
	file = nomfun;
	file.append(".csv");
	ifstream fin;
	ofstream fout;
	fin.open("Asientos_Base.csv", ios::in);
	string line;
	int i = 0;
	fout.open(file, ios::out);
	while (fin.good())
	{

		if (i == 0) 
		{
			if (fout.is_open()) 
			{
				fout << endl;
			}
		}
		getline(fin, line);//6 NumFin
		if (!(i == 0))
		{
			for (int n = 0; n < line.length(); n++)
			{
				A8.push_back(line[n]);
				
			}
		
		}

		if (A1 != "", A2 != "", A3 != "", A4 != "", A5 != "", A6 != "", A7 != "", A8 != "")
		{
			if (fout.is_open()) 
			{
				fout << A1 << ";" << A2 << ";" << A3 << ";" << A4 << ";" << A5 << ";" << A6 << ";" << A7 << ";" << A8 << endl;
				
			}
			miAsientos->Insertar_Asientos(A1, A2, A3, A4, A5, A6, A7, A8);
			
			A1 = ""; A2 = ""; A3 = ""; A4 = ""; A5 = ""; A6 = ""; A7 = ""; A8 = "";

		}
		getline(fin, line, ';');//1 A

		for (int n = 0; n < line.length(); n++)
		{
		     A1.push_back(line[n]);
		}
		getline(fin, line, ';');//2 A

		for (int n = 0; n < line.length(); n++)
		{
			A2.push_back(line[n]);
		
		}

		getline(fin, line, ';');//3 A

		for (int n = 0; n < line.length(); n++)
		{
			A3.push_back(line[n]);
		}
		getline(fin, line, ';');//4 A

		for (int n = 0; n < line.length(); n++)
		{
			A4.push_back(line[n]);
		}
		getline(fin, line, ';');//5 A

		for (int n = 0; n < line.length(); n++)
		{
			A5.push_back(line[n]);
			
		}
		getline(fin, line, ';');//6 A

		for (int n = 0; n < line.length(); n++)
		{
			A6.push_back(line[n]);

		}
		getline(fin, line, ';');//7 A

		for (int n = 0; n < line.length(); n++)
		{
			A7.push_back(line[n]);

		}
		i++;

	}
	
}
void Cinema::LeeryCopiarFun(string nomfun)
{
	string A1 = "", A2 = "", A3 = "", A4 = "", A5 = "", A6 = "", A7 = "", A8 = "";
	string file;
	file = nomfun;
	file.append(".csv");
	ifstream fin;
	ofstream fout;
	fin.open(file, ios::in);
	string line;
	int i = 0;
	while (fin.good())
	{

		getline(fin, line);//6 NumFin
		if (!(i == 0))
		{
			for (int n = 0; n < line.length(); n++)
			{
				A8.push_back(line[n]);

			}

		}

		if (A1 != "", A2 != "", A3 != "", A4 != "", A5 != "", A6 != "", A7 != "", A8 != "")
		{

			miAsientos->Insertar_Asientos(A1, A2, A3, A4, A5, A6, A7, A8);

			A1 = ""; A2 = ""; A3 = ""; A4 = ""; A5 = ""; A6 = ""; A7 = ""; A8 = "";

		}
		getline(fin, line, ';');//1 A

		for (int n = 0; n < line.length(); n++)
		{
			A1.push_back(line[n]);
		}
		getline(fin, line, ';');//2 A

		for (int n = 0; n < line.length(); n++)
		{
			A2.push_back(line[n]);

		}

		getline(fin, line, ';');//3 A

		for (int n = 0; n < line.length(); n++)
		{
			A3.push_back(line[n]);
		}
		getline(fin, line, ';');//4 A

		for (int n = 0; n < line.length(); n++)
		{
			A4.push_back(line[n]);
		}
		getline(fin, line, ';');//5 A

		for (int n = 0; n < line.length(); n++)
		{
			A5.push_back(line[n]);

		}
		getline(fin, line, ';');//6 A

		for (int n = 0; n < line.length(); n++)
		{
			A6.push_back(line[n]);

		}
		getline(fin, line, ';');//7 A

		for (int n = 0; n < line.length(); n++)
		{
			A7.push_back(line[n]);

		}
		i++;

	}
	fin.close();
}
void Cinema::Comprar_Boletos(string Usu)
{
	bool compra;
	bool encontrado;
	Movie Peli;
	Funcion Fun;
	Usuario NUsu;
	int num, hora;
	string peli;
	string asiento;
	string cambio;
	int precio = 78,codi;
	codi = 2000 + rand() % 1000;
	NUsu = miListUsuario->Buscar_Info_Usuario(Usu);
	if (NUsu.cash >= precio)
	{
	
	miListMovies->Mostrar_Por_ID();
	cout << "\nDigite el número asignado a la película seleccionada : ";
	cin >> num;
	system("cls");
	Peli = miListMovies->Buscar_Movie(num);
	if (Peli.peli != "")
	{
		miListFunct->Mostrar_Por_ID(Peli.peli);
		cout << "\nDigite el número asignado a la hora seleccionada : ";
		cin >> hora;
		system("cls");
		Fun = miListFunct->Buscar_Movie(hora);
		encontrado = miListArch->Buscar_Funcion(Fun.nomfun);
		if (encontrado == true)
		{
			//Abrir
			LeeryCopiarFun(Fun.nomfun);
			miAsientos->Mostrar_Asientos();
			do
			{
				cout << "Los  asientos con (OC) quiere decir que están ocupados.";
				cout << "\nDigite el nombre del asiento (A1) : ";
				cin >> asiento;
			} while (asiento == "OC");
			cambio = miAsientos->Cambiar_Asientos(asiento);
			if (cambio != "")
			{
				//dinero
				compra = miListUsuario->Cambiar_Cash(Usu, precio);

				if (compra == true)
				{
					miListUsuario->Reiniciar_BD();
					miListArch->Insertar_Fin(Fun.nomfun);
					miAsientos->Reiniciar_BD(Fun.nomfun);
					miAsientos->Borrar_Todo();
					miBoletos->Insertar_Fin(codi, NUsu.correo, NUsu.nom, Fun.hrs, Fun.sal, asiento, Peli.peli);
					miBoletos->Reiniciar_BD();
					
					Enviar_Mail(codi, NUsu.correo, NUsu.nom, Fun.hrs, Fun.sal, asiento,Peli.peli);
					system("cls");
				}

			}
			else
			{
				Menu_Prin(Usu);
			}
		}
		else
		{
			if (Fun.nomfun != "") 
			{
				//Crear
			    
			    CrearyCopiarFun(Fun.nomfun);
				miAsientos->Mostrar_Asientos();
				do {
					cout << "Los  asientos con (OC) quiere decir que están ocupados.";
					cout << "\nDigite el nombre del asiento (A1) : ";
					cin >> asiento;
				} while (asiento == "OC");
				cambio = miAsientos->Cambiar_Asientos(asiento);
				if (cambio != "")
				{
					//dinero
					compra = miListUsuario->Cambiar_Cash(Usu, precio);
					if (compra == true)
					{
						miListUsuario->Reiniciar_BD();
						miListArch->Insertar_Fin(Fun.nomfun);
						miAsientos->Reiniciar_BD(Fun.nomfun);
						miListArch->Reiniciar_BD();
						miAsientos->Borrar_Todo();
						miBoletos->Insertar_Fin(codi, NUsu.correo, NUsu.nom, Fun.hrs, Fun.sal, asiento, Peli.peli);
						miBoletos->Reiniciar_BD();
						Enviar_Mail(codi, NUsu.correo, NUsu.nom, Fun.hrs, Fun.sal, asiento,Peli.peli);
						system("cls");
					}
				}
				else
				{
					Menu_Prin(Usu);
				}
			}
			else
			{
				Menu_Prin(Usu);
			}
		}
	}
	else
	{
		Menu_Prin(Usu);
	}
}
else
{
		cout << "No cuenta con saldo suficiente para realizar la compra." << endl;
		system("pause()");
		system("cls");
		Menu_Prin(Usu);
}
}
void Cinema::Enviar_Mail(int codi, string correo, string nom, string hrs, int sala, string asiento,string peli)
{
	::CoInitialize(NULL);

	IMailPtr oSmtp = NULL;
	oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
	oSmtp->LicenseCode = _T("TryIt");

	// Set your gmail email address
	oSmtp->FromAddr = _T("cinema_service@outlook.com");

	// Add recipient email address
	_bstr_t Corr(correo.c_str());
	oSmtp->AddRecipientEx(_T(Corr), 0);

	string Code = to_string(codi);
	_bstr_t Codi(Code.c_str());
	_bstr_t Nom(nom.c_str());
	_bstr_t Hrs(hrs.c_str());
	string Sal = to_string(sala);
	_bstr_t Sala(Sal.c_str());
	_bstr_t Asien(asiento.c_str());
	_bstr_t Peli(peli.c_str());

	string Base = "  Hola ";
	_bstr_t Encab(Base.c_str());
	Encab += _T(Nom);
	Encab += _T(", te compartimos la información de tu boleto.   \n   Codigo : ");
	Encab += _T(Codi);
	Encab += _T("\n  Película : ");
	Encab += _T(Peli);
	Encab += _T("\n  Hora : ");
	Encab += _T(Hrs);
	Encab += _T("\n  Sala : ");
	Encab += _T(Sala);
	Encab += _T("\n  Asiento : ");
	Encab += _T(Asien);

	// Set email subject
	oSmtp->Subject = _T("Boleto Cinema");

	// Set email body
	oSmtp->BodyText = _T(Encab);

	// Gmail SMTP server address
	oSmtp->ServerAddr = _T("smtp.office365.com");//("smtp.gmail.com");

	// Gmail user authentication should use your
	// Gmail email address as the user name.
	// For example: your email is "gmailid@gmail.com", then the user should be "gmailid@gmail.com"
	oSmtp->UserName = _T("cinema_service@outlook.com");//("carlosac2198@gmail.com");
	oSmtp->Password = _T("cinema4321");

	// If you want to use direct SSL 465 port,
	// Please add this line, otherwise TLS will be used.
	// oSmtp->ServerPort = 465;

	// Set 25 or 587 SMTP port
	oSmtp->ServerPort = 587;

	// detect SSL/TLS automatically
	oSmtp->ConnectType = ConnectSSLAuto;

	_tprintf(_T("Start to send email via gmail account ...\r\n"));

	if (oSmtp->SendMail() == 0)
	{
		_tprintf(_T("email was sent successfully!\r\n"));
	}
	else
	{
		_tprintf(_T("failed to send email with the following error: %s\r\n"),
			(const TCHAR*)oSmtp->GetLastErrDescription());
	}
}
void Cinema::LeeryCopiarBole()
{
	bool ok = false,ok2 = false;
	int codi = 0,sala = 0;
	string Codi = "",correo = "",nom = "",hrs = "",Sala = "",asiento = "",peli = "";

	ifstream file;
	file.open("Boletos_BD.csv");
	string line;
	int i = 0;
	while (file.good())
	{

		getline(file, line);//7 Peli
		if (!(i == 0))
		{
			for (int n = 0; n < line.length(); n++)
			{
				peli.push_back(line[n]);

			}
		}
		if (Codi != ""&& correo != "" && nom != "" && hrs != "" && Sala != "" && asiento != "" && peli != "")
		{
			miBoletos->Insertar_Fin(codi, correo, nom, hrs, sala, asiento, peli);
			codi = 0; sala = 0;
			Codi = ""; correo = ""; nom = ""; hrs = ""; Sala = ""; asiento = ""; peli = "";
		}
		getline(file, line, ';');//1 Codi

		for (int n = 0; n < line.length(); n++)
		{
			Codi.push_back(line[n]);
			ok = true;
		}
		if (ok == true && Codi !="")
		{
			
			codi = stoi(Codi);
			ok = false;
		}
		getline(file, line, ';');//2  Correo

		for (int n = 0; n < line.length(); n++)
		{
			correo.push_back(line[n]);
		}
	
		getline(file, line, ';');//3 Nombre

		for (int n = 0; n < line.length(); n++)
		{
			nom.push_back(line[n]);
		}
		getline(file, line, ';');//4 Hora

		for (int n = 0; n < line.length(); n++)
		{
			hrs.push_back(line[n]);
		}
		getline(file, line, ';');//5 Sala

		for (int n = 0; n < line.length(); n++)
		{
			Sala.push_back(line[n]);
			ok2 = true;
		}
		if (ok2 == true && Sala !="")
		{
			
			sala = stoi(Sala);
			ok = false;
		}
		getline(file, line, ';');//6 Asiento

		for (int n = 0; n < line.length(); n++)
		{
			asiento.push_back(line[n]);
		}

		i++;
	}
}
