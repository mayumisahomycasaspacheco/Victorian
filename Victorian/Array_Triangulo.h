#pragma once
#include "Triangulo.h"

ref class Array_Triangulo
{
private:
	array<Triangulo^>^ arreglo;
	int n;
public:
	Array_Triangulo();
	~Array_Triangulo();

	void agregar(Triangulo^ triangulo);
	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Array_Triangulo::Array_Triangulo()
{
	arreglo = gcnew array<Triangulo^>(100);
	n = 0;
}

Array_Triangulo::~Array_Triangulo()
{
	//Destructor vacio
}

void Array_Triangulo::agregar(Triangulo^ triangulo)
{
	if (n < 100)
	{
		arreglo[n] = triangulo;
		n = n + 1;
	}
}

void Array_Triangulo::dibujar(Graphics^ graphics)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->dibujar(graphics);
	}
}

void Array_Triangulo::mover(int ancho_ventana, int alto_ventana)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->mover(ancho_ventana, alto_ventana);
	}
}