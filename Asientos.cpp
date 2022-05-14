#include "Asientos.h"
Asientos::Asientos()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
Asientos::~Asientos() {}
void Asientos::Mostrar_Asientos()
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	
	while (nodo)//nodo != NULL
	{
		cout << "\t| " << nodo->A1 << " | " << nodo->A2 << " | " << nodo->A3 << " | " << nodo->A4 << " | " << nodo->A5 << " | " << nodo->A6 << " | " << nodo->A7 << " | " << nodo->A8 << " |";
		cout << endl;
		nodo = nodo->sig;
	}
	cout << "\n\t______________________________________" << endl;
	cout << "\t              PANTALLA                " << endl;
	cout << "\t______________________________________" << endl;
}

void Asientos::Insertar_Asientos(string xA1, string xA2, string xA3, string xA4, string xA5, string xA6, string xA7, string xA8)
{
	nodo = new Seat;   //Paso 1
	nodo->A1 = xA1;    //Paso 2
	nodo->A2 = xA2;
	nodo->A3 = xA3;
	nodo->A4 = xA4;
	nodo->A5 = xA5;
	nodo->A6 = xA6;
	nodo->A7 = xA7;
	nodo->A8 = xA8;

	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}

string Asientos::Cambiar_Asientos(string ext)
{
	string extraido = "";
	Seat* anterior;
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
		if (nodo->A1 == ext)
		{
			extraido = nodo->A1;
			nodo->A1 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A2 == ext)
		{
			extraido = nodo->A2;
			nodo->A2 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A3 == ext)
		{
			extraido = nodo->A3;
			nodo->A3 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A4 == ext)
		{
			extraido = nodo->A4;
			nodo->A4 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A5 == ext)
		{
			extraido = nodo->A5;
			nodo->A5 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A6 == ext)
		{
			extraido = nodo->A6;
			nodo->A6 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A7 == ext)
		{
			extraido = nodo->A7;
			nodo->A7 = "OC";
			bandera = true;
			break;
		}
		if (nodo->A8 == ext)
		{
			extraido = nodo->A8;
			nodo->A8 = "OC";
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
	
	return extraido;
}


bool Asientos::Buscar_Asiento(string ext)
{
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{

		if (nodo->A1 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A2 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A3 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A4 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A5 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A6 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A7 == ext)
		{
			encontrado = true;
			
			break;
		}
		if (nodo->A8 == ext)
		{
			encontrado = true;
			
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}
void Asientos::Reiniciar_BD(string nom)
{
	string doc = nom;
	doc.append(".csv");
	ofstream file(doc);
	nodo = cabecera;
	if (file.is_open())
	{
		file << nom << endl;
		while (nodo)//nodo != NULL
		{
			file << nodo->A1 << ";" << nodo->A2 << ";" << nodo->A3 << ";" << nodo->A4 << ";" << nodo->A5 << ";" << nodo->A6 << ";" << nodo->A7 << ";" << nodo->A8 << endl;
			nodo = nodo->sig;
		}
	}
}
string Asientos::Extrae_Fin()
{
	Seat* anterior;
	string extraido = "";
	if (!cabecera)
	{
		cout << "\n\t" << endl;
		return extraido;
	}

	anterior = NULL;
	nodo = cabecera;
	while (nodo->sig != NULL) //  Paso 1
	{
		anterior = nodo;
		nodo = nodo->sig;
	}
	extraido = nodo->A1; //  Paso 2

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
void Asientos::Borrar_Todo()
{
	string val = "a";
	do 
	{
		val = Extrae_Fin();
	} while (val != "");
}