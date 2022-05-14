#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Archivo
{
	string nomfun;
	Archivo* sig;
};
class ListArch
{
public:
	ListArch();
	~ListArch();
	void Mostrar_Archivo();
	void Insertar_Fin(string nuevo);
	string Extrae_Prin();
	string Extrae_Inter(string ext);
	string Extrae_Fin();
	bool Buscar_Archivo(string usu);
	void Reiniciar_BD();
	bool Buscar_Funcion(string fun);
private:
	Archivo* cabecera, * fin, * nodo;
};

