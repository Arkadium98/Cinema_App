#pragma once
#include <iostream>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <fstream>
using namespace std;
struct Movie
{
	string peli;
	string gene;
	float cali;
	int id;
	Movie* sig;
	Movie* sigalf;
};
class ListMovies
{
public:
	ListMovies();
	~ListMovies();
	void Mostrar_Por_ID();
	void Mostrar_Movie();
	void Mostrar_Movie_y_Seleccionar();
	void Mostrar_Alfa();
	void Insertar_Movie(string pel, string gen,float cal,int idx);
	void Insertar_Alfa(string pel, string gen, float cal, int idx);
	string Extrae_Prin_Movie();
	string Extrae_Inter_Movie(int idx);
	string Extrae_Fin_Movie();
	string Extrae_Prin_Alfa();
	string Extrae_Inter_Alfa(int idx);
	string Extrae_Fin_Alfa();
	Movie Buscar_Movie(int idx);
	void Reiniciar_BD_Movie();
private:
	Movie* cabecera, * fin, * nodo, * aux,*ante;
	Movie* cabealfa, * finalfa, * nodoalfa;
};

