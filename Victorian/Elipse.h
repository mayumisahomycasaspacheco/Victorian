#pragma once
using namespace System::Drawing;

ref class Elipse
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int color;
public:
	Elipse(int x, int y, int dx, int dy, int ancho, int alto, int color);
	~Elipse();

	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Elipse::Elipse(int x, int y, int dx, int dy, int ancho, int alto, int color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->ancho = ancho;
	this->alto = alto;
	this->color = color;
}

Elipse::~Elipse()
{
	//Destructor vacio
}

void Elipse::dibujar(Graphics^ graphics)
{
	Pen^ lapiz = gcnew Pen(ColorTranslator::FromWin32(color), 2);
	graphics->DrawEllipse(lapiz, x, y, ancho, alto);
}

void Elipse::mover(int ancho_ventana, int alto_ventana)
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