#pragma once
using namespace System::Drawing;

ref class Triangulo
{
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int color;
public:
	Triangulo(int x, int y, int dx, int dy, int ancho, int alto, int color);
	~Triangulo();

	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
};

Triangulo::Triangulo(int x, int y, int dx, int dy, int ancho, int alto, int color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->alto = alto;
	this->ancho = ancho;
	this->color = color;
}

Triangulo::~Triangulo()
{
	//Destructor vacio
}

void Triangulo::dibujar(Graphics^ graphics)
{
	Pen^ lapiz = gcnew Pen(ColorTranslator::FromWin32(color), 2);

	array<Point>^ puntos = gcnew array<Point>(3);
	puntos[0] = Point(x + ancho / 2, y);
	puntos[1] = Point(x, y + alto);
	puntos[2] = Point(x + ancho, y + alto);
	graphics->DrawPolygon(lapiz, puntos);
}

void Triangulo::mover(int ancho_ventana, int alto_ventana)
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