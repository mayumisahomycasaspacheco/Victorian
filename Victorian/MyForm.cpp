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
	Application::Run(gcnew Victorian::Form_Carrera());
	return 0;
}