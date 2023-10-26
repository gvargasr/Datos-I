#pragma once
#include "cargarArchivo.h"
#include <string>


#include "ventanaInsertarPais.h"
#include "ventanaBuscarPais.h"
#include "ventanaModificarPais.h"
#include "ventanaEliminarPais.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupPaises
	/// </summary>
	public ref class ventanaPopupPaises : public System::Windows::Forms::Form
	{
	public:
		bool^ flag;
		cargarArchivo* progra;
		ventanaPopupPaises(cargarArchivo* progra, bool^ flag)
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
		~ventanaPopupPaises()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label1;
	protected:
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaInsertarPais^ InsertarPais;
		ventanaBuscarPais^ BuscarPais;
		ventanaModificarPais^ ModificarPais;
		ventanaEliminarPais^ EliminarPais;
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupPaises::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"INSERTAR";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(29, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 8;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupPaises::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(181, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"BUSCAR";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(160, 21);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 10;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupPaises::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 237);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"MODIFICAR";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(29, 149);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 12;
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupPaises::button3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(181, 237);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"ELIMINAR";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(160, 149);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 85);
			this->button4->TabIndex = 14;
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ventanaPopupPaises::button4_Click);
			// 
			// ventanaPopupPaises
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(285, 277);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupPaises";
			this->Text = L"Paises";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupPaises::ventanaPopupPaises_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupPaises_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void ventanaInsertarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupPaises is disposed before accessing it
	if (InsertarPais != nullptr && !InsertarPais->IsDisposed) {
		// Unsubscribe events
		InsertarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaInsertarPais_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupPaises is closed
	}
	this->Show();
}


private: System::Void ventanaBuscarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarPais is disposed before accessing it
	if (BuscarPais != nullptr && !BuscarPais->IsDisposed) {
		// Unsubscribe events
		BuscarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaBuscarPais_FormClosed);
		// Show the ventanaPrincipal form when BuscarPais is closed
	}
	this->Show();
}



private: System::Void ventanaModificarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarPais is disposed before accessing it
	if (ModificarPais != nullptr && !ModificarPais->IsDisposed) {
		// Unsubscribe events
		ModificarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaModificarPais_FormClosed);
		// Show the ventanaPrincipal form when ModificarPais is closed
	}
	this->Show();
}



	private: System::Void ventanaEliminarPais_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaEliminarPais is disposed before accessing it
		if (EliminarPais != nullptr && !EliminarPais->IsDisposed) {
			// Unsubscribe events
			EliminarPais->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaEliminarPais_FormClosed);
			// Show the ventanaPrincipal form when EliminarPais is closed
		}
		this->Show();
	}





private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Pais
	InsertarPais = gcnew ventanaInsertarPais(progra);
	InsertarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaInsertarPais_FormClosed);
	InsertarPais->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Pais
	BuscarPais = gcnew ventanaBuscarPais(progra);
	BuscarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaBuscarPais_FormClosed);
	BuscarPais->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Pais
	ModificarPais = gcnew ventanaModificarPais(progra);
	ModificarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaModificarPais_FormClosed);
	ModificarPais->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Pais
	EliminarPais = gcnew ventanaEliminarPais(progra);
	EliminarPais->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupPaises::ventanaEliminarPais_FormClosed);
	EliminarPais->Show();
}
};
}
