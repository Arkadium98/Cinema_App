#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Administrador
{
	string nom;
	string contra;
	Administrador* sig;
};
class Lista 
{
public:
	Lista();
	~Lista();
	void Mostrar_Admin();
	void Insertar_Fin(string nuevo,string con);
	string Extrae_Prin();
	string Extrae_Inter(string ext);
	string Extrae_Fin();
	bool Buscar_Val_Admin(string usu,string con);
	bool Buscar_Admin(string usu);
	void Reiniciar_BD();
private:
	Administrador* cabecera, * fin, * nodo;
};

