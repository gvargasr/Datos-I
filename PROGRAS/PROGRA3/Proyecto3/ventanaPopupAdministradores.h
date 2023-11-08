#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaInsertarAdmin.h"
#include "ventanaEliminarAdmin.h"
#include "ventanaBuscarAdmin.h"
#include "ventanaModificarAdmin.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupAdministradores
	/// </summary>
	public ref class ventanaPopupAdministradores : public System::Windows::Forms::Form
	{
	public:
		bool^ flag;
	private: System::Windows::Forms::Button^ button5;
	public:
		cargarArchivo* progra;
		ventanaPopupAdministradores(cargarArchivo* progra, bool^ flag)
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
		~ventanaPopupAdministradores()
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
		
		ventanaInsertarAdmin^ InsertarAdmin;
		ventanaEliminarAdmin^ EliminarAdmin;
		ventanaBuscarAdmin^ BuscarAdmin;
		ventanaModificarAdmin^ ModificarAdmin;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupAdministradores::typeid));
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
			this->label4->TabIndex = 31;
			this->label4->Text = L"ELIMINAR";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Control;
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(165, 144);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 85);
			this->button4->TabIndex = 30;
			this->button4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ventanaPopupAdministradores::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 232);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 29;
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
			this->button3->TabIndex = 28;
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupAdministradores::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(186, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 27;
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
			this->button2->TabIndex = 26;
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupAdministradores::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"INSERTAR";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Location = System::Drawing::Point(34, 16);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 24;
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupAdministradores::button1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(105, 257);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 32;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ventanaPopupAdministradores::button5_Click);
			// 
			// ventanaPopupAdministradores
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
			this->Name = L"ventanaPopupAdministradores";
			this->Text = L"Administradores";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupAdministradores::ventanaPopupAdministradores_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupAdministradores_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}


private: System::Void ventanaInsertarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaAdmin is disposed before accessing it
	if (InsertarAdmin != nullptr && !InsertarAdmin->IsDisposed) {
		// Unsubscribe events
		InsertarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaInsertarAdmin_FormClosed);
		// Show the ventanaPrincipal form when ventanaAdmin is closed
	}
	this->Show();
}


private: System::Void ventanaEliminarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaEliminarAdmin is disposed before accessing it
	if (EliminarAdmin != nullptr && !EliminarAdmin->IsDisposed) {
		// Unsubscribe events
		EliminarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaEliminarAdmin_FormClosed);
		// Show the ventanaPrincipal form when EliminarAdmin is closed
	}
	this->Show();
}


private: System::Void ventanaBuscarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaBuscarAdmin is disposed before accessing it
	if (BuscarAdmin != nullptr && !BuscarAdmin->IsDisposed) {
		// Unsubscribe events
		BuscarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaBuscarAdmin_FormClosed);
		// Show the ventanaPrincipal form when BuscarAdmin is closed
	}
	this->Show();
}

private: System::Void ventanaModificarAdmin_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaModificarAdmin is disposed before accessing it
	if (ModificarAdmin != nullptr && !ModificarAdmin->IsDisposed) {
		// Unsubscribe events
		ModificarAdmin->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaModificarAdmin_FormClosed);
		// Show the ventanaPrincipal form when ModificarAdmin is closed
	}
	this->Show();
}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Insertar Admin
	InsertarAdmin = gcnew ventanaInsertarAdmin(progra);
	InsertarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaInsertarAdmin_FormClosed);
	InsertarAdmin->Show();
	this->Hide();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Buscar Admin
	BuscarAdmin = gcnew ventanaBuscarAdmin(progra);
	BuscarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaBuscarAdmin_FormClosed);
	BuscarAdmin->Show();
	this->Hide();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Modificar Admin
	ModificarAdmin = gcnew ventanaModificarAdmin(progra);
	ModificarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaModificarAdmin_FormClosed);
	ModificarAdmin->Show();
	this->Hide();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//text box para Eliminar Admin
	EliminarAdmin = gcnew ventanaEliminarAdmin(progra);
	EliminarAdmin->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupAdministradores::ventanaEliminarAdmin_FormClosed);
	EliminarAdmin->Show();
	this->Hide();
}
};
}
