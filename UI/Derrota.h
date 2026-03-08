#pragma once
#include "MyForm.h"
#include "MenuJuego.h"
namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de Derrota
	/// </summary>
	public ref class Derrota : public System::Windows::Forms::Form
	{
	public: bool reiniciar = false;
	public:
		Derrota(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Derrota()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ botonMenu;
	private: System::Windows::Forms::Button^ botonJugar;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Derrota::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->botonMenu = (gcnew System::Windows::Forms::Button());
			this->botonJugar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->botonMenu);
			this->panel1->Controls->Add(this->botonJugar);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1821, 896);
			this->panel1->TabIndex = 0;
			// 
			// botonMenu
			// 
			this->botonMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonMenu.BackgroundImage")));
			this->botonMenu->FlatAppearance->BorderSize = 0;
			this->botonMenu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonMenu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonMenu->Location = System::Drawing::Point(938, 527);
			this->botonMenu->Name = L"botonMenu";
			this->botonMenu->Size = System::Drawing::Size(345, 146);
			this->botonMenu->TabIndex = 1;
			this->botonMenu->UseVisualStyleBackColor = true;
			this->botonMenu->Click += gcnew System::EventHandler(this, &Derrota::botonMenu_Click);
			this->botonMenu->MouseEnter += gcnew System::EventHandler(this, &Derrota::botonMenu_MouseEnter);
			this->botonMenu->MouseLeave += gcnew System::EventHandler(this, &Derrota::botonMenu_MouseLeave);
			// 
			// botonJugar
			// 
			this->botonJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonJugar.BackgroundImage")));
			this->botonJugar->FlatAppearance->BorderSize = 0;
			this->botonJugar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonJugar->Location = System::Drawing::Point(82, 527);
			this->botonJugar->Name = L"botonJugar";
			this->botonJugar->Size = System::Drawing::Size(338, 135);
			this->botonJugar->TabIndex = 0;
			this->botonJugar->UseVisualStyleBackColor = true;
			this->botonJugar->Click += gcnew System::EventHandler(this, &Derrota::botonJugar_Click);
			this->botonJugar->MouseEnter += gcnew System::EventHandler(this, &Derrota::botonJugar_MouseEnter);
			this->botonJugar->MouseLeave += gcnew System::EventHandler(this, &Derrota::botonJugar_MouseLeave);
			// 
			// Derrota
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Derrota";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Derrota";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void botonJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		reiniciar = true;
		this->Close();
	}
	private: System::Void botonJugar_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		botonJugar->BackgroundImage = Image::FromFile("Resources/Buttons/menuVictoria-assets/jugar de nuevo blanco.png");
	}
	private: System::Void botonJugar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		botonJugar->BackgroundImage = Image::FromFile("Resources/Buttons/menuVictoria-assets/jugar de nuevo copy.png");
	}
	private: System::Void botonMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		reiniciar = false;
		this->Close();
	}
	private: System::Void botonMenu_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		botonMenu->BackgroundImage = Image::FromFile("Resources/Buttons/menuVictoria-assets/menu principal blanco.png");
	}
	private: System::Void botonMenu_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		botonMenu->BackgroundImage = Image::FromFile("Resources/Buttons/menuVictoria-assets/menu principal copy.png");
	}
};
}
