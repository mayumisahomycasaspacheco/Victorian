#include "MyForm.h"
#include "Form_Inicio.h"
#include "Form_Carrera.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	Victorian::Form_Inicio^ inicio = gcnew Victorian::Form_Inicio();
	Application::Run(inicio);

	if (inicio->modo == 1)
	{
		Application::Run(gcnew Victorian::MyForm());
	}

	return 0;
}