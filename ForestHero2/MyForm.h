#pragma once
#include "FuncionesCustom.h"
#include "GestionJuego.h"
#include "Guardian.h"
#include "File.h"
#include "Derrota.h"
#include "MyForm3.h"
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
			bmpEnemigo = gcnew Bitmap("Resources/Images/enemigo.png");
			bmpAliado = gcnew Bitmap("Resources/Images/aliadoTemp.png");
			bmpAgua = gcnew Bitmap("Resources/Images/aguaTemp.png");
			bmpSemilla = gcnew Bitmap("Resources/Images/semilla.png");
			bmpBasura = gcnew Bitmap("Resources/Images/basura.png");
			bmpArbol = gcnew Bitmap("Resources/Images/arbol.png");
			bmpPowerUp = gcnew Bitmap("Resources/Images/corazon.png");
			//aliado = new Aliado(50,500, 20, bmpAliado->Width / 4, bmpAliado->Height / 4);
			guardian = new Guardian(200, 200, bmpGuardian->Width / 4, bmpGuardian->Height / 4);
						
			objGJuego = new GestionJuego();
			file = new File();
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
		Bitmap^ bmpPowerUp;

		Guardian* guardian;
		GestionJuego* objGJuego;
		Aliado* aliado;

		File* file;
		
		/// <summary>
		///  sos
		/// </summary>
		int cantSemillas;
		int cantAguas;
		int cantVidas;
		int cantPuntos;
		int cantReforestacion;
		int milisegundos = 0;
		int segundos = 360;
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
	private: System::Windows::Forms::Label^ CtAgua;
	private: System::Windows::Forms::Label^ CtVidas;

	private: System::Windows::Forms::Label^ CtPuntos;
	private: System::Windows::Forms::Label^ labelPuntos;
	private: System::Windows::Forms::Label^ labelTiempoRestante;
	private: System::Windows::Forms::Label^ segundosRestantes;
	private: System::Windows::Forms::Timer^ timerAliado;
	private: System::Windows::Forms::Label^ CtPorcentaje;

	private: System::Windows::Forms::Label^ CtReforestacion;


	private: System::Windows::Forms::Timer^ timerBasura;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelCanvas = (gcnew System::Windows::Forms::Panel());
			this->CtPorcentaje = (gcnew System::Windows::Forms::Label());
			this->CtReforestacion = (gcnew System::Windows::Forms::Label());
			this->segundosRestantes = (gcnew System::Windows::Forms::Label());
			this->labelTiempoRestante = (gcnew System::Windows::Forms::Label());
			this->labelPuntos = (gcnew System::Windows::Forms::Label());
			this->CtPuntos = (gcnew System::Windows::Forms::Label());
			this->CtVidas = (gcnew System::Windows::Forms::Label());
			this->CtAgua = (gcnew System::Windows::Forms::Label());
			this->CtSemillas = (gcnew System::Windows::Forms::Label());
			this->timerEnemigos = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAgua = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerSemillas = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerBasura = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAliado = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->panelCanvas->BackColor = System::Drawing::Color::Transparent;
			this->panelCanvas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelCanvas.BackgroundImage")));
			this->panelCanvas->Controls->Add(this->CtPorcentaje);
			this->panelCanvas->Controls->Add(this->CtReforestacion);
			this->panelCanvas->Controls->Add(this->segundosRestantes);
			this->panelCanvas->Controls->Add(this->labelTiempoRestante);
			this->panelCanvas->Controls->Add(this->labelPuntos);
			this->panelCanvas->Controls->Add(this->CtPuntos);
			this->panelCanvas->Controls->Add(this->CtVidas);
			this->panelCanvas->Controls->Add(this->CtAgua);
			this->panelCanvas->Controls->Add(this->CtSemillas);
			this->panelCanvas->Location = System::Drawing::Point(0, 0);
			this->panelCanvas->Name = L"panelCanvas";
			this->panelCanvas->Size = System::Drawing::Size(1366, 768);
			this->panelCanvas->TabIndex = 0;
			// 
			// CtPorcentaje
			// 
			this->CtPorcentaje->AutoSize = true;
			this->CtPorcentaje->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->CtPorcentaje->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CtPorcentaje->Location = System::Drawing::Point(1067, 332);
			this->CtPorcentaje->Name = L"CtPorcentaje";
			this->CtPorcentaje->Size = System::Drawing::Size(35, 37);
			this->CtPorcentaje->TabIndex = 8;
			this->CtPorcentaje->Text = L"0";
			// 
			// CtReforestacion
			// 
			this->CtReforestacion->AutoSize = true;
			this->CtReforestacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->CtReforestacion->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CtReforestacion->Location = System::Drawing::Point(1059, 303);
			this->CtReforestacion->Name = L"CtReforestacion";
			this->CtReforestacion->Size = System::Drawing::Size(244, 37);
			this->CtReforestacion->TabIndex = 7;
			this->CtReforestacion->Text = L"Reforestacion:";
			// 
			// segundosRestantes
			// 
			this->segundosRestantes->AutoSize = true;
			this->segundosRestantes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->segundosRestantes->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->segundosRestantes->Location = System::Drawing::Point(1066, 272);
			this->segundosRestantes->Name = L"segundosRestantes";
			this->segundosRestantes->Size = System::Drawing::Size(35, 37);
			this->segundosRestantes->TabIndex = 6;
			this->segundosRestantes->Text = L"0";
			// 
			// labelTiempoRestante
			// 
			this->labelTiempoRestante->AutoSize = true;
			this->labelTiempoRestante->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->labelTiempoRestante->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTiempoRestante->Location = System::Drawing::Point(1059, 242);
			this->labelTiempoRestante->Name = L"labelTiempoRestante";
			this->labelTiempoRestante->Size = System::Drawing::Size(275, 37);
			this->labelTiempoRestante->TabIndex = 5;
			this->labelTiempoRestante->Text = L"Tiempo restante:";
			// 
			// labelPuntos
			// 
			this->labelPuntos->AutoSize = true;
			this->labelPuntos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->labelPuntos->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPuntos->Location = System::Drawing::Point(1214, 191);
			this->labelPuntos->Name = L"labelPuntos";
			this->labelPuntos->Size = System::Drawing::Size(124, 37);
			this->labelPuntos->TabIndex = 4;
			this->labelPuntos->Text = L"Puntos";
			// 
			// CtPuntos
			// 
			this->CtPuntos->AutoSize = true;
			this->CtPuntos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->CtPuntos->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CtPuntos->Location = System::Drawing::Point(1056, 151);
			this->CtPuntos->Name = L"CtPuntos";
			this->CtPuntos->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->CtPuntos->Size = System::Drawing::Size(54, 60);
			this->CtPuntos->TabIndex = 3;
			this->CtPuntos->Text = L"0";
			this->CtPuntos->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// CtVidas
			// 
			this->CtVidas->AutoSize = true;
			this->CtVidas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->CtVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CtVidas->Location = System::Drawing::Point(728, 33);
			this->CtVidas->Name = L"CtVidas";
			this->CtVidas->Size = System::Drawing::Size(86, 31);
			this->CtVidas->TabIndex = 2;
			this->CtVidas->Text = L"label1";
			// 
			// CtAgua
			// 
			this->CtAgua->AutoSize = true;
			this->CtAgua->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->CtAgua->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CtAgua->Location = System::Drawing::Point(471, 34);
			this->CtAgua->Name = L"CtAgua";
			this->CtAgua->Size = System::Drawing::Size(86, 31);
			this->CtAgua->TabIndex = 1;
			this->CtAgua->Text = L"label1";
			// 
			// CtSemillas
			// 
			this->CtSemillas->AutoSize = true;
			this->CtSemillas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->CtSemillas->CausesValidation = false;
			this->CtSemillas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CtSemillas->Location = System::Drawing::Point(225, 34);
			this->CtSemillas->Name = L"CtSemillas";
			this->CtSemillas->Size = System::Drawing::Size(86, 31);
			this->CtSemillas->TabIndex = 0;
			this->CtSemillas->Text = L"label1";
			// 
			// timerEnemigos
			// 
			this->timerEnemigos->Enabled = true;
			this->timerEnemigos->Interval = 15000;
			this->timerEnemigos->Tick += gcnew System::EventHandler(this, &MyForm::timerEnemigos_Tick);
			// 
			// timerAgua
			// 
			this->timerAgua->Enabled = true;
			this->timerAgua->Interval = 5000;
			this->timerAgua->Tick += gcnew System::EventHandler(this, &MyForm::timerAgua_Tick);
			// 
			// timerSemillas
			// 
			this->timerSemillas->Enabled = true;
			this->timerSemillas->Interval = 3000;
			this->timerSemillas->Tick += gcnew System::EventHandler(this, &MyForm::timerSemillas_Tick);
			// 
			// timerBasura
			// 
			this->timerBasura->Enabled = true;
			this->timerBasura->Interval = 8000;
			this->timerBasura->Tick += gcnew System::EventHandler(this, &MyForm::timerBasura_Tick);
			// 
			// timerAliado
			// 
			this->timerAliado->Enabled = true;
			this->timerAliado->Interval = 15000;
			this->timerAliado->Tick += gcnew System::EventHandler(this, &MyForm::timerAliado_Tick);
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
		buffer->Graphics->Clear(Color::Transparent);
		
		//! Reproducimos musica para la parte final del juego
		if (objGJuego->PorcentajeReforestacion() > 50)
		{

		}
		
		objGJuego->ColisionPersonaje(guardian);

		objGJuego->MoverTodo(buffer->Graphics);
		cantPuntos = guardian->getPuntos();
		cantVidas = guardian->getCantVidas();
		cantAguas = guardian->getCantAgua();
		cantSemillas = guardian->getCantSemillas();
		cantReforestacion = objGJuego->PorcentajeReforestacion();
		CtSemillas->Text = L"" + cantSemillas;
		CtAgua->Text = L"" + cantAguas;
		CtVidas->Text = L"" + cantVidas;
		CtPuntos->Text = L"" + cantPuntos;
		CtPorcentaje->Text = L"" + cantReforestacion + L"%";
		milisegundos++;
		if (milisegundos == 10)
		{
			milisegundos = 0;
			segundos--;
		}

		segundosRestantes->Text = L"" + segundos + L"s";

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
				objGJuego->PlantarArbol(
					guardian,
					bmpArbol->Width,
					bmpArbol->Height
				);
			}

			teclaM = false;
		}
		if (teclaP) /// DISPARO
		{
			// disparar semillas
			if (guardian->getCantSemillas() > 0)
			{
				objGJuego->DispararSemilla(
					bmpSemilla->Width,
					bmpSemilla->Height,
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
			bmpArbol,
			bmpAliado,
			bmpPowerUp
		);
		guardian->Dibujar(buffer->Graphics, bmpGuardian);
		
		buffer->Render(g);

		/// analoizamos si termino la partida
		if (segundos <= 0 || objGJuego->AnalizarGAMEOVER(guardian) == true)
		{
			DetenerTimers();
			/// Analisamos si el jugarod ha ganado
			//if (true)
			if (objGJuego->DeterminarVictoria(guardian) == true)
			{
				//! VICTORIA DEL JUGADOR
				MyForm3^ win = gcnew MyForm3();
				this->Hide(); /// cierra el forms

				win->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::OnGameFormClosed);
				win->Show();
			}
			else
			{
				//! DERROTA DEL JUGADOR
				Derrota^ gameOver = gcnew Derrota();
				this->Hide(); /// cierra el forms

				gameOver->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::OnGameFormClosed);
				gameOver->ShowDialog();

				if (gameOver->reiniciar) 
				{
					ReiniciarJuego(); 
				}
				else {
					this->Close(); 
				}
			}
		}
	}

	void OnGameFormClosed(Object^ sender, FormClosedEventArgs^ e) 
	{
		this->Show();
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
		// no se necesita dividir el tamano de la semilla
		objGJuego->AgregarSemilla(bmpSemilla->Width, bmpSemilla->Height);
	}

	private: System::Void timerBasura_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		objGJuego->AgregarBasura(bmpBasura->Width, bmpBasura->Height);
	}

	private: System::Void timerAliado_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (guardian->getCantVidas() <= 3 && objGJuego->AliadoActivo() == false) 
			objGJuego->InvocarAliado();
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
		case Keys::U: DetenerTimers(); break;
		case Keys::Y: ReactivarTimers(); break;
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

	private: void DetenerTimers() 
	{
		timerJuego->Enabled = false;
		timerEnemigos->Enabled = false;
		timerAgua->Enabled = false;
		timerSemillas->Enabled = false;
		timerBasura->Enabled = false;
		timerAliado->Enabled = false;
	}

	private: void ReactivarTimers() 
	{
		timerJuego->Enabled = true;
		timerEnemigos->Enabled = true;
		timerAgua->Enabled = true;
		timerSemillas->Enabled = true;
		timerBasura->Enabled = true;
		timerAliado->Enabled = true;
	}

	private: void ReiniciarJuego() 
	{
		// Reiniciar temporizadores
		timerJuego->Stop();
		timerEnemigos->Stop();
		timerAgua->Stop();
		timerSemillas->Stop();
		timerBasura->Stop();
		timerAliado->Stop();

		// reiniciamos el tiempo
		milisegundos = 0;
		segundos = 360;

		guardian->ReiniciarEstado();
		objGJuego->ReiniciarEstado();
		objGJuego->IniciarElementos(
			bmpEnemigo->Width / 4, bmpEnemigo->Height / 4,
			bmpAgua->Width, bmpAgua->Height,
			bmpSemilla->Width, bmpSemilla->Height
		);

		// reiniciamos el estado de las teclas presionadas
		teclaW = false;
		teclaA = false;
		teclaS = false;
		teclaD = false;
		teclaM = false;
		teclaP = false;

		// Reiniciar y habilitar temporizadores
		timerJuego->Start();
		timerEnemigos->Start();
		timerAgua->Start();
		timerSemillas->Start();
		timerBasura->Start();
		timerAliado->Start();
	}
};
}