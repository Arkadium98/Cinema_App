#include "ListUsuario.h"
ListUsuario::ListUsuario()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
ListUsuario::~ListUsuario() {}
void ListUsuario::Mostrar_Usuarios()
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n LISTA DE USUARIOS: " << endl;
	while (nodo)//nodo != NULL
	{
		cout << "\t" << nodo->correo << "\t" << nodo->nom << "\t" << nodo->contra << "\t" << nodo->cash;
		cout << endl;
		nodo = nodo->sig;
	}
}

void ListUsuario::Insertar_Fin(string xcorr, string xnom, string xcontra, int xcash)
{
	nodo = new Usuario;   //Paso 1
	nodo->correo = xcorr;
	nodo->nom = xnom;    //Paso 2
	nodo->contra = xcontra;
	nodo->cash = xcash;
	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}
string ListUsuario::Extrae_Prin()
{
	string extraido = "";
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return extraido;
	}
	nodo = cabecera;
	extraido = nodo->nom;
	cabecera = nodo->sig;
	delete nodo;
	return extraido;

}
string ListUsuario::Extrae_Inter(string ext)
{
	string extraido;
	Usuario* anterior;
	bool bandera = false;

	if (!cabecera)
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return extraido;
	}

	anterior = NULL;
	nodo = cabecera;

	while (nodo != NULL)
	{
		if (nodo->nom == ext)
		{
			bandera = true;
			break;
		}
		anterior = nodo;
		nodo = nodo->sig;
	}
	if (!bandera)
	{
		cout << "\nNo Existe " << ext << endl;
		return extraido;
	}
	extraido = nodo->nom;
	if (!anterior)
		cabecera = nodo->sig;
	else
		anterior->sig = nodo->sig;

	if (nodo == fin)
		fin = anterior;

	delete nodo;
	return extraido;
}
string ListUsuario::Extrae_Fin()
{
	Usuario* anterior;
	string extraido = "";
	if (!cabecera)
	{
		cout << "\n\t La lista está vacía." << endl;
		return extraido;
	}

	anterior = NULL;
	nodo = cabecera;
	while (nodo->sig != NULL) //  Paso 1
	{
		anterior = nodo;
		nodo = nodo->sig;
	}
	extraido = nodo->nom; //  Paso 2

	if (!anterior)
	{
		cabecera = NULL;
	}
	else
	{
		anterior->sig = NULL; //  Paso 3
	}
	fin = anterior; //  Paso 4
	delete nodo; // Paso 5
	return extraido;

}
bool ListUsuario::Buscar_Val_Usuario(string usu, string con)
{
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if ((nodo->nom == usu || nodo->correo == usu)&& nodo->contra == con)
		{
			encontrado = true;
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}
bool ListUsuario::Buscar_Usuario(string usu)
{
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->nom == usu)
		{
			encontrado = true;
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}
void ListUsuario::Reiniciar_BD()
{
	ofstream file("Usuario_Cinema.csv");
	nodo = cabecera;
	if (file.is_open())
	{
		file << "Correo" << ";" << "Nombre" << ";" << "Contraseña" << ";" << "Dinero" << endl;
		while (nodo)//nodo != NULL
		{
			file << nodo->correo << ";" << nodo->nom << ";" << nodo->contra << ";" << nodo->cash << endl;
			nodo = nodo->sig;
		}
	}
}
Usuario ListUsuario::Buscar_Info_Usuario(string Usu)
{
	Usuario Encont;

	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		Encont.nom = "";
		return Encont;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->nom == Usu || nodo->correo == Usu)
		{
			Encont.nom = nodo->nom;
			Encont.correo = nodo->correo;
			Encont.cash = nodo->cash;
			encontrado = true;
			break;
		}
		nodo = nodo->sig;

	}
	return Encont;
}
bool ListUsuario::Cambiar_Cash(string usu, int rest)
{
	int cash =0;
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->nom == usu || nodo->correo == usu)
		{
			cash = nodo->cash;
			if (cash >= rest)
			{
				nodo->cash = cash - rest;
				encontrado = true;
			}
			else
			{
				encontrado = false;
			}
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}
bool ListUsuario::Sumar_Cash(string usu, int sum)
{
	int cash = 0;
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->nom == usu || nodo->correo == usu)
		{
			cash = nodo->cash;
			
			nodo->cash = cash + sum;
			encontrado = true;
			}
			else
			{
				encontrado = false;
			}
			break;
		
		nodo = nodo->sig;
	}
	return encontrado;
}
