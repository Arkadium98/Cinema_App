#pragma once
#include <iostream>
#include <locale>
#include <wchar.h>
using namespace std;
struct Hora
{
	string peli;
	int sal;
	string hrs;
	string nomfun;
	int HrsI;
	int HrsF;
	Hora* izq;
	Hora* der;
};
class ArbolHorario
{
public:
	ArbolHorario();
	~ArbolHorario();
	Hora* Consultar_Raiz();
	void Crear_Nodo(string nfun, int nsal, string nhrs, string npeli, int NHrsI, int NHrsF);
	void Insertar(Hora* inicio);
	void Recorrer_In_Orden(Hora* inicio);
	void Extraer(Hora* padre, Hora* inicio, int valor, string SubArbol);
	void Intercambiar(Hora* encontrar, Hora* actual, Hora* siguiente, string subArbol);
private:
	Hora* nodo, * aux, * raiz;
	string padreEnlace;
};

