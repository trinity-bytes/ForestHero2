#pragma once

namespace ForestHero2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
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
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ botonRegresar;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Creditos::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->botonRegresar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->botonRegresar);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1366, 768);
			this->panel1->TabIndex = 0;
			// 
			// botonRegresar
			// 
			this->botonRegresar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"botonRegresar.BackgroundImage")));
			this->botonRegresar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->botonRegresar->FlatAppearance->BorderSize = 0;
			this->botonRegresar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->botonRegresar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->botonRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->botonRegresar->Location = System::Drawing::Point(47, 602);
			this->botonRegresar->Name = L"botonRegresar";
			this->botonRegresar->Size = System::Drawing::Size(122, 108);
			this->botonRegresar->TabIndex = 0;
			this->botonRegresar->UseVisualStyleBackColor = true;
			this->botonRegresar->Click += gcnew System::EventHandler(this, &Creditos::botonRegresar_Click);
			this->botonRegresar->MouseEnter += gcnew System::EventHandler(this, &Creditos::botonRegresar_MouseEnter);
			this->botonRegresar->MouseLeave += gcnew System::EventHandler(this, &Creditos::botonRegresar_MouseLeave);
			// 
			// Creditos
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1366, 768);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Creditos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Creditos";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void botonRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void botonRegresar_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		botonRegresar->BackgroundImage = Image::FromFile("Resources/Buttons/menuSeleccionModo-assets/back blanco.png");
	}
	private: System::Void botonRegresar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		botonRegresar->BackgroundImage = Image::FromFile("Resources/Buttons/menuSeleccionModo-assets/back copy.png");
	}
	};
}
