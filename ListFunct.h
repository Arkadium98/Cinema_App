#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Funcion
{
	string peli;
	int sal;
	string hrs;
	string nomfun;
	int HrsI;
	int HrsF;
	int ID;
	Funcion* sig;
};
class ListFunct
{
public:
	ListFunct();
	~ListFunct();
	void Mostrar_Por_ID(string pel);
	void Mostrar_Sala_Hora();
	void Insertar_Sala_Hora(string nfun, int nsal, string nhrs,string npeli,int NHrsI,int NHrsF,int ID);
	string Extrae_Prin();
	string Extrae_Inter(string ext,int xsal);
	string Extrae_Fin();
	string Extrae_Peli(string ext);
	void Reiniciar_BD();
	Funcion Buscar_Movie(int idx);
private:
	Funcion* cabecera, * fin, * nodo;
};

