#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaComprar.h"
#include "ventanaPopupAdministradores.h"
#include "ventanaPopupClientes.h"


namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupUsuarios
	/// </summary>
	public ref class ventanaPopupUsuarios : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		String^ usuario;
	private: System::Windows::Forms::Button^ button5;
	public:
		bool^ flag;
		ventanaPopupUsuarios(cargarArchivo* progra, String^ usuario, bool^ flag)
		{
			this->usuario = usuario;
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
		~ventanaPopupUsuarios()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label2;
	protected:
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaComprar^ ventanaCompra;
		ventanaPopupAdministradores^ popupAdmin;
		ventanaPopupClientes^ popupCliente;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupUsuarios::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(147, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"CLIENTES";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(136, 23);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 7;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupUsuarios::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 115);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"ADMINISTRADORES";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(29, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 9;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupUsuarios::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(271, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"FILA";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(245, 23);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 11;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupUsuarios::button3_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(146, 145);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 25;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ventanaPopupUsuarios::button5_Click);
			// 
			// ventanaPopupUsuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(358, 180);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Name = L"ventanaPopupUsuarios";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Usuarios";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupUsuarios::ventanaPopupUsuarios_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void ventanaComprar_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaCompra != nullptr && !ventanaCompra->IsDisposed) {
		// Unsubscribe events
		ventanaCompra->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaComprar_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Show();
}


private: System::Void ventanaPopupClientes_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarCliente is disposed before accessing it
	if (popupCliente != nullptr && !popupCliente->IsDisposed) {
		// Unsubscribe events
		popupCliente->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaPopupClientes_FormClosed);
		// Show the ventanaPrincipal form when BuscarCliente is closed
	}
	this->Show();
}


private: System::Void ventanaPopupAdministradores_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarCliente is disposed before accessing it
	if (popupAdmin != nullptr && !popupAdmin->IsDisposed) {
		// Unsubscribe events
		popupAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaPopupAdministradores_FormClosed);
		// Show the ventanaPrincipal form when ModificarCliente is closed
	}
	this->Show();
}



	private: System::Void ventanaPopupUsuarios_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (*flag == true) {
		popupAdmin = gcnew ventanaPopupAdministradores(progra, flag);
		popupAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaPopupAdministradores_FormClosed);
		popupAdmin->Show();
	}
	else {
		popupAdmin = gcnew ventanaPopupAdministradores(progra, flag);
		popupAdmin->button1->Enabled = false;
		popupAdmin->button3->Enabled = false;
		popupAdmin->button4->Enabled = false;
		popupAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaPopupAdministradores_FormClosed);
		popupAdmin->Show();
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (*flag == true) {
		popupCliente = gcnew ventanaPopupClientes(progra, flag);
		popupCliente->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaPopupClientes_FormClosed);
		popupCliente->Show();
	}
	else {
		popupCliente = gcnew ventanaPopupClientes(progra, flag);
		popupCliente->button1->Enabled = false;
		popupCliente->button3->Enabled = false;
		popupCliente->button4->Enabled = false;
		popupCliente->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaPopupClientes_FormClosed);
		popupCliente->Show();
	}
}


private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	ventanaCompra = gcnew ventanaComprar(progra, usuario, flag);
	ventanaCompra->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupUsuarios::ventanaComprar_FormClosed);
	ventanaCompra->Show();
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
