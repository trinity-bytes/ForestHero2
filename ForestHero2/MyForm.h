#pragma once
#include "GestionJuego.h"
#include "Guardian.h"
#include "Aliado.h"
namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			

			g = panelCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panelCanvas->ClientRectangle);

			bmpEscenario1 = gcnew Bitmap("Resources/Images/Escenario1.png");
			bmpGuardian = gcnew Bitmap("Resources/Images/personajeTemp.png");
			bmpEnemigo = gcnew Bitmap("Resources/Images/enemigoTemp.png");
			bmpAliado = gcnew Bitmap("Resources/Images/aliadoTemp.png");
			bmpAgua = gcnew Bitmap("Resources/Images/aguaTemp.png");

			guardian = new Guardian(200, 200, bmpGuardian->Width / 4, bmpGuardian->Height / 4);
			objGJuego = new GestionJuego();

			// inicializamos los elementos pasando los parametros de sus dimensiones
			objGJuego->IniciarElementos(
				bmpEnemigo->Width / 4, bmpEnemigo->Height / 4,
				bmpAgua->Width, bmpAgua->Height
			);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpEscenario1;
		Bitmap^ bmpGuardian;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpAliado;
		Bitmap^ bmpAgua;

		Guardian* guardian;
		GestionJuego* objGJuego;
		Aliado* aliado;

		bool mostrar = false;
	private: System::Windows::Forms::Panel^ panelCanvas;

	private: System::Windows::Forms::Timer^ timer1; 

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelCanvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panelCanvas
			// 
			this->panelCanvas->Location = System::Drawing::Point(0, 0);
			this->panelCanvas->Name = L"panelCanvas";
			this->panelCanvas->Size = System::Drawing::Size(1366, 768);
			this->panelCanvas->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			/// Desactiva el escalado automatico vvvv
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None; 

			// todo Anotacion para el futuro: al haber desacrivado el escalado de la fuente
			// todo puede ser que tengamos progmelas al mostrar texto, aun no lo se xD
			//this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panelCanvas);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		objGJuego->MoverTodo(buffer->Graphics);
		
		buffer->Graphics->DrawImage(bmpEscenario1, 0, 0, bmpEscenario1->Width, bmpEscenario1->Height);

		objGJuego->DibujarTodo(buffer->Graphics, bmpEnemigo, bmpAgua);

		guardian->Dibujar(buffer->Graphics, bmpGuardian);

		if (mostrar)
		{
			aliado->Mover(buffer->Graphics, Direccion::Derecha);
			aliado->dibujar(buffer->Graphics, bmpAliado);
		}

		buffer->Render(g);
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			guardian->Mover(buffer->Graphics, Direccion::Izquierda); break;
		case Keys::D:
			guardian->Mover(buffer->Graphics, Direccion::Derecha); break;
		case Keys::S:
			guardian->Mover(buffer->Graphics, Direccion::Abajo); break;
		case Keys::W:
			guardian->Mover(buffer->Graphics, Direccion::Arriba); break;
		case Keys::P:
			// plantar arbol 
			break;
		case Keys::M:
			// Disparar semillas 
			break;
		case Keys::K:
			aliado = new Aliado(panelCanvas->MinimumSize.Width, rand() % 300 + 200, 20, bmpGuardian->Width / 2, bmpGuardian->Height / 2);  // Llamar a su función de mover
			mostrar = true;
			break;
		case Keys::Escape:
			this->Close(); break;
		}
	}

	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		guardian->Mover(buffer->Graphics, Direccion::Ninguna);
	}
};
}