#pragma once
#include "MyForm.h"
#include "MenuJuego.h"
#include "Guardian.h"
#include "MyForm1.h"
#include <string>
#include <msclr/marshal_cppstd.h>
using System::String;
namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public: bool reiniciar = false;
	public: System::String^ nombre;
	public:	 int puntaje;
	public:
		MyForm3(void)
		{
			InitializeComponent();
			guardian = new Guardian(200, 200, 64, 64);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ botonMenu;
	private: System::Windows::Forms::Button^ botonJugar;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Guardian* guardian;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm3::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->botonMenu = (gcnew System::Windows::Forms::Button());
			this->botonJugar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->botonMenu);
			this->panel1->Controls->Add(this->botonJugar);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1366, 768);
			this->panel1->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Pixelify Sans", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(543, 276);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(483, 40);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm3::textBox1_KeyDown);
			// 
			// botonMenu
			// 
			this->botonMenu->BackColor = System::Drawing::Color::Transparent;
			this->botonMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonMenu.BackgroundImage")));
			this->botonMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonMenu->FlatAppearance->BorderSize = 0;
			this->botonMenu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonMenu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonMenu->Location = System::Drawing::Point(939, 511);
			this->botonMenu->Name = L"botonMenu";
			this->botonMenu->Size = System::Drawing::Size(340, 135);
			this->botonMenu->TabIndex = 1;
			this->botonMenu->UseVisualStyleBackColor = false;
			this->botonMenu->Click += gcnew System::EventHandler(this, &MyForm3::botonMenu_Click);
			this->botonMenu->MouseEnter += gcnew System::EventHandler(this, &MyForm3::botonMenu_MouseEnter);
			this->botonMenu->MouseLeave += gcnew System::EventHandler(this, &MyForm3::botonMenu_MouseLeave);
			// 
			// botonJugar
			// 
			this->botonJugar->BackColor = System::Drawing::Color::Transparent;
			this->botonJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonJugar.BackgroundImage")));
			this->botonJugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonJugar->FlatAppearance->BorderSize = 0;
			this->botonJugar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonJugar->Location = System::Drawing::Point(83, 511);
			this->botonJugar->Name = L"botonJugar";
			this->botonJugar->Size = System::Drawing::Size(341, 135);
			this->botonJugar->TabIndex = 0;
			this->botonJugar->UseVisualStyleBackColor = false;
			this->botonJugar->Click += gcnew System::EventHandler(this, &MyForm3::botonJugar_Click);
			this->botonJugar->MouseEnter += gcnew System::EventHandler(this, &MyForm3::botonJugar_MouseEnter);
			this->botonJugar->MouseLeave += gcnew System::EventHandler(this, &MyForm3::botonJugar_MouseLeave);
			// 
			// MyForm3
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm3";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm3";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
	private: System::Void botonMenu_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		botonMenu->BackgroundImage = Image::FromFile("Resources/Buttons/menuVictoria-assets/menu principal blanco.png");
	}
	private: System::Void botonMenu_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		botonMenu->BackgroundImage = Image::FromFile("Resources/Buttons/menuVictoria-assets/menu principal copy.png");
	}
private: System::Void botonMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	reiniciar = false;
	this->Close();
}
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
private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode)
	{
	case Keys::Enter:
		textBox1->ReadOnly = true;
		nombre = textBox1->Text;
		puntaje = guardian->getPuntos();
		ofstream fileWrite;
		ifstream fileRead;
		std::string nombre_std = msclr::interop::marshal_as<std::string>(textBox1->Text);
		fileRead.open("JugadorPuntaje.txt", ios::in);

		if (fileRead.fail())
		{
			fileRead.close();

			fileWrite.open("JugadorPuntaje.txt", ios::out);
			fileWrite << nombre_std << endl;
			fileWrite << puntaje << endl;
			fileWrite.close();

			fileRead.open("JugadorPuntaje.txt", ios::in);
		}

		break;
	}
}
};
}
