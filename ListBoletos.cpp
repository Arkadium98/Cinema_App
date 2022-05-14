#include "ListBoletos.h"
ListBoletos::ListBoletos()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
ListBoletos::~ListBoletos() {}

void ListBoletos::Insertar_Fin(int codi, string correo, string nom, string hrs, int sala, string asiento, string peli)
{
	nodo = new Boletos;   //Paso 1
	nodo->codi = codi;
	nodo->correo = correo;
	nodo->nom = nom;
	nodo->hrs = hrs;
	nodo->sala = sala;
	nodo->asiento = asiento;
	nodo->peli = peli;   //Paso 2
	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}
string ListBoletos::Extrae_Prin()
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
string ListBoletos::Extrae_Inter(string ext)
{
	string extraido;
	Boletos* anterior;
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
string ListBoletos::Extrae_Fin()
{
	Boletos* anterior;
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
Boletos ListBoletos::Buscar_Codi(int  codi)
{
	Boletos Encont;
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		Encont.codi = 0;
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->codi == codi)
		{ 
			Encont.codi = nodo->codi;
			Encont.correo = nodo->correo;
			Encont.nom = nodo->nom;
			Encont.hrs = nodo->hrs;
			Encont.sala = nodo->sala;
			Encont.asiento = nodo->asiento;
			Encont.peli = nodo->peli;
			encontrado = true;
			break;
		}
		nodo = nodo->sig;
	}
	return Encont;
}
void ListBoletos::Reiniciar_BD()
{
	ofstream file("Boletos_BD.csv");
	nodo = cabecera;
	if (file.is_open())
	{
	
		file << "Codigo" << ";" << "Correo" << ";" << "Nombre" << ";" << "Hora" << ";" << "Sala" << ";" << "Asiento" << ";" << "Película" << endl;
		while (nodo)//nodo != NULL
		{
			file << to_string(nodo->codi) << ";" << nodo->correo << ";" << nodo->nom << ";" << nodo->hrs << ";" << to_string(nodo->sala) << ";" << nodo->asiento << ";" << nodo->peli << endl;
			nodo = nodo->sig;
		}
	}
}