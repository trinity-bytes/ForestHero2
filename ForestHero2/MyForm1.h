#pragma once

#include <string>
#include <vector>
#include <fstream>
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

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
			//
			//TODO: agregar código de constructor aquí
			//
			jugadores = gcnew List<jugadorPuntaje^>();
			listaLabels = gcnew List<System::Windows::Forms::Label^>();

			// Configurar el panel
			panel1->BackColor = System::Drawing::Color::Transparent;

			// Cargar y mostrar los datos
			CargarDatos();
			CrearLabels();
		}

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
	private:
		ref class jugadorPuntaje
		{
		public:
			System::String^ nombre;
			System::String^ puntaje;

			// Método para comparar puntajes
			static int CompararPuntajes(jugadorPuntaje^ j1, jugadorPuntaje^ j2)
			{
				int puntaje1 = Int32::Parse(j1->puntaje);
				int puntaje2 = Int32::Parse(j2->puntaje);
				return puntaje2.CompareTo(puntaje1); // Orden descendente
			}
		};

	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

		List<jugadorPuntaje^>^ jugadores; // Lista de jugadores
		List<System::Windows::Forms::Label^>^ listaLabels; // Lista de Labels

		void CargarDatos() {
			jugadores->Clear();
			std::ifstream leerRanked("Resources/Data/JugadorPuntaje.dat");

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
				panel1->Controls->Remove(label);
				delete label;
			}
			listaLabels->Clear();

			// Verificar que hay jugadores cargados
			if (jugadores->Count == 0) {
				MessageBox::Show("No se encontraron jugadores para mostrar.", "Información",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			// Crear nuevos labels
			for (int i = 0; i < jugadores->Count; i++) {
				Label^ nuevoLabel = gcnew Label();
				nuevoLabel->AutoSize = true;
				nuevoLabel->BackColor = System::Drawing::Color::Transparent;
				nuevoLabel->ForeColor = System::Drawing::Color::White;
				nuevoLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);

				// Ajustar la posición (50 de margen izquierdo, espacio entre líneas de 40)
				nuevoLabel->Location = System::Drawing::Point(50, 50 + (i * 40));

				// Configurar el texto del label
				nuevoLabel->Text = String::Format("{0}. {1} - {2}",
					i + 1,
					jugadores[i]->nombre,
					jugadores[i]->puntaje);

				// Agregar al panel y a la lista
				panel1->Controls->Add(nuevoLabel);
				listaLabels->Add(nuevoLabel);
			}

			MessageBox::Show("Labels creados: " + listaLabels->Count, "Debug");
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1366, 768);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(38, 614);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 120);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm1::button1_MouseEnter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm1::button1_MouseLeave);
			// 
			// MyForm1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		button1->BackgroundImage = Image::FromFile("Resources/Buttons/menuSeleccionModo-assets/back blanco.png");
	}
	private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		button1->BackgroundImage = Image::FromFile("Resources/Buttons/menuSeleccionModo-assets/back copy.png");
	}
	};
}
