#pragma once
#include "Array_Circulo.h"
#include "Array_Cuadrado.h"
#include "Array_Rectangulo.h"
#include "Array_Elipse.h"
#include "Array_Triangulo.h"

namespace Victorian {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			fondo = gcnew Bitmap("Sprite-0001.png");
			this->DoubleBuffered = true;
			
			paleta = gcnew array<int>(8);
			paleta[0] = ColorTranslator::ToWin32(Color::FromArgb(139, 69, 19));
			paleta[1] = ColorTranslator::ToWin32(Color::FromArgb(184, 134, 11));
			paleta[2] = ColorTranslator::ToWin32(Color::FromArgb(183, 110, 60));
			paleta[3] = ColorTranslator::ToWin32(Color::FromArgb(128, 0, 32));
			paleta[4] = ColorTranslator::ToWin32(Color::FromArgb(34, 85, 60));
			paleta[5] = ColorTranslator::ToWin32(Color::FromArgb(25, 45, 85));
			paleta[6] = ColorTranslator::ToWin32(Color::FromArgb(112, 66, 20));
			paleta[7] = ColorTranslator::ToWin32(Color::FromArgb(90, 70, 60));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	Bitmap^ fondo;

	Array_Circulo^ circulos = gcnew Array_Circulo();
	Array_Cuadrado^ cuadrados = gcnew Array_Cuadrado();
	Array_Rectangulo^ rectangulos = gcnew Array_Rectangulo();
	Array_Elipse^ elipses = gcnew Array_Elipse();
	Array_Triangulo^ triangulos = gcnew Array_Triangulo();
	Random^ azar = gcnew Random();

	array<int>^ paleta;

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		if (e->KeyCode == Keys::T)
		{
			this->Text = "Presionaste T";

			int ancho = azar->Next(20, 80);
			int alto = azar->Next(20, 80);
			int x = azar->Next(50, this->ClientSize.Width - ancho - 50);
			int y = azar->Next(50, this->ClientSize.Width - alto - 50);
			int dx = azar->Next(2, 7);
			int dy = azar->Next(2, 7);
			int color = paleta[azar->Next(0, 8)];

			triangulos->agregar(gcnew Triangulo(x, y, dx, dy, ancho, alto, color));
		}

		else if (e->KeyCode == Keys::C)
		{
			this->Text = "Presionaste C";

			int diametro = azar->Next(20, 80);
			int x = azar->Next(50, this->ClientSize.Width - diametro - 50);
			int y = azar->Next(50, this->ClientSize.Width - diametro - 50);
			int dx = azar->Next(2, 7);
			int dy = azar->Next(2, 7);
			int color = paleta[azar->Next(0, 8)];

			circulos->agregar(gcnew Circulo(x, y, dx, dy, diametro, color));
		}

		else if (e->KeyCode == Keys::E)
		{
			this->Text = "Presionaste E";

			int ancho = azar->Next(20, 80);
			int alto = azar->Next(20, 80);
			int x = azar->Next(50, this->ClientSize.Width - ancho - 50);
			int y = azar->Next(50, this->ClientSize.Width - alto - 50);
			int dx = azar->Next(2, 7);
			int dy = azar->Next(2, 7);
			int color = paleta[azar->Next(0, 8)];

			elipses->agregar(gcnew Elipse(x, y, dx, dy, ancho, alto, color));
		}

		else if (e->KeyCode == Keys::D)
		{
			this->Text = "Presionaste D";

			int lado = azar->Next(20, 80);
			int x = azar->Next(50, this->ClientSize.Width - lado - 50);
			int y = azar->Next(50, this->ClientSize.Width - lado - 50);
			int dx = azar->Next(2, 7);
			int dy = azar->Next(2, 7);
			int color = paleta[azar->Next(0, 8)];

			cuadrados->agregar(gcnew Cuadrado(x, y, dx, dy, lado, color));
		}

		else if (e->KeyCode == Keys::R)
		{
			this->Text = "Presionaste R";

			int ancho = azar->Next(20, 80);
			int alto = azar->Next(20, 80);
			int x = azar->Next(50, this->ClientSize.Width - ancho - 50);
			int y = azar->Next(50, this->ClientSize.Width - alto - 50);
			int dx = azar->Next(2, 7);
			int dy = azar->Next(2, 7);
			int color = paleta[azar->Next(0, 8)];

			rectangulos->agregar(gcnew Rectangulo(x, y, dx, dy, ancho, alto, color));
		}

		else if (e->KeyCode == Keys::Escape)
		{
			this->Close();
		}
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		circulos->dibujar(e->Graphics);
		cuadrados->dibujar(e->Graphics);
		rectangulos->dibujar(e->Graphics);
		elipses->dibujar(e->Graphics);
		triangulos->dibujar(e->Graphics);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		circulos->mover(this->ClientSize.Width, this->ClientSize.Height);
		cuadrados->mover(this->ClientSize.Width, this->ClientSize.Height);
		rectangulos->mover(this->ClientSize.Width, this->ClientSize.Height);
		elipses->mover(this->ClientSize.Width, this->ClientSize.Height);
		triangulos->mover(this->ClientSize.Width, this->ClientSize.Height);
		this->Invalidate();
	}
};
}
