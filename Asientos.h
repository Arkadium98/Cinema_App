#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Seat
{
	string A1,A2,A3,A4,A5,A6,A7,A8;
	Seat* sig;
};
class Asientos
{
public:
	Asientos();
	~Asientos();
	void Mostrar_Asientos();
	void Insertar_Asientos(string xA1, string xA2, string xA3, string xA4, string xA5, string xA6, string xA7, string xA8);
	string Cambiar_Asientos(string ext);
	void Borrar_Todo();
	string Extrae_Fin();
	bool Buscar_Asiento(string usu);
	void Reiniciar_BD(string nom);
private:
	Seat* cabecera, * fin, * nodo;
	
};

