#pragma once
#include "GestionJuego.h"
#include "Guardian.h"
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
			bmpSemilla = gcnew Bitmap("Resources/Images/semilla.png");
			bmpBasura = gcnew Bitmap("Resources/Images/basura.png");
			bmpArbol = gcnew Bitmap("Resources/Images/arbol.png");

			guardian = new Guardian(200, 200, bmpGuardian->Width / 4, bmpGuardian->Height / 4);
			objGJuego = new GestionJuego();

			// inicializamos los elementos pasando los parametros de sus dimensiones
			objGJuego->IniciarElementos(
				bmpEnemigo->Width / 4, bmpEnemigo->Height / 4,
				bmpAgua->Width, bmpAgua->Height,
				bmpSemilla->Width, bmpSemilla->Height
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
		Bitmap^ bmpSemilla;
		Bitmap^ bmpBasura;
		Bitmap^ bmpArbol;

		Guardian* guardian;
		GestionJuego* objGJuego;
		int cantSemillas;

		// boleanos para capturar el estado de las teclas presionadas
		bool teclaW = false;
		bool teclaA = false;
		bool teclaS = false;
		bool teclaD = false;
		bool teclaM = false;
		bool teclaP = false;

	private: System::Windows::Forms::Panel^ panelCanvas;
	private: System::Windows::Forms::Timer^ timerJuego;
	private: System::Windows::Forms::Timer^ timerEnemigos;
	private: System::Windows::Forms::Timer^ timerAgua;
	private: System::Windows::Forms::Timer^ timerSemillas;
	private: System::Windows::Forms::Label^ CtSemillas;
	private: System::Windows::Forms::Timer^ timerBasura;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelCanvas = (gcnew System::Windows::Forms::Panel());
			this->CtSemillas = (gcnew System::Windows::Forms::Label());
			this->timerEnemigos = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAgua = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerSemillas = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerBasura = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelCanvas->SuspendLayout();
			this->SuspendLayout();
			// 
			// timerJuego
			// 
			this->timerJuego->Enabled = true;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &MyForm::timerJuego_Tick);
			// 
			// panelCanvas
			// 
			this->panelCanvas->Controls->Add(this->CtSemillas);
			this->panelCanvas->Location = System::Drawing::Point(0, 0);
			this->panelCanvas->Name = L"panelCanvas";
			this->panelCanvas->Size = System::Drawing::Size(1366, 768);
			this->panelCanvas->TabIndex = 0;
			// 
			// CtSemillas
			// 
			this->CtSemillas->AutoSize = true;
			this->CtSemillas->BackColor = System::Drawing::Color::Transparent;
			this->CtSemillas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->CtSemillas->Location = System::Drawing::Point(228, 35);
			this->CtSemillas->Name = L"CtSemillas";
			this->CtSemillas->Size = System::Drawing::Size(70, 26);
			this->CtSemillas->TabIndex = 0;
			this->CtSemillas->Text = L"label1";
			// 
			// timerEnemigos
			// 
			this->timerEnemigos->Enabled = true;
			this->timerEnemigos->Interval = 5000; // 5 segundos
			this->timerEnemigos->Tick += gcnew System::EventHandler(this, &MyForm::timerEnemigos_Tick);
			// 
			// timerAgua
			// 
			this->timerAgua->Enabled = true;
			this->timerAgua->Interval = 4000; // 4 segundos
			this->timerAgua->Tick += gcnew System::EventHandler(this, &MyForm::timerAgua_Tick);
			// 
			// timerSemillas
			// 
			this->timerSemillas->Enabled = true;
			this->timerSemillas->Interval = 4000; // 4 segundos
			this->timerSemillas->Tick += gcnew System::EventHandler(this, &MyForm::timerSemillas_Tick);
			// 
			// timerBasura
			// 
			this->timerBasura->Enabled = true;
			this->timerBasura->Interval = 8000; // 8 segundos
			this->timerBasura->Tick += gcnew System::EventHandler(this, &MyForm::timerBasura_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panelCanvas);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->panelCanvas->ResumeLayout(false);
			this->panelCanvas->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		objGJuego->ColisionPersonaje(guardian);

		objGJuego->MoverTodo(buffer->Graphics);

		cantSemillas = guardian->getCantSemillas();
		CtSemillas->Text = L"" + cantSemillas;

		if (teclaW)
		{
			guardian->setDireccionActual(Direccion::Arriba);
		} 
		else if (teclaA)
		{
			guardian->setDireccionActual(Direccion::Izquierda);
		}
		else if (teclaS)
		{
			guardian->setDireccionActual(Direccion::Abajo);
		}
		else if (teclaD)
		{
			guardian->setDireccionActual(Direccion::Derecha);
		}
		else
		{
			guardian->setDireccionActual(Direccion::Ninguna);
		}

		if (teclaM)
		{
			// plantar arbol 
			if (guardian->getCantSemillas() > 0 && guardian->getCantAgua() > 0)
			{
				objGJuego->AgregarArbol(
					guardian->getX(),
					guardian->getY(),
					bmpArbol->Width,
					bmpArbol->Height
				);

				guardian->setCantAgua(guardian->getCantAgua() - 1);
				guardian->setCantSemillas(guardian->getCantSemillas() - 1);
			}

			teclaM = false;
		}
		if (teclaP) /// DISPARO
		{
			// disparar semillas
			if (guardian->getCantSemillas() > 0)
			{
				objGJuego->DispararSemilla(
					guardian->getX(),
					guardian->getY(),
					guardian
				);
				guardian->setCantSemillas(guardian->getCantSemillas() - 1);
			}

			teclaP = false;
		}

		guardian->Mover(buffer->Graphics);

		buffer->Graphics->DrawImage(bmpEscenario1, 0, 0, bmpEscenario1->Width, bmpEscenario1->Height);
		objGJuego->DibujarTodo(
			buffer->Graphics, 
			bmpEnemigo, 
			bmpAgua,
			bmpSemilla,
			bmpBasura,
			bmpArbol
		);
		guardian->Dibujar(buffer->Graphics, bmpGuardian);

		buffer->Render(g);
	}

	private: System::Void timerEnemigos_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		objGJuego->AgregarEnemigo(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4);
	}

	private: System::Void timerAgua_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		objGJuego->AgregarAgua(bmpAgua->Width, bmpAgua->Height);
	}

	private: System::Void timerSemillas_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		objGJuego->AgregarSemilla(bmpSemilla->Width / 4, bmpSemilla->Height / 4);
	}

	private: System::Void timerBasura_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		objGJuego->AgregarBasura(bmpBasura->Width, bmpBasura->Height);
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: teclaW = true; break;
		case Keys::A: teclaA = true; break;
		case Keys::S: teclaS = true; break;
		case Keys::D: teclaD = true; break;
		case Keys::M: teclaM = true; break;
		case Keys::P: teclaP = true; break;
		case Keys::Escape: this->Close(); break;
		}
	}

	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: teclaW = false; break;
		case Keys::A: teclaA = false; break;
		case Keys::S: teclaS = false; break;
		case Keys::D: teclaD = false; break;
		case Keys::M: teclaM = false; break;
		case Keys::P: teclaP = false; break;
		}
	}
};
}