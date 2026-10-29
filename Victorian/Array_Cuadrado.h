#pragma once
#include "Cuadrado.h"

ref class Array_Cuadrado
{
private:
	array<Cuadrado^>^ arreglo;
	int n;
public:
	Array_Cuadrado();
	~Array_Cuadrado();

	void agregar(Cuadrado^ cuadrado);
	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Array_Cuadrado::Array_Cuadrado()
{
	arreglo = gcnew array<Cuadrado^>(100);
	n = 0;
}

Array_Cuadrado::~Array_Cuadrado()
{
	//Destructor vacio
}

void Array_Cuadrado::agregar(Cuadrado^ cuadrado)
{
	if (n < 100)
	{
		arreglo[n] = cuadrado;
		n = n + 1;
	}
}

void Array_Cuadrado::dibujar(Graphics^ graphics)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->dibujar(graphics);
	}
}

void Array_Cuadrado::mover(int ancho_ventana, int alto_ventana)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->mover(ancho_ventana, alto_ventana);
	}
}