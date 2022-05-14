#include "ArbolMovies.h"
ArbolMovies::ArbolMovies()
{
	setlocale(LC_ALL, "");
	raiz = NULL;
}
ArbolMovies::~ArbolMovies() {}
Califica* ArbolMovies::Consultar_Raiz()
{
	return raiz;
}
void ArbolMovies::Crear_Nodo(string pel, string gen, float cal, int idx)
{
	nodo = new Califica();
	nodo->peli = pel;
	nodo->gene = gen;
	nodo->cali = cal;
	nodo->id = idx;
	nodo->izq = NULL;
	nodo->der = NULL;
}
void ArbolMovies::Insertar(Califica* inicio)
{
	if (!raiz)                       //Paso 0
	{
		raiz = nodo;
		/*cout << "Ok. Se insertó como raíz" << endl;*/
		return;
	}
	if (nodo->cali == inicio->cali)   //Paso 1
	{
		/*cout << "Ya existe " << nodo->num << " NO se insertó " << endl;*/
		return;
	}

	if (nodo->cali < inicio->cali)   //Paso 2  
	{
		if (!inicio->izq) //== NULL
		{
			inicio->izq = nodo;
			/*cout << "Ok. Se insertó a la izq de " << inicio->num << endl;*/
			return;
		}
		Insertar(inicio->izq);
	}

	if (nodo->cali > inicio->cali)   //Paso 3
	{
		if (!inicio->der)
		{
			inicio->der = nodo;
			/*cout << "Ok. Se insertó a la der de " << inicio->num << endl;*/
			return;
		}
		Insertar(inicio->der);
	}


}
void ArbolMovies::Recorrer_In_Orden(Califica* inicio)
{

	if (inicio->izq)
		Recorrer_In_Orden(inicio->izq);

	cout << "\t" << inicio->cali << "\t" << inicio->peli<<endl;

	if (inicio->der)
		Recorrer_In_Orden(inicio->der);
}

void ArbolMovies::Extraer(Califica* padre, Califica* inicio, int valor, string SubArbol)
{
	if (valor < inicio->cali)
	{
		Extraer(inicio, inicio->izq, valor, "izq");
		return;
	}
	if (valor > inicio->cali)
	{
		Extraer(inicio, inicio->der, valor, "der");
		return;
	}
	if (inicio->izq == NULL && inicio->der == NULL)
	{
		/*cout << "\tOK. Se extrajó el valor " << inicio->cali << endl << endl;*/
		if (SubArbol == "izq")
			padre->izq = NULL;
		if (SubArbol == "der")
			padre->der = NULL;
		if (raiz == inicio)
			raiz = NULL;
		delete inicio;
		return;
	}
	if (inicio->izq != NULL)
	{
		padreEnlace = "izq";
		Intercambiar(inicio, inicio, inicio->izq, "izq");
		return;
	}
	if (inicio->der != NULL)
	{
		padreEnlace = "der";
		Intercambiar(inicio, inicio, inicio->izq, "der");
		return;
	}
}
void ArbolMovies::Intercambiar(Califica* encontrar, Califica* actual, Califica* siguiente, string subArbol)
{
	int aux;
	if (subArbol == "izq")
	{
		if (siguiente->der == NULL)
		{
			aux = encontrar->cali;
			encontrar->cali = siguiente->cali;
			siguiente->cali = aux;
			Extraer(actual, siguiente, siguiente->cali, padreEnlace);
			return;
		}
	}
	else
	{
		padreEnlace = "der";
		Intercambiar(encontrar, siguiente, siguiente->der, "izq");
		return;
	}
	if (subArbol == "der")
	{
		if (siguiente->izq == NULL)
		{
			aux = encontrar->cali;
			encontrar->cali = siguiente->cali;
			siguiente->cali = aux;
			Extraer(actual, siguiente, siguiente->cali, padreEnlace);
			return;
		}
	}
	else
	{
		padreEnlace = "izq";
		Intercambiar(encontrar, siguiente, siguiente->izq, "der");
		return;
	}
}