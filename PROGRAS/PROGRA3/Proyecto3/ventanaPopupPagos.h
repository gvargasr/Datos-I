#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaPopupFacturacion.h"
#include "ventanaReporteDescuento.h"


namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupPagos
	/// </summary>
	public ref class ventanaPopupPagos : public System::Windows::Forms::Form
	{
	public:
		String^ usuario;
		bool^ flag;
	private: System::Windows::Forms::Button^ button3;
	public:

	public:
		cargarArchivo* progra;
		ventanaPopupPagos(cargarArchivo* progra, String^ usuario, bool^ flag)
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
		~ventanaPopupPagos()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Button^ button1;
	protected:

	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaPopupFacturacion^ ventanaFacturar;
		ventanaReporteDescuento^ ventanaDesc;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupPagos::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(31, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"FACTURACION";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(29, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 8;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupPagos::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(162, 135);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"DESCUENTO";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(151, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 10;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupPagos::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(92, 164);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 25;
			this->button3->Text = L"Cancelar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupPagos::button5_Click);
			// 
			// ventanaPopupPagos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(266, 199);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Name = L"ventanaPopupPagos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Pagos";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupPagos::ventanaPopupPagos_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupPagos_Load(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void ventanaPopupFacturacion_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaFacturar != nullptr && !ventanaFacturar->IsDisposed) {
		// Unsubscribe events
		ventanaFacturar->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupPagos::ventanaPopupFacturacion_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Show();
}

private: System::Void ventanaDesc_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	// Check if ventanaPopupClientees is disposed before accessing it
	if (ventanaDesc != nullptr && !ventanaDesc->IsDisposed) {
		// Unsubscribe events
		ventanaDesc->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupPagos::ventanaDesc_FormClosed);
		// Show the ventanaPrincipal form when ventanaPopupClientees is closed
	}
	this->Enabled = true;
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	ventanaFacturar = gcnew ventanaPopupFacturacion(progra, usuario, flag);
	ventanaFacturar->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupPagos::ventanaPopupFacturacion_FormClosed);
	ventanaFacturar->Show();
	this->Hide();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//DESCUENTO CON TARJETA
	//this->Hide();
	ventanaDesc = gcnew ventanaReporteDescuento(progra);
	ventanaDesc->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupPagos::ventanaDesc_FormClosed);
	ventanaDesc->Show();
	this->Enabled = false;
}
};
}
