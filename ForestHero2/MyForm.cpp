#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ForestHero2;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ForestHero2::MyForm());
}