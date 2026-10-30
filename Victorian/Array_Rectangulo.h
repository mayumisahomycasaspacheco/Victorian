#pragma once
#include "Rectangulo.h"

ref class Array_Rectangulo
{
private:
	array<Rectangulo^>^ arreglo;
	int n;
public:
	Array_Rectangulo();
	~Array_Rectangulo();

	void agregar(Rectangulo^ rectangulo);
	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Array_Rectangulo::Array_Rectangulo()
{
	arreglo = gcnew array<Rectangulo^>(100);
	n = 0;
}

Array_Rectangulo::~Array_Rectangulo()
{
	//Destructor vacio
}

void Array_Rectangulo::agregar(Rectangulo^ rectangulo)
{
	if (n < 100)
	{
		arreglo[n] = rectangulo;
		n = n + 1;
	}
}

void Array_Rectangulo::dibujar(Graphics^ graphics)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->dibujar(graphics);
	}
}

void Array_Rectangulo::mover(int ancho_ventana, int alto_ventana)
{
	for (int i = 0; i < n; i++)
	{
		arreglo[i]->mover(ancho_ventana, alto_ventana);
	}
}