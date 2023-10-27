#pragma once
#include "cargarArchivo.h"
#include <string>

//Ventanas
#include "ventanaInsertarCiudad.h"
#include "ventanaBuscarCiudad.h"
#include "ventanaModificarCiudad.h"
#include "ventanaEliminarCiudad.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupCiudades
	/// </summary>
	public ref class ventanaPopupCiudades : public System::Windows::Forms::Form
	{
	public:
		bool^ flag;
	private: System::Windows::Forms::Button^ button5;
	public:
		cargarArchivo* progra;
		ventanaPopupCiudades(cargarArchivo* progra, bool^ flag)
		{
			this->flag = flag;
			this->progra = progra;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ventanaPopupCiudades()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label4;
	protected:
	public: System::Windows::Forms::Button^ button4;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		ventanaInsertarCiudad^ InsertarCiudad;
		ventanaBuscarCiudad^ BuscarCiudad;
		ventanaModificarCiudad^ ModificarCiudad;
		ventanaEliminarCiudad^ EliminarCiudad;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupCiudades::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(186, 232);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"ELIMINAR";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(165, 144);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 85);
			this->button4->TabIndex = 22;
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ventanaPopupCiudades::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 232);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"MODIFICAR";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(34, 144);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 20;
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupCiudades::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(186, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"BUSCAR";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(165, 16);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 18;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupCiudades::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"INSERTAR";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(34, 16);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 16;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupCiudades::button1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(104, 257);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 24;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ventanaPopupCiudades::button5_Click);
			// 
			// ventanaPopupCiudades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 292);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupCiudades";
			this->Text = L"Ciudades";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupCiudades::ventanaPopupCiudades_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupCiudades_Load(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void ventanaInsertarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaMenu is disposed before accessing it
	if (InsertarCiudad != nullptr && !InsertarCiudad->IsDisposed) {
		// Unsubscribe events
		InsertarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaInsertarCiudad_FormClosed);
		// Show the ventanaPrincipal form when ventanaMenu is closed
	}
	this->Show();
}

private: System::Void ventanaEliminarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarCiudad is disposed before accessing it
	if (EliminarCiudad != nullptr && !EliminarCiudad->IsDisposed) {
		// Unsubscribe events
		EliminarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaEliminarCiudad_FormClosed);
		// Show the ventanaPrincipal form when EliminarCiudad is closed
	}
	this->Show();
}


private: System::Void ventanaBuscarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarCiudad is disposed before accessing it
	if (BuscarCiudad != nullptr && !BuscarCiudad->IsDisposed) {
		// Unsubscribe events
		BuscarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaBuscarCiudad_FormClosed);
		// Show the ventanaPrincipal form when BuscarCiudad is closed
	}
	this->Show();
}

private: System::Void ventanaModificarCiudad_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarCiudad is disposed before accessing it
	if (ModificarCiudad != nullptr && !ModificarCiudad->IsDisposed) {
		// Unsubscribe events
		ModificarCiudad->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaModificarCiudad_FormClosed);
		// Show the ventanaPrincipal form when ModificarCiudad is closed
	}
	this->Show();
}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para InsertarCiudad
	InsertarCiudad = gcnew ventanaInsertarCiudad(progra);
	InsertarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaInsertarCiudad_FormClosed);
	InsertarCiudad->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Ciudad
	BuscarCiudad = gcnew ventanaBuscarCiudad(progra);
	BuscarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaBuscarCiudad_FormClosed);
	BuscarCiudad->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Ciudad
	ModificarCiudad = gcnew ventanaModificarCiudad(progra);
	ModificarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaModificarCiudad_FormClosed);
	ModificarCiudad->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Ciudad
	EliminarCiudad = gcnew ventanaEliminarCiudad(progra);
	EliminarCiudad->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupCiudades::ventanaEliminarCiudad_FormClosed);
	EliminarCiudad->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
