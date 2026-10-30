#pragma once
using namespace System::Drawing;

ref class Rectangulo
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int color;
public:
	Rectangulo(int x, int y, int dx, int dy, int ancho, int alto, int color);
	~Rectangulo();

	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Rectangulo::Rectangulo(int x, int y, int dx, int dy, int ancho, int alto, int color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->alto = alto;
	this->ancho = ancho;
	this->color = color;
}

Rectangulo::~Rectangulo()
{
	//Destructor vacio
}

void Rectangulo::dibujar(Graphics^ graphics)
{
	Pen^ lapiz = gcnew Pen(ColorTranslator::FromWin32(color), 2);
	graphics->DrawRectangle(lapiz, x, y, ancho, alto);
}

void Rectangulo::mover(int ancho_ventana, int alto_ventana)
{
	x = x + dx;
	y = y + dy;

	if (x <= 0)
	{
		dx = -dx;
		x = 0;
	}

	if (y <= 0)
	{
		dy = -dy;
		y = 0;
	}

	if (x + ancho >= ancho_ventana)
	{
		dx = -dx;
		x = ancho_ventana - ancho;
	}

	if (y + alto >= alto_ventana)
	{
		dy = -dy;
		y = alto_ventana - alto;
	}
}