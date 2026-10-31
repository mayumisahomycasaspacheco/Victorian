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
			
			circulo = gcnew Circulo(40, 100, azar->Next(1, 8), 0, 60, 0);
			cuadrado = gcnew Cuadrado(40, 240, azar->Next(1, 8), 0, 60, 0);
			triangulo = gcnew Triangulo(40, 380, azar->Next(1, 8), 0, 50, 80, 0);
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

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form_Carrera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 553);
			this->Name = L"Form_Carrera";
			this->Text = L"Form_Carrera";
			this->Load += gcnew System::EventHandler(this, &Form_Carrera::Form_Carrera_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_Carrera::Form_Carrera_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

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
		e->Graphics->DrawLine(Pens::Black, meta, 0, meta, 576);
		circulo->dibujar(e->Graphics);
		cuadrado->dibujar(e->Graphics);
		triangulo->dibujar(e->Graphics);
	}
	};
}
