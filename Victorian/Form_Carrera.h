#pragma once
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"

namespace Victorian {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Carrera
	/// </summary>
	public ref class Form_Carrera : public System::Windows::Forms::Form
	{
	public:
		Form_Carrera(void)
		{
			InitializeComponent();

			fondo = gcnew Bitmap("..\\sprites\\Sprite-0001.png");
			this->DoubleBuffered = true;
			
			int color_circulo = ColorTranslator::ToWin32(Color::FromArgb(128, 0, 32));
			int color_cuadrado = ColorTranslator::ToWin32(Color::FromArgb(34, 85, 60));
			int color_triangulo = ColorTranslator::ToWin32(Color::FromArgb(25, 45, 85));

			circulo = gcnew Circulo(40, 100, azar->Next(1, 8), 0, 60, color_circulo);
			cuadrado = gcnew Cuadrado(40, 240, azar->Next(1, 8), 0, 60, color_cuadrado);
			triangulo = gcnew Triangulo(40, 380, azar->Next(1, 8), 0, 50, 80, color_triangulo);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form_Carrera()
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
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form_Carrera::timer1_Tick);
			// 
			// Form_Carrera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1332, 703);
			this->KeyPreview = true;
			this->Name = L"Form_Carrera";
			this->Text = L"Form_Carrera";
			this->Load += gcnew System::EventHandler(this, &Form_Carrera::Form_Carrera_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_Carrera::Form_Carrera_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form_Carrera::Form_Carrera_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

		Bitmap^ fondo;

		Circulo^ circulo;
		Cuadrado^ cuadrado;
		Triangulo^ triangulo;
		Random^ azar = gcnew Random();
		int meta = 900;

	private: System::Void Form_Carrera_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	private: System::Void Form_Carrera_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		e->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
		e->Graphics->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;
		e->Graphics->DrawImage(fondo, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		
		e->Graphics->DrawLine(Pens::Black, meta, 0, meta, 576);
		
		circulo->dibujar(e->Graphics);
		cuadrado->dibujar(e->Graphics);
		triangulo->dibujar(e->Graphics);
	}
	private: System::Void Form_Carrera_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		if (e->KeyCode == Keys::Space)
		{
			timer1->Enabled = true;
		}

		else if (e->KeyCode == Keys::Escape)
		{
			this->Close();
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		circulo->avanzar();
		cuadrado->avanzar();
		triangulo->avanzar();

		if (circulo->obtener_borde() >= meta)
		{
			timer1->Enabled = false;
			MessageBox::Show("Gana el circulo");
		}

		else if (cuadrado->obtener_borde() >= meta)
		{
			timer1->Enabled = false;
			MessageBox::Show("Gana el cuadrado");
		}

		else if (triangulo->obtener_borde() >= meta)
		{
			timer1->Enabled = false;
			MessageBox::Show("Gana el triangulo");
		}

		this->Invalidate();
	}
	};
}
