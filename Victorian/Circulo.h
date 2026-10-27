#pragma once
using   namespace System::Drawing;

ref class Circulo
{
private:
	int x, y;
	int dx, dy;
	int diametro;
	int color;
public:
	Circulo(int x, int y, int dx, int dy, int diametro, int color);
	~Circulo();

	void dibujar(Graphics^ g);
	void mover(int ancho_ventana, int alto_ventana);
};

Circulo::Circulo(int x, int y, int dx, int dy, int diametro, int color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->diametro = diametro;
	this->color = color;
}

Circulo::~Circulo()
{
	//Destructor vacio
}

void Circulo::dibujar(Graphics^ g)
{
	Pen^ lapiz = gcnew Pen(ColorTranslator::FromWin32(color), 2);
	g->DrawEllipse(lapiz, x, y, diametro, diametro);
}

void Circulo::mover(int ancho_ventana, int alto_ventana)
{
	x = x + dx;
	y = y + dy;

	if (x <= 0)
	{
		dx = -dx;
	}

	if (y <= 0)
	{
		dy = -dy;
	}

	if (x + diametro >= ancho_ventana)
	{
		dx = -dx;
	}

	if (y + diametro >= alto_ventana)
	{
		dy = -dy;
	}
}