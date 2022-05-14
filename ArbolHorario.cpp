#include "ArbolHorario.h"
ArbolHorario::ArbolHorario()
{
	setlocale(LC_ALL, "");
	raiz = NULL;
}
ArbolHorario::~ArbolHorario() {}
Hora* ArbolHorario::Consultar_Raiz()
{
	return raiz;
}
void ArbolHorario::Crear_Nodo(string nfun, int nsal, string nhrs, string npeli, int NHrsI, int NHrsF)
{
	nodo = new Hora();
	nodo->nomfun = nfun;  //Paso 2
	nodo->sal = nsal;
	nodo->hrs = nhrs;
	nodo->peli = npeli;
	nodo->HrsI = NHrsI;
	nodo->HrsF = NHrsF;
	nodo->izq = NULL;
	nodo->der = NULL;
}
void ArbolHorario::Insertar(Hora* inicio)
{
	if (!raiz)                       //Paso 0
	{
		raiz = nodo;
		/*cout << "Ok. Se insertó como raíz" << endl;*/
		return;
	}
	if (nodo->HrsI == inicio->HrsI)   //Paso 1
	{
		/*cout << "Ya existe " << nodo->num << " NO se insertó " << endl;*/
		return;
	}

	if (nodo->HrsI < inicio->HrsI)   //Paso 2  
	{
		if (!inicio->izq) //== NULL
		{
			inicio->izq = nodo;
			/*cout << "Ok. Se insertó a la izq de " << inicio->num << endl;*/
			return;
		}
		Insertar(inicio->izq);
	}

	if (nodo->HrsI > inicio->HrsI)   //Paso 3
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
void ArbolHorario::Recorrer_In_Orden(Hora* inicio)
{

	if (inicio->izq)
		Recorrer_In_Orden(inicio->izq);

	cout << "\t" << inicio->hrs << "\t" << inicio->peli << endl;

	if (inicio->der)
		Recorrer_In_Orden(inicio->der);
}

void ArbolHorario::Extraer(Hora* padre, Hora* inicio, int valor, string SubArbol)
{
	if (valor < inicio->HrsI)
	{
		Extraer(inicio, inicio->izq, valor, "izq");
		return;
	}
	if (valor > inicio->HrsI)
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
void ArbolHorario::Intercambiar(Hora* encontrar, Hora* actual, Hora* siguiente, string subArbol)
{
	int aux;
	if (subArbol == "izq")
	{
		if (siguiente->der == NULL)
		{
			aux = encontrar->HrsI;
			encontrar->HrsI = siguiente->HrsI;
			siguiente->HrsI = aux;
			Extraer(actual, siguiente, siguiente->HrsI, padreEnlace);
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
			aux = encontrar->HrsI;
			encontrar->HrsI = siguiente->HrsI;
			siguiente->HrsI = aux;
			Extraer(actual, siguiente, siguiente->HrsI, padreEnlace);
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