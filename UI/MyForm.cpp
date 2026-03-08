#include "MenuJuego.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ForestHero2::UI;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MenuJuego());
}
