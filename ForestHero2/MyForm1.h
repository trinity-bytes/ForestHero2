#pragma once
#include "File.h"
#include "Guardian.h"
#include <string>
#include <vector>
#include <fstream>
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

using System::String;

public ref class jugadorPuntaje
{
public:
	System::String^ nombre;
	System::String^ puntaje;

	static int CompararPuntajes(jugadorPuntaje^ j1, jugadorPuntaje^ j2)
	{
		int puntaje1 = Int32::Parse(j1->puntaje);
		int puntaje2 = Int32::Parse(j2->puntaje);
		return puntaje2.CompareTo(puntaje1);
	}
};

namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			bmpRanking = gcnew Bitmap("Resources/Images/menuRanking.png");
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			file = new File();
			guardian = new Guardian(200, 200, 64, 64);
			jugadores = gcnew List<jugadorPuntaje^>();
			listaLabels = gcnew List<System::Windows::Forms::Label^>();

			// Configurar el panel
			panel1->BackColor = System::Drawing::Color::Transparent;
			panel1->BringToFront();

			// Cargar datos iniciales
			CargarDatos();
			CrearLabels();
		}
		// Método estático de comparación para ordenar por puntaje descendente
		
		
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ bmpRanking;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		File* file;
		Guardian* guardian;
		System::String^ nombre;
		int puntos;
		bool labelsCreados = false;
		List<jugadorPuntaje^>^ jugadores;

		void CargarDatos() {
			jugadores->Clear();
			std::ifstream leerRanked;
			leerRanked.open("Resources/Data/JugadorPuntaje.dat");

			if (!leerRanked.is_open()) {
				MessageBox::Show("Error al abrir el archivo de ranking", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			std::string linea;
			while (std::getline(leerRanked, linea)) {
				if (linea.empty()) continue;

				jugadorPuntaje^ nuevoJugador = gcnew jugadorPuntaje();
				nuevoJugador->nombre = gcnew String(linea.c_str());

				if (std::getline(leerRanked, linea)) {
					nuevoJugador->puntaje = gcnew String(linea.c_str());
					jugadores->Add(nuevoJugador);
				}
			}

			leerRanked.close();
			jugadores->Sort(gcnew Comparison<jugadorPuntaje^>(&jugadorPuntaje::CompararPuntajes));
		}

		void CrearLabels() {
			// Limpiar labels existentes
			for each (Label ^ label in listaLabels) {
				if (label != nullptr) {
					panel1->Controls->Remove(label);
					delete label;
				}
			}
			listaLabels->Clear();

			// Crear nuevos labels
			for (int i = 0; i < jugadores->Count; i++) {
				Label^ nuevoLabel = gcnew Label();

				// Configurar propiedades del label
				nuevoLabel->AutoSize = true;
				nuevoLabel->BackColor = System::Drawing::Color::Transparent;
				nuevoLabel->ForeColor = System::Drawing::Color::White;
				nuevoLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
				nuevoLabel->Location = System::Drawing::Point(400, 200 + (i * 50));
				nuevoLabel->Text = String::Format("{0}. {1} - {2}",
					i + 1,
					jugadores[i]->nombre,
					jugadores[i]->puntaje);

				// Asegurar que el label sea visible
				nuevoLabel->Visible = true;
				nuevoLabel->BringToFront();

				// Agregar el label al panel y a la lista
				panel1->Controls->Add(nuevoLabel);
				listaLabels->Add(nuevoLabel);
			}

			// Forzar el redibujado del panel
			panel1->Refresh();
		}


	private: System::Windows::Forms::Panel^ panel1;
		   
	private: System::Collections::Generic::List<System::Windows::Forms::Label^>^ listaLabels;
		  
	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1821, 945);
			this->panel1->TabIndex = 0;
			// 
			// MyForm1
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ranking";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->DrawImage(bmpRanking, 0, 0, bmpRanking->Width, bmpRanking->Height);
		buffer->Render(g);

		// Actualizar datos y labels
		CargarDatos();

		// Actualizar texto de labels existentes
		for (int i = 0; i < jugadores->Count && i < listaLabels->Count; i++) {
			if (listaLabels[i] != nullptr) {
				listaLabels[i]->Text = String::Format("{0}. {1} - {2}",
					i + 1,
					jugadores[i]->nombre,
					jugadores[i]->puntaje);
				listaLabels[i]->BringToFront();
			}
		}
	}

	};
}
