#pragma once

namespace Victorian {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form_Inicio
	/// </summary>
	public ref class Form_Inicio : public System::Windows::Forms::Form
	{
	public:
		Form_Inicio(void)
		{
			InitializeComponent();
			
			fondo = gcnew Bitmap("..\\sprites\\Sprite-0001.png");
			this->DoubleBuffered = true;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Form_Inicio()
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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form_Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1006, 529);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->MaximizeBox = false;
			this->Name = L"Form_Inicio";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form_Inicio";
			this->Load += gcnew System::EventHandler(this, &Form_Inicio::Form_Inicio_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_Inicio::Form_Inicio_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	Bitmap^ fondo;

	private: System::Void Form_Inicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Form_Inicio_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		e->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
		e->Graphics->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;
		e->Graphics->DrawImage(fondo, 0, 0, this->ClientSize.Width, this->ClientSize.Height);;
	}
	};
}
