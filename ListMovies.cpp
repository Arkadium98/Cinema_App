#include "ListMovies.h"
ListMovies::ListMovies()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
ListMovies::~ListMovies() {}
void ListMovies::Mostrar_Por_ID()
{
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n| Número |              Película                     " << endl;
	while (nodo)//nodo != NULL
	{

		cout << "| " << nodo->id << "  |\t" << nodo->peli;

		cout << endl;
		nodo = nodo->sig;
	}
}
void ListMovies::Mostrar_Movie()
{
	
	int n = 0;
	string ch = "                                       ", gran = " ", med = "                                  ";
	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n|              Película                     |    Genero    |  Calificación | " << endl;
	while (nodo)//nodo != NULL
	{
		n = nodo->peli.length();
		if (n < 7)
		{
			cout << "|" << nodo->peli <<ch <<"|" << nodo->gene << "\t|" << nodo->cali << "|";
		}
		if (n > 7 && n < 28)
		{
			cout << "|" << nodo->peli << med << "|" << nodo->gene << "\t|" << nodo->cali << "|";
		}
		if (n >28)
		{
			cout << "|" << nodo->peli << gran << "|" << nodo->gene << "\t|" << nodo->cali << "|";
		}
		cout << endl;
		nodo = nodo->sig;
	}
}
void ListMovies::Mostrar_Movie_y_Seleccionar()
{

	if (!cabecera) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\n|    Número    |              Película                     |" << endl;
	while (nodo)//nodo != NULL
	{
		
		cout <<"|      "<<nodo->id<< "        |" << nodo->peli  << "|" ;
		
		cout << endl;
		nodo = nodo->sig;
	}
}
void ListMovies::Mostrar_Alfa()
{
	int n = 0;
	string ch = "                                       ", gran = " ", med = "                                  ";
	if (!cabealfa) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return;
	}
	nodoalfa = cabealfa;
	cout << "\n Películas Ordenadas Alfabeticamente : " << endl;
	while (nodoalfa)//nodo != NULL
	{
		n = nodo->peli.length();
		if (n < 7)
		{
			cout << "|" << nodoalfa->peli << ch << "|" << nodoalfa->gene << " |";
		}
		if (n > 7 && n < 28)
		{
			cout << "|" << nodoalfa->peli << med << "|" << nodoalfa->gene << "|";
		}
		if (n > 28)
		{
			cout << "|" << nodoalfa->peli << gran << "|" << nodoalfa->gene << "|";
		}
		cout << endl;
		nodoalfa = nodoalfa->sigalf;
	}
}
void ListMovies::Insertar_Movie(string pel, string gen,float cal,int idx)
{
	
	nodo = new Movie;   //Paso 1
	nodo->peli = pel;    //Paso 2
	nodo->gene = gen;
	nodo->cali = cal;
	nodo->id = idx;
	nodo->sig = NULL;     //Paso 3
	if (fin)              //fin != NULL
		fin->sig = nodo;
	if (!cabecera)   //cabecera == NULL
		cabecera = nodo;
	fin = nodo;           //Paso 4
	//cout << "\tOK.Se insertó " << nuevo << endl;
}
void ListMovies::Insertar_Alfa(string pel, string gen, float cal, int idx)
{
	nodoalfa = new Movie;
	nodoalfa->peli = pel;    //Paso 2
	nodoalfa->gene = gen;
	nodoalfa->cali = cal;
	nodoalfa->id = idx;
	if (!cabealfa)
	{
		nodo->sigalf = NULL;
		cabealfa = nodo;
		finalfa = nodo;
		return;
	}
	aux = cabealfa;
	ante = NULL;
	do
	{
		if (nodoalfa->peli < aux->peli)
		{
			nodoalfa->sigalf = aux;
			if (ante)
			{
				ante->sigalf = nodoalfa;
			}
			else
			{
				cabealfa = nodoalfa;
			}
			return;
		}
		ante = aux;
		aux = aux->sigalf;
	} while (aux);
	nodoalfa->sigalf = NULL;
	finalfa->sigalf = nodoalfa;
	finalfa = nodoalfa;
}
string ListMovies::Extrae_Prin_Movie()
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
string ListMovies::Extrae_Inter_Movie(int idx)
{
	string extraido;
	Movie* anterior;
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
		if (nodo->id =  idx)
		{
			bandera = true;
			break;
		}
		anterior = nodo;
		nodo = nodo->sig;
	}
	if (!bandera)
	{
		cout << "\nNo Existe la opción " << idx << endl;
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
string ListMovies::Extrae_Fin_Movie()
{
	Movie* anterior;
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

string ListMovies::Extrae_Prin_Alfa()
{
	string extraido = "";
	if (!cabealfa) //cabecera == NULL
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return extraido;
	}
	nodoalfa = cabealfa;
	extraido = nodoalfa->peli;
	cabecera = nodoalfa->sig;
	delete nodoalfa;
	return extraido;
}
string ListMovies::Extrae_Inter_Alfa(int idx)
{
	string extraido;
	Movie* anterior;
	bool bandera = false;

	if (!cabealfa)
	{
		cout << "\n\t La lista está vacía ** \n" << endl;
		return extraido;
	}

	anterior = NULL;
	nodoalfa = cabealfa;

	while (nodoalfa != NULL)
	{
		if (nodoalfa->id = idx)
		{
			bandera = true;
			break;
		}
		anterior = nodoalfa;
		nodoalfa = nodoalfa->sigalf;
	}
	if (!bandera)
	{
		cout << "\nNo Existe la opción " << idx << endl;
		return extraido;
	}
	extraido = nodoalfa->peli;
	if (!anterior)
		cabealfa = nodoalfa->sigalf;
	else
		anterior->sigalf = nodoalfa->sigalf;

	if (nodoalfa == finalfa)
		finalfa = anterior;

	delete nodoalfa;
	return extraido;
}
string ListMovies::Extrae_Fin_Alfa()
{
	Movie* anterior;
	string extraido = "";
	if (!cabealfa)
	{
		cout << "\n\t La lista está vacía." << endl;
		return extraido;
	}

	anterior = NULL;
	nodoalfa = cabealfa;
	while (nodoalfa->sigalf != NULL) //  Paso 1
	{
		anterior = nodoalfa;
		nodoalfa = nodoalfa->sigalf;
	}
	extraido = nodoalfa->peli; //  Paso 2

	if (!anterior)
	{
		cabealfa = NULL;
	}
	else
	{
		anterior->sigalf = NULL; //  Paso 3
	}
	finalfa = anterior; //  Paso 4
	delete nodoalfa; // Paso 5
	return extraido;
}

Movie ListMovies::Buscar_Movie(int idx)
{
	Movie Encont;
	
	bool encontrado = false;
	if (!cabecera) //cabecera == NULL
	{
		Encont.peli = "";
		return Encont;
	}
	nodo = cabecera;
	while (nodo)//nodo != NULL
	{
		
		if (nodo->id == idx)
		{
			Encont.peli = nodo->peli;
			Encont.gene = nodo->gene;
			Encont.cali = nodo->cali;
			encontrado = true;
			break;
		}
		nodo = nodo->sig;
		
	}
	return Encont;
}
void ListMovies::Reiniciar_BD_Movie()
{
	ofstream file("List_Movies.csv");
	nodo = cabecera;
	if (file.is_open())
	{
		file << "Película" << ";" << "Genero" << ";" << "Calificación" << endl;
		while (nodo)//nodo != NULL
		{
			file << nodo->peli << ";" << nodo->gene << ";" << nodo->cali << endl;
			nodo = nodo->sig;
		}
	}
}