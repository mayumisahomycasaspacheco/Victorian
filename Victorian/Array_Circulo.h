#pragma once
#include "Circulo.h"

ref class Array_Circulo
{
private:
	array<Circulo^>^ arreglo;
	int n;
public:
	Array_Circulo();
	~Array_Circulo();

	void agregar(Circulo^ circulo);
	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Array_Circulo::Array_Circulo()
{
	arreglo = gcnew array<Circulo^>(100);
	n = 0;
}

Array_Circulo::~Array_Circulo()
{
	//Destructor vacio
}

void Array_Circulo::agregar(Circulo^ circulo)
{
	if (n < 100)
	{
		arreglo[n] = circulo;
		n = n + 1;
	}
}

void Array_Circulo::dibujar(Graphics^ graphics)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->dibujar(graphics);
	}
}

void Array_Circulo::mover(int ancho_ventana, int alto_ventana)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->mover(ancho_ventana, alto_ventana);
	}
}