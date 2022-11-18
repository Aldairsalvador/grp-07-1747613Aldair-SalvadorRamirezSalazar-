#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>// funcion new y delete punteros
#include <fstream>//archivos

using namespace std;

//declaracion de variables

int* producto, * year, registros, * decision, n = 1;
string* nombre, * clasificacion, * caracteristicas, * descripcion, * genero;
float* precio, * iva, * total, subtotal;

//funciones void
void alta();
void eliminar();
void modificar();
void lista();
void archivo();

int main()
{
	int opcion;
	printf("\t ***Block buster tienda en linea*** \n");
	printf("1.-Agregar articulo \n 2.-Modificar articulo \n 3.-Eliminar articulo \n 4.-Lista de Articulos \n 5.-Limpiar Pantalla \n 6.-archivo \n 7.-salir ");
	scanf_s("%d", &opcion);


	switch (opcion)
	{
	case 1:
		alta();
		system("pause");
		return main();
		break;

	case 2:
		modificar();
		system("pause");
		return main();
		break;

	case 3:
		eliminar();
		system("pause");
		return main();
		break;

	case 4:
		lista();
		system("pause");
		return main();
		break;

	case 5:
		//Limpiar Pantalla
		system("cls");
		return main();
		break;

	case 6:
		archivo();
		system("cls");
		return main();
		break;

	case 7:
		//Salir
		exit(1);
		break;
	default:
		printf("opcion invalida \n");
		//	return main();
	}
}

void alta()
{
	printf("Cuantos registros desea dar de alta");
	scanf_s("%d", &registros);

	producto = new int[registros];
	nombre = new string[registros];
	caracteristicas = new string[registros];
	clasificacion = new string[registros];
	descripcion = new string[registros];
	genero = new string[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	//arreglo
	for (int i = 0; i < registros; i++)
	{
		printf("ingrese el producto \n");
		scanf_s("%d", &producto[i]);
		do
		{
			if (producto[i] != producto[i - n])
			{
				n = n + 1;
			}
			else
			{
				printf("el articulo ya existe\n");
				printf("Ingrese el articul\n");
				scanf_s("%d", &producto[i]);
			}
		} while (n < registros);
		printf("ingrese el nombre \n");
		cin.ignore();
		getline(cin, nombre[i]);
		printf("ingrese las caracteristicas \n");
		getline(cin, caracteristicas[i]);
		printf("ingrese la clasificacion \n");
		getline(cin, clasificacion[i]);
		printf("ingrese la descripcion \n");
		getline(cin, descripcion[i]);
		printf("ingrese el genero \n");
		getline(cin, genero[i]);
		printf("ingrese el precio \n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
		/*
		if ((registros - 1) == i)
		{
			int desicion;
			printf("Quieres dar de alta otro registro");
			scanf_s("%d", decision);
			if (decision =! 2)
			{
				registros = registros + 1;
			}
		}*/
	}
}

void modificar()
{
	int modificar;
	do
	{
		printf("ingrese el numero del articulo a modificar \n");
		scanf_s("%d", &modificar);
	} while (modificar < 0);


	for (int i = 0; i < registros; i++)
	{
		if (modificar == producto[i])
		{
			printf("ingrese el nombre \n");
			cin.ignore();
			getline(cin, nombre[i]);
			printf("ingrese las caracteristicas \n");
			getline(cin, caracteristicas[i]);
			printf("ingrese la clasificacion \n");
			getline(cin, clasificacion[i]);
			printf("ingrese la descripcion \n");
			getline(cin, descripcion[i]);
			printf("ingrese el genero \n");
			getline(cin, genero[i]);
			printf("ingrese el precio \n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * .16;
			total[i] = precio[i] + iva[i];
		}
	}
}

void eliminar()
{
	int eliminar;
	printf("ingrese el numero del articulo a eliminar \n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registros; i++)
	{
		if (eliminar == producto[i])
		{
			producto[i] = 0;
		}
	}

}

void lista()
{
	int op2;
	int i = 0;
	string buscar;
	printf("1.-Clasificacion \n 2.-Genero \n");
	scanf_s("%d", &op2);
	switch (op2)
	{
	case 1:

		printf("Ingrese la clasificacion a buscar\n");
		cin.ignore();
		getline(cin, buscar);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == buscar)
			{
				if (producto[i] != 0)
				printf("\n articulo: %d ", producto[i]) << endl;
				printf(" videojuego: %s", nombre[i].c_str()) << endl;
				printf(" clasificacion: %s", clasificacion[i].c_str()) << endl;
				printf(" genero: %s", genero[i].c_str()) << endl;
				printf(" caracteristicas: %s", caracteristicas[i].c_str()) << endl;
				printf(" descripcion: %s", descripcion[i].c_str()) << endl;
				printf(" subtotal: %f", precio[i]) << endl;
				printf(" iva: %f", iva[i]) << endl;
				printf(" total: %f", total[i]) << endl;
			}
		}
		break;

	case 2:
		printf("Ingrese el genero  a buscar\n");
		cin.ignore();
		getline(cin, buscar);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == buscar)
			{
				printf("articulo: %d ", producto[i]) << endl;
				printf("videojuego: %s", nombre[i].c_str()) << endl;
				printf("clasificacion: %s", clasificacion[i].c_str()) << endl;
				printf("genero: %s", genero[i].c_str()) << endl;
				printf("caracteristicas: %s", caracteristicas[i].c_str()) << endl;
				printf("descripcion: %s", descripcion[i].c_str()) << endl;
				printf("subtotal: %f", precio[i]) << endl;
				printf("iva: %f", iva[i]) << endl;
				printf("total: %f", total[i]) << endl;
			}
		}
		break;
	}
}

void archivo()
{
	ofstream archivo;
	string nombre2;

	nombre2 = "blockbustertxt";
	archivo.open(nombre2.c_str(), ios::out);

	if (archivo.fail()) {

		printf("ERROR NO SE GENERO EL ARCHIVO");
		system("pause");
		exit(1);

	}
	archivo << "informacion ";
	for (int i = 0; i < registros; i++)
	{
		archivo << "Articulo: %d" << producto[i] << endl;
		archivo << "videojuego:" << nombre[i].c_str() << endl;
		archivo << "clasificacion: %s",clasificacion[i].c_str() << endl;
		archivo << "genero: %s", genero[i].c_str() << endl;
		archivo << "caracteristicas: %s", caracteristicas[i].c_str() << endl;
		archivo << "descripcion: %s", descripcion[i].c_str() << endl;
		archivo << "subtotal: %f", precio[i] << endl;
		archivo << "iva: %f", iva[i] << endl;
		archivo << "total: %f", total[i] << endl;
	}
	archivo.close();
}
