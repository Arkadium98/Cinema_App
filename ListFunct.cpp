#include "ListFunct.h"
ListFunct::ListFunct()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
ListFunct::~ListFunct() {}
void ListFunct::Mostrar_Por_ID(string pel)
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n  " << endl;
	cout << "\n     |Número| Hora |              Película                     |" << endl;
	while (nodo)//nodo != NULL
	{
		if (pel == nodo->peli) 
		{
			cout << "\t" << nodo->ID << "\t" << nodo->hrs << "\t" << nodo->peli;
			cout << endl;
		}
		nodo = nodo->sig;
	}
}
void ListFunct::Mostrar_Sala_Hora()
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n  " << endl;
	cout << "\n     |Función|   Sala  | Hora |Hora Num|Hora Fin|              Película                     |" << endl;
	while (nodo)//nodo != NULL
	{
		cout << "\t" << nodo->nomfun << "\tsala " << nodo->sal << "\t" <<  nodo->hrs << "\t" <<  nodo->HrsI << "\t" << nodo->HrsF << "\t" <<nodo->peli ;
		cout << endl;
		nodo = nodo->sig;
	}
}

void ListFunct::Insertar_Sala_Hora(string nfun, int nsal, string nhrs, string npeli, int NHrsI, int NHrsF,int idx)
{
	nodo = new Funcion;   //Paso 1
	nodo->nomfun = nfun;  //Paso 2
	nodo->sal = nsal;
	nodo->hrs = nhrs;
	nodo->peli = npeli;
	nodo->HrsI = NHrsI;
	nodo->HrsF = NHrsF;
	nodo->ID = idx;
	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}
string ListFunct::Extrae_Prin()
{
	string extraido = "";
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return extraido;
	}
	nodo = cabecera;
	extraido = nodo->peli;
	cabecera = nodo->sig;
	delete nodo;
	return extraido;

}
string ListFunct::Extrae_Inter(string ext,int xsal)
{
	string extraido;
	Funcion* anterior;
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
		if (nodo->hrs == ext && nodo->sal == xsal)
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
	extraido = nodo->peli;
	if (!anterior)
		cabecera = nodo->sig;
	else
		anterior->sig = nodo->sig;

	if (nodo == fin)
		fin = anterior;

	delete nodo;
	return extraido;
}
string ListFunct::Extrae_Fin()
{
	Funcion* anterior;
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
	extraido = nodo->peli; //  Paso 2

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

string ListFunct::Extrae_Peli(string ext)
{
	string extraido;
	Funcion* anterior;
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
		if (nodo->peli == ext)
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
	extraido = nodo->peli;
	if (!anterior)
		cabecera = nodo->sig;
	else
		anterior->sig = nodo->sig;

	if (nodo == fin)
		fin = anterior;

	delete nodo;
	return extraido;
}
void ListFunct::Reiniciar_BD()
{
	
	ofstream file("Funciones_Movies.csv");
	nodo = cabecera;
	if (file.is_open())
	{
		file << "Función" << ";" << "Sala" << ";" << "Hora" << ";" << "Película" << ";" << "Hora en Número" << ";" << "Hora de Fin" << endl;
		while (nodo)//nodo != NULL
		{
			file << nodo->nomfun << ";" << to_string(nodo->sal) << ";" << nodo->hrs << ";" << nodo->peli << ";" << to_string(nodo->HrsI) << ";" << to_string(nodo->HrsF) << endl;
			nodo = nodo->sig;
		}
	}
}
Funcion ListFunct::Buscar_Movie(int idx)
{
	Funcion Encont;

	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		Encont.peli = "";
		Encont.nomfun = "";
		return Encont;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->ID == idx)
		{
			Encont.peli = nodo->peli;
			Encont.hrs = nodo->hrs;
			Encont.sal = nodo->sal;
			Encont.nomfun = nodo->nomfun;
			encontrado = true;
			break;
		}
		nodo = nodo->sig;

	}
	return Encont;
}