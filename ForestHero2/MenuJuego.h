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
			this->botonClose = (gcnew System::Windows::Forms::Button());
			this->botonRanking = (gcnew System::Windows::Forms::Button());
			this->botonJugar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->botonClose);
			this->panel1->Controls->Add(this->botonRanking);
			this->panel1->Controls->Add(this->botonJugar);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1821, 945);
			this->panel1->TabIndex = 0;
			// 
			// botonClose
			// 
			this->botonClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonClose.BackgroundImage")));
			this->botonClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonClose->FlatAppearance->BorderSize = 0;
			this->botonClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonClose->Location = System::Drawing::Point(1676, 26);
			this->botonClose->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->botonClose->Name = L"botonClose";
			this->botonClose->Size = System::Drawing::Size(129, 116);
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
			this->botonRanking->Location = System::Drawing::Point(83, 774);
			this->botonRanking->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->botonRanking->Name = L"botonRanking";
			this->botonRanking->Size = System::Drawing::Size(313, 116);
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
			this->botonJugar->Location = System::Drawing::Point(681, 390);
			this->botonJugar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->botonJugar->Name = L"botonJugar";
			this->botonJugar->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->botonJugar->Size = System::Drawing::Size(451, 162);
			this->botonJugar->TabIndex = 0;
			this->botonJugar->UseVisualStyleBackColor = false;
			this->botonJugar->Click += gcnew System::EventHandler(this, &MenuJuego::botonJugar_Click);
			this->botonJugar->MouseEnter += gcnew System::EventHandler(this, &MenuJuego::botonJugar_MouseEnter);
			this->botonJugar->MouseLeave += gcnew System::EventHandler(this, &MenuJuego::botonJugar_MouseLeave);
			// 
			// MenuJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1821, 945);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MenuJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuJuego";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void botonJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ MyFormJuego = gcnew MyForm();
		MyFormJuego->Show();
		this->Hide();
	}
	private: System::Void botonJugar_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		botonJugar->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/jugarblanco.png");
	}
	private: System::Void botonJugar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		botonJugar->BackgroundImage = Image::FromFile("Resources/Buttons/menuPrincipal-assets/jugarcopy.png");
	}
	private: System::Void botonRanking_Click(System::Object^ sender, System::EventArgs^ e) {
		//// mostrar ranking 
		//MyForm1^ MyFormJuego = gcnew MyForm1();
		//MyFormJuego->Show();
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
};
}
