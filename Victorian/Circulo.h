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

	void dibujar(Graphics^ graphics);
	void mover(int ancho_ventana, int alto_ventana);
	void avanzar();
	int obtener_borde();
};

inline Circulo::Circulo(int x, int y, int dx, int dy, int diametro, int color)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->diametro = diametro;
	this->color = color;
}

inline Circulo::~Circulo()
{
	//Destructor vacio
}

inline void Circulo::dibujar(Graphics^ graphics)
{
	Pen^ lapiz = gcnew Pen(ColorTranslator::FromWin32(color), 2);
	graphics->DrawEllipse(lapiz, x, y, diametro, diametro);
}

inline void Circulo::mover(int ancho_ventana, int alto_ventana)
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

	if (x + diametro >= ancho_ventana)
	{
		dx = -dx;
		x = ancho_ventana - diametro;
	}

	if (y + diametro >= alto_ventana)
	{
		dy = -dy;
		y = alto_ventana - diametro;
	}
}

inline void Circulo::avanzar()
{
	x = x + dx;
}

inline int Circulo::obtener_borde()
{
	return x + diametro;
}