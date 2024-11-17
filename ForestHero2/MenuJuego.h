#pragma once
#include "MyForm.h"
namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuJuego
	/// </summary>
	public ref class MenuJuego : public System::Windows::Forms::Form
	{
	public:
		MenuJuego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			botonJugarNormal = Image::FromFile("Resources/Buttons/menuPrincipal-assets/jugarcopy.png");
			botonJugarHover = Image::FromFile("Resources/Buttons/menuPrincipal-assets/jugarblanco.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ botonJugar;
	private: System::Windows::Forms::Button^ botonRanking;
	private: System::Windows::Forms::Button^ botonClose;


	protected:

	private:
	
	Image^ botonJugarNormal;
	Image^ botonJugarHover;

	private: System::Windows::Forms::Button^ botonCreditos;
	private: System::Windows::Forms::Button^ botonInstruciones;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuJuego::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->botonCreditos = (gcnew System::Windows::Forms::Button());
			this->botonInstruciones = (gcnew System::Windows::Forms::Button());
			this->botonClose = (gcnew System::Windows::Forms::Button());
			this->botonRanking = (gcnew System::Windows::Forms::Button());
			this->botonJugar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->botonCreditos);
			this->panel1->Controls->Add(this->botonInstruciones);
			this->panel1->Controls->Add(this->botonClose);
			this->panel1->Controls->Add(this->botonRanking);
			this->panel1->Controls->Add(this->botonJugar);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1366, 768);
			this->panel1->TabIndex = 0;
			// 
			// botonCreditos
			// 
			this->botonCreditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonCreditos.BackgroundImage")));
			this->botonCreditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonCreditos->FlatAppearance->BorderSize = 0;
			this->botonCreditos->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonCreditos->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonCreditos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonCreditos->Location = System::Drawing::Point(1099, 619);
			this->botonCreditos->Name = L"botonCreditos";
			this->botonCreditos->Size = System::Drawing::Size(97, 95);
			this->botonCreditos->TabIndex = 4;
			this->botonCreditos->UseVisualStyleBackColor = true;
			this->botonCreditos->Click += gcnew System::EventHandler(this, &MenuJuego::botonCreditos_Click);
			this->botonCreditos->MouseEnter += gcnew System::EventHandler(this, &MenuJuego::botonCreditos_MouseEnter);
			this->botonCreditos->MouseLeave += gcnew System::EventHandler(this, &MenuJuego::botonCreditos_MouseLeave);
			// 
			// botonInstruciones
			// 
			this->botonInstruciones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonInstruciones.BackgroundImage")));
			this->botonInstruciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonInstruciones->FlatAppearance->BorderSize = 0;
			this->botonInstruciones->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonInstruciones->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonInstruciones->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonInstruciones->Location = System::Drawing::Point(1220, 620);
			this->botonInstruciones->Name = L"botonInstruciones";
			this->botonInstruciones->Size = System::Drawing::Size(96, 98);
			this->botonInstruciones->TabIndex = 3;
			this->botonInstruciones->UseVisualStyleBackColor = true;
			this->botonInstruciones->Click += gcnew System::EventHandler(this, &MenuJuego::botonInstruciones_Click);
			this->botonInstruciones->MouseEnter += gcnew System::EventHandler(this, &MenuJuego::botonInstruciones_MouseEnter);
			this->botonInstruciones->MouseLeave += gcnew System::EventHandler(this, &MenuJuego::botonInstruciones_MouseLeave);
			// 
			// botonClose
			// 
			this->botonClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonClose.BackgroundImage")));
			this->botonClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonClose->FlatAppearance->BorderSize = 0;
			this->botonClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonClose->Location = System::Drawing::Point(1256, 22);
			this->botonClose->Margin = System::Windows::Forms::Padding(4);
			this->botonClose->Name = L"botonClose";
			this->botonClose->Size = System::Drawing::Size(97, 96);
			this->botonClose->TabIndex = 2;
			this->botonClose->UseVisualStyleBackColor = false;
			this->botonClose->Click += gcnew System::EventHandler(this, &MenuJuego::botonClose_Click);
			this->botonClose->MouseEnter += gcnew System::EventHandler(this, &MenuJuego::botonClose_MouseEnter);
			this->botonClose->MouseLeave += gcnew System::EventHandler(this, &MenuJuego::botonClose_MouseLeave);
			// 
			// botonRanking
			// 
			this->botonRanking->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonRanking.BackgroundImage")));
			this->botonRanking->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonRanking->FlatAppearance->BorderSize = 0;
			this->botonRanking->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonRanking->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonRanking->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonRanking->Location = System::Drawing::Point(59, 621);
			this->botonRanking->Margin = System::Windows::Forms::Padding(4);
			this->botonRanking->Name = L"botonRanking";
			this->botonRanking->Size = System::Drawing::Size(235, 110);
			this->botonRanking->TabIndex = 1;
			this->botonRanking->UseVisualStyleBackColor = false;
			this->botonRanking->Click += gcnew System::EventHandler(this, &MenuJuego::botonRanking_Click);
			this->botonRanking->MouseEnter += gcnew System::EventHandler(this, &MenuJuego::botonRanking_MouseEnter);
			this->botonRanking->MouseLeave += gcnew System::EventHandler(this, &MenuJuego::botonRanking_MouseLeave);
			// 
			// botonJugar
			// 
			this->botonJugar->BackColor = System::Drawing::Color::Transparent;
			this->botonJugar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonJugar.BackgroundImage")));
			this->botonJugar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonJugar->Cursor = System::Windows::Forms::Cursors::Default;
			this->botonJugar->FlatAppearance->BorderSize = 0;
			this->botonJugar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonJugar->Location = System::Drawing::Point(511, 317);
			this->botonJugar->Margin = System::Windows::Forms::Padding(4);
			this->botonJugar->Name = L"botonJugar";
			this->botonJugar->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->botonJugar->Size = System::Drawing::Size(342, 137);
			this->botonJugar->TabIndex = 0;
			this->botonJugar->UseVisualStyleBackColor = false;
			this->botonJugar->Click += gcnew System::EventHandler(this, &MenuJuego::botonJugar_Click);
			this->botonJugar->MouseEnter += gcnew System::EventHandler(this, &MenuJuego::botonJugar_MouseEnter);
			this->botonJugar->MouseLeave += gcnew System::EventHandler(this, &MenuJuego::botonJugar_MouseLeave);
			// 
			// MenuJuego
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MenuJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuJuego";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void botonJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ MyFormJuego = gcnew MyForm();
		this->Hide();

		MyFormJuego->FormClosed += gcnew FormClosedEventHandler(this, &MenuJuego::JuegoForm_Closed);
		MyFormJuego->Show();
	}

	private: System::Void JuegoForm_Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		this->Show(); // Mostrar el menú cuando se cierra el form del juego
	}

	private: System::Void botonJugar_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		botonJugar->BackgroundImage = botonJugarHover;
	}
	private: System::Void botonJugar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		botonJugar->BackgroundImage = botonJugarNormal;
	}
	private: System::Void botonRanking_Click(System::Object^ sender, System::EventArgs^ e) {
		//// mostrar ranking 
		MyForm1^ MyFormJuego = gcnew MyForm1();
		MyFormJuego->Show();
		//this->Hide();
	}
private: System::Void botonRanking_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	botonRanking->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/rankingblanco.png");
}
private: System::Void botonRanking_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	botonRanking->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/rankingcopy.png");
}
private: System::Void botonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void botonClose_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	botonClose->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/closeblanco.png");
}
private: System::Void botonClose_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	botonClose->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/closecopy.png");
}
private: System::Void botonInstruciones_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void botonInstruciones_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	botonInstruciones->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/instruccionesblanco.png");
}
private: System::Void botonInstruciones_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	botonInstruciones->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/instruccionescopy.png");
}
private: System::Void botonCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void botonCreditos_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	botonCreditos->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/preguntablanco.png");
}
private: System::Void botonCreditos_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	botonCreditos->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/preguntacopy.png");
}
};
}
