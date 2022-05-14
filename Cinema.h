#pragma once

#include "Lista.h"
#include "ListMovies.h"
#include "ListFunct.h"
#include "Asientos.h"
#include "ListArch.h"
#include "ListUsuario.h"
#include "ArbolMovies.h"
#include "ArbolHorario.h"
#include "ListBoletos.h"
#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <random>
#include <tchar.h>

#include "EASendMailObj.tlh"
using namespace std;
typedef class  ListMovies ListMovies;
typedef class Lista Lista;
typedef class ListFunct ListFunct;
typedef class Asientos Asientos;
typedef class ListArch ListArch;
typedef class ListUsuario ListUsuario;
typedef class ArbolMovies ArbolMovies;
typedef class ArbolHorario ArbolHorario;
typedef class ListBoletos ListBoletos;

using namespace EASendMailObjLib;

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;
class Cinema 
{
public:
	Cinema();
	~Cinema();
	void Imprimir(vector<string>&, int);
	void Menu();
	void Menu_Admin();
	void Validar_Admin();
	void LeeryCopiarAdmin();
	void Agregar_Admin();
	void Eliminar_Admin();
	void LeeryCopiarMovie();
	void Edit_Movie();
	void Agregar_Movie();
	void Eliminar_Movie();
	void LeeryCopiarSalaHora();
	void Agregar_Sala_Hora();
	void Eliminar_Sala_Hora();
	void LeeryCopiarUsu();
	void Menu_Usuario();
	void Iniciar_Sesion();
	void Crear_Cuenta();
	void Menu_Prin(string nomUsu);
	void Comprar_Boletos(string Usu);
	void LeeryCopiarArch();
	void CrearyCopiarFun(string nomfun);
	void LeeryCopiarFun(string nomfun);
	void Enviar_Mail(int codi,string correo,string nom,string hrs,int sala,string asiento,string peli);
	void LeeryCopiarBole();
private:
	Lista* miLista;
	ListMovies* miListMovies;
	ListFunct* miListFunct;
	Asientos* miAsientos;
	ListArch* miListArch;
	ListUsuario* miListUsuario;
	ArbolMovies* miArbolMovies;
	ArbolHorario* miArbolHorario;
	ListBoletos* miBoletos;
	int ID = 0,ID2 = 0;
	vector<string> Menu_1 = { "1) Menu de Usuario","2) Menu de Administrador","3) Salir" };
	vector<string>Menu_Adm = { "1) Mostrar Administradores","2) Agregar un Administrador","3) Eliminar un Administrador","4) Validar Boleto con Codigo","5) Editar Películas","6) Mostrar Usuarios","7) Regresar a Menu" };
	vector<string> Menu_Edit = { "1) Mostrar Películas" ,"2) Agregar Película","3) Eliminar Película","4) Mostrar Funciones","5) Agregar Funciones","6) Eliminar Funciones","7) Regresar a Menu de Administrador"};
	vector<string> Menu_Usu = { "1) Iniciar Sesion","2) Crear Cuenta","3) Regresar a Menu" };
	vector<string> Menu_Pin = { "1) Mostrar Películas por Calificación","2) Mostrar Películas por Horario","3) Mostrar Películas en Orden Alfabetico","4) Comprar Boletos","5) Ingresar dinero en la Cuenta","6) Mostrar Estado de Cuenta","7) Regresar a Menu de Usuario","8) Salir" };
};

