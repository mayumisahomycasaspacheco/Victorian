#pragma once
using namespace System::Drawing;

ref class Cuadrado
{
private:
	int x, y;
	int dx, dy;
	int lado;
	int color;
public:
	Cuadrado(int x, int y, int dx, int dy, int lado, int color);
	~Cuadrado();

	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Cuadrado::Cuadrado(int x, int y, int dx, int dy, int lado, int color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->lado = lado;
	this->color = color;
}

Cuadrado::~Cuadrado()
{
	//Destructor vacio
}

void Cuadrado::dibujar(Graphics^ graphics)
{
	Pen^ lapiz = gcnew Pen(ColorTranslator::FromWin32(color), 2);
	graphics->DrawRectangle(lapiz, x, y, lado, lado);
}

void Cuadrado::mover(int ancho_ventana, int alto_ventana)
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

	if (x + lado >= ancho_ventana)
	{
		dx = -dx;
		x = ancho_ventana - lado;
	}

	if (y + lado >= alto_ventana)
	{
		dy = -dy;
		y = alto_ventana - lado;
	}
}