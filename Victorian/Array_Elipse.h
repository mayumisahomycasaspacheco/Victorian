#pragma once
#include "Elipse.h"

ref class Array_Elipse
{
private:
	array<Elipse^>^ arreglo;
	int n;
public:
	Array_Elipse();
	~Array_Elipse();

	void agregar(Elipse^ elipse);
	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Array_Elipse::Array_Elipse()
{
	arreglo = gcnew array<Elipse^>(100);
	n = 0;
}

Array_Elipse::~Array_Elipse()
{
	//Destructor vacio
}

void Array_Elipse::agregar(Elipse^ elipse)
{
	if (n < 100)
	{
		arreglo[n] = elipse;
		n = n + 1;
	}
}

void Array_Elipse::dibujar(Graphics^ graphics)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->dibujar(graphics);
	}
}

void Array_Elipse::mover(int ancho_ventana, int alto_ventana)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->mover(ancho_ventana, alto_ventana);
	}
}