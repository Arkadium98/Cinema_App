#include "Lista.h"
Lista::Lista()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
Lista::~Lista() {}
void Lista::Mostrar_Admin()
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n LISTA DE ADMINISTRADORES: " << endl;
	while (nodo)//nodo != NULL
	{
		cout << "\t" << nodo->nom;
		cout << endl;
		nodo = nodo->sig;
	}
}

void Lista::Insertar_Fin(string nuevo,string con)
{
	nodo = new Administrador;   //Paso 1
	nodo->nom = nuevo;    //Paso 2
	nodo->contra = con;
	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}
string Lista::Extrae_Prin()
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
string Lista::Extrae_Inter(string ext)
{
	string extraido;
	Administrador* anterior;
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
string Lista::Extrae_Fin()
{
	Administrador* anterior;
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
bool Lista::Buscar_Val_Admin(string usu, string con)
{
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		 encontrado = false;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{
		
		if (nodo->nom == usu && nodo->contra == con)
		{
			encontrado  = true;
			break;
		}
		nodo = nodo->sig;
	}
	return encontrado;
}
bool Lista::Buscar_Admin(string usu)
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
void Lista::Reiniciar_BD()
{
	ofstream file("Administrador.csv");
	nodo = cabecera;
	if (file.is_open())
	{
		file << "Usuario" << ";" << "Contraseña" << endl;
		while (nodo)//nodo != NULL
		{
			file << nodo->nom << ";" << nodo->contra << endl;
			nodo = nodo->sig;
		}
	}
}