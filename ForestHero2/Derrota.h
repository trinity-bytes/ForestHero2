#pragma once
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
			this->botonJugar = (gcnew System::Windows::Forms::Button());
			this->botonMenu = (gcnew System::Windows::Forms::Button());
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
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1366, 728);
			this->panel1->TabIndex = 0;
			// 
			// botonJugar
			// 
			this->botonJugar->FlatAppearance->BorderSize = 0;
			this->botonJugar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonJugar->Location = System::Drawing::Point(86, 527);
			this->botonJugar->Name = L"botonJugar";
			this->botonJugar->Size = System::Drawing::Size(335, 135);
			this->botonJugar->TabIndex = 0;
			this->botonJugar->UseVisualStyleBackColor = true;
			this->botonJugar->Click += gcnew System::EventHandler(this, &Derrota::botonJugar_Click);
			// 
			// botonMenu
			// 
			this->botonMenu->FlatAppearance->BorderSize = 0;
			this->botonMenu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonMenu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonMenu->Location = System::Drawing::Point(944, 527);
			this->botonMenu->Name = L"botonMenu";
			this->botonMenu->Size = System::Drawing::Size(335, 135);
			this->botonMenu->TabIndex = 1;
			this->botonMenu->UseVisualStyleBackColor = true;
			// 
			// Derrota
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1366, 728);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Derrota";
			this->Text = L"Derrota";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void botonJugar_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
