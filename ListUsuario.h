#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Usuario
{
	string correo;
	string nom;
	string contra;
	int cash;
	Usuario* sig;
};
class ListUsuario
{
public:
	ListUsuario();
	~ListUsuario();
	void Mostrar_Usuarios();
	void Insertar_Fin(string xcorr, string xnom,string xcontra,int xcash);
	string Extrae_Prin();
	string Extrae_Inter(string ext);
	string Extrae_Fin();
	bool Buscar_Val_Usuario(string usu, string con);
	bool Buscar_Usuario(string usu);
	void Reiniciar_BD();
	Usuario Buscar_Info_Usuario(string nomUsu);
	bool Cambiar_Cash(string usu, int rest);
	bool Sumar_Cash(string usu, int sum);
private:
	Usuario* cabecera, * fin, * nodo;
};

