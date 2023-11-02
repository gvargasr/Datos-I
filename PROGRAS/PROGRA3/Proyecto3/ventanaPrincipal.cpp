#include "ventanaPrincipal.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Interfaz;


[STAThreadAttribute]
void main(cli::array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Interfaz::ventanaPrincipal form;
	Application::Run(%form);
}