#pragma once
#include <iostream>
#include <locale>
#include <wchar.h>
using namespace std;
struct Califica
{
	string peli;
	string gene;
	float cali;
	int id;
	int num;
	Califica* izq;
	Califica* der;
};
class ArbolMovies
{
public:
	ArbolMovies();
	~ArbolMovies();
	Califica* Consultar_Raiz();
	void Crear_Nodo(string pel, string gen, float cal, int idx);
	void Insertar(Califica* inicio);
	void Recorrer_In_Orden(Califica* inicio);
	void Extraer(Califica* padre, Califica* inicio, int valor, string SubArbol);
	void Intercambiar(Califica* encontrar, Califica* actual, Califica* siguiente, string subArbol);
private:
	Califica* nodo, * aux, * raiz;
	string padreEnlace;
};

