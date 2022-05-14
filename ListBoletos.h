#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Boletos
{

	int codi;
	string correo;
	string nom;
	string hrs;
	int sala;
	string asiento;
	string peli;
	Boletos* sig;
};
class ListBoletos
{
public:
	ListBoletos();
	~ListBoletos();
	void Insertar_Fin(int codi, string correo, string nom, string hrs, int sala, string asiento, string peli);
	string Extrae_Prin();
	string Extrae_Inter(string ext);
	string Extrae_Fin();
	Boletos Buscar_Codi(int codi);
	void Reiniciar_BD();
private:
	Boletos* cabecera, * fin, * nodo;
};

