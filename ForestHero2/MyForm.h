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

			Random^ r = gcnew Random();

			objGuardian = new Guardian();
			objGuardian->setX(r->Next(this->Size.Width) - 100);
			objGuardian->setY(r->Next(this->Size.Height) - 100);
			objGuardian->setVelocidad(10);
			objGuardian->setImagen("Resources/Images/personajeTemp.png");

			teclaPulsada = Direccion::Ninguna;
			escenario = gcnew Bitmap(gcnew System::String("Resources/Images/escenarioTemp.jpg"));
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
		Guardian* objGuardian;
		Direccion teclaPulsada;
		Bitmap^ escenario;

	private: System::Windows::Forms::Timer^ timer1; 

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1366, 768);
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

		// Creamos el canvas del formulario
		Graphics^ canvas = this->CreateGraphics();

		// Reservamos un espacio para poner el Buffer
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;

		// Creamos un canvas dentro del espacio del buffer utilizando el canvas
		// del formulario
		BufferedGraphics^ buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);

		//A partir de aqui dibujamos en el canvas del buffer
		buffer->Graphics->DrawImage(escenario, 0, 0, System::Drawing::Rectangle(0, 0, 1000, 500), GraphicsUnit::Pixel);

		objGuardian->Mover(buffer->Graphics, teclaPulsada);

		//Dibuja todo en el canvas del formulario
		buffer->Render(canvas);

		//liberamos los punteros
		delete buffer;
		delete espacioBuffer;
		delete canvas;
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		teclaPulsada = Direccion::Ninguna;
		if (e->KeyCode == Keys::W) teclaPulsada = Direccion::Arriba;
		if (e->KeyCode == Keys::S) teclaPulsada = Direccion::Abajo;
		if (e->KeyCode == Keys::A) teclaPulsada = Direccion::Derecha;
		if (e->KeyCode == Keys::D) teclaPulsada = Direccion::Izquierda;

		objGuardian->setVelocidad(10);
		objGuardian->setDireccion(teclaPulsada);
	}

	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		teclaPulsada = Direccion::Ninguna;
		objGuardian->setVelocidad(0);
	}
};
}
