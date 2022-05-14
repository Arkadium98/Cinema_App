#include "ListArch.h"
ListArch::ListArch()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
ListArch::~ListArch() {}
void ListArch::Mostrar_Archivo()
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n LISTA DE Funciones: " << endl;
	while (nodo)//nodo != NULL
	{
		cout << "\t" << nodo->nomfun;
		cout << endl;
		nodo = nodo->sig;
	}
}

void ListArch::Insertar_Fin(string nuevo)
{
	nodo = new Archivo;   //Paso 1
	nodo->nomfun = nuevo;    //Paso 2
	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}
string ListArch::Extrae_Prin()
{
	string extraido = "";
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return extraido;
	}
	nodo = cabecera;
	extraido = nodo->nomfun;
	cabecera = nodo->sig;
	delete nodo;
	return extraido;

}
string ListArch::Extrae_Inter(string ext)
{
	string extraido;
	Archivo* anterior;
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
		if (nodo->nomfun == ext)
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
	extraido = nodo->nomfun;
	if (!anterior)
		cabecera = nodo->sig;
	else
		anterior->sig = nodo->sig;

	if (nodo == fin)
		fin = anterior;

	delete nodo;
	return extraido;
}
string ListArch::Extrae_Fin()
{
	Archivo* anterior;
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
	extraido = nodo->nomfun; //  Paso 2

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
bool ListArch::Buscar_Archivo(string usu)
{
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->nomfun == usu)
		{
			encontrado = true;
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}
void ListArch::Reiniciar_BD()
{
	ofstream file("Archivo_Funcion.csv");
	nodo = cabecera;
	if (file.is_open())
	{
		file << "Función" << endl;
		while (nodo)//nodo != NULL
		{
			file << nodo->nomfun << endl;
			nodo = nodo->sig;
		}
	}
}
bool ListArch::Buscar_Funcion(string usu)
{
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->nomfun == usu)
		{
			encontrado = true;
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}