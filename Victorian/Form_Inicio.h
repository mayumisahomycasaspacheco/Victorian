#pragma once
#include "Fondo.h"

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
			
			fondo = cargar_fondo();
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_Inicio::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Goldenrod;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Old English Text MT", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::SaddleBrown;
			this->button1->Location = System::Drawing::Point(113, 515);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 63);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Inicio::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Goldenrod;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Old English Text MT", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(1067, 515);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 63);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form_Inicio::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Old English Text MT", 79.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(382, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(567, 158);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Victorian";
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::SaddleBrown;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(171, 301);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(993, 152);
			this->label2->TabIndex = 3;
			this->label2->Text = resources->GetString(L"label2.Text");
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form_Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1332, 703);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::SaddleBrown;
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
			this->PerformLayout();

		}
#pragma endregion
	public:
		int modo = 0;
	Bitmap^ fondo;

	private: System::Void Form_Inicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Form_Inicio_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		e->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
		e->Graphics->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::Half;

		if (fondo != nullptr)
		{
			e->Graphics->DrawImage(fondo, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		}

		else
		{
			e->Graphics->Clear(Color::Wheat);
		}

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		modo = 1;
		this->Close();
	}
};
}
